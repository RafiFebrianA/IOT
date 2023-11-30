#define BLYNK_PRINT Serial

/* Fill in information from Blynk Device Info here */
#define BLYNK_TEMPLATE_ID "TMPL68u4ssONh"
#define BLYNK_TEMPLATE_NAME "Otomatisasi Sistem Pencahayaan"
#define BLYNK_AUTH_TOKEN "4F1ncNsixiCCKZmM4x_kmXd39nD7KbZY"

#define VPIN_Saklar_1 V0
#define VPIN_Saklar_2 V1
#define VPIN_Semua_Saklar V2 

#define ldrPin 32
#define servoapin 18
#define servobpin 19

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <ESP32_Servo.h>

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Chronostasis";
char pass[] = "AP4cheGPT";

const float gama = 0.7;
const float rl10 = 50;

Servo servoa;
Servo servob;

bool servoaNyala = false;
bool servobNyala = false;

BLYNK_WRITE(V0)
{
int pinValue1=param.asInt();
if (pinValue1 == 1) {
  Blynk.virtualWrite(V0, 1);
	servoa.write(60);
	servoaNyala = true;
}
else {
Blynk.virtualWrite(V0, 0);
servoa.write(0);
servoaNyala = false;
}

}

BLYNK_WRITE(V1)
{
int pinValue2=param.asInt();
if (pinValue2 == 1) {
  Blynk.virtualWrite(V1, 1);
	servob.write(60);
	servobNyala = true;
}
else {
Blynk.virtualWrite(V1, 0);
servob.write(0);
servobNyala = false;
}

}

BLYNK_WRITE(V2)
{
int pinValue3=param.asInt();
if (pinValue3 == 1) {
  Blynk.virtualWrite(V0, 1);
  Blynk.virtualWrite(V1, 1);
  Blynk.virtualWrite(V2, 1);
	servoa.write(60);
	servob.write(60);
	servoaNyala = true;
	servobNyala = true;
}
else {
Blynk.virtualWrite(V0, 0);
Blynk.virtualWrite(V1, 0);
Blynk.virtualWrite(V2, 0);
servoa.write(0);
servob.write(0);
servoaNyala = false;
servobNyala = false;
}

}

void setup() {
  // put your setup code here, to run once:
  servoa.attach(servoapin);
  servob.attach(servobpin);
  Serial.begin(115200);
  Serial.println("Hello, ESP32!");
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

void loop() {
  // put your main code here, to run repeatedly:
   // this speeds up the simulation
  int nilaiLDR = analogRead(ldrPin);
  nilaiLDR = map(nilaiLDR, 4095, 0, 1024, 0); //mengubah nilai pembacaan sensor LDR dari nilai ADC arduino menjadi nilai ADC ESP32
  float voltase = nilaiLDR / 1024.*5;
  float resistansi = 2000 * voltase / (1-voltase/5);
  float kecerahan = pow(rl10*1e3*pow(10,gama)/resistansi,(1/gama));
  //Serial.print("Kecerahan = ");
  //Serial.println(kecerahan);
  Blynk.virtualWrite(V3, kecerahan);
  Blynk.run();
  delay(1000);
}