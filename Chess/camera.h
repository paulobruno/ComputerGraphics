#ifndef CAMERA_H
#define CAMERA_H

struct point {
    double x, y, z;
};

class Camera {
    private:
        point eye, lookAt, viewUp;
        point I, K, i, j, k;
        double modI, modK;

    public:
        double matrix[16];

        void updateEyeX(double x);
        void updateEyeY(double y);
        void updateEyeZ(double z);

        void setDate(double eyeX, double eyeY, double eyeZ, double lookAtX, double lookAtY, double lookAtZ, double viewUpX, double viewUpY, double viewUpZ);
        void createMatrix();
};

#endif // CAMERA_H
