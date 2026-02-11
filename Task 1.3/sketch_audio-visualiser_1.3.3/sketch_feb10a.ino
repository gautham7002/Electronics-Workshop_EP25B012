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
int sound_detect=A0;
void setup() {
  Serial.begin(9600);

  delay(500);

  pinMode(sound_detect, INPUT);
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); 
  }
  display.clearDisplay();
  
  
}
int read_ss;
int oled_disp;
void loop(){
  display.clearDisplay();  
  read_ss=analogRead(sound_detect);
  oled_disp=map(read_ss, 300,800,0,32);
  display.drawLine(64,32-oled_disp,64,32,WHITE);
  display.drawLine(64,32,64,32+oled_disp,WHITE);
  display.display();
  


    
}
  
