
#include "ofApp.h"
std::vector <ofPolyline> polylines;

//--------------------------------------------------------------
void ofApp::setup(){


	ofSetWindowShape(1000, 1000);
	ofSetFrameRate(30);

	// hold colors 
	//for (int i = 0; i < 400; i++) {


	ofSetBackgroundAuto(false);  
	ofSetBackgroundColor(255,255,255);

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
int yPos = 500;
	ofSetColor(0x000000);
	ofSetCurveResolution(4);  
    ofSetLineWidth(4);  
	ofSetColor(0, 0, 0);    
	ofNoFill();  
	ofBeginShape(); 

	//int spacing = 0;   
	ofBeginShape();   
	for(int x=0; x<ofGetWidth(); x+= 50) {   
		ofCurveVertex(x, yPos += 10.0*sin(ofGetElapsedTimef()));   
	}   
	ofEndShape(false);   
  


}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    polylines.push_back(ofPolyline());
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