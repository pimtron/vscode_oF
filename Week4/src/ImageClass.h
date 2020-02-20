#include "ofMain.h"


class Shape{
public:
	Shape();
	Shape(int x, int y);
	~Shape();

	//void Shape::draw();

	void update();
	void draw();

	ofColor color;
	int startingX;
	int startingY;
    int cornerRadius;
	int size;

	float bgFade;
};

