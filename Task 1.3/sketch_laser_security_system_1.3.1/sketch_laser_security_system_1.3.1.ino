#include <LiquidCrystal.h>
int laser=7;
int ldr=10;                                                                                
int piezo=8;

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  pinMode(laser,OUTPUT);
  pinMode(piezo,OUTPUT);
  pinMode(ldr,INPUT);
  lcd.begin(16, 2);
  lcd.print("starting");
  
}
int x;
void loop() {
  digitalWrite(laser,HIGH);
  x=digitalRead(ldr);
  if(x==LOW){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("No");
    lcd.setCursor(0,1);
    lcd.print("Interference");
    noTone(piezo);
    

  }
  else{
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Interference");
    lcd.setCursor(0,1);
    lcd.print("detected");
    tone(piezo, 4000);
    delay(100);
    }

}

