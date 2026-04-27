//declarar variables 

#include <LiquidCrystal.h>

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

  // --- Pines adicionales (retrocediendo desde 45) ---
  // LCD (rs, en, d4, d5, d6, d7)
    const int LCD_RS_PIN = 44;
    const int LCD_E_PIN  = 43;
    const int LCD_D4_PIN = 42;
    const int LCD_D5_PIN = 41;
    const int LCD_D6_PIN = 40;
    const int LCD_D7_PIN = 39;
    LiquidCrystal lcd(LCD_RS_PIN, LCD_E_PIN, LCD_D4_PIN, LCD_D5_PIN, LCD_D6_PIN, LCD_D7_PIN);

  // Display 7 segmentos (segmentos A-G, DP)
    const int SEG_A = 38;
    const int SEG_B = 37;
    const int SEG_C = 36;
    const int SEG_D = 35;
    const int SEG_E = 34;
    const int SEG_F = 33;
    const int SEG_G = 32;
    const int SEG_DP = 31;
    const int DIGIT_1 = 30;
    const int DIGIT_2 = 29;
    const int DIGIT_3 = 28;
    const int DIGIT_4 = 27;

  // Teclado matricial 4x3 (filas 26..23, columnas 22..20)
    const int KEYPAD_ROW_0 = 26;
    const int KEYPAD_ROW_1 = 25;
    const int KEYPAD_ROW_2 = 24;
    const int KEYPAD_ROW_3 = 23;
    const int KEYPAD_COL_0 = 22;
    const int KEYPAD_COL_1 = 21;
    const int KEYPAD_COL_2 = 20;

    const int keypadRows[4] = {KEYPAD_ROW_0, KEYPAD_ROW_1, KEYPAD_ROW_2, KEYPAD_ROW_3};
    const int keypadCols[3] = {KEYPAD_COL_0, KEYPAD_COL_1, KEYPAD_COL_2};

  // Pulsadores (siguiendo hacia atrás desde 19)
    const int BUTTON_1_PIN = 19;
    const int BUTTON_2_PIN = 18;
    const int BUTTON_3_PIN = 17;
    const int BUTTON_4_PIN = 16;

    const int buttonPins[4] = {BUTTON_1_PIN, BUTTON_2_PIN, BUTTON_3_PIN, BUTTON_4_PIN};

  // Potenciometros (entradas analogicas)
    const int POT_1_PIN = A0;
    const int POT_2_PIN = A1;
    const int POT_3_PIN = A2;

    const int potPins[3] = {POT_1_PIN, POT_2_PIN, POT_3_PIN};


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
// LCD
  pinMode(LCD_RS_PIN, OUTPUT);
  pinMode(LCD_E_PIN, OUTPUT);
  pinMode(LCD_D4_PIN, OUTPUT);
  pinMode(LCD_D5_PIN, OUTPUT);
  pinMode(LCD_D6_PIN, OUTPUT);
  pinMode(LCD_D7_PIN, OUTPUT);

// 7-segment segmentos
  pinMode(SEG_A, OUTPUT);
  pinMode(SEG_B, OUTPUT);
  pinMode(SEG_C, OUTPUT);
  pinMode(SEG_D, OUTPUT);
  pinMode(SEG_E, OUTPUT);
  pinMode(SEG_F, OUTPUT);
  pinMode(SEG_G, OUTPUT);
  pinMode(SEG_DP, OUTPUT);
  pinMode(DIGIT_1, OUTPUT);
  pinMode(DIGIT_2, OUTPUT);
  pinMode(DIGIT_3, OUTPUT);
  pinMode(DIGIT_4, OUTPUT);

// Teclado matricial: filas como OUTPUT, columnas INPUT_PULLUP
  for (int i=0;i<4;i++) pinMode(keypadRows[i], OUTPUT);
  for (int j=0;j<3;j++) pinMode(keypadCols[j], INPUT_PULLUP);

// Pulsadores: entradas con pullup interno
  for (int i=0;i<4;i++) pinMode(buttonPins[i], INPUT_PULLUP);

  // Estado inicial: apagar dígitos y dejar filas en HIGH
  digitalWrite(DIGIT_1, LOW);
  digitalWrite(DIGIT_2, LOW);
  digitalWrite(DIGIT_3, LOW);
  digitalWrite(DIGIT_4, LOW);
  for (int i=0;i<4;i++) digitalWrite(keypadRows[i], HIGH);
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

// -----------------------
// Funciones: LCD
// -----------------------
// Inicia el LCD (16x2)
void lcd_iniciar(){
  lcd.begin(16, 2);
}

