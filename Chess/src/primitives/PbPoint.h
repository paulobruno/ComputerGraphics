#ifndef PB_POINT_H
#define PB_POINT_H

class PbPoint{
	public:
        PbPoint();
        PbPoint(double x, double y, double z);

        virtual ~PbPoint();

        void set_x(double x);
        void set_y(double y);
        void set_z(double z);
        void set_xyz(double x, double y, double z);

        double get_x();
        double get_y();
        double get_z();

	protected:
		double p_x, p_y, p_z;
};

#endif // PB_POINT_H
