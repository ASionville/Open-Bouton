import socket
import time
from config import HOST_IP, HOST_PORT

sock = socket.socket(socket.AF_INET, # Internet
                     socket.SOCK_DGRAM) # UDP
sock.bind((HOST_IP, HOST_PORT))

def write_command(data):
	with open('data.txt', 'a') as file:
		file.write(str(data) + "\n")

time.sleep(5)
while True:
	data, addr = sock.recvfrom(1024) # Buffer
	print("a")
	data = str(data)[2:-1]
	write_command(data)

