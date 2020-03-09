#pragma once

#include "ofMain.h"
#include "ImageClass.h"
#include "ofxGui.h"

class Line {
public:
    ofPoint a;
    ofPoint b;
};

class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
	

	//Shape definedShape;
	Shape myFirstShape;
	vector<Shape*> shapes; 

	//Camera controls
	ofEasyCam easyCam;

	//GUI
	ofxPanel gui; 
	ofParameter<int> uiAmount;
	ofParameter<ofVec3f> uiPower;
	ofParameter<float> uiRadius;
	ofParameter<ofVec2f> uiPosition;

	bool drawGui = true;
};

