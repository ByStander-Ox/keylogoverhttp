#include "../include/sendoverhttp.h"
#include "../include/connect.h"

bool sendHTTPRequest(char* buffer) {

    char request[256];
    snprintf(request, 256, "%s%s%s%sData:%s\r\n\r\n", getSection, hostSection, contentTypeSection, contentLengthSection, buffer);

    if (send(tcpSocket, request, strlen(request), 0) < 0) {
        printf("Sending packet failed");
        return false;
    }
    return true;
}