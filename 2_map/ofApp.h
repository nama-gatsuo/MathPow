#pragma once

#include "ofMain.h"
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
    
    void createTetra();
    void createOcta();
    
    ofEasyCam cam;
    
    ofxPanel panel;
    ofParameter<ofVec3f> pos;
    ofParameter<ofVec3f> rot;
    ofParameter<ofVec3f> scale;
    ofParameter<ofColor> color;
    ofParameter<int> num;
    ofxToggle isTetra;
    ofxToggle isOcta;
    
    ofVbo tetra;
    vector<ofVec3f> tv;
    
    const float tc[4][3] = {
        {-1, -1, -1}, {-1, 1, 1}, {1, -1, 1}, {1, 1, -1}
    };
    
    
    const int ti[4][3] = {
        {0, 3, 2}, {0, 2, 1}, {0, 1, 3}, {1, 2, 3}
    };
    
    ofVbo octa;
    vector<ofVec3f> ov;
    
    const float oc[6][3] = {
        {1,0,0}, {-1,0,0}, {0,1,0}, {0,-1,0}, {0,0,1}, {0,0,-1}
    };
    
    const unsigned int oi[8][3] = {
        {0, 2, 4}, {0, 4, 3}, {0, 3, 5}, {0, 5, 2},
        {1, 2, 5}, {1, 5, 3}, {1, 3, 4}, {1, 4, 2}
    };

    float rStep, pStep, sStep;
    
};
