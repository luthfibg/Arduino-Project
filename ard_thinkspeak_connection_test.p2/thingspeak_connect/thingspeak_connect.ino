#include <ThingSpeak.h>                           //Library platform thingspeak
#include <ESP8266WiFi.h>                          //Library WiFi NodeMCU ESP8266
#include <WiFiClient.h>       //Library Client

#define sensor A0

int nilai;

const char *ssid = "ICE.OFFICIAL";                 // setting nama WiFi router
const char *password = "elektro.indo";                // password Wifi router
WiFiClient client;                                // cheking jika channel sudah terhubung

unsigned long myChannelNumber = 1497611;          // ID akun thingspeak
const char *myWriteAPIKey = "Z69BTLIAZT1291KD";    // memasukkan API Key Write
const char *myReadAPIKey = "IB0BDJV3RZI5RSSN";     // memasukkan API Key Read

void setup() {
  Serial.begin(115200);

  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password); // menghubungkan dengan wifi router
  while(WiFi.status() != WL_CONNECTED) // cek koneksi WiFi
  {
    delay(500);
    Serial.print(".");  
  }
  Serial.println("");
  Serial.println("WiFi Connected");
  Serial.println(WiFi.localIP());
  ThingSpeak.begin(client); // melakukan inisialisasi ke thingspeak

  pinMode(sensor, INPUT);
  
  
}

void loop() {

  nilai = analogRead(sensor);
  Serial.println(nilai);

  ThingSpeak.writeField(myChannelNumber, 1, nilai, myWriteAPIKey); 
  
}
