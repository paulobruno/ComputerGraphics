#include "gldisplay.h"

GLDisplay::GLDisplay(QWidget *parent) :
    QGLWidget(parent)
{
    angleX = 0.0;
    angleY = 90.0;
    chessboardDrawable = true;
    pawnDrawable = true;
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
        glOrtho(-2.0f, 8.0f*w/h, -2.0f, 8.0f, -20.0f, 20.0f);
    } else {
        glOrtho(-2.0f, 8.0f, -2.0f, 8.0f*h/w, -20.0f, 20.0f);
    }
}

void GLDisplay::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glRotatef(-angleY, 1.0, 0.0, 0.0);
    glRotatef(-angleX, 0.0, 0.0, 1.0);

    if (chessboardDrawable) chessboard.draw();
    if (pawnDrawable) {
        glPushMatrix();
            glTranslatef(2.5, 1.5, 0.0);
            pawn1.draw();
        glPopMatrix();
        glPushMatrix();
            glTranslatef(3.5, 1.5, 0.0);
            pawn2.draw();
        glPopMatrix();
    }
}

void GLDisplay::mouseMoveEvent(QMouseEvent *event)
{
    if( event != NULL ) {
        QPoint position = event->pos();

        angleX += (position.x() - _position.x());
        angleY += (position.y() - _position.y());

        _position = position;

        updateGL();
    }
}

void GLDisplay::mousePressEvent(QMouseEvent *event)
{
    if( event != NULL )
        _position = event->pos();
}

void GLDisplay::setChessboardDrawable(bool draw)
{
    chessboardDrawable = draw;
    updateGL();

}

void GLDisplay::setAngleX(int a)
{
    angleX = a;
    updateGL();
}

void GLDisplay::setAngleY(int a)
{
    angleY = a;
    updateGL();
}

void GLDisplay::setPawnDrawable(bool draw)
{
    pawnDrawable = draw;
    updateGL();
}

void GLDisplay::setDefault()
{
    angleX = 0.0;
    angleY = 90.0;
    chessboardDrawable = true;
    pawnDrawable = true;
    updateGL();
}
