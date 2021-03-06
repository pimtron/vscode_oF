#include "ofMain.h"


class Shape{
public:

	Shape();
	Shape(int x, int y);
	~Shape();

	//void Shape::draw();
	void setup();
	void update();
	void draw();

	ofParameterGroup shapeParameters;
	ofParameter<int> tri;
	ofParameter<int> targetRadius;

	ofColor color;
	int startingX;
	int startingY;

	int startingX2;
	int startingY2;

    int cornerRadius;
	int size;
	int size2;

	float bgFade;
	float time = ofGetElapsedTimef();

	float triXStart;
	float triYStart;
	float triXStart2;
	float triYStart2;

	float triXFlutter;
	float triYFlutter;
	float triXFlutter2;
	float triYFlutter2;
	
};

