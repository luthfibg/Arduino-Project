
const int led1 = 13; 
void setup() {
  pinMode(led1, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  digitalWrite(led1, HIGH);
  delay(100);
  digitalWrite(led1, LOW);
  delay(100);
  digitalWrite(led1, HIGH);
  delay(100);
  digitalWrite(led1, LOW);
  delay(100);
}
