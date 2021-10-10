#include <WiFi.h>;
#include <HTTPClient.h>;
#include <ArduinoJson.h>;

const char* ssid = "MOTO M 3321";
const char* password = "futuristik";
char jsonOutput[128];                         //json post

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");

  while (WiFi.status() != WL_CONNECTED){
      Serial.print(".");
      delay(500);
  }
  Serial.println("\nConnected to the WiFi network");
  Serial.print("WiFi address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  if((WiFi.status() == WL_CONNECTED)){
//    long rnd = random(1, 10);                         //json get
    HTTPClient client;

//    client.begin("http:\\jsonplaceholder.typicode.com/comments?id=" + String(rnd));  //json get
    client.begin("http:\\jsonplaceholder.typicode.com/posts");    //json post
    client.addHeader("Content-Type", "application/json");         //json post

    const size_t CAPACITY = JSON_OBJECT_SIZE(1);                  //json post
    StaticJsonDocument<CAPACITY> doc;                             //json post

    JsonObject object = doc.to<JsonObject>();
    object["title"] = "Subscibe to Sebelas Level";

    serializeJson(doc, jsonOutput);
    
//    int httpCode = client.GET();                                //json get
    int httpCode = client.POST(String(jsonOutput));               //json post

    if(httpCode > 0){
      String payload = client.getString();
      Serial.println("\nStatuscode: " + String(httpCode));
      Serial.println(payload);

//      char json[500];
//      payload.replace(" ", "");
//      payload.replace("\n", "");
//      payload.trim();
//      payload.remove(0, 1);                                   /* json get */
//      payload.toCharArray(json, 500);
//      
//      StaticJsonDocument<200> doc;
//      deserializeJson(doc, json);
//
//      int id = doc["id"];
//      const char* email = doc["email"];
//
//      Serial.println(String(id) + " - " + String(email) + "\n");
      client.end();
    }
    else{
      Serial.println("Error on http request");  
    }
  }
  else{
    Serial.println("Connection lost");  
  }
  delay(10000);

}
