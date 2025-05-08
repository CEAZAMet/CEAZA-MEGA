/*
 * This sketch is to show you the LEDs built in CEAZAmega board
 * 
 * For more details about CEAZAmega board you can see the repository.
 * https://github.com/CEAZAmet/CEAZA-MEGA
 * 
 */

// Used pins definition
#define LED_A   40
#define LED_B   41

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LED_A, OUTPUT);
  pinMode(LED_B, OUTPUT);

  Serial.begin(115200);
  Serial.println("\nCEAZA-mega multi blink!");

}

void loop() {
  Serial.println("Arduino built in LED blinking");
  for(int i=0;i<30;i++){
    digitalWrite(LED_BUILTIN,!digitalRead(LED_BUILTIN));
    delay(100);
  }
  digitalWrite(LED_BUILTIN,LOW);

  Serial.println("LED_A blinking (duplpicated in LED JST connector)");
  for(int i=0;i<30;i++){
    digitalWrite(LED_A,!digitalRead(LED_A));
    delay(100);
  }
  digitalWrite(LED_A,LOW);

  Serial.println("LED_B blinking (duplpicated in LED JST connector)");
  for(int i=0;i<30;i++){
    digitalWrite(LED_B,!digitalRead(LED_B));
    delay(100);
  }
  digitalWrite(LED_B,LOW);

}
