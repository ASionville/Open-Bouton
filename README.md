Open-Bouton
===========
[![GPLv3 license](https://img.shields.io/badge/License-GPLv3-blue.svg)](http://perso.crans.org/besson/LICENSE.html)
[![forthebadge](https://forthebadge.com/images/badges/made-with-c-plus-plus.svg)](https://forthebadge.com) [![forthebadge](https://forthebadge.com/images/badges/made-with-python.svg)](https://forthebadge.com)

[![N|Solid](https://www.lab-ouest.org/tiki-download_file.php?fileId=141&display)](https://www.lab-ouest.org/)

*If French is not your main language, we recommend you to check the [English Version](README_en.md)*

Explications
------------
Ce programme repose sur un Arduino ESP 8266 et un Raspberry Pi connectés via DNS

Un bouton fait maison est également à imprimer en 3D et à assembler

Dans le dossier `Raspberry` figure le code Python pour le Raspberry :
- `bot.py` : Fichier Python principal, analyse la reception UDP et gère l'envoi des messages vers Discord
- `udp_receiver.py` : Fichier Python qui gère la reception UDP et retransmet les messages à `bot.py`
- `config.py` : Fichier de configuration de la partie Raspberry
- `data.txt` : Fichier tampon dans lequel sont stockées les commandes UDP avant d'être traitées

Dans le dossier `Arduino` figure le code C++ pour l'ESP :
- `m̀ain.ino` : Fichier C++ principal, il gère le lien entre les composants ainsi que la communication UDP
- `rotary.ino` : Fichier C++ qui contrôle la reception du signal transmis par le bouton rotatif
- `neoled.ino` : Fichier C++ qui contrôle l'allumage des LEDs
- Les `[].h` : Déclaration des classes utilisées dans les fichiers `.ino` correspondants

Dans le dossier `Montage` figurent les fichiers pour l'impression 3D du bouton ainsi que le diagramme de l'électronique


---
Installation
------------
#### Prérequis

- Un [Arduino ESP 8266](https://www.banggood.com/Geekcreit-D1-Mini-NodeMcu-Lua-WIFI-ESP8266-Development-Board-Module-p-1044858.html?akmClientCountry=FR&p=RA18043558422201601Y&cur_warehouse=CN)
- Un [Raspberry Pi](https://www.amazon.fr/Raspberry-Pi-Official-Desktop-Starter/dp/B01CI5879A/)
- Un encodeur [KY-040](https://www.banggood.com/5Pcs-5V-KY-040-Rotary-Encoder-Module-AVR-PIC-p-951151.html?akmClientCountry=FR&p=RA18043558422201601Y&cur_warehouse=CN)
- Une [bande de leds]
- De quoi imprimer en 3D le bouton

---
### Partie Discord

Il va vous falloir [créer votre serveur Discord](https://www.supinfo.com/articles/single/10420-creer-serveur-discord) puis [créer votre bot](https://dylanbonjean.wordpress.com/2018/01/05/bot-discord/) (Arrêtez vous au point 7 sur ce dernier tutoriel)

N'oubliez pas de conserver l'identifiant de votre Bot et de [récupérer les identifiants du serveur et du channel](https://support.discord.com/hc/fr/articles/206346498-O%C3%B9-trouver-l-ID-de-mon-compte-utilisateur-serveur-message-) sur lequel vous voulez envoyer les messages

---
#### Partie Raspberry

- En premier lieu, il vous faudra installer Raspbian sur le raspberry, un tutoriel à ce sujet est disponible [ici](https://www.raspberrypi-france.fr/guide/installer-raspbian-raspberry-pi/)

- Il faut ensuite vérifier que Python 3 soit installé sur le raspberry, pour cela tapez `python --version` puis `python3 --version` dans un terminal et vérifiez bien qu'une de ces deux commandes renvoies un python 3.X

- Ensuite, téléchargez le contenu du dossier `Raspberry` et envoyez-le sur le Raspberry (des tutoriels sont accessibles facilement sur Internet)
- Placez tous les fichiers dans `/home/pi/udp_esp_button` (vous devrez créer le dossier)

- Vous pouvez alors modifier le fichier `config.py`, les instructions sont dans le fichier lui-même
- Dans le fichier `start.sh`, vous allez pouvoir enlever le `#` devant la ligne qui renvoyais Python 3.X précédemment

- Ensuite pour devrez [faire un serveur DNS](https://www.ionos.fr/digitalguide/serveur/configuration/comment-creer-un-serveur-dns-a-partir-dun-raspberry-pi/) sur votre Raspberry

- Accordez le droit à pi de lancer le bot avec `cd /home/pi/udp_esp_button` puis `chmod 754 start.sh`

- Pour lancer la machine, ouvrez le dossier `/home/pi/udp_esp_button` dans le terminal et tapez `./start.sh`

##### Lancer le script au démarrage

Si votre Raspberry redémarre, vous devrez relancer le script vous-même, pour pallier à cela, vous pouvez le faire se lancer au démarrage comme cela :
- Tapez `sudo nano /etc/rc.local` dans un terminal
- Avant la dernière ligne (`exit 0`), tapez `bash /home/pi/udp_esp_button/start.sh`
- Sauvegardez et fermez le fichier

---
#### Partie Arduino

- Installez la librairie [WifiManager](https://github.com/tzapu/WiFiManager)
- Téléchargez le dossier `Arduino` et ouvrez le fichier `main/main.ino` qu'il contient dans l'[IDE Arduino](https://www.arduino.cc/en/Main/Software).
- Dans ce fichier, changez si vous le voulez 
    - Le port de communication UDP à la ligne 16
    - L'IP du Raspberry Pi à la ligne 20
- Après avoir vérifié que la modèle de carte est bien défini, uploadez le fichier dans l'ESP, il détectera et uploadera tout seul chacun des fichiers annexes.
---
#### Partie Electronique
 - Branchez la bande de LEDs et l'encodeur comme indiquée sur l'image ci-dessous : 
 ![`Montage/schema.png`](Montage/schema.png "Schéma Electronique")
 - Une alimentation de 5V est nécessaire au bon fonctionnement du système, n'importe quelle alimentation micro-usb type chargeur de portable suffira (le système total a été testé sur 5V à environ 500mA)

###### Photo du système final
![Image du bouton final](Montage/bouton.png)

---
Utilisation
-----------

#### Allumage du bot
Pour allumer le bot, vous pouver faire `./home/pi/udp_esp_button/start.sh`

Pour éteindre le bot, envoyez par UDP ceci : `stopbot`

---
License
------
La [`license`](LICENSE) appliquée à ce projet est une License GNU Public License v3
Cette license autorise le partage, la modification et la redistribution du projet sous ces conditions :
    - Le code source de votre projet doit être disponible gratuitement
    - Votre projet doit comporter la license GPLv3 ainsi qu'une mention de copyright en notre faveur
    - Les modifications apportées doivent être clairement énoncées
Toutes les spécifications de cette license sont écrites en anglais dans le fichier éponyme.

---
En cas de problème
------------------
En cas de problème, n'hésitez pas à nous contacter par mail :
- aubin.sionville@orange.fr
- cle.chec@laposte.net

Ou sur notre [serveur Discord](https://discord.gg/fvUzJbk)-

---
Nous soutenir
-------------
Adresse BTC : `3Hkvtm6uYy27X76buSNepsQcZ77692cLMm`
