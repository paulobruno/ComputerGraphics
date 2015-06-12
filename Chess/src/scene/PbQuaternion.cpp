#include "PbQuaternion.h"
#include <cmath>

PbQuaternion :: PbQuaternion()
{
    s = 0.0;
    x = 0.0;
    y = 0.0;
    z = 0.0;

    //load identity
    matrix[0] = 1.0;
    matrix[1] = 0.0;
    matrix[2] = 0.0;
    matrix[3] = 0.0;
    matrix[4] = 0.0;
    matrix[5] = 1.0;
    matrix[6] = 0.0;
    matrix[7] = 0.0;
    matrix[8] = 0.0;
    matrix[9] = 0.0;
    matrix[10] = 1.0;
    matrix[11] = 0.0;
    matrix[12] = 0.0;
    matrix[13] = 0.0;
    matrix[14] = 0.0;
    matrix[15] = 1.0;
}

PbQuaternion :: PbQuaternion(double scalar, double v_x, double v_y, double v_z)
{
    s = scalar;
    x = v_x;
    y = v_y;
    z = v_z;

    //load identity
    matrix[0] = 1.0;
    matrix[1] = 0.0;
    matrix[2] = 0.0;
    matrix[3] = 0.0;
    matrix[4] = 0.0;
    matrix[5] = 1.0;
    matrix[6] = 0.0;
    matrix[7] = 0.0;
    matrix[8] = 0.0;
    matrix[9] = 0.0;
    matrix[10] = 1.0;
    matrix[11] = 0.0;
    matrix[12] = 0.0;
    matrix[13] = 0.0;
    matrix[14] = 0.0;
    matrix[15] = 1.0;
}

void PbQuaternion :: calculateMagnitude()
{
    magnitude = s*s + x*x + y*y + z*z;
}

void PbQuaternion :: calculateRotationMatrix()
{
    matrix[0] = s*s + x*x - y*y - z*z;
    matrix[1] = 2*(s*z + x*y);
    matrix[2] = 2*(-s*y + x*z);
    matrix[3] = 0.0;

    matrix[4] = 2*(-s*z + x*y);
    matrix[5] = s*s - x*x + y*y - z*z;
    matrix[6] = 2*(s*x + y*z);
    matrix[7] = 0.0;

    matrix[8] = 2*(s*y + x*z);
    matrix[9] = 2*(-s*x + y*z);
    matrix[10] = s*s - x*x - y*y + z*z;
    matrix[11] = 0.0;

    matrix[12] = 0.0;
    matrix[13] = 0.0;
    matrix[14] = 0.0;
    matrix[15] = magnitude;
}

void PbQuaternion :: setScalar(double scalar)
{
    s = scalar;
    calculateMagnitude();
}

void PbQuaternion::setVector(double v_x, double v_y, double v_z)
{
    x = v_x;
    y = v_y;
    z = v_z;

    calculateMagnitude();
}
