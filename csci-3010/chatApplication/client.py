'''
chatApplication
client.py
Jackson Fitch
4/9/2025
'''

import threading
from socket import socket, AF_INET, SOCK_STREAM, error as socket_error

# Bool to control the main loop
running = True

# Function to continuously receive messages from the server
def receive_messages(sock):
    global running
    try:
        while running:
            try:
                message = sock.recv(1024).decode()
                if not message:
                    print("\nConnection to server lost.")
                    running = False
                    break
                    
                if message.lower() == "end":
                    print("\nServer has ended the conversation.")
                    running = False
                    break
                    
                print(f"\nServer: {message}")
                print("Enter message (or 'end' to quit): ", end="", flush=True)
            except socket_error as e:
                running = False
                break
    except Exception as e:
        if running:
            print(f"\nReceive thread error: {e}")
        running = False

try:
    server_ip = input("Enter server IP address (ENTER for localhost): ")
    server_ip = "localhost" if server_ip == "" else server_ip

    try:
        port_input = input("Enter server port number (ENTER for 8080): ")
        server_port = 8080 if port_input == "" else int(port_input)
    except ValueError as e:
        print(f"Invalid port number: {e}")
        server_port = 8080
        
    client_username = input("Enter your username: ")

    # Create client socket
    try:
        client_socket = socket(AF_INET, SOCK_STREAM)
        print("Created client socket successfully")
    except socket_error as e:
        print(f"Socket creation error: {e}")
        exit(1)
    
    # Connect to the server
    try:
        client_socket.connect((server_ip, server_port))
        print(f"Connected to server at {server_ip}:{server_port}")
    except socket_error as e:
        print(f"Connection error: {e}")
        client_socket.close()
        exit(1)
    
    # Receive username from server
    try:
        server_username = client_socket.recv(1024).decode()
        print(f"Connected with {server_username}")
    except socket_error as e:
        print(f"Error receiving server username: {e}")
        client_socket.close()
        exit(1)
    
    # Send username to server
    try:
        client_socket.send(client_username.encode())
    except socket_error as e:
        print(f"Error sending username: {e}")
        client_socket.close()
        exit(1)
    
    # Start a thread to receive messages
    receive_thread = threading.Thread(target=receive_messages, args=(client_socket,))
    receive_thread.daemon = True
    receive_thread.start()
    
    # Main loop for sending messages
    while running:
        message = input("Enter message (or 'end' to quit): ")
        
        if message.lower() == 'end':
            running = False
            try:
                client_socket.send("end".encode())
            except socket_error as e:
                print(f"Error sending end message: {e}")
            break
        
        # Send message to server
        try:
            client_socket.send(message.encode())
        except socket_error as e:
            print(f"Error sending message: {e}")
            running = False
            break
            
except Exception as e:
    print(f"Client error: {e}")
finally:
    running = False
    try:
        client_socket.close()
        print("Client socket closed")
    except:
        pass