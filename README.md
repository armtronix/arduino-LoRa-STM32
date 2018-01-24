# Arduino LoRa

[![Build Status](https://travis-ci.org/sandeepmistry/arduino-LoRa.svg?branch=master)](https://travis-ci.org/sandeepmistry/arduino-LoRa)

An [Arduino](http://arduino.cc/) library for sending and receiving data using [LoRa](https://www.lora-alliance.org/) radios.

## Compatible Hardware

 * [Semtech SX1276/77/78/79](http://www.semtech.com/apps/product.php?pn=SX1276) based boards including:
   * [Dragino Lora Shield](http://www.dragino.com/products/module/item/102-lora-shield.html)
   * [HopeRF](http://www.hoperf.com/rf_transceiver/lora/) [RFM95W](http://www.hoperf.com/rf_transceiver/lora/RFM95W.html), [RFM96W](http://www.hoperf.com/rf_transceiver/lora/RFM96W.html), and [RFM98W](http://www.hoperf.com/rf_transceiver/lora/RFM98W.html)
   * [Modtronix](http://modtronix.com/) [inAir4](http://modtronix.com/inair4.html), [inAir9](http://modtronix.com/inair9.html), and [inAir9B](http://modtronix.com/inair9b.html)

### Semtech SX1276/77/78/79 wiring

| Semtech SX1276/77/78/79 | Arduino |
| :---------------------: | :------:|
| VCC | 3.3V |
| GND | GND |
| SCK | SCK |
| MISO | MISO |
| MOSI | MOSI |
| NSS | 10 |
| NRESET | 9 |
| DIO0 | 2 |


`NSS`, `NRESET`, and `DIO0` pins can be changed by using `LoRa.setPins(ss, reset, dio0)`. `DIO0` pin is optional, it is only needed for receive callback mode. If `DIO0` pin is used, it **must** be interrupt capable via [`attachInterrupt(...)`](https://www.arduino.cc/en/Reference/AttachInterrupt).

**NOTES**:
 * Some boards (like the Arduino Nano), cannot supply enough current for the SX127x in TX mode. This will cause lockups when sending, be sure to use an external 3.3V supply that can provide at least 120mA's when using these boards.
 * If your Arduino board operates at 5V, like the Arduino Uno, Leonardo or Mega, you will need to use a level converter for the wiring to the Semtech SX127x module. Most Semtech SX127x breakout boards do not have logic level converters built-in.

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
