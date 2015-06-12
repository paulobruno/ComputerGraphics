#include "gldisplay.h"

GLDisplay::GLDisplay(QWidget *parent) : QGLWidget(parent)
{
    crowdEyeX = -6.0;
    crowdEyeY = 0.0;
    crowdEyeZ = 6.0;

    chessboardDrawable = true;
    pawnDrawable = true;

    player1camera.setDate(0.0, -6.0, 6.0, 0.0, 0.0, 0.0, 0.0, 0.0, 12.0);
    player2camera.setDate(0, 6, 6, 0, 0, 0, 0, 0, 12);
    pawn3camera.setDate(-1.5, -2.25, 1.75, -1.5, -1.25, 1.75, -1.5, -2.25, 2.75);

    setPlayer1camera = true;
    setPlayer2camera = false;
    setPawn3camera = false;
    setCrowdCamera = false;
}

void GLDisplay::initializeGL()
{
    glClearColor(0.0f, 1.0f, 0.0f, 1.0f);
    glEnable(GL_DEPTH_TEST);
}

void GLDisplay::resizeGL(int w, int h)
{
    if (h == 0) h = 1;

    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    if (w > h) {
        glFrustum(-0.001f, 0.001f*w/h, -0.001f, 0.001f, 0.0004f, 20.0f);
    } else {
        glFrustum(-0.001f, 0.001f, -0.001f, 0.001f*h/w, 0.0004f, 20.0f);
    }
}

void GLDisplay::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);

    crowdCamera.setDate(crowdEyeX, crowdEyeY, crowdEyeZ, 0.0, 0.0, 0.0, 0.0, 0.0, crowdEyeZ+1.0);

    if (setPlayer1camera) {
        player1camera.createMatrix();
        glLoadMatrixd(player1camera.matrix);
    }
    else if (setPlayer2camera) {
        player2camera.createMatrix();
        glLoadMatrixd(player2camera.matrix);
    }
    else if (setPawn3camera) {
         pawn3camera.createMatrix();
         glLoadMatrixd(pawn3camera.matrix);
    }
    else if (setCrowdCamera) {
         crowdCamera.createMatrix();
         glLoadMatrixd(crowdCamera.matrix);
    }
    else
        glLoadIdentity();

    if (chessboardDrawable) chessboard.draw();
    if (pawnDrawable) {
        glPushMatrix();
            glTranslatef(-1.5, -2.5, 0.0);
            pawn3.draw();
        glPopMatrix();
    }
}

void GLDisplay::setChessboardDrawable(bool draw)
{
    chessboardDrawable = draw;
    updateGL();

}

void GLDisplay::setPawnDrawable(bool draw)
{
    pawnDrawable = draw;
    updateGL();
}

void GLDisplay::setPlayer1()
{
    setPlayer1camera = true;
    setPlayer2camera = false;
    setPawn3camera = false;
    setCrowdCamera = false;
    updateGL();
}

void GLDisplay::setPlayer2()
{
    setPlayer1camera = false;
    setPlayer2camera = true;
    setPawn3camera = false;
    setCrowdCamera = false;
    updateGL();
}

void GLDisplay::setPawn3()
{
    setPlayer1camera = false;
    setPlayer2camera = false;
    setPawn3camera = true;
    setCrowdCamera = false;
    updateGL();
}

void GLDisplay::setCrowd()
{
    setPlayer1camera = false;
    setPlayer2camera = false;
    setPawn3camera = false;
    setCrowdCamera = true;
    updateGL();
}

void GLDisplay::setCrowdEyeX(double x)
{
    crowdEyeX = x;
    updateGL();
}

void GLDisplay::setCrowdEyeY(double y)
{
    crowdEyeY = y;
    updateGL();
}

void GLDisplay::setCrowdEyeZ(double z)
{
    crowdEyeZ = z;
    updateGL();
}
