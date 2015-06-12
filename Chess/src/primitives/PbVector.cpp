#include "PbVector.h"
#include <cmath>

PbVector :: PbVector() {}

PbVector :: PbVector(double end_x, double end_y, double end_z)
{
    initialPoint->set_x(0.0);
    initialPoint->set_y(0.0);
    initialPoint->set_z(0.0);

	endPoint->set_x(end_x);
	endPoint->set_y(end_y);
	endPoint->set_z(end_z);

    magnitude = sqrt(pow(end_x, 2) + pow(end_y, 2) + pow(end_z, 2));
}

PbVector :: PbVector(double init_x, double init_y, double init_z, double end_x, double end_y, double end_z)
{
	initialPoint->set_x(init_x);
	initialPoint->set_y(init_y);
	initialPoint->set_z(init_z);

	endPoint->set_x(end_x);
	endPoint->set_y(end_y);
	endPoint->set_z(end_z);

    magnitude = sqrt(pow(end_x - init_x, 2) + pow(end_y - init_y, 2) + pow(end_z - init_z, 2));
}

PbVector :: ~PbVector()
{
}

PbVector* PbVector :: normalize()
{
	double ix = initialPoint->get_x();
	double iy = initialPoint->get_y();
	double iz = initialPoint->get_z();
	double ex = endPoint->get_x() / magnitude;
	double ey = endPoint->get_y() / magnitude;
	double ez = endPoint->get_z() / magnitude;

    PbVector *normV;
    normV = new PbVector(ix, iy, iz, ex, ey, ez);

	return normV;
}

double PbVector :: getMagnitude()
{
	return magnitude;
}

void PbVector :: setInitXYZ(double init_x, double init_y, double init_z)
{
	initialPoint->set_x(init_x);
	initialPoint->set_y(init_y);
	initialPoint->set_z(init_z);
}

void PbVector :: setEndXYZ(double end_x, double end_y, double end_z)
{
	endPoint->set_x(end_x);
	endPoint->set_y(end_y);
	endPoint->set_z(end_z);
}
/*
void PbVector :: setInitX(double x)
{
}

void PbVector :: setInitY(double y)
{
}

void PbVector :: setInitZ(double z)
{
}

void PbVector :: setEndX(double x)
{
}

void PbVector :: setEndY(double y)
{
}

void PbVector :: setEndZ(double z)
{
}

double PbVector :: getInitX()
{
}

double PbVector :: getInitY()
{
}

double PbVector :: getInitZ()
{
}

double PbVector :: getEndX()
{
}

double PbVector :: getEndY()
{
}

double PbVector :: getEndZ()
{
}*/
