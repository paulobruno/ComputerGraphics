#include "PbChessboard.h"
#include <cstdlib>
#include <fstream>


#ifdef __APPLE__
    #include "gl.h"
#else
    #include "GL/gl.h"
#endif

using namespace std;

PbChessboard :: PbChessboard()
{
    identifier = 1;
    drawable = true;

    char trash;
    float a, b, c;
    int i = 0, j;

    ifstream fin;
    fin.open("../../assets/models/chessboard.obj");

    for (i = 0; i < CHESSBOARD_HEIGHT; i++) {
        for (j = 0; j < CHESSBOARD_WIDTH; j++) {
            fin >> trash >> a >> b >> c;
            chessPoint newPoint = {a, b, c};
            chessVertex[i][j] = newPoint;
        }
    }

    for (i = 0; i < CHESSBOARD_HEIGHT-1; i++) {
        for (j = 0; j < CHESSBOARD_WIDTH-1; j++) {
            chessFaceList[i][j].faceId = i*(CHESSBOARD_WIDTH-1) + j + 1;

            chessFaceList[i][j].v1 = chessVertex[i][j];
            chessFaceList[i][j].v2 = chessVertex[i+1][j];
            chessFaceList[i][j].v3 = chessVertex[i+1][j+1];
            chessFaceList[i][j].v4 = chessVertex[i][j+1];

            chessFaceList[i][j].calculateCenter();
        }
    }
    /*
    //lista todas as faces do tabuleiro
    for (i = 0; i < CHESSBOARD_HEIGHT-1; i++) {
        for (j = 0; j < CHESSBOARD_WIDTH-1; j++) {
            printf("face %d:\n", chessFaceList[i][j].faceId);
            printf("%f %f %f\n", chessFaceList[i][j].v1.x, chessFaceList[i][j].v1.y, chessFaceList[i][j].v1.z);
            printf("%f %f %f\n", chessFaceList[i][j].v2.x, chessFaceList[i][j].v2.y, chessFaceList[i][j].v2.z);
            printf("%f %f %f\n", chessFaceList[i][j].v3.x, chessFaceList[i][j].v3.y, chessFaceList[i][j].v3.z);
            printf("%f %f %f\n", chessFaceList[i][j].v4.x, chessFaceList[i][j].v4.y, chessFaceList[i][j].v4.z);
            printf("%f %f %f\n\n", chessFaceList[i][j].center.x, chessFaceList[i][j].center.y, chessFaceList[i][j].center.z);
        }
    }*/
}

void PbChessboard :: draw()
{
    int i, j;

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
}

void PbChessboard :: drawForPicking()
{
    int i, j;

    for (i = 0; i < CHESSBOARD_HEIGHT-1; i++) {
        for (j = 0; j < CHESSBOARD_WIDTH-1; j++) {
            glColor4f((i+j+1)%2, (i+j+1)%2, (i+j+1)%2, 1.0);

            glPushName(chessFaceList[i][j].faceId);
                glBegin(GL_QUADS);
                    glVertex3f(chessFaceList[i][j].v1.x, chessFaceList[i][j].v1.y, chessFaceList[i][j].v1.z);
                    glVertex3f(chessFaceList[i][j].v2.x, chessFaceList[i][j].v2.y, chessFaceList[i][j].v2.z);
                    glVertex3f(chessFaceList[i][j].v3.x, chessFaceList[i][j].v3.y, chessFaceList[i][j].v3.z);
                    glVertex3f(chessFaceList[i][j].v4.x, chessFaceList[i][j].v4.y, chessFaceList[i][j].v4.z);
                glEnd();
            glPopName();
        }
    }
}
