#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    float t = ofGetElapsedTimef();
    cam.setPosition(500 * sin(t), 150, 500 * cos(t));
    cam.lookAt(ofVec3f(0, 150, 0));
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetColor(150, 160, 200);
    
    cam.begin();
    
    tree.draw();
    
    cam.end();
    
    ofDrawBitmapString("TZ:  " + ofToString(tree.TZ),   10, 20);
    ofDrawBitmapString("TY0: " + ofToString(tree.TY[0]),10, 40);
    ofDrawBitmapString("TY1: " + ofToString(tree.TY[1]),10, 60);
    ofDrawBitmapString("TY2: " + ofToString(tree.TY[2]),10, 80);
    ofDrawBitmapString("M0:  " + ofToString(tree.M[0]), 10, 100);
    ofDrawBitmapString("M1:  " + ofToString(tree.M[1]), 10, 120);
    ofDrawBitmapString("M2:  " + ofToString(tree.M[2]), 10, 140);
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if (key == ' ') {
        tree.calc();
    }
    
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
