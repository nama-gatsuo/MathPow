PVector[] pv;
float[] rv;

int pNum = 100;
int aNum = 6;

float r = 400;
float e;

void setup() {
  
  size(1000, 1000);
  background(0);
  blendMode(ADD);
  
  stroke(150, 150, 150);
  noFill();
  
  e = r * sin(TWO_PI / aNum);
  
  pv = new PVector[pNum];
  rv = new float[pNum];
  
  for (int i = 0; i < pNum; i++) {
    pv[i] = new PVector(random(e), random(r));
    rv[i] = random(1) * 10 + 5;
  }
  
  translate(width / 2, height / 2);
  
  for (int i = 0; i < aNum; i++) {
    
    rotate(TWO_PI / aNum);
    drawFan();
    
  }
}


void drawFan() {
  
  for (int i = 0; i < pNum; i++) {
    
    ellipse(pv[i].x, pv[i].y, rv[i], rv[i]);
    
    for (int j = i+1; j < pNum; j++) {
    
      float d = pow(pow((pv[i].x - pv[j].x), 2) + pow((pv[i].y - pv[j].y), 2), 0.5);
      if (d < 60) {
        line(pv[i].x, pv[i].y, pv[j].x, pv[j].y);
        
      }
      
    }
    
  }
  
}