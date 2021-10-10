#include <WiFi.h>;
#include <HTTPClient.h>;
#include <ArduinoJson.h>;

const char* ssid = "MOTO M 3321";
const char* password = "futuristik";
char jsonOutput[128];

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
    long rnd = random(1, 10);
    
    HTTPClient client;

    client.begin("http:\\jsonplaceholder.typicode.com/posts/" + String(rnd));    
    client.addHeader("Content-Type", "application/json");

    const size_t CAPACITY = JSON_OBJECT_SIZE(3);
    StaticJsonDocument<CAPACITY> doc;

    JsonObject obj = doc.to<JsonObject>();
    obj["id"] = rnd;
    obj["title"] = "Subscibe to Sebelas Level";
    obj["body"] = "Sebelas Level is the new initiated interested YT channel by M Luthfi";

    serializeJson(doc, jsonOutput);
    Serial.println(jsonOutput);
    
    int httpCode = client.PUT(String(jsonOutput));
    if(httpCode > 0){
      String payload = client.getString();
      Serial.println("\nStatuscode: " + String(httpCode));
      Serial.println(payload);

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
