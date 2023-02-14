// Include RadioHead Amplitude Shift Keying Library
#include <RH_ASK.h>
#include <SPI.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);  
// Create Amplitude Shift Keying Object
RH_ASK rf_driver;
 
void setup()
{
    // Initialize ASK Object
    rf_driver.init();
    // Setup Serial Monitor
    lcd.init();        
    lcd.backlight();  
    Serial.begin(9600);
}
 
void loop()
{
    // Set buffer to size of expected message
    uint8_t buf[20];
    uint8_t buflen = sizeof(buf);

    // Check if received packet is correct size
    if (rf_driver.recv(buf, &buflen))
    {
      
      // Message received with valid checksum
      Serial.print("Message Received:");
      Serial.println((char*)buf);
      lcd.setCursor(0,0);  
      lcd.print((char*)buf);       
    }
}