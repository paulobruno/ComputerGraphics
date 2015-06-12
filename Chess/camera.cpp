#include "camera.h"
#include <cmath>

void Camera::setDate(double eyeX, double eyeY, double eyeZ, double lookAtX, double lookAtY, double lookAtZ, double viewUpX, double viewUpY, double viewUpZ)
{
    eye.x = eyeX;
    eye.y = eyeY;
    eye.z = eyeZ;
    lookAt.x = lookAtX;
    lookAt.y = lookAtY;
    lookAt.z = lookAtZ;
    viewUp.x = viewUpX;
    viewUp.y = viewUpY;
    viewUp.z = viewUpZ;
}

void Camera::createMatrix()
{
    point vAux;

    // vector of z axis

    K.x = eye.x - lookAt.x;
    K.y = eye.y - lookAt.y;
    K.z = eye.z - lookAt.z;

    modK = sqrt(pow(K.x,2) + pow(K.y,2) + pow(K.z,2));

    k.x = K.x/modK;
    k.y = K.y/modK;
    k.z = K.z/modK;


    // vector of y axis

    vAux.x = viewUp.x - eye.x;
    vAux.y = viewUp.y - eye.y;
    vAux.z = viewUp.z - eye.z;

    I.x = (vAux.y * k.z) - (k.y * vAux.z);
    I.y = (vAux.z * k.x) - (k.z * vAux.x);
    I.z = (vAux.x * k.y) - (k.x * vAux.y);

    modI = sqrt(pow(I.x,2) + pow(I.y,2) + pow(I.z,2));

    i.x = I.x/modI;
    i.y = I.y/modI;
    i.z = I.z/modI;


    // vector of x axis

    j.x = (k.y * i.z) - (i.y * k.z);
    j.y = (k.z * i.x) - (i.z * k.x);
    j.z = (k.x * i.y) - (i.x * k.y);

    // matrix of transformation
    matrix[0] = i.x;
    matrix[1] = j.x;
    matrix[2] = k.x;
    matrix[3] = 0;
    matrix[4] = i.y;
    matrix[5] = j.y;
    matrix[6] = k.y;
    matrix[7] = 0;
    matrix[8] = i.z;
    matrix[9] = j.z;
    matrix[10] = k.z;
    matrix[11] = 0;
    matrix[12] = -(i.x*eye.x + i.y*eye.y + i.z*eye.z);
    matrix[13] = -(j.x*eye.x + j.y*eye.y + j.z*eye.z);
    matrix[14] = -(k.x*eye.x + k.y*eye.y + k.z*eye.z);
    matrix[15] = 1;
}
