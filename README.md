SparkX Qwiic ADC ADS1219 - 24-Bit 4-Channel
========================================

![SparkX Qwiic 24-Bit ADC - 4-Channel ADS1219](https://cdn.sparkfun.com/r/600-600/assets/parts/2/3/7/6/5/23455-Qwiic-24-bit-ADC-4-channel-Feature.jpg)

[*SparkX Qwiic 24-Bit ADC - 4-Channel ADS1219 (SPX-23455)*](https://www.sparkfun.com/products/23455)

Qwiic breakout board for the ADS1219 4-channel 24-bit ADC from TI.

A lot of the time you just need to add more analog inputs to solve a problem. It happens. The SparkX Qwiic 24-Bit ADC can provide four channels of I<sup>2</sup>C controlled ADC input to your Qwiic enabled project. These channels can be used as single-ended inputs, or in pairs for differential inputs, running at sample rates of up to 1kHz. What makes this ADC even more powerful is that it has a programmable x1 or x4 gain amplifier that lets you "zoom in" on a very small change in analog voltage (but will still effect your input range and resolution). Utilizing our handy Qwiic system, it is easy to connect it to the rest of your system. However, we have broken out 0.1"-spaced pads too in case you prefer to use a breadboard. The analog inputs and reference pins are all broken out on 0.1"-spaced pads too. This board does not have screw terminals - there was not enough room!

The ADS1219 can use its own internal 2.048V voltage reference for measurements, or you can provide your own reference via the REFP and REFN breakout pads. You can also provide your own VDDA (AVDD) by opening the jumper and connecting a voltage to the VDDA pad. This ADC board has eight address jumpers that let you choose one of sixteen unique addresses (0x40 to 0x4F). With these, you can connect up to sixteen of these on the same I<sup>2</sup>C bus and have 64 channels of ADC. The maximum resolution of the converter is 24-bits, corresponding to 244.14nV per count at a gain of x1. At a gain of x4, the resolution is 61.04nV per count. Note: the _effective_ resolution is limited to 20-bits.

Repository Contents
-------------------

* [**/Documents**](./Documents/) - TI datasheet
* [**/Hardware**](./Hardware/) - KiCad design files (_pcb, _sch), Schematic (PDF)
* [**/Hardware/Production**](./Hardware/Production/) - Production panel files (_pcb, gerbers)
* [**/Production_Test**](./Production_Test/) - The Arduino sketch we use to test the board

Documentation
--------------

* [**Arduino Library**](https://github.com/sparkfun/SparkFun_ADS1219_Arduino_Library) - Arduino library for the ADS1219.

License Information
-------------------

This product is _**open source**_! 

Please review the LICENSE.md file for license information. 

If you have any questions or concerns on licensing, please visit the [SparkFun Forum](https://forum.sparkfun.com/viewforum.php?f=152) and post a topic. For more specific questions about this board, please visit this section of the forum: [SparkFun Forums: SparkX](https://forum.sparkfun.com/viewforum.php?f=123)

Distributed as-is; no warranty is given.

- Your friends at SparkFun.

