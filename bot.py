#Librairies
import discord
from discord.ext import commands, tasks
import subprocess

#Variables DISCORD
TOKEN = "NjkwNTM3NzIzNzA1OTUwMjM4.XnS31Q.nUBoW61fgZfgo3Zt0P7jrjf7gZU"
client = commands.Bot(command_prefix = ".")

SERVER_ID = 698571178561896608
CHANNEL_ID = 698640778720837792
SERVER = ""
#Subprocess pour reception UDP
reception = subprocess.Popen(['python', 'udp_receiver.py'])

async def hello():
    CHANNEL = SERVER.get_channel(CHANNEL_ID)
    await CHANNEL.send("Le lab est ouvert")

#Nettoyage fichier
async def cleaner():
    open('data.txt', 'w').close()


#Programme principal, boucle 15s
@tasks.loop(seconds=15.0)
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
                    if current_command == "hello":
                        await hello()
                    else:
                        print("Cette commande n'existe pas")
                    await cleaner()
                except Exception as error:
                    print(f"Erreur : {error}")

    except Exception as e:
        print(f"Erreur : {e}")

#Check up du bot
@client.event
async def on_ready():
    print('Bot online')
    global SERVER

    SERVER = client.get_guild(SERVER_ID)
#On démarre tout
get_data.start()
client.run(TOKEN)