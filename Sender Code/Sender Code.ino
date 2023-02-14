#include <RH_ASK.h>
#include <SPI.h> // Not actually used but needed to compile

int inp = A1;
int SPEAKER = 10;
int SPEAKER1 = 10;    

RH_ASK driver;

void setup()
{
    Serial.begin(9600);	  // Debugging only
    pinMode(inp, INPUT);
    pinMode(SPEAKER, OUTPUT);
    pinMode(SPEAKER1, OUTPUT);

    if (!driver.init())
         Serial.println("init failed");

}

void loop()
{
  Serial.print(digitalRead(inp));

      if(digitalRead(inp)==LOW)
      {
        Msg1();
      }
      else
      {
       Msg2();
       digitalWrite(SPEAKER,LOW);
      noTone(SPEAKER);
      }


}

void Msg1()
{
    tone(SPEAKER, 1000);
    const char *msg = "Alert Driver!!!";
    Serial.println(msg);
    driver.send((uint8_t *)msg, strlen(msg));
    driver.waitPacketSent();
    delay(1000);
}

void Msg2()
{
    const char *msg = "Driver Awake!!!";
    Serial.println(msg);
    driver.send((uint8_t *)msg, strlen(msg));
    driver.waitPacketSent();
    delay(1000);
}

