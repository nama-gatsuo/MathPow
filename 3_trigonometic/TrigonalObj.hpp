

class TrigonalObj {
    
public:
    TrigonalObj() {
        
        calc();
        
    };
    
    void calc() {
        
        vbos.clear();
        ps.clear();
        
        r = ofRandom(10, 20);
        r0 = ofRandom(30);
        zFactor = floor(ofRandom(8));
        
        if (ofRandom(1.0) > 0.5) {
            funcB();
        } else {
            funcA();
        }
    
    };
    
    void funcA() {
        for (int iv = 0; iv < vCount; iv++) {
            
            ofVbo vbo;
            vector<ofVec3f> p;
            
            for (int iu = 0; iu < uCount + 1; iu++) {
                
                float u = ofMap(iu, 0, uCount, 0, TWO_PI);
                float v = ofMap(iv, 0, vCount, 0, TWO_PI);
                
                float x = (r0 + r * cos(u)) * cos(v) * 10;
                float y = (r0 + r * sin(u)) * sin(v) * 10;
                float z = (r * sin(u) + r * 0.5 * sin(zFactor * u)) * 10;
                
                p.push_back( ofVec3f(x, y, z) );
                
                v = ofMap(iv+1, 0, vCount, 0, TWO_PI);
                
                x = (r0 + r * cos(u)) * cos(v) * 10;
                y = (r0 + r * sin(u)) * sin(v) * 10;
                z = (r * sin(u) + r * 0.5 * sin(zFactor * u)) * 10;
                
                p.push_back( ofVec3f(x, y, z) );
            }
            
            vbo.setVertexData(p.data(), p.size(), GL_DYNAMIC_DRAW);
            
            ps.push_back(p);
            vbos.push_back(vbo);
        }
    }
    
    void funcB() {
        for (int iv = 0; iv < vCount; iv++) {
            
            ofVbo vbo;
            vector<ofVec3f> p;
            
            for (int iu = 0; iu < uCount + 1; iu++) {
                
                float u = ofMap(iu, 0, uCount, 0, TWO_PI);
                float v = ofMap(iv, 0, vCount, 0, TWO_PI);
                
                float x = (r0 + r * cos(u)) * cos(v) * 10;
                float y = (r0 + r * cos(u)) * sin(v) * 10;
                float z = (r * sin(u) + r * 0.5 * sin(zFactor * v)) * 10;
                
                p.push_back( ofVec3f(x, y, z) );
                
                v = ofMap(iv+1, 0, vCount, 0, TWO_PI);
                
                x = (r0 + r * cos(u)) * cos(v) * 10;
                y = (r0 + r * cos(u)) * sin(v) * 10;
                z = (r * sin(u) + r * 0.5 * sin(zFactor * v)) * 10;
                
                p.push_back( ofVec3f(x, y, z) );
            }
            
            vbo.setVertexData(p.data(), p.size(), GL_DYNAMIC_DRAW);
            
            ps.push_back(p);
            vbos.push_back(vbo);
        }
    }
    
    
    void draw() {
        
        for (int i = 0; i < vbos.size(); i++) {
            
            vbos[i].draw(GL_TRIANGLE_STRIP, 0, ps[i].size());
            
        }
        
    };
    
    vector<ofVbo> vbos;
    vector<vector<ofVec3f>> ps;
    
    float uMin, uMax, vMin, vMax;
    float r, r0;
    float zFactor;
    const int uCount = 100, vCount = 100;
    
};
