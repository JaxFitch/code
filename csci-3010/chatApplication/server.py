'''
chatApplication
server.py
Jackson Fitch
4/9/2025
'''

import threading
from socket import socket, AF_INET, SOCK_STREAM, error as socket_error

# Bool to control the main loop
running = True

# Function to continuously receive messages from client
def receive_messages(sock, username):
    global running
    try:
        while running:
            try:
                client_message = sock.recv(1024).decode()
                if not client_message:
                    print("Connection to client lost.")
                    running = False
                    break
                    
                print(f"\n{username}: {client_message}")
                
                if client_message.lower() == "end":
                    print("Client has ended the conversation.")
                    running = False
                    break
                print("Enter message (or 'end' to quit): ", end="", flush=True)
            except socket_error as e:
                running = False
                break
    except Exception as e:
        if running:
            print(f"Receive thread error: {e}")
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
        
    server_username = input("Enter your username: ")

    # Create server socket
    try:
        server_socket = socket(AF_INET, SOCK_STREAM)
        print("Created server socket successfully")
    except socket_error as e:
        print(f"Socket creation error: {e}")
        exit(1)
    
    # Bind the socket to the server address
    try:
        server_socket.bind((server_ip, server_port))
        print("Socket bound successfully")
    except socket_error as e:
        print(f"Socket binding error: {e}")
        server_socket.close()
        exit(1)
    
    # Listen for incoming connections
    try:
        server_socket.listen(1)
        print(f"Server listening on {server_ip}:{server_port}")
    except socket_error as e:
        print(f"Socket listen error: {e}")
        server_socket.close()
        exit(1)
    
    # Accept client connection
    try:
        connection_socket, client_address = server_socket.accept()
        print(f"Connected to client at {client_address}")
    except socket_error as e:
        print(f"Connection acceptance error: {e}")
        server_socket.close()
        exit(1)
    
    # Send username to client
    try:
        connection_socket.send(server_username.encode())
    except socket_error as e:
        print(f"Error sending username: {e}")
        connection_socket.close()
        server_socket.close()
        exit(1)
    
    # Receive username from client
    try:
        client_username = connection_socket.recv(1024).decode()
        print(f"Connected with {client_username}.")
    except socket_error as e:
        print(f"Error receiving client username: {e}")
        connection_socket.close()
        server_socket.close()
        exit(1)
    
    # Start a thread to receive messages
    receive_thread = threading.Thread(target=receive_messages, args=(connection_socket, client_username))
    receive_thread.daemon = True
    receive_thread.start()
    
    # Main loop for sending messages
    while running:
        server_message = input("Enter message (or 'end' to quit): ")
        
        if server_message.lower() == 'end':
            running = False
            try:
                connection_socket.send("end".encode())
            except socket_error as e:
                print(f"Error sending end message: {e}")
            break
        
        # Send message to client
        try:
            connection_socket.send(server_message.encode())
        except socket_error as e:
            print(f"Error sending message: {e}")
            running = False
            break
            
except Exception as e:
    print(f"Server error: {e}")
finally:
    running = False
    try:
        connection_socket.close()
        print("Client connection closed")
    except:
        pass
    try:
        server_socket.close()
        print("Server socket closed")
    except:
        pass