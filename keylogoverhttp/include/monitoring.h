#pragma once
#ifndef MONITORING_H_
#define MONITORING_H_

#include <stdbool.h>
#define BUFF_SIZE 64

void startMonitorKeyStrokes();
void appendToEnd(char*, char);
bool capsLockPressed();
bool checkFunctionalKeys(int, char*, bool*);


#endif