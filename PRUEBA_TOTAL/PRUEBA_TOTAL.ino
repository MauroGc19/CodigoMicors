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

    // Display 7 segmentos (4 bits: A, B, C, D - envía números binarios)
      const int SEG_A = 38;
      const int SEG_B = 37;
      const int SEG_C = 36;
      const int SEG_D = 35;
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

  // 7-segment (4 bits ABCD)
    pinMode(SEG_A, OUTPUT);
    pinMode(SEG_B, OUTPUT);
    pinMode(SEG_C, OUTPUT);
    pinMode(SEG_D, OUTPUT);
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
    
    // Inicializar LCD
    lcd_iniciar();
    lcd.clear();
    lcd_escribirTexto("Esperando...", 0, 0);
  }

  void loop() {
    // ===== PRUEBA DE TODOS LOS ELEMENTOS (CON UN SOLO POTENCIÓMETRO) =====
    
    // 1. LEER POTENCIÓMETRO 1
    int pot1 = pot_leerPorIndice(0);  // 0-1023
    int numeroDePot = map(pot1, 0, 1018, 0, 9);  // Rango 0-900 para asegurar que llega al 9
    
    // 2. MOSTRAR EN LCD
    lcd.setCursor(0, 0);
    lcd.print("Numero: ");
    lcd.print(numeroDePot);
    lcd.print("  ");
    
    lcd.setCursor(0, 1);
    lcd.print("Val: ");
    lcd.print(pot1);
    lcd.print("    ");
    
    // 3. MOSTRAR EN DISPLAY 7 SEGMENTOS (cada dígito muestra un número diferente)
    for (int digito = 0; digito < 4; digito++) {
      int numeroMostrar = (numeroDePot + digito) % 10;  // Números diferentes en cada dígito
      display7_showDigit(digito, numeroMostrar, 50);
    }
    
    // 4. LEER TECLADO MATRICIAL
    char tecla = keypad_read();
    if (tecla >= '0' && tecla <= '9') {
      int numero = tecla - '0';
      lcd.clear();
      lcd.print("Tecla: ");
      lcd.print(tecla);
      delay(1000);
      prueba_integrada(numero);
    }
    
    // 5. LEER PULSADORES
    for (int i = 0; i < 4; i++) {
      if (pulsador_leerPorIndice(i)) {
        lcd.clear();
        lcd.print("Pulsador: ");
        lcd.print(i + 1);
        delay(1000);
        
        // Ejecutar prueba con número del potenciómetro
        prueba_integrada(numeroDePot);
        break;
      }
    }
  }

  // ======== FUNCIÓN PRINCIPAL DE PRUEBA INTEGRADA ========
  void prueba_integrada(int numero) {
    // Limpiar LCD y mostrar el número
    lcd.clear();
    lcd_escribirTexto("Numero: ", 0, 0);
    lcd.print(numero);
    
    // Leer potenciómetro 2 para velocidad del motor (0-1023 -> 50-500ms)
    int velocidadMotor = map(pot_leerPorIndice(1), 0, 1023, 50, 300);
    
    // Leer potenciómetro 3 para duración LED (0-1023 -> 100-1000ms)
    int duracionLED = map(pot_leerPorIndice(2), 0, 1023, 100, 500);
    
    // Mostrar en display 7 segmentos (parpadea el número)
    for (int i = 0; i < 30; i++) {
      display7_showDigit(0, numero, 30);
    }
    
    // Mostrar velocidad en LCD
    lcd.setCursor(10, 0);
    lcd.print("V:");
    lcd.print(velocidadMotor);
    
    // Girar el motor 'numero' veces con velocidad controlada por potenciómetro 2
    rotarMotor_n_velocidad(numero, velocidadMotor);
    
    // Encender el LED correspondiente al número (0-3: E, F, G, H)
    encenderLed_n_duracion(numero % 4, duracionLED);
    
    // Activar el relay 'numero' veces con intervalo de 1 segundo
    relay_activar_n(numero);
    
    // Mostrar mensaje de completado
    lcd.clear();
    lcd_escribirTexto("Completo!", 0, 0);
    lcd_escribirTexto("Presione otra", 0, 1);
    delay(2000);
    
    // Limpiar pantalla
    lcd.clear();
  }

  // ======== MOTOR: Girar N veces ========
  void rotarMotor_n(int veces) {
    int motorPins[4] = {MOTOR_PIN_A, MOTOR_PIN_B, MOTOR_PIN_C, MOTOR_PIN_D};
    
    for (int v = 0; v < veces; v++) {
      // Girar el motor una vez (4 pasos)
      for (int i = 0; i < 4; i++) {
        digitalWrite(motorPins[i], HIGH);
        delay(100);
        digitalWrite(motorPins[i], LOW);
        delay(100);
      }
    }
  }

  // ======== MOTOR: Girar N veces con velocidad controlada ========
  void rotarMotor_n_velocidad(int veces, int delayMs) {
    int motorPins[4] = {MOTOR_PIN_A, MOTOR_PIN_B, MOTOR_PIN_C, MOTOR_PIN_D};
    
    for (int v = 0; v < veces; v++) {
      // Girar el motor una vez (4 pasos)
      for (int i = 0; i < 4; i++) {
        digitalWrite(motorPins[i], HIGH);
        delay(delayMs);
        digitalWrite(motorPins[i], LOW);
        delay(delayMs);
      }
    }
  }

  // ======== LED: Encender un LED específico ========
  void encenderLed_n(int numLed) {
    int leds[4] = {LED_PIN_E, LED_PIN_F, LED_PIN_G, LED_PIN_H};
    
    // Apagar todos los LEDs primero
    for (int i = 0; i < 4; i++) {
      digitalWrite(leds[i], LOW);
    }
    
    // Encender el LED correspondiente (parpadeando)
    for (int i = 0; i < 5; i++) {
      digitalWrite(leds[numLed], HIGH);
      delay(200);
      digitalWrite(leds[numLed], LOW);
      delay(200);
    }
  }

  // ======== LED: Encender un LED específico con duración controlada ========
  void encenderLed_n_duracion(int numLed, int duracionMs) {
    int leds[4] = {LED_PIN_E, LED_PIN_F, LED_PIN_G, LED_PIN_H};
    
    // Apagar todos los LEDs primero
    for (int i = 0; i < 4; i++) {
      digitalWrite(leds[i], LOW);
    }
    
    // Encender el LED correspondiente (parpadeando con duración controlada)
    for (int i = 0; i < 5; i++) {
      digitalWrite(leds[numLed], HIGH);
      delay(duracionMs / 2);
      digitalWrite(leds[numLed], LOW);
      delay(duracionMs / 2);
    }
  }

  // ======== RELAY: Activar N veces con 1 segundo de intervalo ========
  void relay_activar_n(int veces) {
    for (int i = 0; i < veces; i++) {
      digitalWrite(RELAY_PIN, HIGH);
      delay(500);  // Relay encendido 0.5 segundos
      digitalWrite(RELAY_PIN, LOW);
      delay(500);  // Esperar 0.5 segundos entre activaciones
    }
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
  // Funciones: Display 7 segmentos (4 bits binarios ABCD)
  // -----------------------
  // Tabla de conversión: dígito 0-9 -> número binario 4 bits (ABCD)
  const uint8_t SEG_PATTERNS[10] = {
    0b0000, //0
    0b0001, //1
    0b0010, //2
    0b0011, //3
    0b0100, //4
    0b0101, //5
    0b0110, //6
    0b0111, //7
    0b1000, //8
    0b1001  //9
  };

  // Envía un número binario de 4 bits a los pines ABCD (CÁTODO COMÚN - activa con LOW)
  void setSegments(uint8_t pattern) {
    // Para cátodo común: HIGH = encendido, LOW = apagado
    digitalWrite(SEG_A, (pattern & 0x01) ? HIGH : LOW);
    digitalWrite(SEG_B, (pattern & 0x02) ? HIGH : LOW);
    digitalWrite(SEG_C, (pattern & 0x04) ? HIGH : LOW);
    digitalWrite(SEG_D, (pattern & 0x08) ? HIGH : LOW);
  }

  // Muestra un dígito en la posición pos (0..3) con un número binario (ÁNODO COMÚN)
  void display7_showDigit(int pos, int value, int timeMs){
    uint8_t pat = SEG_PATTERNS[value % 10];
    setSegments(pat);
    // ÁNODO COMÚN: activar dígito con LOW
    digitalWrite(DIGIT_1, pos==0 ? LOW : HIGH);
    digitalWrite(DIGIT_2, pos==1 ? LOW : HIGH);
    digitalWrite(DIGIT_3, pos==2 ? LOW : HIGH);
    digitalWrite(DIGIT_4, pos==3 ? LOW : HIGH);
    delay(timeMs);
    // Apagar todos los dígitos
    digitalWrite(DIGIT_1, HIGH);
    digitalWrite(DIGIT_2, HIGH);
    digitalWrite(DIGIT_3, HIGH);
    digitalWrite(DIGIT_4, HIGH);
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