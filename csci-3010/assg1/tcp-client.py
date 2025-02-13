'''
Assignment 1
tcp-client.py
Jackson Fitch
2/10/2025
'''
from socket import socket, AF_INET, SOCK_STREAM
import sys

server_ip = "127.0.0.1"
server_port = 8000

try:
    # Create client socket
    print("Creating client socket...")
    client_socket = socket(AF_INET, SOCK_STREAM)
    
    # Connect to the server
    print(f"Connecting to server at {server_ip}:{server_port}...")
    client_socket.connect((server_ip, server_port))
    print("Connected successfully")
    
    client_name = "Client: Client-Jackson"
    
    # Input validation loop
    while True:
        try:
            user_input = input("Enter a number(1-100): ")
            user_number = int(user_input)
            if 1 <= user_number <= 100:
                break
            print("Error: Number must be between 1 and 100")
        except ValueError:
            print("Error: Please enter a valid integer")
    
    # Send client name and number
    message = f"{client_name},{user_number}"
    print(f"Sending message: {message}")
    client_socket.send(message.encode())
    print("Message sent successfully")
    
    # Receive server reply
    print("Waiting for server response...")
    server_reply = client_socket.recv(1024).decode()
    print(f"Received response: {server_reply}")
    
    # Parse server reply
    server_name, server_number = server_reply.split(',')
    server_number = int(server_number)
    
    # Display transaction details
    print("\nTransaction Details:")
    print(f"Client name: {client_name}")
    print(f"Server name: {server_name}")
    print(f"Client number: {user_number}")
    print(f"Server number: {server_number}")
    print(f"Sum: {user_number + server_number}")

except Exception as e:
    print(f"Client error: {e}")
    sys.exit(1)
finally:
    client_socket.close()
    print("Client socket closed")