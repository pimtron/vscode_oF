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
	size = 50;

	rotationZ = 0.0;
	rotateZ = 20.0;
	rotationY = 0.0;
	rotateY = 20.0;
	rotationX = 0.0;
	rotateX = 20.0;

	box2d.init();
	box2d.setGravity(0,30);
	box2d.createBounds();

	circle.setPhysics(3.0, 0.5, 1.0);

}

void Shape::update() {

	circle.setup(box2d.getWorld(),0, 0, size);
	float y = ofMap(sin(angle), -1, 1, 0, float(ofGetWindowHeight()));

	rotationZ = rotationZ + rotateZ;
	rotationX = rotationX + rotateX;
	//rotationY = rotationY + rotateY;

    float xPos = ofMap(sin(ofGetElapsedTimef()), -1, 1, 0, ofGetWidth());
    //ofRect(xPos, ofGetHeight()/2, 10,10);

	//ofPushMatrix();
	//ofSetColor(ofRandom(240, 255), ofRandom(240, 255), ofRandom(240, 255));
	//ofTranslate(startingX, startingY);
	//startingY = startingY + y;
	//startingX = startingX * (sin(ofGetElapsedTimef() * .01));
	startingY = startingY + xPos;
	startingX = startingX + xPos;
	//ofPopMatrix();


	color = ofColor(ofRandom(240, 255), ofRandom(240, 255), ofRandom(240, 255));

	cornerRadius = ofRandom(10,50);
	startingX = ofRandom(startingX - 5, startingX + 5);
	size = size - .5;

	if (size < 3 ){
	size = 0;
	};

	//angle += 0.01;

}

void Shape::draw()
{
	ofSetRectMode(OF_RECTMODE_CENTER);
	ofPushMatrix();
	ofFill();
	ofSetColor(50, 50, 50);
	ofTranslate(startingX, startingY);
	ofDrawRectRounded(0, 0, size, size, cornerRadius);
	ofPopMatrix();

	ofSetRectMode(OF_RECTMODE_CENTER);
	ofPushMatrix();
	ofNoFill();
	ofSetColor(50, 50, 50);
	ofTranslate(startingX, startingY);
	//ofRotateZ(rotationZ);
	//ofRotateY(rotationY);
	//ofRotateX(rotationX);
	//for (int i = 0; i < 30; i++){
		//ofRotateDeg(ofGetElapsedTimef());
		//ofScale(0.9);
		//ofDrawRectRounded(0, 0, size, size, cornerRadius);
	//}
	ofPopMatrix();


}



Shape::~Shape()
{
}