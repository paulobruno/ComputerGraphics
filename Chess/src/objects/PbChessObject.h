#ifndef PB_CHESS_OBJECT_H
#define PB_CHESS_OBJECT_H

struct _point {
    double x, y, z;
};

class PbChessObject {
    public:
        virtual void draw() = 0;
        virtual void drawForPicking() = 0;

        void setId(unsigned int id) {identifier = id;}
        unsigned int getId() {return identifier;}

		void setDrawable(bool b) {drawable = b;}
        bool getDrawable() {return drawable;}
		
        void setSingleScale(float s) {singleScale = s;}
        float getSingleScale() {return singleScale;}

        void setRotateAngle(float delta) {rotateAngle = delta;}
        float getRotateAngle() {return rotateAngle;}

        void setCenterPoint(double x, double y, double z) {centerPoint.x = x;
                                                           centerPoint.y = y;
                                                           centerPoint.z = z;}
        _point getCenterPoint() {return centerPoint;}

	protected:
        _point centerPoint;

        float singleScale, rotateAngle;
        unsigned int identifier;
		bool drawable;
};

#endif // PB_CHESS_OBJECT_H
