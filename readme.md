# ESP-01 Move MQTT

## ESP-01

https://docs.platformio.org/en/stable/boards/espressif8266/esp01.html

## ESP-32

https://github.com/espressif/arduino-esp32

https://docs.platformio.org/en/stable/boards/espressif32/esp32dev.html

## FT232

## MPU-6050

## WiFi

https://github.com/arduino-libraries/WiFi

## ArduinoJson

https://arduinojson.org/

## ESP-01 Wiring

```
3.3V -> VC
GND -> GND
RX -> TX
TX -> RX
```

## ESP-01 Flashing

https://edistechlab.com/esp8266-01-einfach-erklaert/?v=3a52f3c22ed6

Default setup for connecting a FT232 to an ESP-01:

```
3.3V -> VC
GND -> GND
RX -> TX
TX -> RX
```

Easiest setup for flashing an ESP-01:

```
VCC -> 10k resistor -> CHPD
GND -> GPO (Flashmode)
GND -> RST (Reset)
```

![Sketch to flash an ESP-01](sketch-flash_bb.png)

## ESP-01 Regular Serial Output

`monitor_speed = 115800`

```
Initializing sensors
```

## ESP-01 Boot Serial Output

`monitor_speed = 74880`

```
load 0x4010f000, len 3424, room 16 
tail 0
chksum 0x2e
load 0x3fff20b8, len 40, room 8 
tail 0
chksum 0x2b
csum 0x2b
v000490b0
~ld
rf cal sector: 124
freq trace enable 0
rf[112] : 0
```

## ESP-01 After Connecting to WLAN Serial Output

```
ets Jan  8 2013,rst cause:4, boot mode:(3,3)

wdt reset
load 0x4010f000, len 3424, room 16 
tail 0
chksum 0x2e
load 0x3fff20b8, len 40, room 8 
tail 0
chksum 0x2b
csum 0x2b
v00047930
```

https://www.esp8266.com/viewtopic.php?f=28&t=21249

https://arduino-esp8266.readthedocs.io/en/latest/boards.html#boot-messages-and-modes

https://stackoverflow.com/questions/70450459/how-to-solve-wdt-reset-rst-cause4-boot-mode3-6-nodemcu-1-0-esp-8266

https://arduino-esp8266.readthedocs.io/en/3.0.1/faq/a02-my-esp-crashes.html

https://www.mikrocontroller.net/topic/413744

https://www.mikrocontroller.net/topic/408026#new

https://forum.arduino.cc/t/watchdog-error/656667/29

## ESP-32 Wiring

https://randomnerdtutorials.com/esp32-mpu-6050-accelerometer-gyroscope-arduino/

## I2C

https://wolles-elektronikkiste.de/i2c-schnittstellen-des-esp32-nutzen 

## Related Projects

https://wolles-elektronikkiste.de/mpu6050-beschleunigungssensor-und-gyroskop

https://github.com/adafruit/Adafruit_MPU6050/tree/master