# Welcome to CEAZA mega!
A low power consumption, reliable and expandable Arduino-derivative datalogger for scientists

![alt text](/Images/CM_PINOUT.PNG?raw=true "CEAZA MEGA Board")


# What is the CEAZA mega?
Is a new simple, robust and expandable datalogger Arduino derivative board based in typical maker’s community integrations.  The board was designed and implemented taking into account requirements as low consumption, expandability and integration. Different tests where made so reliability in low temperatures and low energy needs are satisfied. 
Is expected that the scientific community can add this board to their tool set, as this board solves the energy problem and present an easy transition from handmade logger integrations.

CEAZA mega board integrate:
- ATMEGA2560 8-bit microcontroller
- Arduino mega 2560 bootloader for easy Arduino Ide compatibility
- A real time clock (RTC)
- A microSD card socket for data storage
- USB/Serial driver connected to UART0 for program as an Arduino mega or computer serial communication
- Serial RS-232 driver (connected to UART1) 
- Controlled high frequency (2MHz) step down switching regulator MP2451DT-LF-Z configured to deliver 5V and up to 600mA for external sensor
- Built in 10Kohm NTC thermistor for PCB temperature monitoring
- Power source system voltage monitor
- Terminal for direct connection with DS18B20 1-wire digittal temperature sensor
- 3 LEDs on board and external duplicate conection for two of those LEDs
- an ISCP terminal to program with external programer
- 3 expansion terminal for direct wires soldering or easy plug/unplug expansion boards for CEAZA MEGA

Furthermore, all integrated devices, except the main MCU uses a firmware controlled switched power supply in order to optimize de power consumption.


## Documentation
A comprehensive documentation for well undertand, use or modify the CEAZA MEGA board is available in our Wiki. In adition, we share with you the schematics diagrams, adns Arduino example codes.

## Quickstart guide
Plug a 6.5V to 14V dc power supply in the power terminal and connect CEAZA MEGA main board system to the host PC by mini-USB connector, open the Arduino ide software, select the Arduino Mega board and the correspondign COM port.
Open any of examples scketches and upload to the board.


# Contact and support
For all kinds of inquiries, please contact me to my e-mail address: adrian.gallardo@ceaza.cl

# Contributing
You are welcome to contribute to the development or improvement of CEAZA MEGA hardware design or example application codes. Feel free to submit a new pull request via github.

# Academic Context

# Licensing
MIT License

Copyright (c) 2021 CEAZA

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

# Disclaimer
Use CEAZA MEGA board and examples code at your own risk. We do not encourage any malicious use of our board.
