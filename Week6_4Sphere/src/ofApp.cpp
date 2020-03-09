#include "ofApp.h"


int x = 500;
int y = 500;
int j = 1;
ofPoint first;
ofPoint second;

int inLoc = 50;
int inLoc2 = 250;
int inLoc3 = 50;
//--------------------------------------------------------------
void ofApp::setup(){

	rotationZ = 0.0;
	rotateZ = 1.0;
	rotationY = 180.0;
	rotateY = .1;
	rotationX = 0.0;
	rotateX = 1.0;
	
	//Window size setup
	ofSetWindowShape(1000, 1000);
	ofSetBackgroundAuto(false);  
	ofSetFrameRate(30); 
	ofEnableAlphaBlending();
	ofSetBackgroundColor(250,250,250);


}

//comment
//--------------------------------------------------------------
void ofApp::update(){

	rotationZ = rotationZ + rotateZ;
	rotationX = rotationX + rotateX;
	rotationY = rotationY + rotateY;

	//int x = ofRandom(0,1000);
	//int y = ofRandom(0,1000);

	//walk(x,y);
	//Update all the drawn classes
	myFirstShape.update();
	for (int i = 0; i < shapes.size(); i++){  
		shapes[i]->update();  

	}  

	for(int i = 0; i < shapes.size(); i++){ 

	}
	


}

//--------------------------------------------------------------
void ofApp::draw(){



	//ofSetRectMode(OF_RECTMODE_CENTER);
	ofPushMatrix();
	ofNoFill();

	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
	ofRotateZ(rotationZ);
	ofRotateY(rotationY);
	ofRotateX(rotationX);


	for (int i = 0; i < 30; i++){
		//for (int j = 0; j < 30; j++){
			ofRotateDeg(ofGetElapsedTimef());

			//ofRotateY(90);
			//ofScale(0.9);
			//ofDrawRectRounded(0, 0, size, size, cornerRadius);
			ofSetColor(150, 150, 150);
			//ofDrawCone(0, -175, 50, 350);
			ofDrawIcoSphere(0, inLoc2, 0, 10);
			first.set(0, 350);


	}

	for (int i = 0; i < 30; i++){
		//for (int j = 0; j < 30; j++){
			ofRotateDeg(ofGetElapsedTimef());
			//ofRotateY(180);
			//ofScale(0.9);
			//ofDrawRectRounded(0, 0, size, size, cornerRadius);
			ofSetColor(75, 75, 75);
			//ofDrawCone(0, -175, 50, 350);
			ofDrawIcoSphere(0, 200, 0, 10);
			first.set(0, 350);


	}

	for (int i = 0; i < 30; i++){
		//for (int j = 0; j < 30; j++){
			ofRotateDeg(ofGetElapsedTimef());
			//ofRotateY(90);
			//ofScale(0.9);
			//ofDrawRectRounded(0, 0, size, size, cornerRadius);
			ofSetColor(50, 50, 50);
			//ofDrawCone(0, -175, 50, 350);
			ofDrawIcoSphere(0, inLoc, 0, 5);
			first.set(0, 350);


	}

	//for (int i = 0; i < 30; i++){

	//		ofRotateDeg(ofGetElapsedTimef());
	//		ofRotateY(rotationY);
	//		//ofScale(0.9);
	//		ofSetColor(50, 50, 50);
	//		ofDrawCone(0, -125, 50, 250);
	///		second.set(0, -250);

//	}

	
			


		if(inLoc  <= 1 || inLoc  >= 300)
		{
		j =- j;
		}

		inLoc = inLoc - j;

		if(inLoc2  <= 1 || inLoc2  >= 300)
		{
		j =- j;
		}

		inLoc2 = inLoc2 - j;



	//for (int i = 0; i < 30; i++){
		//for (int j = 0; j < 30; j++){
			//ofRotateDeg(ofGetElapsedTimef());
			//ofRotateX(45);
			//ofScale(0.9);
			//ofDrawRectRounded(0, 0, size, size, cornerRadius);
			//ofSetColor(50, 50, 50);
			//ofDrawCone(0, -125, 50, 250);
		//}
		//glRotatef(30, 0, 0, 1);
	//}
	//ofDrawRectRounded(0, 0, size, size, cornerRadius);


	ofPopMatrix();

	//Fade the class out subtly over time
    ofEnableAlphaBlending(); 
	ofFill();   
    ofSetColor(254,255,219,5);   
    ofDrawRectangle(0,0,2000,2000);
	ofDisableAlphaBlending();  

	rotationY = rotationY + .1;

	


	// <------ magic happens here --------->

	for (int i = 0; i < shapes.size(); i++){
		shapes[i]->update();
	}

	//shapes.push_back(new Shape(x, y));
	
	//Draw all the classes to the canvas
	myFirstShape.draw();

	for (int i = 0; i < shapes.size(); i++){  
		shapes[i]->draw();  
	}  





}


void ofApp::walk(int x, int y){

	shapes.push_back(new Shape(x, y));
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){
	//Draw classes to canvas based on mouse movement

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){


}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}