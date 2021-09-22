/*
 * This sketch is to show you how to read the power supply voltage for CEAZA mega board.
 * The built in voltage monitor reads the Vin pin, so if you only energized the board by the  
 * USB terminal and not by the external power supply, the readings should be near 0V.
 * For more details about CEAZAmega board you can see the repository.
 * https://github.com/CEAZAmet/CEAZA-MEGA
 * 
 */
// Used pins definition
#define VCC_MONITOR_PIN A14

void setup() {
  Serial.begin(115200);
  Serial.println("\nCEAZA-mega system power supply voltage reading!");
}

void loop() {
  // Update external power supply voltage measurement
  float vMonitor = analogRead(VCC_MONITOR_PIN) / 65.415;

  // Show last voltage read by serial monitor
  Serial.print("System input voltage: ");
  Serial.print(vMonitor);
  Serial.println("V");

  delay(2000);
}
