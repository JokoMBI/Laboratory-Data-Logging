#include <Wire.h>
#include <Adafruit_AM2315.h>

/***************************************************
 * Driver to read out the AM2315 using the Adafruit_AM2315 lib and
 * send data to a RasPi via serial interface
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
float t, h;


void setup() {
  Serial.begin(9600);
  Serial.println("AM2315 Test!");

  if (! am2315.begin()) {
     Serial.println("Sensor not found, check wiring & pullups!");
     while (1);
  }
}

void loop() {


    am2315.readTemperatureAndHumidity(t,h);
    Serial.println("Temp: "+String(t));
    Serial.println("Hum: "+String(h));

    
//    Serial.print("Temp: "); 
//    Serial.println(am2315.readTemperature());
//    delay(30);
//    Serial.print("Hum: "); 
//    Serial.println(am2315.readHumidity());


  delay(1000);
}
