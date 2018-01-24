# Arduino LoRa For STM32F103CB

[![Build Status](https://travis-ci.org/sandeepmistry/arduino-LoRa.svg?branch=master)](https://travis-ci.org/sandeepmistry/arduino-LoRa)

An [Arduino](http://arduino.cc/) library for sending and receiving data using [LoRa](https://www.lora-alliance.org/) radios.

### Semtech SX1276/77/78/79 wiring

| Semtech SX1276/77/78/79 | Arduino(STM32F103CB) |
| :---------------------: | :------:|
| VCC | 3.3V |
| GND | GND |
| SCK | SCK |
| MISO | MISO |
| MOSI | MOSI |
| NSS | PA4 |
| NRESET | PC13 |
| DIO0 | PA1 |
| DIO1 | PB13 |
| DIO2 | PB12 |

| Charger Header J4 | Battery 3.7V Li  |
| :---------------------: | :------:|
| 1 | + |
| 2 | - |

| Charge Value| Arduino(STM32F103CB)  |
| :---------------------: | :------:|
| Divinder 430K/1.5M | PA0 |


### Board Header Details

| Header J1 Pins | Arduino(STM32F103CB) |
| :---------------------: | :------:|
| 1 | 3.3V |
| 2 | PB9 |
| 3 | PB8 |
| 4 | GND |
| 5 | GND |
| 6 | PB1 |
| 7 | PB0 |
| 8 | GND |
| 9 | PA2 |
| 10 | PA3|
| 11 | PB10 |
| 12 | PB11 |
| 13 | GND |

| Header J2 Pins | Arduino(STM32F103CB) |
| :---------------------: | :------:|
| 1 | 5V |
| 2 | GND |
| 3 | PB5 |
| 4 | PB4 |
| 5 | PB3 |
| 6 | PA15 |
| 7 | PA12|
| 8 | PA11|
| 9 | PA8|
| 10 | PB15|
| 11 | PB14 |
| 12 | GND |
| 13 | GND |

| Header J3 Pins | Arduino(STM32F103CB) |
| :---------------------: | :------:|
| 1 | 3.3V |
| 2 | SWIO |
| 3 | SWCLK|
| 4 | GND |


| Header J5 Pins | Arduino(STM32F103CB) |
| :---------------------: | :------:|
| 1 | 3.3V |
| 2 | GND |
| 3 | PB6/SCL |
| 4 | PB7/SDA |

| Header J7 Row One Pins | Arduino(STM32F103CB) | Header J7 Row Two Pins | Arduino(STM32F103CB) |
| :---------------------: | :------:|:---------------------:|:------:|
| 1 | 3.3V | 2 |3.3V |
| 3 | BOOT0 | 4 | BOOT1
| 5 | GND | 6 | GND |

**NOTES**:
While Programming through on board USB (CH340 USB to UART Driver required in windows) connected to STM32F103CB's PA10/USART1_RX and PA9/USART1_TX select the following in Arduino IDE

|Board :Generic STM32F103C Series|
|Variant : STM32F103CB(20k RAM,128k Flash)|
|CPU Speed:72MHz Normal|
|Upload Meathod: Serial|
|Port should be picked as per windows (Com 1,2,3 etc)| 


To add STM32 board to arduino ide use 
https://github.com/rogerclarkmelbourne/Arduino_STM32

## Header J7 should be set as following for programming 
Pin 1 --- Pin 3 Short using Jumper 
Pin 4 --- Pin 6 Short using Jumper
Press reset pin S3 before pressing upload button 

## Header J7 should be set as following to run application program
Pin 3 --- Pin 5 Short using Jumper 
Pin 4 --- Pin 6 Short using Jumper
Press reset pin S3 after this  


`NSS`, `NRESET`, and `DIO0` pins can be changed by using `LoRa.setPins(ss, reset, dio0)`. `DIO0` pin is optional, it is only needed for receive callback mode. If `DIO0` pin is used, it **must** be interrupt capable via [`attachInterrupt(...)`](https://www.arduino.cc/en/Reference/AttachInterrupt).


## Installation

### Using the Arduino IDE Library Manager

1. Choose `Sketch` -> `Include Library` -> `Manage Libraries...`
2. Type `LoRa` into the search box.
3. Click the row to select the library.
4. Click the `Install` button to install the library.

### Using Git

```sh
cd ~/Documents/Arduino/libraries/
git clone https://github.com/sandeepmistry/arduino-LoRa LoRa
```

## API

See [API.md](API.md).

## Examples

See [examples](examples) folder.

## FAQ

**1) Initilizating the LoRa radio is failing**

Please check the wiring you are using matches what's listed in [Semtech SX1276/77/78/79 wiring](#semtech-sx1276777879-wiring). You can also use `LoRa.setPins(ss, reset, dio0)` to change the default pins used. Some logic level converters cannot operate at 8 MHz, you can call `LoRa.setSPIFrequency(frequency)` to lower the SPI frequency used by the library. Both API's must be called before `LoRa.begin(...)`.

**2) Can other radios see the packets I'm sending?**

Yes, any LoRa radio that are configured with the same radio parameters and in range can see the packets you send.

**3) Is the data I'm sending encrypted?**

No, all data is sent unencrypted. If want your packet data to be encrypted, you must encrypt it before passing it into this library, followed by decrypting on the receiving end.

**4) How does this library differ from LoRaWAN libraries?**

This library exposes the LoRa radio directly, and allows you to send data to any radios in range with same radio parameters. All data is broadcasted and there is no addressing. LoRaWAN builds on top of LoRA, but adds addressing, encryption, and additional layers. It also requires a LoRaWAN gateway and LoRaWAN network and application server.



## License

This libary is [licensed](LICENSE) under the [MIT Licence](http://en.wikipedia.org/wiki/MIT_License).
# arduino-LoRa-STM32
