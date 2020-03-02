#include "ofApp.h"
#include "ofxGui.h"

ofImage img;

//--------------------------------------------------------------
void ofApp::setup(){



	//Window size setup
	ofSetWindowShape(1000, 1000);
	ofSetBackgroundAuto(false);  
	ofSetFrameRate(30); 
	ofEnableAlphaBlending();
	ofSetBackgroundColor(250,250,250);

	//GUI
	shapeGroup.setup();
	parameterGroup.add(shapeGroup.shapeParameters);
	gui.setup(parameterGroup);
	gui.add(lineConnect.set("Line Connect", 30, 10, 100));
	gui.add(backgroundAlpha.set("Alertness Level", 120, 0, 255));
	//gui.add(backgroundColor.set("Sky Color", 255, 0, 255));
	gui.add(lineColor.set("Coffee Color", ofColor(50, 0, 50), ofColor(0), ofColor(255)));
	gui.add(bgColor.set("Sky Color", ofColor(50, 0, 50), ofColor(0), ofColor(255)));
	gui.add(screenShot.set("Screenshot"));
	//gui.add(rotateZ.set("x", 0.0, 0.0, 9.0));

	//rotationZ = 0.0;
}

//comment
//--------------------------------------------------------------
void ofApp::update(){
	rotationZ = rotationZ + rotateZ; 

	//Update all the drawn classes
	myFirstShape.update();
	for (int i = 0; i < shapes.size(); i++){  
		shapes[i]->update();  
	}  

	//Fade the class out subtly over time
    ofEnableAlphaBlending(); 
	ofFill();   
    ofSetColor(bgColor);   
    ofDrawRectangle(0,0,2000,2000);
	ofDisableAlphaBlending();  
}

//--------------------------------------------------------------
void ofApp::draw(){


	if (drawGui) {
		gui.draw();
	}

	shapeGroup.draw();
	//gui.draw();


			//Draw all the classes to the canvas
			myFirstShape.draw();
			for (int i = 0; i < shapes.size(); i++){  
				shapes[i]->draw();  
			}  
				
			ofEnableAlphaBlending();
			ofSetColor(30,30,30,30);

			for (auto line : lines) {
				ofSetColor(lineColor);
				ofDrawLine(line.a, line.b);
			}

			for (auto line2 : lines2) {

			}


	//Allows me to adjust camera on runtime
    easyCam.begin();
        ofPushMatrix();
            ofTranslate(-ofGetWidth()/2, -ofGetHeight()/2);
			ofRotateX(rotationZ);
        ofPopMatrix();
    easyCam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == 'x') {
		drawGui = !drawGui;
	}

	else if (key == 's') {
		img.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
		img.save(screenShot.toString() + ".jpg");
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){
	//Draw classes to canvas based on mouse movement
	shapes.push_back(new Shape(x, y));

	//Draw points and connect lines based on relative position to one another 
	for (auto point : drawnPoints){
        ofPoint mouse;
        mouse.set(x,y);
        float dist = (mouse - point).length();
        if (dist < lineConnect){
            Line lineTemp;
            lineTemp.a = mouse;
            lineTemp.b = point;
            lines.push_back(lineTemp);
        }
    }
    drawnPoints.push_back(ofPoint(x,y));


	for (auto point : drawnPoints2){
        ofPoint mouse;
        mouse.set(x,y);
        float dist = (mouse - point).length();
		float angle = 0;
       
	    if (dist < lineConnect * 10){
            Line lineTemp;
            lineTemp.a = mouse;
            lineTemp.b = point;
            lines2.push_back(lineTemp);
        }
    }
    drawnPoints.push_back(ofPoint(x,y));
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

} 

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	//Extra color fade on mouse press
    ofEnableAlphaBlending(); 
	ofFill();   
    ofSetColor(250,250,250,100);   
    ofDrawRectangle(0,0,2000,2000);
	ofDisableAlphaBlending();  
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
