#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    panel.setup("panel");
    panel.add(pos.set("pos",ofVec3f(0,0,0),ofVec3f(0,0,0),ofVec3f(30,30,30)));
    panel.add(scale.set("scale",ofVec3f(0,0,0),ofVec3f(0,0,0),ofVec3f(10,10,10)));
    panel.add(rot.set("rotate",ofVec3f(0,0,0),ofVec3f(0,0,0),ofVec3f(72,72,72)));
    panel.add(color.set("color",ofColor(255,255,255,128),ofColor(0,0,0,0),ofColor(255,255,255,255)));
    panel.add(num.set("num",10, 1, 100));
    panel.add(isTetra.setup("draw Tetrahedron",false));
    panel.add(isOcta.setup("draw Octahedron",false));

    ofBackground(0);
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    
    createTetra();
    createOcta();
}

//--------------------------------------------------------------
void ofApp::update(){
    
    rStep = 10.0f / num;
    pStep = 10.0f / num;
    sStep = 10.0f / num;
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    cam.begin();
    ofPopStyle();
    
    ofNoFill();
    ofSetColor(color->r, color->g, color->b, color->a);
    
    for (int i = 0; i < num; i++) {
        
        ofPushMatrix();
        
        ofRotateX(i * rStep * rot->x);
        ofRotateY(i * rStep * rot->y);
        ofRotateZ(i * rStep * rot->z);
        
        ofTranslate((i - num/2) * pStep * pos->x,
                    (i - num/2) * pStep * pos->y,
                    (i - num/2) * pStep * pos->z);
        
        ofScale(40 + i * sStep * scale->x,
                40 + i * sStep * scale->y,
                40 + i * sStep * scale->z);
        
        if (isOcta) octa.draw(GL_TRIANGLES, 0, ov.size());
        if (isTetra) tetra.draw(GL_TRIANGLES, 0, tv.size());
        
        ofPopMatrix();
        
    }
    ofPopStyle();
    
    cam.end();
    
    panel.draw();
}

void ofApp::createTetra(){
    
    for (int i = 0; i < 4; i++) {
        
        for (int j = 0; j < 3; j++) {
            
            tv.push_back(ofVec3f(tc[ ti[i][j] ][0], tc[ ti[i][j] ][1], tc[ ti[i][j] ][2]));
            
        }
        
    }
    
    tetra.setVertexData(tv.data(), tv.size(), GL_DYNAMIC_DRAW);
};

void ofApp::createOcta(){

    for (int i = 0; i < 8; i++) {
    
        for (int j = 0; j < 3; j++) {
        
            ov.push_back(ofVec3f(oc[ oi[i][j] ][0], oc[ oi[i][j] ][1], oc[ oi[i][j] ][2]));
        
        }
    
    }
    
    octa.setVertexData(ov.data(), ov.size(), GL_DYNAMIC_DRAW);

};


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
