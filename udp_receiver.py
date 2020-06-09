import socket
import time

UDP_IP = "192.168.1.40"
UDP_PORT = 5005

sock = socket.socket(socket.AF_INET, # Internet
                     socket.SOCK_DGRAM) # UDP
sock.bind((UDP_IP, UDP_PORT))

def write_command(data):
	with open('data.txt', 'a') as file:
		file.write(str(data) + "\n")

time.sleep(5)
while True:
	data, addr = sock.recvfrom(1024) # Buffer en 1024
	print("a")
	data = str(data)[2:-1]
	write_command(data)

