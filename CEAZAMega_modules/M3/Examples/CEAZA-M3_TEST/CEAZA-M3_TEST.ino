/*
 * For this code you have to connect an M3 board to a CEAZA MEGA borad.
 * To program the CEAZA MEGA borad you have to select the "Arduino Mega or Mega 2560" board.
 * 
 * This code show by serial monitor the battery voltage and solar panel voltage read from M3 board.
 * Make sure the rigth plug in of battery and solar panel in M3 board.
 * 
 * WARNING!:
 * Do not connect the battery in the main CEAZA MEGA board power plug when the M3 board is in use.
 * 
 *  https://github.com/adgallardo/CEAZA-M3
 */
#define SOLAR_PANEL_MONITOR_PIN A11   // Analog port for solar monitor
#define BATTERY_MONITOR_PIN     A10   // Analog port for battery monitor

void setup() {
  Serial.begin(115200);
  Serial.println("CEAZA-M3 Board Test!");
}

void loop() {
  float vbat = analogRead(BATTERY_MONITOR_PIN)/69.1;      // Calculated battery voltage
  float vsun = analogRead(SOLAR_PANEL_MONITOR_PIN)/34.1;  // Calculated solar panel voltage

  Serial.print("- Battery Voltage:     ");Serial.print(vbat);Serial.println("V");
  Serial.print("- Solar Panel Voltage: ");Serial.print(vsun);Serial.println("V\n");

  delay(5000);
}
