#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 
#define SCREEN_HEIGHT 64 

// On an arduino UNO:       A4(SDA), A5(SCL)

#define OLED_RESET     -1 
#define SCREEN_ADDRESS 0x3C 
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

int left=2;
int right=3;
int top=4;
int bottom=5;
void setup() {
  pinMode(left,INPUT_PULLUP);
  pinMode(right,INPUT_PULLUP);
  pinMode(top, INPUT_PULLUP);
  pinMode(bottom,INPUT_PULLUP);

  Serial.begin(9600);

  delay(500);

  
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); 
  }
  display.clearDisplay();
  display.setCursor(0,0);
  display.drawRect(56,24,8,8,WHITE);
  display.display();
  
}
int rl;
int rr;
int rt;
int rb;
int x=56;
int y=24;
int movleft=0;
int movright=0;
int movtop=0;
int movbottom=0;
void loop(){
  display.clearDisplay();
  rl=digitalRead(left);
  rr=digitalRead(right);
  rt=digitalRead(top);
  rb=digitalRead(bottom);
  if(rl==LOW and movleft==0){
    x=x-8;
    movleft=1;
  }
  if(rr==LOW and movright==0){
    x=x+8;
    movright=1;
  }
  if(rt==LOW and movtop==0){
    y=y-8;
    movtop=1;
  }
  if(rb==LOW and movbottom==0){
    y=y+8;
    movbottom=1;
  }
  if(x>120){
    x=0;
  }
  if(x<0){
    x=120;
  }
  if(y<0){
    y=56;
  }
  if(y>56){
    y=0;
  }
  if(rl){
    movleft=0;
  }
  if(rr){
    movright=0;
  }
  if(rt){
    movtop=0;
  }
  if(rb){
    movbottom=0;
  }
  display.drawRect(x,y,8,8,WHITE);
  display.display();
  delay(10);



  
}
  
