/*
 * This sketch is to show you an easy way to set and get the date, time and RTC remperature.
 * Feel free to use any other library or program to comumunicate with the built in DS3231MZ+ RTC.
 * 
 * Is highly recommend power the RTC by pin D36 when request or send data to avoid a fast discharge of 
 * integrated CR2032 coin cell RTC backup battery.
 * 
 * For more details about CEAZAmega board you can see the repository.
 * https://github.com/CEAZAmet/CEAZA-MEGA
 * 
 * This scketch id based on the RTClib library from Adafruit to simplify the program.
 * https://github.com/adafruit/RTClib
 * 
 */

#include "RTClib.h"

#define VRTC_EN_PIN   36

RTC_DS3231 rtc;


void setup() {
  // Set the RTC power pin as output
  pinMode(VRTC_EN_PIN,OUTPUT);digitalWrite(VRTC_EN_PIN,HIGH); // Turn-on the RTC

  Serial.begin(115200);
  Serial.println("\nCEAZA-mega RTC read-write!");

  // Start the RTC module
  Serial.print("RTC...");
  if (! rtc.begin()) {
    Serial.println("NOK");
    Serial.flush();
    abort();
  }else{
    Serial.println("OK");
  }

  /* 
   *  If the RTC was reset due power faliure, automaticly set date and time
   *  when the scketch was compiled
  */
  if (rtc.lostPower()) {
    Serial.println("RTC lost power, let's set the time!");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }

}

void loop() {
  // Get updated date and time from RTC
  digitalWrite(VRTC_EN_PIN,HIGH);delay(10); // Turn-on RTC
  DateTime now = rtc.now();                 // Request data to RTC
  digitalWrite(VRTC_EN_PIN,LOW);            // Turn-off RTC

  // Show date and time by serial monitor
  Serial.println();
  Serial.print(now.year(), DEC);
  Serial.print('/');
  Serial.print(now.month(), DEC);
  Serial.print('/');
  Serial.print(now.day(), DEC);
  Serial.print(" ");
  Serial.print(now.hour(), DEC);
  Serial.print(':');
  Serial.print(now.minute(), DEC);
  Serial.print(':');
  Serial.print(now.second(), DEC);
  Serial.println();

  // Show RTC temperature by serial monitor 
  Serial.print("RTC Temperature: ");
  Serial.print(rtc.getTemperature());
  Serial.println("*C");

  
  delay(5000);
}
