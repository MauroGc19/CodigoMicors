//declarar variables 

  //MOTOR
    const int MOTOR_PIN_A = 46;
    const int MOTOR_PIN_B = 47;
    const int MOTOR_PIN_C = 48;
    const int MOTOR_PIN_D = 49;
    
  //LED
    const int LED_PIN_E = 50;
    const int LED_PIN_F = 51;
    const int LED_PIN_G = 52;
    const int LED_PIN_H = 53;

  //RELAY
    const int RELAY_PIN = 45;


void setup() {
  // put your setup code here, to run once:
  pinMode(MOTOR_PIN_A, OUTPUT);
  pinMode(MOTOR_PIN_B, OUTPUT);
  pinMode(MOTOR_PIN_C, OUTPUT);
  pinMode(MOTOR_PIN_D, OUTPUT);

//LED
  pinMode(LED_PIN_E, OUTPUT);
  pinMode(LED_PIN_F, OUTPUT);
  pinMode(LED_PIN_G, OUTPUT);
  pinMode(LED_PIN_H, OUTPUT);

//RELAY
  pinMode(RELAY_PIN, OUTPUT);
}

void loop() {
  rotarMotor();
  encenderLeds();
  relayProbar();
}

//Prueba relay
void relayProbar(){
  digitalWrite(RELAY_PIN, HIGH);
  delay(1000);
  digitalWrite(RELAY_PIN, LOW);
  delay(1000);
}

// Prueba motor
void rotarMotor(){
  digitalWrite(MOTOR_PIN_A, HIGH);
  delay(100);
  digitalWrite(MOTOR_PIN_A, LOW);
  delay(100);
  digitalWrite(MOTOR_PIN_B, HIGH);
  delay(100);
  digitalWrite(MOTOR_PIN_B, LOW);
  delay(100);
  digitalWrite(MOTOR_PIN_C, HIGH);
  delay(100);
  digitalWrite(MOTOR_PIN_C, LOW);
  delay(100);
  digitalWrite(MOTOR_PIN_D, HIGH);
  delay(100);
  digitalWrite(MOTOR_PIN_D, LOW);
  delay(100);
}

// Prueba de los leds
void encenderLeds(){
  digitalWrite(LED_PIN_A, HIGH);
  delay(100);
  digitalWrite(LED_PIN_A, LOW);
  delay(100);
  digitalWrite(LED_PIN_B, HIGH);
  delay(100);
  digitalWrite(LED_PIN_B, LOW);
  delay(100);
  digitalWrite(LED_PIN_C, HIGH);
  delay(100);
  digitalWrite(LED_PIN_C, LOW);
  delay(100);
  digitalWrite(LED_PIN_D, HIGH);
  delay(100);
  digitalWrite(LED_PIN_D, LOW);
  delay(100);
  digitalWrite(LED_PIN_E, HIGH);
  delay(100);
  digitalWrite(LED_PIN_E, LOW);
  delay(100);
  digitalWrite(LED_PIN_F, HIGH);
  delay(100);
  digitalWrite(LED_PIN_F, LOW);
  delay(100);
  digitalWrite(LED_PIN_G, HIGH);
  delay(100);
  digitalWrite(LED_PIN_G, LOW);
  delay(100);
  digitalWrite(LED_PIN_H, HIGH);
  delay(100);
  digitalWrite(LED_PIN_H, LOW);
  delay(100);
}