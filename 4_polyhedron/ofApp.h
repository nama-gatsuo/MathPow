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
    void drawTri(ofPoint * p1, ofPoint * p2, ofPoint * p3);
    
    
    float t = (1 + pow(5, 0.5)) * 0.5;
    
    float vertices[36] = {
        - 1,  t,  0,    1,  t,  0,   - 1, - t,  0,    1, - t,  0,
        0, - 1,  t,    0,  1,  t,    0, - 1, - t,    0,  1, - t,
        t,  0, - 1,    t,  0,  1,   - t,  0, - 1,   - t,  0,  1
    };
    
    ofPoint p[12] = {
        ofPoint(-1, t,  0), ofPoint(1,  t,  0), ofPoint(-1, -t, 0), ofPoint(1, -t,  0),
        ofPoint(0, -1,  t), ofPoint(0,  1,  t), ofPoint(0, -1, -t), ofPoint(0,  1, -t),
        ofPoint(t,  0, -1), ofPoint(t,  0,  1), ofPoint(-t, 0, -1), ofPoint(-t, 0,  1)
    };
    
    int indices[60] = {
        0, 11,  5,    0,  5,  1,    0,  1,  7,    0,  7, 10,    0, 10, 11,
        1,  5,  9,    5, 11,  4,   11, 10,  2,   10,  7,  6,    7,  1,  8,
        3,  9,  4,    3,  4,  2,    3,  2,  6,    3,  6,  8,    3,  8,  9,
        4,  9,  5,    2,  4, 11,    6,  2, 10,    8,  6,  7,    9,  8,  1
    };
    
    ofEasyCam cam;
    
    ofxPanel panel;
    ofParameter<float> a;
    ofParameter<float> b;
    ofParameter<int> DIV_NUM;
    ofParameter<ofColor> color;
    
    bool bDraw = true;
};
