#ifndef PB_VECTOR_H
#define PB_VECTOR_H

#include "PbPoint.h"

class PbVector{
	public:
        PbVector();
        PbVector(double end_x, double end_y, double end_z);
        PbVector(double init_x, double init_y, double init_z,
                 double end_x, double end_y, double end_z);

        virtual ~PbVector();

        PbVector* normalize();

		void setInitXYZ(double init_x, double init_y, double init_z);
		void setEndXYZ(double end_x, double end_y, double end_z);

		double getMagnitude();
/*
		void setInitX(double x);
		void setInitY(double y);
		void setInitZ(double z);
		void setEndX(double x);
		void setEndY(double y);
		void setEndZ(double z);

		double getLenght();
		double getInitX();
		double getInitY();
		double getInitZ();
		double getEndX();
		double getEndY();
		double getEndZ();
*/
	private:
        PbPoint *initialPoint, *endPoint;
		double magnitude;
};

#endif // PB_VECTOR_H
