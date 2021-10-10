const int jumlah = 5;
int LED[] = {2,3,4,5,6};
int x;

void setup() {
  for (x=0; x<jumlah; x++){
      pinMode(LED[x],OUTPUT);
    }
}

void loop() {
//  for (x=0; x<jumlah; x++){
//      digitalWrite(LED[x], HIGH);
//      delay(1000);
//    }
animasi1();
}
void animasi1(){

    for (x=0; x<jumlah; x++){
      digitalWrite(LED[x], HIGH);
      delay(500);
      digitalWrite(LED[x], LOW);
      delay(500);
      digitalWrite(LED[x], HIGH);
      delay(500);
      digitalWrite(LED[x], LOW);
      delay(500);
      digitalWrite(LED[x], HIGH);
      delay(500);
    }
}
