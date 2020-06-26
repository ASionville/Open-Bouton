# Libs
import discord
from discord.ext import commands, tasks
import subprocess
import re
from datetime import *

from config import *

# Regex pour tester la validité du message UDP
# Regex pattern to check UDP message validity
PATTERN = '^open-([1-9]|1[0-9]|2[0-4])$'

# Définition du client en bot
# Defining client as bot
client = commands.Bot(command_prefix = ".")

# Sous-programme pour la réception UDP
# Subroutine for UDP reception
reception = subprocess.Popen(['python3', 'udp_receiver.py'])

# Arrondi de l'heure actuelle à la demi-heure
# Rounding from the current hour to half an hour
def time_rounded():
    now = datetime.now()
    rounded = now - (now - datetime.min) % timedelta(minutes=30)
    return rounded.hour, rounded.minute

# Fonction principale, envoie le message Discord
# Main function, sends the Discord message
async def lab_open(current_command):
    CHANNEL = SERVER.get_channel(CHANNEL_ID)

    # On récupère le nb de demi-heures
    # We recover the number of half hours
    nb_demi_heures = current_command[-1] if len(current_command) == 6 else current_command[-2:]
    nb_demi_heures = int(nb_demi_heures)


    # On prend l'arrondi de l'heure actuelle et on ajoute les demi-heures
    # We take the rounding of the current time and add the half hours
    heures_round, minutes_round = time_rounded()

    heure_fin = heures_round + (nb_demi_heures//2)
    minutes_fin = minutes_round + 30 if nb_demi_heures % 2 else minutes_round

    # Si on dépasse les 60 minutes, on passe à l'heure d'après
    # If we exceed 60 minutes, we go to the next hour 
    if minutes_fin >= 60:
        heure_fin += 1
        minutes_fin -= 60

    # Si on dépasse les 24 heures, on passe au jour suivant
    # If we exceed 24 hours, we go to the next day 
    heure_fin = heure_fin - 24 if heure_fin >= 24 else heure_fin

    await CHANNEL.send(f"Le lab est ouvert de {heures_round}h{minutes_round if minutes_round != 0 else ''} jusqu'à {heure_fin}h{minutes_fin if minutes_fin != 0 else ''}")


# Nettoyage fichier
# Cleaning the file up
async def cleaner():
    open('data.txt', 'w').close()


# Boucle principale, toutes les 15s
# Main loop, every 15s
@tasks.loop(seconds=15.0)
async def get_data():

    try:
        # Ouverture fichier + récupération des données
        # Opening file + getting data
        with open('data.txt') as f:
            data = f.readlines()
            print(data)

            # Si fichier pas vide
            # If file is not empty
            if len(data) >= 1:

                # On récupère la commande UDP et on vérifie que la regex soit validée
                # We recover the UDP command and we check that the regex is validated
                current_command = data[-1][:-1]
                command_ok = re.match(PATTERN, current_command)

                try:
                    if command_ok:
                        await lab_open(current_command)
                    else:
                        print("Cette commande n'existe pas")
                    await cleaner()
                except Exception as error:
                    print(f"Erreur : {error}")

    except Exception as e:
        print(f"Erreur : {e}")

# Vérification du bot
# Bot check
@client.event
async def on_ready():
    print('Bot online')
    global SERVER

    SERVER = client.get_guild(SERVER_ID)


# On démarre tout
# We start everything
get_data.start()
client.run(TOKEN)