#include <LiquidCrystal.h> 
#include <SimpleDHT.h> 
int pinDHT11 = 11; 
SimpleDHT11 dht11; 
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

 void setup() 
    { // set up the LCD's number of columns and rows: 
    lcd.begin(16, 2);
    lcd.setCursor(4,0); 
    lcd.print("IBNUWANI");
    lcd.setCursor(1,1); 
    lcd.print("PROJECT DHT-11");
    delay(5000); 
    lcd.setCursor(0,0); 
    lcd.clear(); 
    delay(100); 
    lcd.setCursor(0,1); 
    lcd.clear(); 
    delay(500); }


void loop()
 { 
    byte temperature = 0;
    byte humidity = 0; 
    int err = SimpleDHTErrSuccess; 
    if ((err = dht11.read(pinDHT11, &temperature, &humidity, NULL)) != SimpleDHTErrSuccess)
     { 
        lcd.print("Read DHT11 failed, err="); 
        lcd.println(err);
         delay(1000);
         return;
         } // LCD output
    lcd.setCursor(0,0); // Set the first row (location at which subsequent text written to the LCD will be displayed) 
    lcd.print("Temperatur: "); // Print "Temp.:" on the LCD
     lcd.print((int)temperature); // Print string temperature
     lcd.print(" C"); // Prints "C" on the LCD 
    lcd.setCursor(0,1); // Set the second row (location at which subsequent text written to the LCD will be displayed) 
    lcd.print("Hummidity : "); // Print "Humi.:" on the LCD
 lcd.print((int)humidity); // Print string humidity 
    lcd.print(" %");
    delay(1500); 
    }