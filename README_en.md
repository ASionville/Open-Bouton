Open-Button
===========
[![GPLv3 license](https://img.shields.io/badge/License-GPLv3-blue.svg)](LICENSE)
[![forthebadge](https://forthebadge.com/images/badges/made-with-c-plus-plus.svg)](Arduino/main/main.ino) [![forthebadge](https://forthebadge.com/images/badges/made-with-python.svg)](Raspberry/bot.py)

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

---
### Discord part

You will need to [create a Discord Bot and a server](https://realpython.com/how-to-make-a-discord-bot-python/)(Stop before the `How to Make a Discord Bot in Python
`)

Do not forget to keep the identifier of your Bot and to [recover the identifiers of the server and the channel](https://support.discord.com/hc/en-us/articles/206346498-Where-can-I-find-my-User-Server-Message-ID-) to which you want to send messages

#### Raspberry Part

- First, you will need to install Raspbian on the raspberry, a tutorial on this subject is available [here](https://www.howtoforge.com/tutorial/howto-install-raspbian-on-raspberry-pi/)

- You must then verify that Python 3 is installed on the raspberry, for that type `python --version` then` python3 --version` in a terminal and verify that one of these two commands returns a python 3.X

- Then download the content of the `Raspberry` folder and send it to the Raspberry (tutorials are easily accessible on the Internet)
- Place all files in `/home/pi/open_bouton` (you will have to create the folder)

- You can then modify the file `config.py`, the instructions are in the file itself
- In the file `start.sh`, you will be able to remove the `#` in front of the line which returned Python 3.X previously

- Then you will have to [make a DNS server](https://www.howtoforge.com/tutorial/howto-install-raspbian-on-raspberry-pi/) on your Raspberry

- Grant the right to pi to launch the bot with `cd/home/pi/open_bouton` then` chmod 754 start.sh`

- To start the script, open the `/home/pi/open_bouton` folder in the terminal and type`./start.sh`

##### Startup on boot

If your Raspberry reboots, you will have to relaunch the script yourself, to remedy this, you can it launch at startup like this:
* Type `sudo nano/etc/rc.local` in a terminal
* Before the last line (`exit 0`), type` bash /home/pi/open_bouton/start.sh`
* Save and close the file

---
#### Arduino Part

- Install the [WifiManager](https://github.com/tzapu/WiFiManager) lib
- Download the `Arduino` folder and open the file `main/main.ino` in the [Arduino IDE](https://www.arduino.cc/en/Main/Software).
- In this file, you may change :
    - The UDP communication port on line 16
    - The Raspberry Pi local IP on line 20
- After checking that the card model is well defined, upload the main file to the ESP, it will detect and upload all of the additional files on its own.
---

#### Electronic Part
 - Connect the LED strip and the encoder as shown in the image below:
 ![`Montage/schema.png`](Montage/schema.png "Schéma Electronique")
 - A 5V power supply is necessary for the proper functioning of the system, any micro-usb power supply type laptop charger will suffice (the total system has been tested on 5V at around 500mA)

###### Photo of the final system
![Photo of the final system](Montage/bouton.png)

---
License
------

The [`license`] (LICENSE) applied to this project is a GNU Public License v3
This license authorizes sharing, modifying and redistributing the project under these conditions:
     - The source code of your project must be available for free
     - Your project must include the GPLv3 license and a copyright notice in our favor
     - Changes made must be clearly stated
All the specifications of this license are written in the eponymous file.


---
In case of problem
------------------
In case of problems, do not hesitate to contact us by email:
- aubin.sionville@orange.fr
- cle.chec@laposte.net

Or on our [Discord server](https://discord.gg/fvUzJbk)-

---
Support us
----------
BTC Adress: `3Hkvtm6uYy27X76buSNepsQcZ77692cLMm`
