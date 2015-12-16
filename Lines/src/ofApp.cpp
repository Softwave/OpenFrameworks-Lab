#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    
    ofSetWindowTitle("Lines");
    
    //GUI
    //Gui styling
    ofxGuiSetBackgroundColor(ofColor(100,0,200));
    ofxGuiSetFillColor(ofColor(255,0,170));
    ofxGuiSetBorderColor(ofColor(255,255,255));
    ofxGuiSetHeaderColor(ofColor(100, 0, 200));
    
    //Setting up gui
    guiGroup.setName("controls");
    gui.setup(guiGroup);
    
    //Adding controls
    gui.add(num.set("number", 200, 10, 2000));
    gui.add(a.set("a", 0.5, 0, 2.0));
    gui.add(iter.set("iter", 10, 1, 100));
    
    gui.add(rotateX.set("rotX", 0.0, -0.03, 0.03));
    gui.add(rotateY.set("rotY", 0.0, -0.03, 0.03));
    gui.add(rotateZ.set("rotZ", 0.0, -0.03, 0.03));
    
    //polyline.curveTo(0, ofGetHeight()/2, ofGetHeight());
    //for (int i=-150; i<=150; i+=10) polyline.addVertex(ofVec2f(i, 0));
    //for (int i=-150; i<=150; i+=10) polyline.addVertex(ofVec3f(i, i*sin(i), i*cos(i)));
    for (int i=-150; i<=150; i+=10) polyline.addVertex(ofVec2f(i, 0));
}

//--------------------------------------------------------------
void ofApp::update(){
    //for (int i=-(num); i<=num; i+=10) polyline.addVertex(ofVec3f(i, i*sin(i), i*cos(i)));
    rotationX = rotationX + rotateX;
    rotationY = rotationY + rotateY;
    rotationZ = rotationZ + rotateZ;
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    ofEnableDepthTest();
    ofSetColor(255);
    
    mCam.begin();
    polyline.clear();
    for (int i=-(num); i<=num; i+=iter) {
        ofRotateX(rotationX);
        ofRotateY(rotationY);
        ofRotateZ(rotationZ);
        
        ofSetColor(ofColor(sin(a*i) * 255, cos(a*i) * 255, sin(a) * 255));
        
        //polyline.addVertex(ofVec3f(i, i*sin(i*a), i*cos(i*a)));
        //polyline.addVertex(ofVec3f(i, i * sin(i), i * cos(i)));
        
        polyline.addVertex(ofVec3f(i*cos(i*sin(a)), i*sin(i*a), i*cos(i*a)));
        
        polyline.draw();
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
