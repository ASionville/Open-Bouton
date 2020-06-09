#Librairies
import discord
from discord.ext import commands, tasks
import subprocess

#Variables DISCORD
TOKEN = "NjkwNTM3NzIzNzA1OTUwMjM4.XnS31Q.nUBoW61fgZfgo3Zt0P7jrjf7gZU"
client = commands.Bot(command_prefix = ".")

#Liste Commandes disponibles via UDP
available_commands = {'hello' : "hello()"}

#Subprocess pour reception UDP
reception = subprocess.Popen(['python', 'udp_receiver.py'])

#Nettoyage fichier
async def cleaner():
    with open('data.txt') as f:
        print(f.write(""))

#Programme principal, boucle 30s
@tasks.loop(seconds=30.0)
async def get_data():

    try:
        #Ouverture fichier + get data
        with open('data.txt') as f:
            data = f.readlines()
            print(data)

            #Si fichier pas vide
            if len(data) >= 1:

                current_command = data[-1][:-1]
                try:
                    #Si commande existe
                    await exec(available_commands[current_command])
                    await cleaner

                except KeyError:
                    print("Cette commande n'existe pas")
                except Exception as error:
                    print(f"Erreur inconnue : {error}")

    except Exception as e:
        print(f"Erreur : {e}")

#Check up du bot
@client.event
async def on_ready():
    print('Bot online')

#On démarre tout
get_data.start()
client.run(TOKEN)