'''
Assignment 1
tcp-server.py
Jackson Fitch
2/10/2025
'''
from socket import socket, AF_INET, SOCK_STREAM
import random
import sys

server_ip = "127.0.0.1"
server_port = 8000

try:
    # Create server socket
    server_socket = socket(AF_INET, SOCK_STREAM)
    print("Created server socket successfully")
    
    # Bind the socket to the server address
    server_socket.bind((server_ip, server_port))
    print("Socket bound successfully")
    
    # Listen for incoming connections
    server_socket.listen(1)
    print(f"Server listening on {server_ip}:{server_port}")
    
    server_name = "Server: Server-Jackson"
    print(f"Starting {server_name}")
    
    while True:
        print("\nWaiting for client connection...")
        connection_socket, client_address = server_socket.accept()
        print(f"Connected to client at {client_address}")
        
        try:
            print("Waiting to receive client message...")
            client_message = connection_socket.recv(2048).decode()
            
            if client_message:
                print(f"Received message: {client_message}")
                
                # Parse client name and number from message
                client_parts = client_message.split(',')
                client_name = client_parts[0]
                client_number = int(client_parts[1])
                
                # Generate server's random number
                server_number = random.randint(1, 100)
                sum_numbers = client_number + server_number
                
                # Print required information
                print("\nTransaction Details:")
                print(f"Client name: {client_name}")
                print(f"Server name: {server_name}")
                print(f"Client number: {client_number}")
                print(f"Server number: {server_number}") 
                print(f"Sum: {sum_numbers}")
                
                # Send response back to client
                response = f"{server_name},{server_number}"
                print(f"Sending response: {response}")
                connection_socket.send(response.encode())
                print("Response sent successfully")
            
        except Exception as e:
            print(f"Error handling client: {e}")
        finally:
            connection_socket.close()
            print("Client connection closed")
            
except Exception as e:
    print(f"Server error: {e}")
    sys.exit(1)
finally:
    server_socket.close()
    print("Server socket closed")
