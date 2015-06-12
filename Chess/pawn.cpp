#include "pawn.h"
#include <GL/gl.h>
#include <cstdlib>
#include <fstream>

using namespace std;

Pawn::Pawn()
{
    float a, b, c;
    int i = 0, j;

    ifstream fin;
    fin.open("../objects/pawn.txt");

    {
        fin >> a >> b >> c;
        pawnPoint newPoint = {a, b, c};
        pawnVertex[0][0] = newPoint;
    }

    for (i = 1; i< PAWN_HEIGHT - 1; i++) {
        for (j = 0; j < PAWN_WIDTH; j++) {
            fin >> a >> b >> c;
            pawnPoint newPoint = {a, b, c};
            pawnVertex[i][j] = newPoint;
        }
    }

    for (i = 1; i< PAWN_HEIGHT - 1; i++) {
        pawnVertex[i][PAWN_WIDTH] = pawnVertex[i][0];
    }

    {
        fin >> a >> b >> c;
        pawnPoint newPoint = {a, b, c};
        pawnVertex[PAWN_HEIGHT-1][0] = newPoint;
        i++;
    }



}

void Pawn::draw()
{
    int i=1, j;

    glBegin(GL_TRIANGLES);
        //tampa do peao
        for (j = 0; j < PAWN_WIDTH; j++) {
            glColor4f(0.0, 0.0, 0.0, 1.0);
            glVertex3f(0.0, 0.0, 2.0);
            glVertex3f(pawnVertex[i][j].x, pawnVertex[i][j].y, pawnVertex[i][j].z);
            glVertex3f(pawnVertex[i][j+1].x, pawnVertex[i][j+1].y, pawnVertex[i][j+1].z);
        }

        //corpo do peao
        for (i = 1; i < PAWN_HEIGHT-2; i++) {
            glColor4f(i/20.0, 0.0, 0.0, 1.0);
            for (j = 0; j < PAWN_WIDTH; j++) {
                glVertex3f(pawnVertex[i][j].x, pawnVertex[i][j].y, pawnVertex[i][j].z);
                glVertex3f(pawnVertex[i+1][j].x, pawnVertex[i+1][j].y, pawnVertex[i+1][j].z);
                glVertex3f(pawnVertex[i][j+1].x, pawnVertex[i][j+1].y, pawnVertex[i][j+1].z);

                //glColor4f(1.0, 1.0, 0.0, 1.0);
                glVertex3f(pawnVertex[i][j+1].x, pawnVertex[i][j+1].y, pawnVertex[i][j+1].z);
                glVertex3f(pawnVertex[i+1][j].x, pawnVertex[i+1][j].y, pawnVertex[i+1][j].z);
                glVertex3f(pawnVertex[i+1][j+1].x, pawnVertex[i+1][j+1].y, pawnVertex[i+1][j+1].z);
            }
        }

        //base do peao
        for (j = 0; j < PAWN_WIDTH; j++) {
            glColor4f(0.0, 0.0, 0.0, 1.0);
            glVertex3f(pawnVertex[i][j].x, pawnVertex[i][j].y, pawnVertex[i][j].z);
            glVertex3f(0.0, 0.0, 0.0);
            glVertex3f(pawnVertex[i][j+1].x, pawnVertex[i][j+1].y, pawnVertex[i][j+1].z);
        }

    glEnd();
}
