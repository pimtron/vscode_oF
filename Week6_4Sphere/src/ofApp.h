#pragma once

#include "ofMain.h"
#include "ImageClass.h"


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
		void walk(int x, int y);
		
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
	
		float rotationZ;
		float rotateZ;
		float rotationY;
		float rotateY;
		float rotationX;
		float rotateX;

		Shape myFirstShape;
		//Shape definedShape;
		vector<Shape*> shapes; 

    	vector < ofPoint > points;
   		vector < Line > lines;
	
};


