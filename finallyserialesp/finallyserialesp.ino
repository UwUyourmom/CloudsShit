#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#define SDA 13 //Define SDA pins
#define SCL 14 //Define SCL pins
LiquidCrystal_I2C lcd(0x27,16,2);
int ledPin = 2;
String readString;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT); 
   Wire.begin(SDA, SCL); // attach the IIC pin 
  if (!(i2CAddrTest(0x27))) {
    lcd = LiquidCrystal_I2C(0x3F, 16, 2);
  }
  lcd.init(); // LCD driver initialization
  lcd.backlight(); // Open the backlight
  lcd.setCursor(0,0); // Move the cursor to row 0, column 0

}

void loop() {

  while (Serial.available()) {
    delay(3);  
    char c = Serial.read();
    readString += c; 
  }
  readString.trim();
  if (readString.length() >0) {
    if (readString == "on"){
      lcd.clear();
      Serial.println("switching on");
      Serial.println(readString);
      digitalWrite(ledPin, HIGH);
      lcd.print("ON");
    }
    else{
    if (readString == "off")
    {
      lcd.clear();
      Serial.println("switching off");
      Serial.println(readString);
      digitalWrite(ledPin, LOW);
      lcd.print("OFF");
    }
    else{
    if (readString == "test"){
      lcd.clear();
      Serial.println("Good");
      Serial.println(readString);
      lcd.print("Good!");
    }
    else{
      lcd.clear();
      Serial.println("Wtf Bro -->:");
      Serial.println(readString);
      lcd.print("Wtf Bro :<");
    }}}

    readString="";
  } 
}
bool i2CAddrTest(uint8_t addr) {
 Wire.begin();
 Wire.beginTransmission(addr);
 if (Wire.endTransmission() == 0) {
 return true;
 }
 return false;
}