#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

using namespace std;

int main()
{
    // create a client socket
    int client_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (client_fd == -1)
    {
        cerr << "Socket creation failed" << endl;
        return 1;
    }
    cout << "Client socket created successfully" << endl;

    return 0;
}