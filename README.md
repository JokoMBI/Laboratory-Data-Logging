# Laboratory-Data-Logging
project for measuring ambient conditions from a laboratory using Raspberry PI and share them via Ethernet for logging and evaluating

Sensor types:
- AM2315 (humidity, temperature)
- ...

Controllers:
- Raspberry Pi 3 Model B for collecting data via serial interface (USB) and sharing it via Ethernet
- Arduino Nano as an interface for the AM2315 and the RasPi (the I2C lib for the RaspPi to read out the AM2315 directly via the bus is still buggy and you can only use one AM2315 on the bus because they all have the same hardware adress)
- ...

