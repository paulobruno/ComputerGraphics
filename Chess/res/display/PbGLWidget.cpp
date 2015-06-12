#include "PbGLWidget.h"
#include <stdio.h>
#include <cmath>

#ifdef __APPLE__
    #include "glu.h"
#else
    #include "GL/glu.h"
#endif

PbGLWidget :: PbGLWidget(QWidget *parent) : QGLWidget(parent)
{
    renderMode = GL_RENDER;

    pawn3 = new PbPawn;
    chessboard = new PbChessboard;

    pawn3->setSingleScale(1.0f);
    pawn3->setCenterPoint(-1.5, -2.5, 0.0);
    pawn3->setId(110);

    translatePawn_x = -1.5;
    translatePawn_y = -2.5;
    translatePawn_z = -0.0;

    angle = 0.0;

    player1camera = new PbCamera(0.0, -8.0, 8.0, 0.0, 0.0, 0.0);
    player2camera = new PbCamera(0.0, 8.0, 8.0, 0.0, 0.0, 0.0);
    crowdCamera = new PbCamera(-8.0, 0.0, 8.0, 0.0, 0.0, 0.0);
    pawnCamera = new PbCamera(translatePawn_x, translatePawn_y+0.25, 1.75,
                                     translatePawn_x, translatePawn_y+0.25+1.0, 1.75);

    rotateQuaternion = new PbQuaternion();
}

PbGLWidget :: ~PbGLWidget()
{
    delete player1camera;
    delete player2camera;
    delete crowdCamera;
    delete pawnCamera;
}

void PbGLWidget :: initializeGL()
{
    glClearColor(0.0f, 1.0f, 0.0f, 1.0f);
    glEnable(GL_DEPTH_TEST);
    glDisable(GL_CULL_FACE);
    glFrontFace(GL_CCW);

}

void PbGLWidget :: resizeGL(int w, int h)
{
    if (h == 0) h = 1;

    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    if (w > h) {
        glFrustum(-0.0008f, 0.0008f*w/h,
                  -0.0008f, 0.001f,
                  0.001f, 30.0f);
    }
    else {
        glFrustum(-0.0008f, 0.0008f,
                  -0.0008f, 0.001f*h/w,
                  0.001f, 30.0f);
    }
}

void PbGLWidget :: paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);

    if (setPlayer1camera) {
        glLoadMatrixd(player1camera->getMatrix());
    }
    else if (setPlayer2camera) {
        glLoadMatrixd(player2camera->getMatrix());
    }
    else if (setPawnCamera) {
        pawnCamera->updateCamera(translatePawn_x, translatePawn_y+0.25, 1.75,
                                        translatePawn_x, translatePawn_y+0.25+1.0, 1.75);
        glLoadMatrixd(pawnCamera->getMatrix());
    }
    else if (setCrowdCamera) {
        glLoadMatrixd(crowdCamera->getMatrix());
        adjustRotation();
    }
    else
        glLoadIdentity();

    if (renderMode == GL_SELECT) {
        startPick();
            drawPickableObjects();
        finishPick();

        renderMode = GL_RENDER;
        updateGL();
    }
    else
        drawObjects();
}

void PbGLWidget :: adjustRotation()
{
    float pivot_x, pivot_y, pivot_z;

    pivot_x = (float) crowdCamera->getLookAt_x();
    pivot_y = (float) crowdCamera->getLookAt_y();
    pivot_z = (float) crowdCamera->getLookAt_z();

    glTranslatef(pivot_x, pivot_y, pivot_z);
    glMultMatrixd(rotateQuaternion->getMatrix());
    glTranslatef(-pivot_x, -pivot_y, -pivot_z);
}

void PbGLWidget :: drawObjects()
{
    if (chessboard->getDrawable())
        chessboard->draw();
    if (pawn3->getDrawable()) {
        glPushMatrix();
            glTranslatef(translatePawn_x, translatePawn_y, translatePawn_z);
            glScalef(pawn3->getSingleScale(), pawn3->getSingleScale(), pawn3->getSingleScale());
            pawn3->draw();
        glPopMatrix();
    }
}

void PbGLWidget :: drawPickableObjects()
{
    if (chessboard->getDrawable()) {
        chessboard->drawForPicking();
    }
    if (pawn3->getDrawable()) {
        glPushName(pawn3->getId());
            glPushMatrix();
                glTranslatef(translatePawn_x, translatePawn_y, translatePawn_z);
                pawn3->draw();
            glPopMatrix();
        glPopName();
    }
}

