#include "../include/connect.h"

bool winSockInitialize() {
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        printf("Winsock library initializing failed. Error code: %d", WSAGetLastError());
        return false;
    }
    return true;
}

bool connectToServer() {
    struct sockaddr_in server;

    if ((tcpSocket = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
        printf("Could not create socket: %d", WSAGetLastError());
        return false;
    }
    else {
        server.sin_addr.s_addr = inet_addr(SERVER_IP);
        server.sin_family = AF_INET;
        server.sin_port = htons(SERVER_PORT);

        int flags = 1;
        if (setsockopt(tcpSocket, SOL_SOCKET, SO_KEEPALIVE, (void*)&flags, sizeof(flags)) < 0) {
            printf("setsocket options failed\n");
            closesocket(tcpSocket);
            return false;
        }
        else {
            if (connect(tcpSocket, (struct sockaddr*) & server, sizeof(server)) < 0) {
                printf("Connection to server addres failed.");
                return false;
            }
        }
    }
    return true;
}

bool initializeConnection() {
    while (true) {
        if (winSockInitialize()) {
            if (connectToServer()) {
                break;
            }
        }
        Sleep(1000 * 5);
    }
    return true;
}
