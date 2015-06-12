#include "PbPoint.h"

PbPoint :: PbPoint()
{
	p_x = 0.0;
	p_y = 0.0;
	p_z = 0.0;
}

PbPoint :: PbPoint(double x, double y, double z)
{
	p_x = x;
	p_y = y;
    p_z = z;
}

PbPoint :: ~PbPoint() {}

void PbPoint :: set_x(double x)
{
	p_x = x;
}

void PbPoint :: set_y(double y)
{
	p_y = y;
}

void PbPoint :: set_z(double z)
{
	p_z = z;
}

void PbPoint :: set_xyz(double x, double y, double z)
{
	p_x = x;
	p_y = y;
	p_z = z;
}

double PbPoint :: get_x()
{
	return p_x;
}

double PbPoint :: get_y()
{
	return p_y;
}

double PbPoint :: get_z()
{
	return p_z;
}
