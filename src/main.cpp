#include <Arduino.h>

#include "OneWire.h"
#include "DallasTemperature.h"
#include "LiquidCrystal_I2C.h"

OneWire oneWire(15);  //data pin for ds18b20 thermometers


LiquidCrystal_I2C lcd(0x27, 16, 2); //      set the LCD address to 0x27 for a 16 chars and 2 line display
DallasTemperature sensors(&oneWire);

void setup()
{
  Serial.begin(115200);
  lcd.init(); // initialize the lcd  
  // Print a message to the LCD.
  lcd.noBacklight();
  lcd.setCursor(3, 0);
  lcd.print("Hello, world!");
  //lcd.setCursor(2, 1);
  //lcd.print("Ywrobot Arduino!");
  //lcd.setCursor(0, 2);
  //lcd.print("Arduino LCM IIC 2004");
  lcd.setCursor(0, 1);
  lcd.print("Power By Ec-yuan!");
  lcd.clear();
  sensors.begin();
  Serial.println("booted");
}

void loop()
{
  lcd.setCursor(0, 1);
  lcd.print(sensors.getTempCByIndex(0));
  lcd.backlight();
  //delay(1000);
  //lcd.noBacklight();

  Serial.print("Requesting temperatures...");
  sensors.requestTemperatures(); // Send the command to get temperatures
  Serial.println("DONE");
  // After we got the temperatures, we can print them here.
  // We use the function ByIndex, and as an example get the temperature from the first sensor only.
  Serial.print("Temperature for the device 1 (index 0) is: ");
  Serial.println(sensors.getTempCByIndex(0));

  delay(1000);
}
