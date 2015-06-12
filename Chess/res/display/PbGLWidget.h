#ifndef PB_GLWIDGET_H
#define PB_GLWIDGET_H

#include <QGLWidget>
#include <QMouseEvent>

#include "PbChessObject.h"
#include "PbPawn.h"
#include "PbChessboard.h"
#include "PbCamera.h"
#include "PbQuaternion.h"

#define SELECT_BUFFER_SIZE 4*16

class PbGLWidget : public QGLWidget{
	Q_OBJECT

	public:
        explicit PbGLWidget(QWidget *parent = 0);

        ~PbGLWidget();

        PbChessObject *pawn3;
        PbChessObject *chessboard;

        PbCamera *player1camera, *player2camera, *crowdCamera, *pawnCamera;
        PbQuaternion *rotateQuaternion;
        bool setPlayer1camera, setPlayer2camera, setCrowdCamera, setPawnCamera;

        void setAngle(double delta);
        void setRotateCamera();

	protected:
		virtual void initializeGL();
		virtual void resizeGL(int w, int h);
        virtual void paintGL();

    private:
        double angle;

        void drawObjects();
        void drawPickableObjects();
        void adjustRotation();
};

#endif // PB_GLWIDGET_H
