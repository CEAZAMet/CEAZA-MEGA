/*
 * This sketch is to show you how to use the RS-232 terminal built in CEAZAmega board.
 * Is recommended communicate over RS-232 up to 9600bps to minimize the driver's enable pin (D49) damage chance.
 * 
 * For single test you can connect RX and TX pins of RS-232 terminal and you will receive the same message you 
 * sent by serial monitor as an RS-232 incoming message.
 * 
 * For more details about CEAZAmega board you can see its repository.
 * https://github.com/CEAZAmet/CEAZA-MEGA
 */

#define V232_EN_PIN   49
#define RS232         Serial1

void setup() {
  pinMode(V232_EN_PIN, OUTPUT); digitalWrite(V232_EN_PIN, HIGH);  // Turn-on RS-232 driver
  
  Serial.begin(115200);
  RS232.begin(9600);

  Serial.println("\nCEAZA-mega serial / rs-232 communication!");

}

void loop() {
  if (RS232.available()) {
    int inByte = RS232.read();
    Serial.write(inByte);
  }

  if (Serial.available()) {
    int inByte = Serial.read();
    RS232.write(inByte);
  }

}
