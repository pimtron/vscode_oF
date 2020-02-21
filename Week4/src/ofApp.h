#pragma once

#include "ofMain.h"
#include "../addons/ofxGui.h"

class ofApp : public ofBaseApp {

    public:
    void setup();
    void update();
    void draw();

    /*ofVideoPlayer video; //Prerecorded video

    ofImage image1; //Original image
    ofImage image2; //Modified image

    ofImage wave(ofImage sourceImg);

    private:

    ofxPanel gui;
    ofxFloatSlider wavelength, amplitude, noiseScale, distortion, ySpeed;

    ofVideoPlayer video;
    ofFbo fbo;

    int videoWidth = 720;
    int videoHeight = 480;*/

    ofVideoPlayer video; //Prerecorded video
    ofFbo fbo;
    ofMesh mesh;

    private:

    int videoWidth = 720;
    int videoHeight = 480;
    int W = 100; //Grid size
    int H = 100;
    int meshSize = 6;
};