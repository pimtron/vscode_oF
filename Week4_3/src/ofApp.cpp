#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(60);

	//load the image and resize it so i don't und up with 10000000 vertices
	image.load("image-2.jpg");
	image.resize(200, 200);

	//Primitive lines and vertices
    mesh.setMode(OF_PRIMITIVE_POINTS);
    mesh.enableColors();
	mesh.setMode(OF_PRIMITIVE_LINES);
	mesh.enableIndices();

	//everything brighter than 150/255 gets removed
    float intensityThreshold = 150.0;
    int w = image.getWidth();
    int h = image.getHeight();
    for (int x=0; x<w; ++x) {
        for (int y=0; y<h; ++y) {
            ofColor c = image.getColor(x, y);
            float intensity = c.getLightness();
			//This is remapping the vertices in Z space based on their saturation level
			if (intensity <= intensityThreshold) {
				//float intensity = c.getLightness();
				float saturation = c.getSaturation();
				float z = ofMap(saturation, 0, 255, -500, 500);
				ofVec3f pos(x*8, y*8, z);
				mesh.addVertex(pos);
				mesh.addColor(c);
				//makes the vertices dance
				offsets.push_back(ofVec3f(ofRandom(0,100000), ofRandom(0,100000), ofRandom(0,100000)));
			}
        }
	}
	// Let's add some lines!
	//All vertices within 30 pixels of eachother will be joined by a line
	float connectionDistance = 50;
	int numVerts = mesh.getNumVertices();
	for (int a=0; a<numVerts; ++a) {
		ofVec3f verta = mesh.getVertex(a);
		for (int b=a+1; b<numVerts; ++b) {
			ofVec3f vertb = mesh.getVertex(b);
			float distance = verta.distance(vertb);
			if (distance <= connectionDistance) {
				// In OF_PRIMITIVE_LINES, every pair of vertices or indices will be connected to form a line
				mesh.addIndex(a);
				mesh.addIndex(b);
			}
		}
	}
}

//--------------------------------------------------------------
void ofApp::update(){
	//Add a slight perliny wiggle to the vertices making the mesh feel alive
	int numVerts = mesh.getNumVertices();
	for (int i=0; i<numVerts; ++i) {
		ofVec3f vert = mesh.getVertex(i);

		float time = ofGetElapsedTimef();
		float timeScale = 5.0;
		float displacementScale = 0.75;
		ofVec3f timeOffsets = offsets[i];
		
		vert.x += (ofSignedNoise(time*timeScale+timeOffsets.x)) * displacementScale;
		vert.y += (ofSignedNoise(time*timeScale+timeOffsets.y)) * displacementScale;
		vert.z += (ofSignedNoise(time*timeScale+timeOffsets.z)) * displacementScale;
		mesh.setVertex(i, vert);
	}
}
//--------------------------------------------------------------
void ofApp::draw(){
	//background gradient adds a nice effect
    ofColor centerColor = ofColor(85, 78, 68);
    ofColor edgeColor(0, 0, 0);
    ofBackgroundGradient(centerColor, edgeColor, OF_GRADIENT_CIRCULAR);

	//Allows me to adjust camera on runtime
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
