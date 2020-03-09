#include "ImageClass.h"
#include "ofxBox2d.h"

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
	size = 50;

	rotationZ = 0.0;
	rotateZ = 20.0;
	rotationY = 0.0;
	rotateY = 20.0;
	rotationX = 0.0;
	rotateX = 20.0;
}

void Shape::update() {

	rotationZ = rotationZ + rotateZ;
	rotationX = rotationX + rotateX;
	//rotationY = rotationY + rotateY;

	//ofPushMatrix();
	//ofSetColor(ofRandom(240, 255), ofRandom(240, 255), ofRandom(240, 255));
	//ofTranslate(startingX, startingY);
	//startingY = startingY * (sin(ofGetElapsedTimef() * .01));
	//startingX = startingX * (sin(ofGetElapsedTimef() * .01));
	startingY = startingY + ofRandom(-5,5) * sin(ofGetElapsedTimef());
	startingX = startingX + ofRandom(-5,5);
	//ofPopMatrix();


	color = ofColor(ofRandom(240, 255), ofRandom(240, 255), ofRandom(240, 255));

	cornerRadius = ofRandom(10,50);
	//startingX = ofRandom(startingX - 5, startingX + 5);
	size = size - .5;

	if (size < 3 ){
	size = 0;
	};

	if(){


	}

}

void Shape::draw()
{
	ofSetRectMode(OF_RECTMODE_CENTER);
	ofPushMatrix();
	ofFill();
	ofSetColor(50, 50, 50);
	ofTranslate(startingX, startingY);
	//ofRotateZ(rotationZ);
	//ofRotateY(rotationY);
	//ofRotateX(rotationX);
	ofDrawRectRounded(0, 0, size, size, cornerRadius);
	ofPopMatrix();

	ofSetRectMode(OF_RECTMODE_CENTER);
	ofPushMatrix();
	ofNoFill();
	ofSetColor(50, 50, 50);
	ofTranslate(startingX, startingY);
	ofRotateZ(rotationZ);
	ofRotateY(rotationY);
	ofRotateX(rotationX);
	//ofDrawRectRounded(0, 0, size, size, cornerRadius);
	ofPopMatrix();


}



Shape::~Shape()
{
}