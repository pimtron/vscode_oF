#include "ImageClass.h"


Shape::Shape()
{	
	color = ofColor(ofRandom(255), ofRandom(255), ofRandom(255));
	startingX = 500;
	startingY = 900;
    circleRadius = 50;
	size = 50;
}

Shape::Shape(int x, int y)
{
	color = ofColor(ofRandom(255), ofRandom(255), ofRandom(255));
	startingX = x;
	startingY = y;
}

void Shape::update() {

	color = ofColor(ofRandom(255), ofRandom(255), ofRandom(255));
    startingY = startingY - 8;
	circleRadius = circleRadius - 5;
	//startingX = ofRandom(5);

}

void Shape::draw()
{
	ofSetRectMode(OF_RECTMODE_CENTER);
	ofPushMatrix();
	ofSetColor(ofRandom(255), ofRandom(255), ofRandom(255));
	ofTranslate(startingX, startingY);
	ofDrawRectangle(0, 0, 50, 50);
	ofPopMatrix();


}

Shape::~Shape()
{
}