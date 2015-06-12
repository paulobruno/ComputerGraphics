#ifndef PB_CHESSBOARD_H
#define PB_CHESSBOARD_H

#include <QGLWidget>

#define CHESSBOARD_HEIGHT 9
#define CHESSBOARD_WIDTH 9

#include "PbChessObject.h"

struct chessPoint{
    float x, y, z;
};

class PbChessboard : public PbChessObject
{
    public:
        PbChessboard();

        void draw();

    private:
        chessPoint *chessPoints;
        chessPoint chessVertex[CHESSBOARD_HEIGHT][CHESSBOARD_WIDTH];
};

#endif // PB_CHESSBOARD_H
