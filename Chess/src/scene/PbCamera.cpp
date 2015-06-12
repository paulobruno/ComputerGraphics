#include "PbCamera.h"
#include <cmath>

PbCamera :: PbCamera(double eye_x, double eye_y, double eye_z,
                     double lookAt_x, double lookAt_y, double lookAt_z)
{
    eye.x = eye_x;
    eye.y = eye_y;
    eye.z = eye_z;

    lookAt.x = lookAt_x;
    lookAt.y = lookAt_y;
    lookAt.z = lookAt_z;

    viewUp.x = eye_x;
    viewUp.y = eye_y;
    viewUp.z = eye_z + 1.0;
}

PbCamera :: PbCamera(double eye_x, double eye_y, double eye_z,
                     double lookAt_x, double lookAt_y, double lookAt_z,
                     double viewUp_x, double viewUp_y, double viewUp_z)
{
    eye.x = eye_x;
    eye.y = eye_y;
    eye.z = eye_z;

    lookAt.x = lookAt_x;
    lookAt.y = lookAt_y;
    lookAt.z = lookAt_z;

    viewUp.x = viewUp_x;
    viewUp.y = viewUp_y;
    viewUp.z = viewUp_z;
}

void PbCamera :: updateEye(double x, double y, double z)
{
    eye.x = x;
    eye.y = y;
    eye.z = z;
}

void PbCamera :: updateLookAt(double x, double y, double z)
{
    lookAt.x = x;
    lookAt.y = y;
    lookAt.z = z;
}

void PbCamera :: updateViewUp(double x, double y, double z)
{
    viewUp.x = x;
    viewUp.y = y;
    viewUp.z = z;
}

void PbCamera :: updateCamera(double eye_x, double eye_y, double eye_z,
                              double lookAt_x, double lookAt_y, double lookAt_z)
{
    eye.x = eye_x;
    eye.y = eye_y;
    eye.z = eye_z;

    lookAt.x = lookAt_x;
    lookAt.y = lookAt_y;
    lookAt.z = lookAt_z;

    viewUp.x = eye_x;
    viewUp.y = eye_y;
    viewUp.z = eye_z + 1.0;
}

void PbCamera :: updateCamera(double eye_x, double eye_y, double eye_z,
                              double lookAt_x, double lookAt_y, double lookAt_z,
                              double viewUp_x, double viewUp_y, double viewUp_z)
{
    eye.x = eye_x;
    eye.y = eye_y;
    eye.z = eye_z;

    lookAt.x = lookAt_x;
    lookAt.y = lookAt_y;
    lookAt.z = lookAt_z;

    viewUp.x = viewUp_x;
    viewUp.y = viewUp_y;
    viewUp.z = viewUp_z;
}

double* PbCamera :: getMatrix()
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

    return matrix;
}
