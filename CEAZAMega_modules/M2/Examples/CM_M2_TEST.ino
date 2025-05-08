/*
 * This sketch shows how to activate or deactivate the power sources available in
 * CEAZA M2 board for CEAZA MEGA systrem through a LED power pilot on/off pattern.
 * M2 board have 4 firmware controlled power nodes for precise energy management aplications.
 * The power nodes are:
 * - SW/VIN: Is a controlled Vin terminal form connected devices over 5V supply
 * - SW/+5V: Is a dc-dc stepdown converter wich can deliver up to 3A
 * - SW/V1:  Is a controlled SW/+5V terminal wich can deliver up to 2A. If you need to activate V1 you must activate SW/+5V before
 * - SW/V2:  Is a second controlled SW/+5V terminal wich can deliver up to 2A. If you need to activate V2 you must activate SW/+5V before
 */
#define M2_5V_EN_PIN 27
#define M2_V1_EN_PIN 24
#define M2_V2_EN_PIN 25
#define M2_VIN_EN_PIN 26

void setup() {
  // M2 power controller pins setup
  pinMode(M2_5V_EN_PIN,OUTPUT);digitalWrite(M2_5V_EN_PIN,LOW);
  pinMode(M2_V1_EN_PIN,OUTPUT);digitalWrite(M2_V1_EN_PIN,LOW);
  pinMode(M2_V2_EN_PIN,OUTPUT);digitalWrite(M2_V2_EN_PIN,LOW);
  pinMode(M2_VIN_EN_PIN,OUTPUT);digitalWrite(M2_VIN_EN_PIN,LOW);
}

void loop() {
  digitalWrite(M2_5V_EN_PIN,HIGH);    // Turn on 5V dc-dc step down power supply
  delay(500);
  digitalWrite(M2_V1_EN_PIN,HIGH);    // Turn on V1
  delay(500);
  digitalWrite(M2_V2_EN_PIN,HIGH);    // Turn on V2
  delay(500);
  digitalWrite(M2_VIN_EN_PIN,HIGH);   // Turn on SW/VIN
  delay(500);
  digitalWrite(M2_VIN_EN_PIN,LOW);    // Turn off SW/VIN
  digitalWrite(M2_V2_EN_PIN,LOW);     // Turn off V2
  digitalWrite(M2_V1_EN_PIN,LOW);     // Turn off V1
  digitalWrite(M2_5V_EN_PIN,LOW);     // Turn off 5V dc-dc step down power supply
  delay(500);
}
