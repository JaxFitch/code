'''
Python Lab 1
tcp-client.py
Jackson Fitch
2/7/2025
'''

from socket import *

server_ip = "127.0.0.1"
server_port = 8000

# Create client socket. AF_INET: IPv4 and SOCK_STREAM: TCP Socket
client_socket = socket(AF_INET, SOCK_STREAM)
client_socket.settimeout(5.0)  # 5 second timeout

# Connect to the server
client_socket.connect((server_ip, server_port))

# Send message to server
client_message = input("Enter a message to send to the server: ")
client_socket.sendall(client_message.encode())

# Receive response from server
server_response = client_socket.recv(2048).decode()
print(f"Received from server: {server_response}")

# Close connection
client_socket.close()