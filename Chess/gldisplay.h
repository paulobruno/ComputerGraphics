#ifndef GLDISPLAY_H
#define GLDISPLAY_H

#include <QGLWidget>
#include <QMouseEvent>
#include "pawn.h"
#include "chessboard.h"

class GLDisplay : public QGLWidget
{
    Q_OBJECT
private:
    float angleX, angleY;
    bool chessboardDrawable, pawnDrawable;
    QPoint _position;
    Pawn pawn1, pawn2;
    Chessboard chessboard;

public:
    explicit GLDisplay(QWidget *parent = 0);

protected:
    virtual void initializeGL();
    virtual void paintGL();
    virtual void resizeGL(int w, int h);
    virtual void mouseMoveEvent ( QMouseEvent * event );
    virtual void mousePressEvent ( QMouseEvent * event );

public slots:
    void setDefault();
    void setPawnDrawable(bool draw);
    void setChessboardDrawable(bool draw);
    void setAngleX(int a);
    void setAngleY(int a);
};

#endif // GLDISPLAY_H
