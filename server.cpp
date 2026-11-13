
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>

using namespace std;

int main()
{
    // Step 1: Create TCP Socket
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);

    // Step 2: Socket Error Handling
    if (server_fd == -1)
    {
        cerr << "Socket creation failed" << endl;
        return 1;
    }

    cout << "Socket created successfully" << endl;

    // Step 3: Create Address Structure
    struct sockaddr_in address{};

    // Step 4: Set Address Family
    address.sin_family = AF_INET;

    // Step 5: Set Port Number
    address.sin_port = htons(8080);

    // Step 6: Set IP Address
    address.sin_addr.s_addr = INADDR_ANY;

    // Step 7: Bind Socket
    int bind_status = ::bind(
        server_fd,
        (struct sockaddr *)&address,
        sizeof(address));

    // Step 8: Bind Error Handling
    if (bind_status == -1)
    {
        cerr << "Binding failed" << endl;
        close(server_fd);
        return 1;
    }
    else
    {
        cout << "Binding successful" << endl;
    }

    // Step 9: Listen for Connections
    int listen_status = listen(server_fd, SOMAXCONN);

    // Step 10: Listen Error Handling
    if (listen_status == -1)
    {
        cerr << "Listen failed" << endl;
        close(server_fd);
        return 1;
    }
    else
    {
        cout << "Server is listening..." << endl;
    }

    // Step 11: Create Client Address Structure
    struct sockaddr_in client_address{};

    socklen_t client_len = sizeof(client_address);

    // Step 12: Accept Client Connection
    int client_fd = accept(
        server_fd,
        (struct sockaddr *)&client_address,
        &client_len);

    // Step 13: Accept Error Handling
    if (client_fd == -1)
    {
        cerr << "Accept failed" << endl;
        close(server_fd);
        return 1;
    }
    else
    {
        cout << "Client connected successfully" << endl;
    }

    // Step 14: Close Connections
    close(client_fd);
    close(server_fd);

    return 0;
}
