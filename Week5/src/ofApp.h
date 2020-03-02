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

	//Line and Point
	ofPolyline line;
	vector < ofPoint > drawnPoints;
    vector < Line > lines;

	ofPolyline line2;
	vector < ofPoint > drawnPoints2;
    vector < Line > lines2;

	//Camera controls
	ofEasyCam easyCam;

	//GUI
	ofxPanel gui; 
	ofParameter<int> lineConnect;
	ofParameter<string> screenShot;
	ofParameter<int> backgroundAlpha;
	ofParameter<int> backgroundColor;
	ofParameter<float> rotateZ;
	ofParameter<ofColor> lineColor;
	ofParameter<ofColor> bgColor;
	//ofParameter<int> triPoint;
	ofParameterGroup parameterGroup;
	Shape shapeGroup;

	float rotationZ;

	bool drawGui = true;
};

