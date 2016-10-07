#include "ofMain.h"

class TreeObj {
public:
    TreeObj() {
        
        calc();
        
    };
    
    void fractalLoop(ofVec3f * p, ofMatrix4x4 * mat, float r, int level) {
        
        if (level == MAX_LEVEL) return;
        
        for (int i = 0; i < 3; i++) {
            
            ofVec3f _p = ofVec3f(0, r, 0);
            
            float rad = TY[i];
            ofMatrix4x4 _m1 = ofMatrix4x4(cos(rad), 0.0, sin(rad), 0,
                                          0.0,      1.0, 0.0,      0,
                                          -sin(rad),0.0, cos(rad), 0,
                                          0,        0,   0,        0 );
            
            
            rad = TZ;
            ofMatrix4x4 _m2 = ofMatrix4x4(cos(rad), -sin(rad), 0.0, 0,
                                          sin(rad), cos(rad),  0.0, 0,
                                          0.0,      0.0,       1.0, 0,
                                          0,        0,         0,   0 );
            
            
            ofMatrix4x4 _m3 = *mat * _m1 * _m2;
            
            ofVec4f v = ofVec4f(_p.x, _p.y, _p.z, 1.0);
            v = _m3 * v;
            
            pos.push_back( *p );
            _p.set(p->x + v.x, p->y + v.y, p->z + v.z);
            pos.push_back( _p );
            
            fractalLoop(&_p, &_m3, r * M[i], level+1);
        }
        
        mesh.setVertexData(pos.data(), pos.size(), GL_DYNAMIC_DRAW);
        
    };
    
    void calc() {
        
        pos.clear();
        
        for (int i = 0; i < 3; i++) {
            M[i] = ofRandom(1.5);
        }
        
        TZ = PI * ofRandom(0.5);
        float coin = ofRandom(1.0);
        
        if (coin < 0.5) {
            TY[0] = TWO_PI * 0.25;
            TY[1] = TWO_PI * 0.5;
            TY[2] = TWO_PI * 0.75;
            
            if (coin < 0.2) {
                TZ = PI * 0.5;
            }
            
        } else {
            TY[0] = TWO_PI * 0.333333;
            TY[1] = TWO_PI * 0.666666;
            TY[2] = TWO_PI;
        }
        
        pos.push_back(ofVec3f(0,0,0));
        
        ofMatrix4x4 mat = ofMatrix4x4(1.0, 0, 0, 0,
                                      0, 1.0, 0, 0,
                                      0, 0, 1.0, 0,
                                      0, 0, 0, 1.0 );
        
        ofVec3f v = ofVec3f(0, 0, 0);
        pos.push_back(v);
        
        fractalLoop(&v, &mat, 80, 0);
        
    };
    
    
    void draw() {
        
        glPointSize(5.0);
        mesh.draw(GL_LINES, 0, pos.size());
        mesh.draw(GL_POINTS, 0, pos.size());
        
    };
    
    ofVbo mesh;
    vector<ofVec3f> pos;
    
    int MAX_LEVEL = 7;
    
    float M[3] = { 1.01, 1.01, 0.49 };
    float TY[3] = { TWO_PI * 0.25, TWO_PI * 0.5, TWO_PI };
    float TZ = PI * 0.5;

};
