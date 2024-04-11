#define BLYNK_TEMPLATE_ID "TMPL3h2RscGF2"
#define BLYNK_TEMPLATE_NAME "ECG"

#include <Blynk.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#define BLYNK_PRINT Serial

char auth[] = "N9yu07Fiwl0GFM40sS251Cjz6zIj6Iym";
char ssid[] = "JioFiber-hAa8n";
char pass[] = "Mother123"; // all ur web & mobile & node mcu

#define ANALOGIN A0 
// What digital pin we're connected to
BlynkTimer timer;
void sendSensor()
{
  int h = analogRead(A0); //89. 
  Blynk.virtualWrite(V5, h);
  //Blynk.virtualWrite(V6, A0);
}
void setup()
{
  // Debug console
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  timer.setInterval(1L, sendSensor);
}//
void loop()
{
  Blynk.run();
  timer.run();
}
