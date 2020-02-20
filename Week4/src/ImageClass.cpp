#include "ImageClass.h"


Shape::Shape()
{	
	color = ofColor(ofRandom(255), ofRandom(255), ofRandom(255));
	startingX = 500;
	startingY = 900;
    cornerRadius = 50;

}

Shape::Shape(int x, int y)
{
	color = ofColor(ofRandom(255), ofRandom(255), ofRandom(255));
	startingX = x;
	startingY = y;
	size = 50;
}

void Shape::update() {

	color = ofColor(ofRandom(100,200), ofRandom(100,200), ofRandom(100,200));
    startingY = startingY - 8;
	cornerRadius = ofRandom(10,50);
	startingX = ofRandom(startingX - 5, startingX + 5);
	size = size - 1;

	if (size < 3 ){
	size = 0;
	};



}

void Shape::draw()
{
	ofSetRectMode(OF_RECTMODE_CENTER);
	ofPushMatrix();
	ofFill();
	ofSetColor(ofRandom(150,250), ofRandom(150,250), ofRandom(150,250));
	ofTranslate(startingX, startingY);
	ofDrawRectRounded(0, 0, size, size, cornerRadius);
	ofPopMatrix();

	ofSetRectMode(OF_RECTMODE_CENTER);
	ofPushMatrix();
	ofNoFill();
	ofSetColor(0, 0, 0);
	ofTranslate(startingX, startingY);
	ofDrawRectRounded(0, 0, size, size, cornerRadius);
	ofPopMatrix();


}

Shape::~Shape()
{
}