#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	ofSetWindowShape(1000, 1000);
	ofSetBackgroundAuto(false);  
	ofSetFrameRate(30); 
	//image.setup();

}

//--------------------------------------------------------------
void ofApp::update(){

	myFirstShape.update();
	for (int i = 0; i < shapes.size(); i++){  
		shapes[i].update();  
	}  



}

//--------------------------------------------------------------
void ofApp::draw(){

	myFirstShape.draw();
	for (int i = 0; i < shapes.size(); i++){  
		shapes[i].draw();  
	}  

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){
	shapes.push_back(Shape(x, y));
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