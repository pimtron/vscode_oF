#include "ofApp.h"
#include "ofxGui.h"

ofImage img;

//--------------------------------------------------------------
void ofApp::setup(){



	//Window size setup
	ofSetWindowShape(1000, 1000);
	///
	ofSetBackgroundAuto(false);  
	ofSetFrameRate(30); 
	ofEnableAlphaBlending();


	ofSetLineWidth(3);
	ofSetCircleResolution(128);

	gui.setup();
	gui.add(uiAmount.set("amount", 1, 1, 30));
	gui.add(uiPower.set("power", ofVec3f(0), ofVec3f(0), ofVec3f(3.0)));
	gui.add(uiRadius.set("radius", 0, 0, 60.0));
	gui.add(uiPosition.set("position", ofVec2f(0), ofVec2f(-ofGetWidth(), -ofGetHeight()), ofVec2f(ofGetWidth(), ofGetHeight())));
}

//comment
//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetBackgroundColor(0,0,0);

	if (drawGui) {
		gui.draw();
	}


ofPushMatrix();
easyCam.begin();
ofTranslate(uiPosition->x, uiPosition->y);
float radius = uiRadius;
for (int i = 0; i < uiAmount; i++){
	float noisex = ofNoise((ofGetElapsedTimef() + i) * uiPower->x);
	float noisey = ofNoise((ofGetElapsedTimef() + i) * uiPower->y);
	float noisez = ofNoise((ofGetElapsedTimef() + i) * uiPower->z);

	float x = ofGetWidth() / 2 * noisex;
	float y = ofGetWidth() / 2 * noisey;
	float z = ofGetWidth() / 2 * noisez;

	ofNoFill();
	//ofSetColor();
	ofDrawCircle(x, y, z, radius);

	radius += i;
}


easyCam.end();
ofPopMatrix();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == 'x') {
		drawGui = !drawGui;
	}
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
