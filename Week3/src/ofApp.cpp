#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

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

	//Update all the drawn classes
	myFirstShape.update();
	for (int i = 0; i < shapes.size(); i++){  
		shapes[i].update();  
	}  

	//Fade the class out subtly over time
    ofEnableAlphaBlending(); 
	ofFill();   
    ofSetColor(250,250,250,20);   
    ofDrawRectangle(0,0,2000,2000);
	ofDisableAlphaBlending();  
}

//--------------------------------------------------------------
void ofApp::draw(){

	//Draw all the classes to the canvas
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
	//Draw classes to canvas based on mouse movement
	shapes.push_back(Shape(x, y));
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	//Extra color fade on mouse press
    ofEnableAlphaBlending(); 
	ofFill();   
    ofSetColor(250,250,250,100);   
    ofDrawRectangle(0,0,2000,2000);
	ofDisableAlphaBlending();  
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