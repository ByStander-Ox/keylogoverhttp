#include "../include/regaction.h"

bool createRegisteryKey(PWCHAR exePath, PWCHAR appName) {
    DWORD dwDisposition;
    HKEY hKey;
    DWORD ret;

    ret = RegCreateKeyExW(HKEY_CURRENT_USER, L"Software\\Microsoft\\Windows\\CurrentVersion\\Run", 0, NULL, 0, (KEY_WRITE | KEY_READ), NULL, &hKey, &dwDisposition);
    if (ret != ERROR_SUCCESS) {
        printf("Error while creating registery key.");
        return false;
    }
    else {
        LONG setStatus = RegSetValueEx(hKey, appName, 0, REG_SZ, (LPBYTE)(exePath), ((((DWORD)lstrlen(exePath) + 1)) * 2));
        if (setStatus == ERROR_SUCCESS) {
            printf("Registery OK.");
        }
    }
    RegCloseKey(hKey);
    return true;
}