/*
 * This sketch is to show you how to read temperature from DS18B20 sensor connected to CEAZAmega board.
 * The built int terminal is powered by D48 MCU pin and the pull-up resistor in data pin (D38) is integrated
 * on board, so is not necesary add any external electronic component to the DS18B20 sensor.
 * The appropiate DS18B20 board terminal is a 3 pin, 2mm pitch JST type with "T°C" marking on PCB to proper detection.
 * 
 * WARNING!
 * Be careful to do not make a short circuit with the sensor power pin to avoid MCU pin damage.
 * 
 * For more details about CEAZAmega board you can see the repository.
 * https://github.com/CEAZAmet/CEAZA-MEGA
 * 
 * You need to install  the library DallasTemperature.h
 * https://github.com/milesburton/Arduino-Temperature-Control-Library
 * 
 */

#include <OneWire.h>
#include <DallasTemperature.h>

// Used pins definition
#define TEMP_EN_PIN   48
#define ONE_WIRE_BUS  38

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void setup() {
  pinMode(TEMP_EN_PIN,OUTPUT);digitalWrite(TEMP_EN_PIN,HIGH); // Turn-on DS18B20 sensor
  
  Serial.begin(115200);
  Serial.println("\nCEAZA-mega DS18B20 temperature sensor reading!");

  sensors.begin();
}

void loop() {
  // Temperature measurement update
  float ds18b20Temperature = get18B20Temp();

  // Show new data by serial monitor
  Serial.print("DS18B20 Temperature reading: ");
  Serial.print(ds18b20Temperature);
  Serial.println("*C");

  // Validation of data
  if(ds18b20Temperature < -126){
    Serial.println("Invalid read... Have you properly connected the DS18B20 sensor to the board?");
  }

  // wait for next temperature read
  delay(2000);
}


// Dedicated function for read data from DS18B20 connected to board terminal for this prupose 
float get18B20Temp(void){
  digitalWrite(TEMP_EN_PIN,HIGH); delay(10);  // Turn-on the sensor
  sensors.requestTemperatures();              // Update temperature value
  digitalWrite(TEMP_EN_PIN,LOW);              // Turn off the sensor
  return sensors.getTempCByIndex(0);
}