void PbGLWidget::mousePressEvent(QMouseEvent *event)
{
    if (event != NULL) {
        position = event->pos();

        //picking
        renderMode = GL_SELECT;
        updateGL();
    }
}

void PbGLWidget :: startPick()
{
    for(int i = 0; i < SELECT_BUFFER_SIZE; i++)
        selectBuffer[i] = 0;

    GLint view[4];
    GLfloat projection[16];

    // This choose the buffer where store the values for the selection data
    glSelectBuffer(SELECT_BUFFER_SIZE, selectBuffer);

    // Switching in selecton mode
    glRenderMode(GL_SELECT);

    // Now modify the viewing volume, restricting selection area around the cursor
    glMatrixMode(GL_PROJECTION);

    // Save the current Frustum
    glGetFloatv(GL_PROJECTION_MATRIX, projection);
    glPushMatrix();

    // Load identity
    glLoadIdentity();

    // Retrieve info about the viewport
    glGetIntegerv(GL_VIEWPORT, view);

    // Get the cursor position (invert y)
    GLdouble x = position.x();
    GLdouble y = view[3] - position.y();

    gluPickMatrix(x, y, 1.0, 1.0, view);

    // Apply our projection matrix
    glMultMatrixf(projection);

    // Draw the objects onto the screen
    glMatrixMode(GL_MODELVIEW);

    // Clear the name stack
    glInitNames();
}

void PbGLWidget :: finishPick() {
    GLint hits;

    // Reset projection
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();

    // Return to GL_MODELVIEW
    glMatrixMode(GL_MODELVIEW);

    // Get number of objects drawed in that area
    // and return to render mode
    hits = glRenderMode(GL_RENDER);

    // Handle the hits
    handlePick(hits, selectBuffer);
}

void PbGLWidget :: handlePick(GLint hits, GLuint *_selectBuffer)
{
    // Print a list of the objects
    printf("Number of hits: %d\n", hits);

    GLuint hitId = 0;
    GLuint smallestHit = 0;

    for (int i = 0; i < hits; i++) {
        printf("====== Hit ======\n");
        printf(	/**
                 * "Number: %u\n"
                 */
                "Min Z: %u\n"
                "Max Z: %u\n"
                "Name on stack: %u\n",
                 /**
                  *_selectBuffer[(i * 4)],
                  */
                 _selectBuffer[(i * 4) + 1], // zMin
                 _selectBuffer[(i * 4) + 2],
                 _selectBuffer[(i * 4) + 3]); // name

        if (hitId == 0 || _selectBuffer[(i * 4) + 1] < smallestHit) {
            smallestHit = _selectBuffer[(i * 4) + 1];
            hitId = _selectBuffer[(i * 4) + 3];
        }
    }

    if (pawn3 != NULL && pawn3->getId() == hitId) {
        printf("Piece selected!\n");
        pawn3->setSingleScale(1.5f);
    }
    else if (chessboard != NULL && hitId >= 1 && hitId <= 64) {
        printf("Board selected!\n");

        if (pawn3->getSingleScale() == 1.5) {
            pawn3->setSingleScale(1.0f);

            int i = (hitId-1) % 8;
            int j = (hitId-1) / 8;

            translatePawn_x = chessboard->chessFaceList[j][i].center.x;
            translatePawn_y = chessboard->chessFaceList[j][i].center.y;
            translatePawn_z = chessboard->chessFaceList[j][i].center.z;
        }
    }

    printf("\n");
    fflush(stdout);
}

void PbGLWidget :: setAngle(double delta)
{
    angle = delta*M_PI/180.0;
    setRotateCamera();
}

void PbGLWidget :: setRotateCamera()
{
    double ux, uy, uz, magnitude;

    ux = (crowdCamera->getEye_x() - crowdCamera->getLookAt_x());
    uy = (crowdCamera->getEye_y() - crowdCamera->getLookAt_y());
    uz = (crowdCamera->getEye_z() - crowdCamera->getLookAt_z());

    magnitude = sqrt((ux * ux) + (uy * uy) + (uz * uz));

    ux /= magnitude;
    uy /= magnitude;
    uz /= magnitude;

    rotateQuaternion->setScalar(cos(angle/2));
    rotateQuaternion->setVector(ux*sin(angle/2), uy*sin(angle/2), uz*sin(angle/2));
    rotateQuaternion->calculateRotationMatrix();

    updateGL();
}
