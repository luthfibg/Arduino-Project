

const int lamp = 15;
const int led = 12;

void setup() {
  pinMode(lamp, OUTPUT);
  pinMode(led, OUTPUT);
}

void loop() {
 digitalWrite(lamp, HIGH);
 digitalWrite(led, HIGH);
 delay(100);
 digitalWrite(lamp, LOW);
 digitalWrite(led, LOW);
 delay(100);
}
