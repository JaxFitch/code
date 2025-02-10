'''
Python Lab 1
tcp-server.py
Jackson Fitch
2/7/2025
'''

from socket import *

server_ip = "127.0.0.1"
server_port = 8000

# Create server socket. AF_INET: IPv4 and SOCK_STREAM: TCP Socket
server_socket = socket(AF_INET, SOCK_STREAM)
server_socket.setsockopt(SOL_SOCKET, SO_REUSEADDR, 1)

# Bind the socket to the server address
server_socket.bind((server_ip, server_port))

# Listen for incoming connections
server_socket.listen(1)

print(f"Server listening on {server_ip}:{server_port}")

while True:
    connection_socket, client_address = server_socket.accept()
    print(f"Connected to {client_address}")
    
    client_message = connection_socket.recv(2048).decode()
    if client_message:
        print(f"Received message: {client_message}")
        server_message = client_message.upper()
        connection_socket.send(server_message.encode())
    
    connection_socket.close()
