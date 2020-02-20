#pragma once

#include "ofMain.h"
#include "../addons/ofxGui.h"

class ofApp : public ofBaseApp {

public:
void setup();
void update();
void draw();

ofImage image1; //Original image
ofImage image2; //Modified image

ofImage wave(ofImage sourceImg);

private:

ofxPanel gui;
ofxFloatSlider wavelength, amplitude, noiseScale, distortion, ySpeed;

};