#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    
    ofSetWindowTitle("Spirals");
    
    //Gui styling
    ofxGuiSetBackgroundColor(ofColor(100,0,200));
    ofxGuiSetFillColor(ofColor(255,0,170));
    ofxGuiSetBorderColor(ofColor(255,255,255));
    ofxGuiSetHeaderColor(ofColor(100, 0, 200));
    //Setting up gui
    guiGroup.setName("controls");
    gui.setup(guiGroup);
    //Adding spiral controls
    gui.add(num.set("number", 200, 10, 2000));
    gui.add(size.set("size", 3, 0, 10));
    gui.add(a.set("a", 0.5, 0, 2.0));
    gui.add(d.set("d", 5, 0, 20));
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0, 0, 0);
    ofEnableDepthTest();
    
    mCam.begin();
    
    float f = TWO_PI * (sqrt((int)d) - 1) * a;
    for (int r = 0; r < num; r++) {
        ofSetColor(ofColor(sin(f*r) * 255, cos(f*r) * 255, sin(f) * 255));
        ofDrawCircle(cos(f*r)*r, sin(f*r)*r, size * (cos(r)));
    }
    
    mCam.end();
    ofDisableDepthTest();
    gui.draw();
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
