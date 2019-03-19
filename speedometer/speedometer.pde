int window_height = 300;
int window_length = 500;

void setup()  {
  size(550, 180);
}

void draw()  {
  background(255);
  stroke(0);
  line(640,window_height*0.225,0,window_height*0.225);
  line(100,window_height*0.225,100,200);
  textSize(15);
  text("km/t", 220,170);
  
  textSize(22);
  fill(0);
  text("BATTERY PERCENT:",10,1,150,100);
  text("ASSIST:", 10,95);
  text("SPEED:",110,95); 
  textSize(70);
  text("1", 25,170);
  text("0.0", 110,170);
  
}
