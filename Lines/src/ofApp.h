#pragma once

#include "ofMain.h"
#include "ofxGrabCam.h"
#include "ofxGui.h"

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
    
    //Lines
    ofPolyline polyline;
    
    //Camera
    ofEasyCam mCam;
    
    //GUI
    ofxPanel gui;
    ofParameter<float> a;
    ofParameter<int> num;
    ofParameter<int> iter;
    
    ofParameter<float> rotateX;
    ofParameter<float> rotateY;
    ofParameter<float> rotateZ;
    
    float rotationX = 0.0;
    float rotationY = 0.0;
    float rotationZ = 0.0;
    
    ofParameterGroup guiGroup;
    
};
