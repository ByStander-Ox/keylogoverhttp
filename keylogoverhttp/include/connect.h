#pragma once
#ifndef CONNECT_H_
#define CONNECT_H_

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <stdbool.h>

#define SERVER_IP "192.168.114.128"
#define SERVER_PORT 80

SOCKET tcpSocket;

bool initializeConnection();
bool winSockInitialize();
bool connectToServer();

#endif

