import discord
from discord.ext import commands, tasks

TOKEN = "NjkwNTM3NzIzNzA1OTUwMjM4.XnS31Q.nUBoW61fgZfgo3Zt0P7jrjf7gZU"
client = commands.Bot(command_prefix = ".")

available_commands = {'hello' : "hello()"}

@tasks.loop(seconds=30.0)
async def get_data():

    try:
        with open('data.txt', 'r') as file:
            current_command = file.readlines()[-1][:-1]
            try:
                await exec(available_commands[current_command])
            except KeyError:
                print("Cette commande n'existe pas")
            except Exception as error:
                print(f"Erreur inconnue : {error}")
    except:
        print("Le fichier est déjà ouvert")

@client.event
async def on_ready():
    print('Bot online')

@client.command(pass_context=True)
async def combien(ctx):
    channel = ctx.message.author.voice.channel
    amount = len(channel.members)
    new_name = str(channel.name) + ' (' + str(amount) + ')'
    await channel.edit(name=new_name)

get_data.start()
client.run(TOKEN)