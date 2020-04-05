#include "ImageClass.h"

float angle = 0;

Shape::Shape()
{	
	color = ofColor(ofRandom(255), ofRandom(255), ofRandom(255));
	startingX = 500;
	startingY = 900;
    cornerRadius = 50;

}

Shape::Shape(int x,  int y)
{
	color = ofColor(ofRandom(240, 255), ofRandom(240, 255), ofRandom(240, 255));
	startingX = x;
	startingY = y;
	size = 100;

	rotationZ = 0.0;
	rotateZ = 20.0;
	rotationY = 0.0;
	rotateY = 20.0;
	rotationX = 0.0;
	rotateX = 20.0;


}

void Shape::update() {


	//rotationZ = rotationZ + rotateZ;
	//rotationX = rotationX + rotateX;
	//rotationY = rotationY + rotateY;

	color = ofColor(ofRandom(240, 255), ofRandom(240, 255), ofRandom(240, 255));


	cornerRadius = ofRandom(10,50);
	startingX = startingX + ofRandom(-15, 15);
	startingY = startingY + ofRandom(-15, 15);
	size = size - .5;

	if (size < 3 ){
	size = 0;
	};


}

void Shape::draw()
{
	ofSetRectMode(OF_RECTMODE_CENTER);
	ofPushMatrix();
	ofFill();
	ofSetColor(250, 250, 250);
	ofTranslate(startingX, startingY);
	ofDrawRectRounded(0, 0, size, size, cornerRadius);
	ofPopMatrix();


}

Shape::~Shape()
{
}