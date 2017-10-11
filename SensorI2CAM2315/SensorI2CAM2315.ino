#include <Wire.h>
#include <Adafruit_AM2315.h>

/***************************************************
 * Driver to read out the AM2315 using the Adafruit_AM2315 lib and
 * send data to a RasPi via serial interface
 * the program is waiting for a character from the RasPi, 
 * getting a 't' causes sending back the temperature in a String
 * getting a 'h' causes sending back the humidity in a String
 * 
 * Program bases on the example program "am2315test" (view text below)
 * 
  This is an example for the AM2315 Humidity + Temp sensor

  Designed specifically to work with the Adafruit BMP085 Breakout 
  ----> https://www.adafruit.com/products/1293

  These displays use I2C to communicate, 2 pins are required to  
  interface
  Adafruit invests time and resources providing this open source code, 
  please support Adafruit and open-source hardware by purchasing 
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.  
  BSD license, all text above must be included in any redistribution
 ****************************************************/

// Connect RED of the AM2315 sensor to 5.0V
// Connect BLACK to Ground
// Connect WHITE to i2c clock - on '168/'328 Arduino Uno/Duemilanove/etc thats Analog 5
// Connect YELLOW to i2c data - on '168/'328 Arduino Uno/Duemilanove/etc thats Analog 4

Adafruit_AM2315 am2315;
float t,  //temperature variable to send
      h;  //humidity variable to send

int c;

void setup() {
  Serial.begin(9600);
  Serial.println("new AM2315 module"); //new sensor module AM2315 connected

  if (! am2315.begin()) {
     Serial.println("Sensor not found, check wiring!");
     while (1);
  }
}

void loop() {

  if (Serial.available() > 0) {
    // get incoming byte:
    c = Serial.read();
      
      switch (c) {
          case 't':
            Serial.println(am2315.readTemperature());
            break;
          case 'h':
            Serial.println(am2315.readHumidity());
            break;
          default:
            // if nothing else matches, do the default
            // default is optional
          break;
        }
  }

}
