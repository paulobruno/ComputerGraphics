#ifndef GLDISPLAY_H
#define GLDISPLAY_H

#include <QGLWidget>
#include <QMouseEvent>
#include "pawn.h"
#include "chessboard.h"
#include "camera.h"

class GLDisplay : public QGLWidget
{
    Q_OBJECT
private:
    bool chessboardDrawable, pawnDrawable, setPlayer1camera, setPlayer2camera, setPawn3camera, setCrowdCamera;
    double crowdEyeX, crowdEyeY, crowdEyeZ;

    Pawn pawn3;
    Chessboard chessboard;
    Camera player1camera, player2camera, pawn3camera, crowdCamera;

public:
    explicit GLDisplay(QWidget *parent = 0);

protected:
    virtual void initializeGL();
    virtual void paintGL();
    virtual void resizeGL(int w, int h);

public slots:
    void setPawnDrawable(bool draw);
    void setChessboardDrawable(bool draw);
    void setPlayer1();
    void setPlayer2();
    void setPawn3();
    void setCrowd();
    void setCrowdEyeX(double x);
    void setCrowdEyeY(double y);
    void setCrowdEyeZ(double z);
};

#endif // GLDISPLAY_H
