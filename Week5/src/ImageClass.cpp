#include "ImageClass.h"


Shape::Shape()
{	
	color = ofColor(ofRandom(255), ofRandom(255), ofRandom(255));
	startingX = 500;
	startingY = 900;

	startingX2 = 500;
	startingY2 = 900;
    cornerRadius = 50;


}

Shape::Shape(int x, int y)
{
	color = ofColor(ofRandom(255), ofRandom(255), ofRandom(255));
	startingX = x;
	startingY = y;
	startingX2 = x;
	startingY2 = y;

	size = 150;
	size2 = 5;
	triXStart = ofRandom(-10,10);
	triYStart = ofRandom(-10,10);
	triXStart2 = ofRandom(-10,10);
	triYStart2 = ofRandom(-10,10);
}


void Shape::update() {

	//triXStart = triXStart + ofNoise(time * 0.3);
	//triYStart = triYStart + ofNoise(time * 0.4);
	//triXStart2 = triXStart2 + ofNoise(time * 0.3);
	//triYStart2 = triYStart2 + ofNoise(time * 0.4);

	triXStart = ofRandom(-10, 10);
	triXStart2 = ofRandom(-10,10);
	triYStart = ofRandom(-10,10);
	triYStart2 = ofRandom(-10,10);
	//if (triXStart >= 20 || triXStart <= 2){
	//	triXStart =- triXStart;
	//	};


	color = ofColor(ofRandom(100,200), ofRandom(100,200), ofRandom(100,200));
    startingY = startingY;
	startingY2 = startingY2 + 5;
	cornerRadius = ofRandom(10,50);
	size = size - 1;

	if (size < 3 ){
	size = 0;
	};



}

void Shape::draw()
{

	//Tris
	ofSetRectMode(OF_RECTMODE_CENTER);
	ofPushMatrix();
	ofFill();
	ofSetColor(ofRandom(150,250), ofRandom(150,250), ofRandom(150,250));
	ofTranslate(startingX, startingY);
	ofDrawTriangle(0, 0, triXStart, triYStart, triXStart2, triYStart2);
	//ofDrawRectRounded(0, 0, size, size, cornerRadius);
	ofPopMatrix();

	//Bubbles
	ofSetRectMode(OF_RECTMODE_CENTER);
	ofPushMatrix();
	ofNoFill();
	ofSetColor(0, 0, 0);
	ofTranslate(startingX, startingY);
	ofDrawRectRounded(0, 0, size, size, cornerRadius);
	ofPopMatrix();

	//Drips
	ofSetRectMode(OF_RECTMODE_CENTER);
	ofPushMatrix();
	ofNoFill();
	ofSetColor(0, 0, 0);
	ofTranslate(startingX2, startingY2);
	ofDrawRectRounded(0, 0, size2, size2, cornerRadius);
	ofPopMatrix();


}

Shape::~Shape()
{
}