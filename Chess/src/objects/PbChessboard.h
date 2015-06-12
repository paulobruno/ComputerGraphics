#ifndef PB_CHESSBOARD_H
#define PB_CHESSBOARD_H

#include <QGLWidget>
#include "PbChessObject.h"

#define CHESSBOARD_HEIGHT 9
#define CHESSBOARD_WIDTH 9

struct chessPoint{
    float x, y, z;
};

struct chessFace{
    chessPoint v1, v2, v3, v4;
    chessPoint center;
    int faceId;

    void calculateCenter() {
        center.x = (v1.x + v3.x) / 2.0;
        center.y = (v1.y + v3.y) / 2.0;
        center.z = (v1.z + v3.z) / 2.0;
    }
};

class PbChessboard : public PbChessObject
{
    public:
        chessFace chessFaceList[CHESSBOARD_HEIGHT-1][CHESSBOARD_WIDTH-1];

        PbChessboard();

        void draw();
        void drawForPicking();

    private:
        chessPoint *chessPoints;
        chessPoint chessVertex[CHESSBOARD_HEIGHT][CHESSBOARD_WIDTH];
};

#endif // PB_CHESSBOARD_H
