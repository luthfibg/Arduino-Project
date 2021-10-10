

#include <ESP8266Firebase.h>
#include <ESP8266WiFi.h>

#define _SSID "Hadid.Techno"        // Your WiFi SSID
#define _PASSWORD "0r1g4m1m4s3t3r"    // Your WiFi Password
#define PROJECT_ID "smarthome-4411"   // Your Firebase Project ID. Can be found in project settings.

Firebase firebase(PROJECT_ID);

int saklar1, saklar2, saklar3, saklar4;
int led[] = {14,12,13,15};

void setup() {
  Serial.begin(115200);
  for(int i=0; i<4; i++){
      pinMode(led[i], OUTPUT);
  }
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(1000);

  // Connect to WiFi
  Serial.println();
  Serial.println();
  Serial.print("Connecting to: ");
  Serial.println(_SSID);
  WiFi.begin(_SSID, _PASSWORD);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print("-");
  }

  Serial.println("");
  Serial.println("WiFi Connected");

  // Print the IP address
  Serial.print("Use this URL to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());

}

void loop() {
  saklar1 = firebase.getString("sakelar/sakelar1").toInt();
  saklar2 = firebase.getString("sakelar/sakelar2").toInt();
  saklar3 = firebase.getString("sakelar/sakelar3").toInt();
  saklar4 = firebase.getString("sakelar/sakelar4").toInt();

  //sakelar1
  if(saklar1 == 1){
      digitalWrite(led[0], HIGH);
      Serial.println("Sakelar 1: On");
  }
  if(saklar1 == 0){
      digitalWrite(led[0], LOW);
      Serial.println("Sakelar 1: Off");
  }
  
//sakelar2
  if(saklar2 == 1){
      digitalWrite(led[1], HIGH);
      Serial.println("Sakelar 2: On");
      
  }
  if(saklar2 == 0){
      digitalWrite(led[1], LOW);
      Serial.println("Sakelar 2: Off");
  }

  //sakelar3
  if(saklar3 == 1){
      digitalWrite(led[2], HIGH);
      Serial.println("Sakelar 3: On");
  }
  if(saklar3 == 0){
      digitalWrite(led[2], LOW);
      Serial.println("Sakelar 3: Off");
  }

  //sakelar4
  if(saklar4 == 1){
      digitalWrite(led[3], HIGH);
      Serial.println("Sakelar 4: On");
  }
  if(saklar4 == 0){
      digitalWrite(led[3], LOW);
      Serial.println("Sakelar 4: Off");
  }
}
