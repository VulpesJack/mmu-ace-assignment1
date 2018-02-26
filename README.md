# Advanced Computer Engineering - Assignment 1 - MMU
Sharing code for the ACE first assignment, most code will be C++.

## Function of Project
This project is a home automation system built on the Nordic Semiconductor [nRF51 DK](https://www.nordicsemi.com/eng/Products/nRF51-DK), an ARM mbed development kit. The assignment has asked for the following features:
* Intrusion detection
* Temperature sensing
* Light sensing
* Ability to switch heating on and off
* Ability to switch lights on and off
* Integral display of system data
* Remote control of key equipment

## Components Used in Project
The following components are being used in this project. The text in parenthesis is the function of each part. Where possible, a link to the part's product page has been provided.
* [Nordic Semiconductor nRF51-DK](https://www.nordicsemi.com/eng/Products/nRF51-DK) (Acts as a brain for the whole system, interfaces with mobile devices)
* [keyestudio Single Relay Module](http://www.keyestudio.com/keyestudio-single-relay-module-compatible-with-arduino.html) (Will be used to switch mains powered devices, such as lights and heaters, on and off)
  * [Songle SRD-05VDC-SL-C Relay](http://www.circuitbasics.com/wp-content/uploads/2015/11/SRD-05VDC-SL-C-Datasheet.pdf) (The relay used on the keyestudio module)
* [keyestudio Photocell Sensor](http://www.keyestudio.com/keyestudio-photocell-sensor-for-arduino.html) (Used to measure the ambient light of the room)
* [DHT11 Temperature and Humidity Sensor](https://akizukidenshi.com/download/ds/aosong/DHT11.pdf) (Used to measure the temperature and humidity within the room)
* [Parallax PIR Sensor (Rev B)](https://www.parallax.com/product/555-28027) (Used for intrusion detection)

Additional components used within this project include:

* [Xiaomi Redmi Note 3](http://www.mi.com/en/note3/) (Android phone used for bluetooth testing)
