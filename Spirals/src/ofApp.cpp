#include "ofApp.h"

/* SPIRALS
 * 
 * Generate cool spirals 
 * Made with C++ and OpenFrameworks
 * Only tested on OS X El Capitan
 * 
 * This is free and unencumbered software released into the public domain.
 * 
 * Libraries and frameworks used are copyright of their respective authors.
 */


//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    
    ofSetWindowTitle("Spirals");
    
    //Save image
    saveImg = false;
    
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
    
    gui.add(rotateX.set("rotX", 0.0, -0.03, 0.03));
    gui.add(rotateY.set("rotY", 0.0, -0.03, 0.03));
    gui.add(rotateZ.set("rotZ", 0.0, -0.03, 0.03));
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    rotationX = rotationX + rotateX;
    rotationY = rotationY + rotateY;
    rotationZ = rotationZ + rotateZ;
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0, 0, 0);
    ofEnableDepthTest();
    
    mCam.begin();
    
    float f = TWO_PI * (sqrt((int)d) - 1) * a;
    for (int r = 0; r < num; r++) {
        ofRotateX(rotationX);
        ofRotateY(rotationY);
        ofRotateZ(rotationZ);
        ofSetColor(ofColor(sin(f*r) * 255, cos(f*r) * 255, sin(f) * 255));
        ofDrawSphere(cos(f*r)*r, sin(f*r)*r, size * (cos(r)));
        //ofDrawSphere(cos(f*r)*r, sin(f*r)*r, size * (cos(r)) * f);
    }
    
    if (saveImg) {
        ofSaveViewport("screen" + ofGetTimestampString() + ".png");
        saveImg = false;
    }
    
    mCam.end();
    ofDisableDepthTest();
    gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 's') {
        gui.saveToFile("settings.xml");
    }
    
    if (key == 'l') {
        gui.loadFromFile("settings.xml");
    }
    
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if (key == 'd') {
        std::cout << ofGetTimestampString() << "test" << std::endl;
    }
    
    if (key == 'p') {
        saveImg = true;
    }
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
