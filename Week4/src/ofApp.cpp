#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	//setup UI elements
	gui.setup();

	//setup each gui element: args = name, default, min, max
	gui.add(wavelength.setup( "wavelength", 0.125, 0.05, 0.2 ));
	gui.add(amplitude.setup( "amplitude", 0, 0, 50 ));
	gui.add(noiseScale.setup( "noiseScale", 0, 0, 10 ));
	gui.add(distortion.setup( "distortion", 0, 0, 50 ));
	gui.add(ySpeed.setup( "ySpeed", 0, 0, 10 ));

	//Load image
	image1.load( "image-1.jpg" );
}

//comment
//--------------------------------------------------------------
void ofApp::update(){

	// image2 is now the result of the processed image returned by the wave function
	image2 = wave(image1);
}

//--------------------------------------------------------------
void ofApp::draw(){

	//set background color
	ofBackgroundGradient(ofColor::white, ofColor::gray);

	// draw image
	ofSetColor( 255, 255, 255);
	image2.draw(0, 0);

	//set background color
	ofBackgroundGradient(ofColor::white, ofColor::gray);

	// draw image
	ofSetColor( 255, 255, 255);
	image2.draw(0, 0);

	gui.draw();
}

//--------------------------------------------------------------
ofImage ofApp::wave(ofImage sourceImg){

//create a clone of the source image (cloning allocates memory automatically based on the cloned image)
ofImage newImg;
newImg = sourceImg;

// returns how much time has elapsed since the start of the program
float time = ofGetElapsedTimef();

// iterate through every pixel in the image1 array, calculate distortion and use this to set the color values of the corresponding newImg pixels
for (int y=0; y<1000; y++) {
for (int x=0; x<1000; x++) {

// calculate wave distortion
float noise = ofNoise(time + y * 0.001) * noiseScale; // multiplying by 0.001 smooths the waveform
float noiseAmp = noise * amplitude; // scale the noise value again
float waveform = sin((y * wavelength) + time * ySpeed); // classic waveform algorithm (along the y-axis)
float wave = (waveform + distortion) * noiseAmp; // distortion shifts everything on the x-axis

//xWave represents the distorted pixel location (taken from the original image)
int xWave = x + wave;

//Set newImg pixel color (at location x,y) equal to the sourceImg pixel color (at location xWave, y)
ofColor color = sourceImg.getColor( xWave, y );
newImg.setColor( x, y, color );
}
}

newImg.update();
return newImg;
}
