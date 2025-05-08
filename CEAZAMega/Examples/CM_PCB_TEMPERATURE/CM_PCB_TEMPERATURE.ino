/*
 * This sketch is to show you how to read the PCB temperature for CEAZA mega board.
 * The built in thermistor is powered by integrated 5v step down power supply, so the 
 * system must be connected to a battery or external power supply for valid PCB temperature readings.
 * For more details about CEAZAmega board you can see the repository.
 * https://github.com/CEAZAmet/CEAZA-MEGA
 * 
 * For low-power consumption the MCU is going to sleep between readings, so you should intall LowPower.h libray
 * in your Arduino Ide
 * https://github.com/rocketscream/Low-Power
 * 
 */

#include "LowPower.h"

// Used pins definition
#define VINSTR_EN_PIN 44
#define THERMISTOR_PIN A12

// PCB Temperature calculation's constants
#define rAux 10000
#define vcc 5.
#define beta 3380
#define T0 298.
#define R0 10000

void setup() {
  pinMode(VINSTR_EN_PIN,OUTPUT);
  
  Serial.begin(115200);
  Serial.println("\nCEAZA-mega PCB temperature reading!");
}

void loop() {
  // Update PCB temperature measurement
  float pcbTemperature = getPcbTemp();

  // Show last PCB temperature read by serial monitor
  Serial.print("PCB Temperature: ");
  Serial.print(pcbTemperature);
  Serial.println("*C");

  // Invalid reads detection
  if(pcbTemperature < -40){
    Serial.print("Invalid read... have you connected the power supply to the system?");
  }

  // Go to sleep 2 seconds for energy save
  Serial.flush();
  LowPower.powerDown(SLEEP_2S, ADC_OFF, BOD_OFF);
}


// Read and calculation of PCB temperature function
float getPcbTemp(void){
  digitalWrite(VINSTR_EN_PIN, HIGH); delay(10);             // Turn-on intruments power supply
  float variableAux=(vcc/1024)*analogRead(THERMISTOR_PIN);  // ADC voltage calculation
  variableAux = rAux/((vcc/variableAux)-1);                 // Thermistor calculation
  variableAux = beta/(log(variableAux/R0)+(beta/T0));       // PCB temperature calculation in Kelvin degrees
  variableAux = variableAux - 273.;                         // Convert temperature to celsius degrees
  digitalWrite(VINSTR_EN_PIN, LOW);                         // Turn-off instruments power supply
  return variableAux;
 }
