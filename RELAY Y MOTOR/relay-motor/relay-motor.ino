c

void setup() {
  // put your setup code here, to run once:
  pinMode(pinA, OUTPUT);
  pinMode(pinB, OUTPUT);
  pinMode(pinC, OUTPUT);
  pinMode(pinD, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i=1; i <=12; i++){
     digitalWrite(pinA, HIGH);
     delay(100);
     digitalWrite(pinA, LOW);
     delay(100);
     digitalWrite(pinB, HIGH);
      delay(100);
      digitalWrite(pinB, LOW);
      delay(100);
      digitalWrite(pinC, HIGH);
      delay(100);
      digitalWrite(pinC, LOW);
      delay(100);
      digitalWrite(pinD, HIGH);
      delay(100);
      digitalWrite(pinD, LOW);
      delay(100);
  }
 digitalWrite(pinA, HIGH);
     delay(100);
     digitalWrite(pinA, LOW);
     delay(100);
     
  delay(2000);
}
