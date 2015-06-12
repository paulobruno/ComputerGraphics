#ifndef PAWN_H
#define PAWN_H

#include <QGLWidget>
#include "camera.h"

#define PAWN_HEIGHT 23
#define PAWN_WIDTH 20

struct pawnPoint {
    float x, y, z;
};

class Pawn
{
private:
    pawnPoint *pawnPoints;
    pawnPoint pawnVertex[PAWN_HEIGHT+1][PAWN_WIDTH+1];

public:
    Pawn();
    void draw();
};

#endif // PAWN_H
