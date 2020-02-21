#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
/*	//setup UI elements
	gui.setup();

	//setup each gui element: args = name, default, min, max
	gui.add(wavelength.setup( "wavelength", 0.125, 0.05, 0.2 ));
	gui.add(amplitude.setup( "amplitude", 0, 0, 50 ));
	gui.add(noiseScale.setup( "noiseScale", 0, 0, 10 ));
	gui.add(distortion.setup( "distortion", 0, 0, 50 ));
	gui.add(ySpeed.setup( "ySpeed", 0, 0, 10 ));

	video.load( "india.mov" ); //Load the video file
	video.play(); //Start the video

	//Load image
	image1.load("image-1.jpg");*/


	video.load( "india.mov" ); //Load the video file
	video.play(); //Start the video

	//setup fbo
	fbo.allocate();
	// clear fbo
	fbo.begin();
	ofClear(255,255,255, 0);
	fbo.end();

	//Set up vertices
	for (int y=0; y<H; y++) {
	for (int x=0; x<W; x++) { 
	mesh.addVertex(ofPoint((x - W/2) * meshSize, (y - H/2) * meshSize, 0 )); // adding texure coordinates allows us to bind textures to it later // --> this could be made into a function so that textures can be swapped / updated
	mesh.addTexCoord(ofPoint(x * (720 / 100), y * (480 / 100)));
	mesh.addColor(ofColor(255, 255, 255));
	}
	}

	//Set up triangles' indices
	for (int y=0; y<H-1; y++) {
	for (int x=0; x<W-1; x++) {
	int i1 = x + W * y;
	int i2 = x+1 + W * y;
	int i3 = x + W * (y+1);
	int i4 = x+1 + W * (y+1);
	mesh.addTriangle( i1, i2, i3 );
	mesh.addTriangle( i2, i4, i3 );
	}
	}

}

//comment
//--------------------------------------------------------------
void ofApp::update(){

	// image2 is now the result of the processed image returned by the wave function
	//image2 = wave(image1);

	//update video
	video.update();

	//Change vertices
	for (int y=0; y<H; y++) {
	for (int x=0; x<W; x++) {

	//Vertex index
	int i = x + W * y;
	ofPoint p = mesh.getVertex( i );

	//Change z-coordinate of vertex
	p.z = ofNoise(x * 0.05, y * 0.05, ofGetElapsedTimef() * 0.5) * 100;
	mesh.setVertex( i, p );

	//Change color of vertex
	mesh.setColor(i , ofColor(255, 255, 255));
	}
	}
}

//--------------------------------------------------------------
void ofApp::draw(){

	/*
	/*set background color
	ofBackgroundGradient(ofColor::white, ofColor::gray);

	// draw image
	ofSetColor( 255, 255, 255);
	image2.draw(0, 0);

	//set background color
	ofBackgroundGradient(ofColor::white, ofColor::gray);

	// draw image
	ofSetColor( 255, 255, 255);
	image2.draw(0, 0);

	gui.draw();*/

	//Set background to black and rendering color to white
	//Set background to black and rendering color to white
	ofBackground(0);
	ofSetHexColor(0xffffff);

	fbo.draw(0, 0);

	ofPushMatrix(); //Store the coordinate system

	//Move the coordinate center to screen's center
	ofTranslate( ofGetWidth()/2, ofGetHeight()/2, 0 );
	mesh.drawWireframe();
	ofPopMatrix(); //Restore the coordinate system

}

/*//--------------------------------------------------------------
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
}*/

/*newImg.update();
//return newImg;
}*/
