#include "ofApp.h"

/* 
 
 This code is really messy and bad. 
 
 Based off of the example for ofxFft and requires that library.
 
 Only tested on OS X. 
 
 */



//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofSetFrameRate(60);
    ofSetWindowTitle("VJ");
    
    //Music
    music.load("hyperion.mp3");
    music.setLoop(true);
    //music.play();
    
    //FFT
    fftFile.setMirrorData(false);
    fftFile.player = &music;
    fftFile.setup();
    
    //Gui styling
    ofxGuiSetBackgroundColor(ofColor(100,0,200));
    ofxGuiSetFillColor(ofColor(255,0,170));
    ofxGuiSetBorderColor(ofColor(255,255,255));
    ofxGuiSetHeaderColor(ofColor(100, 0, 200));
    //GUI
    guiGroup.setName("controls");
    gui.setup(guiGroup);
    gui.add(volume.set("volume", 0.5, 0.0, 1.0));
    gui.add(speed.set("speed", 1.0, -3.0, 3.0));
    gui.add(red.set("red", 255, 0, 255));
    gui.add(green.set("green", 255, 0, 255));
    gui.add(blue.set("blue", 255, 0, 255));
    gui.add(alpha.set("alpha", 255, 0, 255));
    gui.add(rotateX.set("rotX", 0.0, -0.5, 0.5));
    gui.add(rotateY.set("rotY", 0.0, -0.5, 0.5));
    gui.add(rotateZ.set("rotZ", 0.0, -0.5, 0.5));
    gui.add(modifier.set("modifier", 100, 1, 200));
    gui.add(audioThreshold.set("audioThreshold", 1.0, -10.0, 10.0));
    gui.add(audioPeakDecay.set("audioPeakDecay", 0.915, 0.0, 1.0));
    gui.add(audioMaxDecay.set("audioMaxDecay", 0.995, 0.0, 1.0));
    gui.add(audioMirror.setup("audioMirror", true));
    audioMirror.setBackgroundColor(ofColor(100,0,200));
    audioMirror.setFillColor(ofColor(255,0,170));
    audioMirror.setBorderColor(ofColor(255,255,255));
    
    
    //Objects
    //meshOriginal = meshWarped = ofMesh::sphere(200, 30)
    //ofMesh::plane(200, 200, 30, 30);
    //ofMesh::box(200, 20, 200, 30, 3, 30);
    //meshOriginal = meshWarped = ofMesh::box(200, 1, 200, 120, 0, 120);
    meshOriginal = meshWarped = ofMesh::sphere(200, 60);
    
    //glPointSize(10.f);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    fftFile.player->setVolume(volume);
    fftFile.player->setSpeed(speed);
    fftFile.setThreshold(audioThreshold);
    fftFile.setPeakDecay(audioPeakDecay);
    fftFile.setMaxDecay(audioMaxDecay);
    fftFile.setMirrorData(audioMirror);
    fftFile.update();
    
    //
    rotationX = rotationX + rotateX;
    rotationY = rotationY + rotateY;
    rotationZ = rotationZ + rotateZ;
    
    //
    vector<ofVec3f> &vertsOriginal = meshOriginal.getVertices();
    vector<ofVec3f> &vertsWarped = meshWarped.getVertices();
    int numOfVerts = meshOriginal.getNumVertices();
    int numOfIndices = meshOriginal.getNumIndices();
    
    float* audioData = new float[numOfVerts];
    fftFile.getFftPeakData(audioData, numOfVerts);
    
    float meshDisplacement = modifier;
    
    for (int i = 0; i < numOfVerts; i++) {
        float audioValue = audioData[i];
        ofVec3f &vertOriginal = vertsOriginal[i];
        ofVec3f &vertWarped = vertsWarped[i];
        
        ofVec3f direction = vertOriginal.getNormalized();
        //getNormalized();
        vertWarped = vertOriginal + direction * meshDisplacement * audioValue;
        //vertWarped.rotate(sin(rotationX), cos(rotationY), sin(rotationZ));
        vertWarped.rotate(rotationX * sin(i), rotationY * cos(i), rotationZ);
        //vertWarped.y = (vertOriginal.y + direction.y * meshDisplacement * audioValue) * -(1);
    }
    
    delete[] audioData;
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofEnableDepthTest();
    //ofSetColor(255, 0, 128);
    
    //int w = OFX_FFT_WIDTH;
    //int h = OFX_FFT_HEIGHT;
    //int x = 20;
    //int y = ofGetHeight() - h - 20;
    //fftLive.draw(x, y, w, h);
    
    
    mCam.begin();

    
    //ofRotateX(rotationX);
    ///ofRotateY(rotationY);
    //ofRotateZ(rotationZ);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    ofSetColor(red, green, blue, alpha);
    //meshWarped.drawWireframe();
    //meshWarped.drawVertices();
    meshWarped.drawFaces();

    glDisable(GL_CULL_FACE);
    mCam.end();
    
    ofDisableDepthTest();
    gui.draw();
    //fftFile.draw(x, y, w, h);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if (key == 'p') {
        music.play();
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
