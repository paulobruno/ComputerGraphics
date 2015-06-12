#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <QGLWidget>

#define CHESSBOARD_HEIGHT 9
#define CHESSBOARD_WIDTH 9

struct chessPoint{
    float x, y, z;
};

class Chessboard
{
public:
    Chessboard();
    void draw();
private:
    chessPoint * chessPoints;
    chessPoint chessVertex[CHESSBOARD_HEIGHT][CHESSBOARD_WIDTH];
};

#endif // CHESSBOARD_H
