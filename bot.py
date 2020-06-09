import discord
from discord.ext import commands, tasks
import subprocess

TOKEN = "NjkwNTM3NzIzNzA1OTUwMjM4.XnS31Q.nUBoW61fgZfgo3Zt0P7jrjf7gZU"
client = commands.Bot(command_prefix = ".")

available_commands = {'hello' : "hello()"}

reception = subprocess.Popen(['python', 'udp_receiver.py'])

async def cleaner():
    with open('data.txt') as f:
        print(f.write(""))

@tasks.loop(seconds=30.0)
async def get_data():

    try:
        with open('data.txt') as f:
            data = f.readlines()
            print(data)
            if len(data) >= 1:
                current_command = data[-1][:-1]
                try:
                    await exec(available_commands[current_command])
                    await cleaner
                except KeyError:
                    print("Cette commande n'existe pas")
                except Exception as error:
                    print(f"Erreur inconnue : {error}")
    except Exception as e:
        print(f"Erreur : {e}")

@client.event
async def on_ready():
    print('Bot online')

get_data.start()
client.run(TOKEN)