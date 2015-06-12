#include "PbGLWidget.h"
#include "GL/glu.h"
#include <stdio.h>
#include <cmath>

PbGLWidget :: PbGLWidget(QWidget *parent) : QGLWidget(parent)
{
    pawn3 = new PbPawn;
    chessboard = new PbChessboard;

    pawn3->setSingleScale(1.0f);
    pawn3->setCenterPoint(-1.5, -2.5, 0.0);

    angle = 0.0;

    player1camera = new PbCamera(0.0, -8.0, 8.0, 0.0, 0.0, 0.0);
    player2camera = new PbCamera(0.0, 8.0, 8.0, 0.0, 0.0, 0.0);
    crowdCamera = new PbCamera(-8.0, 0.0, 8.0, 0.0, 0.0, 0.0);
    pawnCamera = new PbCamera(-1.5, -2.25, 1.75, -1.5, -1.25, 1.75);

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
        glFrustum(-0.0008f*(float)w/(float)h, 0.0008f*(float)w/(float)h,
                  -0.0008f, 0.0008f,
                  0.001f, 30.0f);
    }
    else {
        glFrustum(-0.0008f, 0.0008f,
                  -0.0008f*(float)h/(float)w, 0.0008f*(float)h/(float)w,
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
        glLoadMatrixd(pawnCamera->getMatrix());
    }
    else if (setCrowdCamera) {
        glLoadMatrixd(crowdCamera->getMatrix());
        adjustRotation();
    }
    else
        glLoadIdentity();

    drawObjects();
}

void PbGLWidget :: drawObjects()
{
    if (chessboard->getDrawable())
        chessboard->draw();
    if (pawn3->getDrawable()) {
        glPushMatrix();
            glTranslatef(-1.5, -2.5, 0.0);
            glScalef(pawn3->getSingleScale(), pawn3->getSingleScale(), pawn3->getSingleScale());
            pawn3->draw();
        glPopMatrix();
    }
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
