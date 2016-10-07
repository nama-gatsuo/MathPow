#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    ofNoFill();
    
    panel.setup("panel");
    panel.add(a.set("a", 0.5, 0, 1.0));
    panel.add(DIV_NUM.set("DIV_NUM", 10, 2, 100));
    panel.add(color.set("color",ofColor(255,255,255,255),ofColor(0,0,0,0),ofColor(255,255,255,255)));
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetColor(color->r, color->g, color->b, color->a);
    
    cam.begin();
    
    for (int i = 0; i < 20; i++) {
        
        ofPoint * p1 = &p[ indices[i*3 + 0] ];
        ofPoint * p2 = &p[ indices[i*3 + 1] ];
        ofPoint * p3 = &p[ indices[i*3 + 2] ];
        
        drawTri(p1, p2, p3);
        
    }
    
    cam.end();
    
    if (bDraw) panel.draw();
}

void ofApp::drawTri(ofPoint * p1, ofPoint * p2, ofPoint * p3) {
    
    for (int i = 0; i < DIV_NUM - 1; i++) {
        
        ofVec3f _tv = (*p1 * (i + 1) / DIV_NUM + *p2 * a * (DIV_NUM - 1 - i) / DIV_NUM) * 100;
        ofVec3f _fv = (*p1 * (i + 1) / DIV_NUM + *p3 * a * (DIV_NUM - 1 - i) / DIV_NUM) * 100;
        
        ofDrawLine(_tv.x, _tv.y, _tv.z, _fv.x, _fv.y, _fv.z);
    
    }
    
    for (int i = 0; i < DIV_NUM - 1; i++) {
        
        ofVec3f _tv = (*p2 * (i + 1) / DIV_NUM + *p1 * a * (DIV_NUM - 1 - i) / DIV_NUM) * 100;
        ofVec3f _fv = (*p2 * (i + 1) / DIV_NUM + *p3 * a * (DIV_NUM - 1 - i) / DIV_NUM) * 100;
        
        ofDrawLine(_tv.x, _tv.y, _tv.z, _fv.x, _fv.y, _fv.z);
        
    }
    
    for (int i = 0; i < DIV_NUM - 1; i++) {
        
        ofVec3f _tv = (*p3 * (i + 1) / DIV_NUM + *p2 * a * (DIV_NUM - 1 - i) / DIV_NUM) * 100;
        ofVec3f _fv = (*p3 * (i + 1) / DIV_NUM + *p1 * a * (DIV_NUM - 1 - i) / DIV_NUM) * 100;
        
        ofDrawLine(_tv.x, _tv.y, _tv.z, _fv.x, _fv.y, _fv.z);
        
    }
    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if (key == 'h') {
        
        bDraw = !bDraw;
    
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
