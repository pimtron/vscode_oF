#include "ofApp.h"


int x = 500;
int y = 500;
int j = 1;

ofPoint first;
ofPoint second;

//Distance Variables
int inLoc = 50;
int inLoc2 = 250;
int inLoc3 = 50;

//Distance Variables
int inLocSpeed = 1;
int inLoc2Speed = 1;
int inLoc3Speed = 1;

//Color Variables
float r = 2;
float g = 220;
float b = 127;

//Color Fade Variance Variables
float rspeed = .25;
float gspeed = .25;
float bspeed = .25;
		
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
	ofSetFrameRate(60); 
	ofEnableAlphaBlending();
	ofSetBackgroundColor(150,150,150);


}

//comment
//--------------------------------------------------------------
void ofApp::update(){

	rotationZ = rotationZ + rotateZ;
	rotationX = rotationX + rotateX;
	rotationY = rotationY + rotateY;

	//int x = ofRandom(0,1000);
	//int y = ofRandom(0,1000);

	walk(ofGetWidth() / 2, ofGetHeight() / 2);
	//Update all the drawn classes
	myFirstShape.update();
	for (int i = 0; i < shapes.size(); i++){  
		shapes[i]->update();  

	}  

	for(int i = 0; i < shapes.size(); i++){ 

	}
	
		// <------ magic happens here --------->

		for (int i = 0; i < shapes.size(); i++){
			shapes[i]->update();
		}
		myFirstShape.draw();

		for (int i = 0; i < shapes.size(); i++){  
			shapes[i]->draw();  
		}  
	



}

//--------------------------------------------------------------
void ofApp::draw(){



	//ofSetRectMode(OF_RECTMODE_CENTER);
	ofPushMatrix();
	ofNoFill();

	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);



	for (int i = 0; i < 5; i++){
		//for (int j = 0; j < 30; j++){
			ofRotateDeg(ofGetElapsedTimef());
    		ofEnableAlphaBlending(); 
			//ofRotateY(90);
			//ofScale(0.9);
			//ofDrawRectRounded(0, 0, size, size, cornerRadius);
			ofSetColor(220, 220, 220, 50);
			ofDrawCone(0, -175, 50, inLoc2);
			//ofDrawIcoSphere(0, inLoc2, 0, 3);
			first.set(0, 350);
			ofRotateZ(rotationZ);
			ofRotateY(rotationY);
			ofRotateX(rotationX);

	}

	for (int i = 0; i < 5; i++){
		//for (int j = 0; j < 30; j++){
		ofRotateDeg(ofGetElapsedTimef());
		//ofRotateY(180);
		//ofScale(0.9);
		//ofDrawRectRounded(0, 0, size, size, cornerRadius);
		ofSetColor(50, 50, 50);
		ofDrawCone(0, -125, 20, inLoc);
		//ofDrawIcoSphere(0, 200, 0, 5);
		first.set(0, 350);


	}

	for (int i = 0; i < 5; i++){
		//for (int j = 0; j < 30; j++){
		ofRotateDeg(ofGetElapsedTimef());
		//ofRotateY(90);
		//ofScale(0.9);
		//ofDrawRectRounded(0, 0, size, size, cornerRadius);
		ofSetColor(r, g, b);
		ofDrawCone(0, -175, 50, inLoc);
		//ofDrawIcoSphere(0, inLoc, 0, 5);
		first.set(0, 350);
	}

      r = r + rspeed;
      if ((r > 254 || r < 0 )) {
        rspeed = rspeed * -1;
      }
      g = g + gspeed;
      if ((g > 254 || g < 0 )) {
        gspeed = gspeed * -1;
      }
      b = b + bspeed;
      if ((b > 254 || b < 0 )) {
        gspeed = gspeed * -1;
      }

	//for (int i = 0; i < 30; i++){

	//		ofRotateDeg(ofGetElapsedTimef());
	//		ofRotateY(rotationY);
	//		//ofScale(0.9);
	//		ofSetColor(50, 50, 50);
	//		ofDrawCone(0, -125, 50, 250);
	///		second.set(0, -250);

//	}

	
			


		if(inLoc  < 1 || inLoc  > 500)
		{
		inLocSpeed =- inLocSpeed;
		}

		inLoc = inLoc - inLocSpeed;

		if(inLoc2  < 1 || inLoc2  > 600)
		{
		inLoc2Speed =- inLoc2Speed ;
		}

		inLoc2 = inLoc2 - inLoc2Speed;



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
    ofSetColor(250,250,250,0);   
    ofDrawRectangle(0,0,2000,2000);
	ofDisableAlphaBlending();  

	rotationY = rotationY + .1;

	






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