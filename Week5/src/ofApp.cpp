#include "ofApp.h"
#include "ofxGui.h"

//--------------------------------------------------------------
void ofApp::setup(){

	//Window size setup
	ofSetWindowShape(1000, 1000);
	ofSetBackgroundAuto(false);  
	ofSetFrameRate(30); 
	ofEnableAlphaBlending();
	ofSetBackgroundColor(250,250,250);


	gui.setup("Our Parameters!");
	gui.add(lineConnect.set("Line Connect", 30, 10, 50));
	gui.add(backgroundAlpha.set("Background Alpha", 120, 0, 255));
}

//comment
//--------------------------------------------------------------
void ofApp::update(){

	//Update all the drawn classes
	myFirstShape.update();
	for (int i = 0; i < shapes.size(); i++){  
		shapes[i]->update();  
	}  

	//Fade the class out subtly over time
    ofEnableAlphaBlending(); 
	ofFill();   
    ofSetColor(250,250,250,backgroundAlpha);   
    ofDrawRectangle(0,0,2000,2000);
	ofDisableAlphaBlending();  
}

//--------------------------------------------------------------
void ofApp::draw(){

	gui.draw();

	//Draw all the classes to the canvas
	myFirstShape.draw();
	for (int i = 0; i < shapes.size(); i++){  
		shapes[i]->draw();  
	}  
	    
	ofEnableAlphaBlending();
    ofSetColor(30,30,30,30);

    for (auto line : lines) {
        ofDrawLine(line.a, line.b);
    }

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){
	//Draw classes to canvas based on mouse movement
	shapes.push_back(new Shape(x, y));

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
