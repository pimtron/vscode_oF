#include "ofMain.h"


class Shape{
public:
	Shape();
	Shape(int x, int y);
	~Shape();

	//void Shape::draw();


	void update();
	void draw();
	void walk();

	ofColor color;
	int startingX;
	int startingY;
    int cornerRadius;
	float size;
	float size2;
	float size3;
	float size4;


	float bgFade;

	float rotationZ;
	float rotateZ;
	float rotationY;
	float rotateY;
	float rotationX;
	float rotateX;
};

