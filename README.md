ESP-Raspberry Clock Entrance Button
===================================

[![N|Solid](https://www.lab-ouest.org/tiki-download_file.php?fileId=141&display)](https://www.lab-ouest.org/)

*If French is not your main language, we recommend you to check the English Version*

Explications
------------
Ce programme repose sur un Arduino ESP 8266 et un Raspberry Pi connectés via DNS
Un bouton fait maison est également à imprimer en 3D et à assembler

Dans le dossier `Raspberry` figure le code Python pour le Raspberry :
* `bot.py` : Fichier Python principal, analyse la reception UDP et gère l'envoi des messages vers Discord
* `udp_receiver.py` : Fichier Python qui gère la reception UDP et retransmet les messages à `bot.py`
* `config.py` : Fichier de configuration de la partie Raspberry
* `data.txt` : Fichier tampon dans lequel sont stockées les commandes UDP avant d'être traitées

Dans le dossier `Arduino` figure le code C++ pour l'ESP :
* `m̀ain.ino` : Fichier C++ principal, il gère le lien entre les composants ainsi que la communication UDP
* `rotary.ino` : Fichier C++ qui contrôle la reception du signal transmit par le bouton rotatif
* `neoled.ino` : Fichier C++ qui contrôle l'allumage des LEDs
* Les `[].h` : Déclaration des classes utilisées dans les fichiers `.ino` correspondants

Dans le dossier `Montage` figurent les fichiers pour l'impression 3D du bouton ainsi que le diagramme de l'électronique



Installation
------------
#### Prérequis

* Un [Arduino ESP 8266](https://www.banggood.com/Geekcreit-D1-Mini-NodeMcu-Lua-WIFI-ESP8266-Development-Board-Module-p-1044858.html?akmClientCountry=FR&p=RA18043558422201601Y&cur_warehouse=CN)
* Un [Raspberry Pi](https://www.amazon.fr/Raspberry-Pi-Official-Desktop-Starter/dp/B01CI5879A/)
* Un encodeur [KY-040](https://www.banggood.com/5Pcs-5V-KY-040-Rotary-Encoder-Module-AVR-PIC-p-951151.html?akmClientCountry=FR&p=RA18043558422201601Y&cur_warehouse=CN)
* Une [bande de leds]
* De quoi imprimer en 3D le bouton


#### Partie Raspberry

- En premier lieu, il vous faudra installer Raspbian sur le raspberry, un tutoriel à ce sujet est disponible [ici](https://www.raspberrypi-france.fr/guide/installer-raspbian-raspberry-pi/)⋅⋅

- Il faut ensuite vérifier que Python 3 soit installé sur le raspberry, pour cela tapez `python --version` puis `python3 --version` dans un terminal et vérifiez bien qu'une de ces deux commandes renvoies un python 3.X

- Ensuite, téléchargez le contenu du dossier `Raspberry` et envoyez-le sur le Raspberry (des tutoriels sont accessibles facilement sur Internet)
- Placez tous les fichiers dans `/home/pi/udp_esp_button` (vous devrez créer le dossier)

- Vous pouvez alors modifier le fichier `config.py`, les instructions sont dans le fichier lui-même
- Dans le fichier `start.sh`, vous allez pouvoir mettre un `#` devant la ligne qui n'est **pas** celle qui renvoyais Python 3.X précédemment

- Ensuite pour devrez [faire un serveur DNS](https://www.ionos.fr/digitalguide/serveur/configuration/comment-creer-un-serveur-dns-a-partir-dun-raspberry-pi/) sur votre Raspberry

- Pour lancer la machine, ouvrez le dossier `/home/pi/udp_esp_button` dans le terminal et tapez `./start.sh`

##### Lancer le script au démarrage

Si votre Raspberry redémarre, vous devrez relancer le script vous-même, pour pallier à celà, vous pouvez le faire se lancer au démarrage comme celà :
* Tapez `sudo nano /etc/rc.local` dans un terminal
* Avant la dernière ligne (`exit 0`), tapez `bash /home/pi/udp_esp_button/start.sh`
* Sauvegardez et fermez le fichier
