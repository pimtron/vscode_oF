#include "ofApp.h"

// width and height of your image

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(60);

	image.load("image-2.jpg");
	image.resize(100, 100);

    mesh.setMode(OF_PRIMITIVE_POINTS);
    mesh.enableColors();

	// Don't forget to change to lines mode!
	mesh.setMode(OF_PRIMITIVE_LINES);

	// We are going to be using indices this time
	mesh.enableIndices();

    float intensityThreshold = 75.0;
    int w = image.getWidth();
    int h = image.getHeight();
    for (int x=0; x<w; ++x) {
        for (int y=0; y<h; ++y) {
            ofColor c = image.getColor(x, y);
            float intensity = c.getLightness();
			if (intensity >= intensityThreshold) {
				// We shrunk our image by a factor of 4, so we need to multiply our pixel
				// locations by 4 in order to have our mesh cover the openFrameworks window
				ofVec3f pos(x*8, y*8, 0.0);
				mesh.addVertex(pos);
				mesh.addColor(c);
			if (intensity >= intensityThreshold) {
				float saturation = c.getSaturation();
				float z = ofMap(saturation, 0, 255, -500, 500);
				ofVec3f pos(x*4, y*4, z);
				mesh.addVertex(pos);
				mesh.addColor(c);
			}

            }
        }
	}
	// Let's add some lines!
	float connectionDistance = 30;
	int numVerts = mesh.getNumVertices();
	for (int a=0; a<numVerts; ++a) {
		ofVec3f verta = mesh.getVertex(a);
		for (int b=a+1; b<numVerts; ++b) {
			ofVec3f vertb = mesh.getVertex(b);
			float distance = verta.distance(vertb);
			if (distance <= connectionDistance) {
				// In OF_PRIMITIVE_LINES, every pair of vertices or indices will be
				// connected to form a line
				mesh.addIndex(a);
				mesh.addIndex(b);
			}
		}
	}
	for (int x=0; x<w; ++x) {
		for (int y=0; y<h; ++y) {
			ofColor c = image.getColor(x, y);
			float intensity = c.getLightness();
			if (intensity >= intensityThreshold) {
				float saturation = c.getSaturation();
				float z = ofMap(saturation, 0, 255, -100, 100);
				ofVec3f pos(x*4, y*4, z);
				mesh.addVertex(pos);
				mesh.addColor(c);

				// And add this line to your existing for loop:
				// It will create a ofVec3f with 3 random values, which
				// will allow us to move the x, y and z coordinates of
				// each vertex independently
				offsets.push_back(ofVec3f(ofRandom(0,100000), ofRandom(0,100000), ofRandom(0,100000)));
			}
		}
	}
}

//--------------------------------------------------------------
void ofApp::update(){
	int numVerts = mesh.getNumVertices();
	for (int i=0; i<numVerts; ++i) {
		ofVec3f vert = mesh.getVertex(i);

		float time = ofGetElapsedTimef();
		float timeScale = 5.0;
		float displacementScale = 0.75;
		ofVec3f timeOffsets = offsets[i];

		// A typical design pattern for using Perlin noise uses a couple parameters:
		// ofSignedNoise(time*timeScale+timeOffset)*displacementScale
		//     ofSignedNoise(time) gives us noise values that change smoothly over
		//         time
		//     ofSignedNoise(time*timeScale) allows us to control the smoothness of
		//         our noise (smaller timeScale, smoother values)
		//     ofSignedNoise(time+timeOffset) allows us to use the same Perlin noise
		//         function to control multiple things and have them look as if they
		//         are moving independently
		//     ofSignedNoise(time)*displacementScale allows us to change the bounds
		//         of the noise from [-1, 1] to whatever we want
		// Combine all of those parameters together, and you've got some nice
		// control over your noise

		vert.x += (ofSignedNoise(time*timeScale+timeOffsets.x)) * displacementScale;
		vert.y += (ofSignedNoise(time*timeScale+timeOffsets.y)) * displacementScale;
		vert.z += (ofSignedNoise(time*timeScale+timeOffsets.z)) * displacementScale;
		mesh.setVertex(i, vert);
	}
}
//--------------------------------------------------------------
void ofApp::draw(){
    ofColor centerColor = ofColor(85, 78, 68);
    ofColor edgeColor(0, 0, 0);
    ofBackgroundGradient(centerColor, edgeColor, OF_GRADIENT_CIRCULAR);

    easyCam.begin();
        ofPushMatrix();
            ofTranslate(-ofGetWidth()/2, -ofGetHeight()/2);
            mesh.draw();
        ofPopMatrix();
    easyCam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

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