// Escribe texto en la posición (col,row)
void lcd_escribirTexto(const char* texto, uint8_t col, uint8_t row){
  lcd.setCursor(col, row);
  lcd.print(texto);
}

// Mueve el cursor a (col,row)
void lcd_moverCursor(uint8_t col, uint8_t row){
  lcd.setCursor(col, row);
}

// Borra el carácter en (col,row)
void lcd_borrarEn(uint8_t col, uint8_t row){
  lcd.setCursor(col, row);
  lcd.print(' ');
}

// -----------------------
// Funciones: Display 7 segmentos
// -----------------------
// Patrones (bits: a b c d e f g) - asume mapeo bit0=a
const uint8_t SEG_PATTERNS[10] = {
  0b00111111, //0
  0b00000110, //1
  0b01011011, //2
  0b01001111, //3
  0b01100110, //4
  0b01101101, //5
  0b01111101, //6
  0b00000111, //7
  0b01111111, //8
  0b01101111  //9
};

void setSegments(uint8_t pattern){
  digitalWrite(SEG_A, (pattern & 0x01) ? HIGH : LOW);
  digitalWrite(SEG_B, (pattern & 0x02) ? HIGH : LOW);
  digitalWrite(SEG_C, (pattern & 0x04) ? HIGH : LOW);
  digitalWrite(SEG_D, (pattern & 0x08) ? HIGH : LOW);
  digitalWrite(SEG_E, (pattern & 0x10) ? HIGH : LOW);
  digitalWrite(SEG_F, (pattern & 0x20) ? HIGH : LOW);
  digitalWrite(SEG_G, (pattern & 0x40) ? HIGH : LOW);
}

// Muestra un dígito en la posición pos (0..3)
void display7_showDigit(int pos, int value, int timeMs){
  uint8_t pat = SEG_PATTERNS[value % 10];
  setSegments(pat);
  digitalWrite(DIGIT_1, pos==0 ? HIGH : LOW);
  digitalWrite(DIGIT_2, pos==1 ? HIGH : LOW);
  digitalWrite(DIGIT_3, pos==2 ? HIGH : LOW);
  digitalWrite(DIGIT_4, pos==3 ? HIGH : LOW);
  delay(timeMs);
  digitalWrite(DIGIT_1, LOW);
  digitalWrite(DIGIT_2, LOW);
  digitalWrite(DIGIT_3, LOW);
  digitalWrite(DIGIT_4, LOW);
}

// Test: muestra 0..9 secuencialmente en las 4 posiciones
void display7_test(){
  for (int v=0; v<=9; v++){
    for (int rep=0; rep<60; rep++){
      for (int pos=0; pos<4; pos++){
        display7_showDigit(pos, v, 2);
      }
    }
    delay(150);
  }
}

// -----------------------
// Funciones: Teclado matricial 4x3
// -----------------------
const char KEYPAD_MAP[4][3] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};

// Lee una tecla (devuelve '\'0' si no hay tecla)
char keypad_read(){
  for (int r=0; r<4; r++){
    // activar fila (bajar)
    digitalWrite(keypadRows[r], LOW);
    delayMicroseconds(5);
    for (int c=0; c<3; c++){
      if (digitalRead(keypadCols[c]) == LOW){
        // debounce simple
        delay(20);
        while (digitalRead(keypadCols[c]) == LOW);
        digitalWrite(keypadRows[r], HIGH);
        return KEYPAD_MAP[r][c];
      }
    }
    digitalWrite(keypadRows[r], HIGH);
  }
  return '\0';
}

// -----------------------
// Funciones: Pulsadores
// -----------------------
// Lee el estado de un pulsador con antirrebote
bool pulsador_leerEstado(int pin){
  if (digitalRead(pin) == LOW){
    delay(20);
    if (digitalRead(pin) == LOW){
      while (digitalRead(pin) == LOW);
      return true;
    }
  }
  return false;
}

// Lee un pulsador por indice (0..3)
bool pulsador_leerPorIndice(int indice){
  if (indice < 0 || indice > 3){
    return false;
  }
  return pulsador_leerEstado(buttonPins[indice]);
}

// -----------------------
// Funciones: Potenciometros
// -----------------------
// Lee el valor analogico de un pin de potenciómetro (0..1023)
int pot_leerValor(int pin){
  return analogRead(pin);
}

// Lee un potenciómetro por indice (0..2)
int pot_leerPorIndice(int indice){
  if (indice < 0 || indice > 2){
    return 0;
  }
  return analogRead(potPins[indice]);
}