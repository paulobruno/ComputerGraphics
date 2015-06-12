#ifndef PAWN_H
#define PAWN_H

#include <QGLWidget>

#define PAWN_HEIGHT 23
#define PAWN_WIDTH 20

struct pawnPoint {
    float x, y, z;
};

class Pawn
{
public:
    Pawn();
    void draw();

private:
    pawnPoint *pawnPoints;
    pawnPoint pawnVertex[PAWN_HEIGHT+1][PAWN_WIDTH+1];
};

#endif // PAWN_H
