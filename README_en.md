ESP-Raspberry Clock Entrance Button
===================================

[![N|Solid](https://www.lab-ouest.org/tiki-download_file.php?fileId=141&display)](https://www.lab-ouest.org/)

*If you are French, we recommend you to check the [French Version](README.md)*

Explanations
------------
This program is based on an Arduino ESP 8266 and a Raspberry Pi connected via DNS

A homemade button is also to 3D print and assemble

In the `Raspberry` folder is the Python code for the Raspberry:
* `bot.py`: Main Python file, analyzes UDP reception and manages the sending of messages to Discord
* `udp_receiver.py`: Python file which manages UDP reception and forwards messages to` bot.py`
* `config.py`: Configuration file for the Raspberry part
* `data.txt`: Buffer file in which the UDP commands are stored before being processed

In the `Arduino` folder is the C ++ code for ESP:
* `m̀ain.ino`: Main C ++ file, manages the link between the components as well as UDP communication
* `rotary.ino`: C ++ file which controls the reception of the signal transmitted by the rotary button
* `neoled.ino`: C ++ file which controls the lighting of the LEDs
* The `[] .h`: Declaration of the classes used in the corresponding` .ino` files

In the `Montage` folder are the files to 3D print the button as well as the electronics diagram



Installation
------------
#### Prerequisites

* An [Arduino ESP 8266](https://www.banggood.com/Geekcreit-D1-Mini-NodeMcu-Lua-WIFI-ESP8266-Development-Board-Module-p-1044858.html?akmClientCountry=FR&p=RA18043558422201601Y&cur_warehouse=CN)
* A [Raspberry Pi](https://www.amazon.fr/Raspberry-Pi-Official-Desktop-Starter/dp/B01CI5879A/)
* A encoder: [KY-040](https://www.banggood.com/5Pcs-5V-KY-040-Rotary-Encoder-Module-AVR-PIC-p-951151.html?akmClientCountry=FR&p=RA18043558422201601Y&cur_warehouse=CN)
* A [led strip]
* Something to 3D print the button


#### Raspberry Part

- First, you will need to install Raspbian on the raspberry, a tutorial on this subject is available [here](https://www.howtoforge.com/tutorial/howto-install-raspbian-on-raspberry-pi/)

- You must then verify that Python 3 is installed on the raspberry, for that type `python --version` then` python3 --version` in a terminal and verify that one of these two commands returns a python 3.X

- Then download the content of the `Raspberry` folder and send it to the Raspberry (tutorials are easily accessible on the Internet)
- Place all files in `/home/pi/udp_esp_button` (you will have to create the folder)

- You can then modify the file `config.py`, the instructions are in the file itself
- In the file `start.sh`, you will be able to put a` # `in front of the line which is ** not ** the one which returned Python 3.X previously

- Then you will have to [make a DNS server](https://www.howtoforge.com/tutorial/howto-install-raspbian-on-raspberry-pi/) on your Raspberry

- To start the script, open the `/home/pi/udp_esp_button` folder in the terminal and type`./start.sh`

##### Startup on boot

If your Raspberry reboots, you will have to relaunch the script yourself, to remedy this, you can it launch at startup like this:
* Type `sudo nano/etc/rc.local` in a terminal
* Before the last line (`exit 0`), type` bash /home/pi/udp_esp_button/start.sh`
* Save and close the file
