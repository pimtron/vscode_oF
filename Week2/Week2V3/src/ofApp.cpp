
#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){


	ofSetWindowShape(1000, 1000);
	ofSetFrameRate(30);

	// hold colors 
	//for (int i = 0; i < 400; i++) {


	ofSetBackgroundAuto(false);  
	ofSetBackgroundColor(1,15,16);

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){



int idx = 0;

	//Fluctuates the radius of each circle
 	xoff += 0.01;
	//Sets range but caps them so they never intersect  
	float n =  ofNoise(xoff) * 30;


	//Right side oscillating circles 
	ofSetColor(r, g, b);
	ofDrawCircle(xPos1, 100, n);

	ofSetColor(r, g, b);
	ofDrawCircle(xPos2, 200, n);

	ofSetColor(r, g, b);
	ofDrawCircle(xPos3, 300, n);

	ofSetColor(r, g, b);
	ofDrawCircle(xPos4, 400, n);

	ofSetColor(r, g, b);
	ofDrawCircle(xPos5, 500, n);

	ofSetColor(r, g, b);
	ofDrawCircle(xPos6, 600, n);

	ofSetColor(r, g, b);
	ofDrawCircle(xPos7, 700, n);

	ofSetColor(r, g, b);
	ofDrawCircle(xPos8, 800, n);


	//Right side motion
	xPos1 = xPos1 + xDir1;
	xPos2 = xPos2 + xDir2;
	xPos3 = xPos3 + xDir3;
	xPos4 = xPos4 + xDir4;
	xPos5 = xPos5 + xDir5;
	xPos6 = xPos6 + xDir6;
	xPos7 = xPos7 + xDir7;
	xPos8 = xPos8 + xDir8;
	xPos9 = xPos9 + xDir9;
	xPos10 = xPos10 + xDir10;
	xPos11 = xPos11 + xDir11;
	xPos12 = xPos12 + xDir12;

	//Right side switch
	if (xPos1 >= 850 || xPos1<=150){
    	xDir1=-xDir1;
	}
	if (xPos2 >= 850 || xPos2<=150){
    	xDir2=-xDir2;
	}
	if (xPos3 >= 850 || xPos3<=150){
    	xDir3=-xDir3;
	}
	if (xPos4 >= 850 || xPos4<=150){
    	xDir4=-xDir4;
	}
	if (xPos5 >= 850 || xPos5<=150){
    	xDir5=-xDir5;
	}
	if (xPos6 >= 850 || xPos6<=150){
    	xDir6=-xDir6;
	}
	if (xPos7 >= 850 || xPos7<=150){
    	xDir7=-xDir7;
	}
	if (xPos8 >= 850 || xPos8<=150){
    	xDir8=-xDir8;
	}
	if (xPos9 >= 850 || xPos9<=150){
    	xDir9=-xDir9;
	}
	if (xPos10 >= 850 || xPos10<=150){
    	xDir10=-xDir10;
	}
	if (xPos11 >= 850 || xPos11<=150){
    	xDir11=-xDir11;
	}
	if (xPos12 >= 850 || xPos12<=150){
    	xDir12=-xDir12;
	}

	//Left side oscillating circles 
	ofSetColor(r, g, b);
	ofDrawCircle(x2Pos1, 150, n);

	ofSetColor(r, g, b);
	ofDrawCircle(x2Pos2, 250, n);

	ofSetColor(r, g, b);
	ofDrawCircle(x2Pos3, 350, n);

	ofSetColor(r, g, b);
	ofDrawCircle(x2Pos4, 450, n);

	ofSetColor(r, g, b);
	ofDrawCircle(x2Pos5, 550, n);

	ofSetColor(r, g, b);
	ofDrawCircle(x2Pos6, 650, n);

	ofSetColor(r, g, b);
	ofDrawCircle(x2Pos7, 750, n);

	ofSetColor(r, g, b);
	ofDrawCircle(x2Pos8, 850, n);
	



	//Right side motion
	x2Pos1 = x2Pos1 - x2Dir1;
	x2Pos2 = x2Pos2 - x2Dir2;
	x2Pos3 = x2Pos3 - x2Dir3;
	x2Pos4 = x2Pos4 - x2Dir4;
	x2Pos5 = x2Pos5 - x2Dir5;
	x2Pos6 = x2Pos6 - x2Dir6;
	x2Pos7 = x2Pos7 - x2Dir7;
	x2Pos8 = x2Pos8 - x2Dir8;
	x2Pos9 = x2Pos9 - x2Dir9;
	x2Pos10 = x2Pos10 - x2Dir10;
	x2Pos11 = x2Pos11 - x2Dir11;
	x2Pos12 = x2Pos12 - x2Dir12;

	//Right side switch
	if (x2Pos1 >= 850 || x2Pos1<=150){
    	x2Dir1=-x2Dir1;
	}
	if (x2Pos2 >= 850 || x2Pos2<=150){
    	x2Dir2=-x2Dir2;
	}
	if (x2Pos3 >= 850 || x2Pos3<=150){
    	x2Dir3=-x2Dir3;
	}
	if (x2Pos4 >= 850 || x2Pos4<=150){
    	x2Dir4=-x2Dir4;
	}
	if (x2Pos5 >= 850 || x2Pos5<=150){
    	x2Dir5=-x2Dir5;
	}
	if (x2Pos6 >= 850 || x2Pos6<=150){
    	x2Dir6=-x2Dir6;
	}
	if (x2Pos7 >= 850 || x2Pos7<=150){
    	x2Dir7=-x2Dir7;
	}
	if (x2Pos8 >= 850 || x2Pos8<=150){
    	x2Dir8=-xDir8;
	}
	if (x2Pos9 >= 850 || x2Pos9<=150){
    	x2Dir9=-x2Dir9;
	}
	if (x2Pos10 >= 850 || x2Pos10<=150){
    	x2Dir10=-x2Dir10;
	}
	if (x2Pos11 >= 850 || x2Pos11<=150){
    	x2Dir11=-x2Dir11;
	}
	if (x2Pos12 >= 850 || x2Pos12<=150){
    	x2Dir12=-x2Dir12;
	}

	//Color oscillator
	if (r >= 255 || r<=150){
    	rDir=-rDir;
	}
	if (g >= 255 || g<=150){
    	gDir=-gDir;
	}
	if (b >= 255 || b<=150){
    	bDir=-bDir;
	}

	r = r - rDir;
	g = g - gDir;
	b = b - bDir;

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

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