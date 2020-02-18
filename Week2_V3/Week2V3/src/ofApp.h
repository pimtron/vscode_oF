#pragma once

#include "ofMain.h"

class MyClass{

public:
	void set(int _i, float _f){
		i = _i; f = _f;
	};

	int i;
	float f;
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
		
		int speed = 15;

		int xPos1 = 150;
		int xPos2 = 200;
		int xPos3 = 250;
		int xPos4 = 300;
		int xPos5 = 350;
		int xPos6 = 400;
		int xPos7 = 450;
		int xPos8 = 500;
		int xPos9 = 550;
		int xPos10 = 600;
		int xPos11 = 650;
		int xPos12 = 700;

		int xDir1=speed;
		int xDir2=speed;
		int xDir3=speed;
		int xDir4=speed;
		int xDir5=speed;
		int xDir6=speed;
		int xDir7=speed;
		int xDir8=speed;
		int xDir9=speed;
		int xDir10=speed;
		int xDir11=speed;
		int xDir12=speed;

		int x2Pos1 = 751;
		int x2Pos2 = 701;
		int x2Pos3 = 651;
		int x2Pos4 = 601;
		int x2Pos5 = 551;
		int x2Pos6 = 501;
		int x2Pos7 = 451;
		int x2Pos8 = 401;
		int x2Pos9 = 351;
		int x2Pos10 = 301;
		int x2Pos11 = 251;
		int x2Pos12 = 151;

		int x2Dir1=speed;
		int x2Dir2=speed;
		int x2Dir3=speed;
		int x2Dir4=speed;
		int x2Dir5=speed;
		int x2Dir6=speed;
		int x2Dir7=speed;
		int x2Dir8=speed;
		int x2Dir9=speed;
		int x2Dir10=speed;
		int x2Dir11=speed;
		int x2Dir12=speed;

		int r = 68;
		int g = 244;
		int b = 255;

		int rDir=1;
		int gDir=1;
		int bDir=1;
		
		float xoff, xoff2 = 0.0;


		ofPoint pos;
		//ofTrueTypeFont font1;

};
