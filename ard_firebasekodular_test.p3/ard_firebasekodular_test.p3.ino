#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

// Set these to run example.
#define FIREBASE_HOST "smarthome-4411-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "VGhVmLcGfglUzjRTKk8h5vvfqG5h6DnyvyUKfsWK"
#define WIFI_SSID "Moto M 3321"
#define WIFI_PASSWORD "futuristik"

int saklar1, saklar2, saklar3, saklar4;
int led[] = {14,12,13,15};

void setup() {
  Serial.begin(115200);
//  pinMode(led[0], OUTPUT);
  for(int i=0; i<4; i++){
      pinMode(led[i], OUTPUT);
  }

  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
  Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);

}

void loop() {
  saklar1 = Firebase.getString("sakelar/sakelar1").toInt();
  saklar2 = Firebase.getString("sakelar/sakelar2").toInt();
  saklar3 = Firebase.getString("sakelar/sakelar3").toInt();
  saklar4 = Firebase.getString("sakelar/sakelar4").toInt();

//sakelar1
  if(saklar1 == 1){
      digitalWrite(led[0], HIGH);
      Serial.print("Sakelar 1: On");
  }
  if(saklar1 == 0){
      digitalWrite(led[0], LOW);
      Serial.print("Sakelar 1: Off");
  }
  
//sakelar2
  if(saklar2 == 1){
      digitalWrite(led[1], HIGH);
      Serial.print("Sakelar 2: On");
      
  }
  if(saklar2 == 0){
      digitalWrite(led[1], LOW);
      Serial.print("Sakelar 2: Off");
  }

  //sakelar3
  if(saklar3 == 1){
      digitalWrite(led[2], HIGH);
      Serial.print("Sakelar 3: On");
  }
  if(saklar3 == 0){
      digitalWrite(led[2], LOW);
      Serial.print("Sakelar 3: Off");
  }

  //sakelar4
  if(saklar4 == 1){
      digitalWrite(led[3], HIGH);
      Serial.print("Sakelar 4: On");
  }
  if(saklar4 == 0){
      digitalWrite(led[3], LOW);
      Serial.print("Sakelar 4: Off");
  }
}
