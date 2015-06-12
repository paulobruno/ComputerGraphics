#ifndef PB_CAMERA_H
#define PB_CAMERA_H

struct point {
    double x, y, z;
};

class PbCamera {
    public:
        PbCamera() {}
        PbCamera(double eye_x, double eye_y, double eye_z,
                 double lookAt_x, double lookAt_y, double lookAt_z);
		PbCamera(double eye_x, double eye_y, double eye_z, 
                 double lookAt_x, double lookAt_y, double lookAt_z,
                 double viewUp_x, double viewUp_y, double viewUp_z);

		void updateEye(double x, double y, double z);
		void updateLookAt(double x, double y, double z);
		void updateViewUp(double x, double y, double z);

        double getEye_x() {return eye.x;}
        double getEye_y() {return eye.y;}
        double getEye_z() {return eye.z;}

        double getLookAt_x() {return lookAt.x;}
        double getLookAt_y() {return lookAt.y;}
        double getLookAt_z() {return lookAt.z;}

        double* getMatrix() {return matrix;}

    private:
        double matrix[16];

        double modI, modK;
        point eye, lookAt, viewUp;
        point I, K, i, j, k;

        void createMatrix();
};

#endif // PB_CAMERA_H
