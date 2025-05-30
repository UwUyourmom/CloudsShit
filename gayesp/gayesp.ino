#include <LiquidCrystal_I2C.h>
#include <Wire.h>
char* Name[] = {"C","l","o","u","d","H","a","x","k","o",".","S","p","a","c","e"};
#define SDA 13 //Define SDA pins
#define SCL 14 //Define SCL pins
LiquidCrystal_I2C lcd(0x27,16,2);


void setup() {

   Serial.begin(115200);
    Wire.begin(SDA, SCL); // attach the IIC pin 
  if (!(i2CAddrTest(0x27))) {
    lcd = LiquidCrystal_I2C(0x3F, 16, 2);
  }
  lcd.init(); // LCD driver initialization
  lcd.backlight(); // Open the backlight
  lcd.setCursor(0,0); // Move the cursor to row 0, column 0
}



void loop() {
  for (int i = 0; i < 16; i++) {
        switch(i){
          case 0:
          lcd.setCursor(0, 0);
          break;
          case 5:
          lcd.setCursor(0, 1);
          break;
          default:
          break;
        }
        delay(250);
        printf("%d ", Name[i]);
        lcd.print(Name[i]);
        

  }
  delay(1000);
  lcd.clear();


}
bool i2CAddrTest(uint8_t addr) {
 Wire.begin();
 Wire.beginTransmission(addr);
 if (Wire.endTransmission() == 0) {
 return true;
 }
 return false;
}