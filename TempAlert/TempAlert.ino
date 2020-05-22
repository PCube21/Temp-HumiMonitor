
#include <LiquidCrystal_I2C.h>
#include "DHT.h"

#define DHTPIN 2
#define DHTTYPE DHT22

LiquidCrystal_I2C lcd(0x27,16,2);
DHT dht(DHTPIN, DHTTYPE);

void setup() 
{
  Serial.begin(9600);
  dht.begin();
  lcd.init();                  
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("TemperatureAlert");
  lcd.setCursor(1,1);
  lcd.print("Power By PCube");  
  delay(1000); 
}

void loop() 
{
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Temp:");
  lcd.print(t);
  lcd.setCursor(0,1);
  lcd.print("Humi:");
  lcd.print(h);
  delay(3000);
  if(t>35)
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Temperature is too hot outside!");
    delay(1000);
    for(int positionCounter = 0; positionCounter < 17; positionCounter++) 
    {
      lcd.scrollDisplayLeft();
      delay(300);
    }
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Don't forget to wear long shirt!");
    delay(1000);
    for(int positionCounter = 0; positionCounter < 17; positionCounter++) 
    {
      lcd.scrollDisplayLeft();
      delay(300);
    }
  }
  lcd.clear();
  lcd.setCursor(1,0);
  lcd.print("Wash Your Hand");
  lcd.setCursor(2,1);
  lcd.print("Stay At Home"); 
  delay(2000); 
}
