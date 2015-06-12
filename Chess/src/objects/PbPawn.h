#ifndef PB_PAWN_H
#define PB_PAWN_H

#include <QGLWidget>

#define PAWN_HEIGHT 23
#define PAWN_WIDTH 20

#include "PbChessObject.h"

struct pawnPoint {
    float x, y, z;
};

class PbPawn : public PbChessObject
{
    public:
        PbPawn();

        void draw();
        void drawForPicking() {}

    private:
        pawnPoint *pawnPoints;
        pawnPoint pawnVertex[PAWN_HEIGHT+1][PAWN_WIDTH+1];
};

#endif // PB_PAWN_H
