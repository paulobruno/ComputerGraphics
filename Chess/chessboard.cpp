#include "chessboard.h"
#include <GL/gl.h>
#include <cstdlib>
#include <fstream>

using namespace std;

Chessboard::Chessboard(){
    char trash;
    float a, b, c;
    int i = 0, j;

    ifstream fin;
    fin.open("../objects/chessboard.obj");

    for (i = 0; i < CHESSBOARD_HEIGHT; i++) {
        for (j = 0; j < CHESSBOARD_WIDTH; j++) {
            fin >> trash >> a >> b >> c;
            chessPoint newPoint = {a, b, c};
            chessVertex[i][j] = newPoint;
        }
    }
}

void Chessboard::draw()
{
    int i, j;

    glBegin(GL_TRIANGLES);
        for (i = 0; i < CHESSBOARD_HEIGHT-1; i++) {
            for (j = 0; j < CHESSBOARD_WIDTH-1; j++) {
                glColor4f((i+j+1)%2, (i+j+1)%2, (i+j+1)%2, 1.0);

                glVertex3f(chessVertex[i][j].x, chessVertex[i][j].y, chessVertex[i][j].z);
                glVertex3f(chessVertex[i+1][j].x, chessVertex[i+1][j].y, chessVertex[i+1][j].z);
                glVertex3f(chessVertex[i][j+1].x, chessVertex[i][j+1].y, chessVertex[i][j+1].z);

                glVertex3f(chessVertex[i][j+1].x, chessVertex[i][j+1].y, chessVertex[i][j+1].z);
                glVertex3f(chessVertex[i+1][j].x, chessVertex[i+1][j].y, chessVertex[i+1][j].z);
                glVertex3f(chessVertex[i+1][j+1].x, chessVertex[i+1][j+1].y, chessVertex[i+1][j+1].z);
            }
        }
    glEnd();

    //espessura do tabuleiro
    glBegin(GL_TRIANGLES);
        glColor4f(0.2, 0.2, 0.2, 1.0);
        glVertex3f(-4, -4, 0);
        glVertex3f(-4, -4, -0.5);
        glVertex3f(4, -4, 0);
        glVertex3f(4, -4, 0);
        glVertex3f(-4, -4, -0.5);
        glVertex3f(4, -4, -0.5);

        glVertex3f(4, -4, 0);
        glVertex3f(4, -4, -0.5);
        glVertex3f(4, 4, 0);
        glVertex3f(4, 4, 0);
        glVertex3f(4, -4, -0.5);
        glVertex3f(4, 4, -0.5);

        glVertex3f(4, 4, 0);
        glVertex3f(4, 4, -0.5);
        glVertex3f(-4, 4, 0);
        glVertex3f(-4, 4, 0);
        glVertex3f(4, 4, -0.5);
        glVertex3f(-4, 4, -0.5);

        glVertex3f(-4, 4, 0);
        glVertex3f(-4, 4, -0.5);
        glVertex3f(-4, -4, 0);
        glVertex3f(-4, -4, 0);
        glVertex3f(-4, 4, -0.5);
        glVertex3f(-4, -4, -0.5);

        glColor4f(0.0, 0.0, 0.0, 1.0);
        glVertex3f(-4, -4, -0.5);
        glVertex3f(4, -4, -0.5);
        glVertex3f(-4, 4, -0.5);
        glVertex3f(-4, 4, -0.5);
        glVertex3f(4, -4, -0.5);
        glVertex3f(4, 4, -0.5);
    glEnd();
}
