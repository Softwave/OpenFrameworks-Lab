#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "ofxFFTFile.h"


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    //Camera
    ofEasyCam mCam;
    
    //FFT
    ofxFFTFile fftFile;
    ofSoundPlayer music;
    
    //GUI
    ofxPanel gui;
    ofParameter<float> volume;
    ofParameter<float> speed;
    ofParameter<int> modifier;
    ofParameter<float> audioThreshold;
    ofParameter<float> audioPeakDecay;
    ofParameter<float> audioMaxDecay;
    ofParameter<int> red;
    ofParameter<int> green;
    ofParameter<int> blue;
    ofParameter<int> alpha;
    ofParameter<float> rotateX;
    ofParameter<float> rotateY;
    ofParameter<float> rotateZ;
    ofxToggle audioMirror;
    ofParameterGroup guiGroup;
    
    //Objects
    ofMesh meshOriginal;
    ofMesh meshWarped;
    
    //vars
    float rotationX = 0.0;
    float rotationY = 0.0;
    float rotationZ = 0.0;
        
		
};
