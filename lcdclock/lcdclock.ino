

#include <LiquidCrystal.h>
// Pin for the LCD Contrast
const int CON_PIN = 9;
LiquidCrystal lcd(2,3,4,5,6,7); 


//Config

//Set tick rate (tick/second)
const int tickrate = 8;

//Enable/Disable Debug Box Verbose Output
bool dMode = true;

int hr = 0;
int minute = 0;
int sec = 0;
int millisecond = 0;
int num1,num2,num3;

// Set up pinModes and starts serial output
void setup(){   
  
  
  pinMode(CON_PIN, OUTPUT);
  // Defaults to disabled
  
  
  Serial.begin(9600);
  Serial.println("Trasg Detectore lol"); 
  // Sets the display size to 2x16
  lcd.begin(16, 2);
  // Sets default contrast of display to 100/255
  analogWrite(CON_PIN, 100);
    lcd.setCursor(2,0);
  lcd.write(58);
  lcd.setCursor(5,0);
  lcd.write(58);
  lcd.setCursor(8,0);
  lcd.write(58);
}


void loop(){
  /*millisecond++;
  if (millisecond>123) {
    millisecond = 0;
    sec+=1;
    }
  if (sec==60) {
    sec = 0;
    minute+=1;
    }
    if (minute=60) {
    minute = 0;
    hr+=1;
    }
  if (hr=12) 
    hr = 0;
    //(String)hr + ":" + (String)minute + ":" + (String)sec + ":" + 

  */
  lcd.setCursor(0,0);
  num1 = hr/10+48;
  num2 = hr%10+48;
  lcd.write(num1);
  lcd.setCursor(1,0);
  lcd.write(num2);
  

  
  lcd.setCursor(3,0);
  num1 = minute/10+48;
  num2 = minute%10+48;
  lcd.write(num1);
  lcd.setCursor(4,0);
  lcd.write(num2);

  lcd.setCursor(6,0);
  num1 = sec/10+48;
  num2 = sec%10+48;
  lcd.write(num1);
  lcd.setCursor(7,0);
  lcd.write(num2);

  lcd.setCursor(9,0);
  num1 = millisecond/100+48;
  num2 = millisecond/10+48;
  num3 = millisecond%10+48;
  lcd.write(num1);
  lcd.setCursor(10,0);
  lcd.write(num2);
  lcd.setCursor(11,0);
  lcd.write(num3);
  
  Serial.println(minute);
  lcd.setCursor(0,1);
  lcd.write("bruh");
  lcd.setCursor(6,1);
  double val = (analogRead(A0)* (3300/1024) - 0.5) * 100;
  int temp = (int)val;
  num1 = temp / 100+48;
  num2 = temp / 10+48;
  num3 = temp % 10+48;
  lcd.write(num1);
lcd.setCursor(7,1);
  lcd.write(num2);
lcd.setCursor(8,1);
  lcd.write(num3);
  Serial.println(temp);
  delay(900);
  // Tickrate
  delay(1);
}
