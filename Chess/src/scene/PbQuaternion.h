#ifndef PB_QUATERNION_H
#define PB_QUATERNION_H

#include "PbVector.h"

class PbQuaternion{
	public:
        PbQuaternion();
		PbQuaternion(double scalar, double v_x, double v_y, double v_z);
		//PbQuaternion(double scalar, Vector v);

		void calculateMagnitude();
        //void calculateConjugate();
        //void calculateInverse();
        void calculateRotationMatrix();

        void setScalar(double scalar);
        double getScalar() {return s;}

        void setVector(double v_x, double v_y, double v_z);
        double getX() {return x;}
        double getY() {return y;}
        double getZ() {return z;}

        double* getMatrix() {return matrix;}

	protected:
		double s, x, y, z, magnitude;
		double matrix[16];
        //PbQuaternion *conjugate, *inverse;

};

#endif // QUATERNION_H
