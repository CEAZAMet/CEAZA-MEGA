/*
 * This sketch is to show you how to write data in a microSD card in CEAZA mega board.
 * The built in microSD socket must be powered by D436 pin.
 * 
 * For more details about CEAZAmega board you can see the repository.
 * https://github.com/CEAZAmet/CEAZA-MEGA
 * 
 */

#include <SPI.h>
#include <SD.h>

// Used pins definition
#define VUSD_EN_PIN   43
#define USD_SS_PIN    53

// Data line counter
int count = 0;

void setup() {
  pinMode(VUSD_EN_PIN,OUTPUT);digitalWrite(VUSD_EN_PIN,LOW); // Turn-on microSD card

  Serial.begin(115200);
  Serial.println("\nCEAZA-mega microSD data write!");

  // microSD init
  Serial.print("SD...");
  delay(100);                   // Is recommended wait a time after turn on the microSD due some cards require some initialization time.
  if (!SD.begin(USD_SS_PIN)) {  // Init the microSD
    Serial.println("NOK"); 
    while(1);                   // If there is a problem with the microSD do nothing else
  }else{
    Serial.println("OK");
  }
  Serial.flush();digitalWrite(VUSD_EN_PIN,HIGH);  // Turn-off microSD for energy save

}

void loop() {
  // Update new data line
  String dataString = "Hello ";
  dataString += count;
  count++;

  digitalWrite(VUSD_EN_PIN,LOW); delay(100);  // Tun-on microSD
  
  SD.begin(USD_SS_PIN);                                   // Is necesary to init the microSD after Turn-on
    File dataFile = SD.open("datalog.txt", FILE_WRITE);   // Open data file
  if (dataFile) {
    dataFile.println(dataString);                         // Save new data line in the file
    dataFile.close();                                     // close data file
    Serial.println(dataString);                           // Show by serial monitor last data line saved
  }
  else {
    Serial.println("error opening datalog.txt");          // Error message when the microSD is not able to write
  }
  
  delay(100);digitalWrite(VUSD_EN_PIN,HIGH);              // Turn-off microSD to save energy

  delay(5000);
}
