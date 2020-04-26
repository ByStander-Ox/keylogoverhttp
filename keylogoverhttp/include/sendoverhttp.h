#pragma once
#ifndef SENDOVERHTTP_H_
#define SENDOVERHTTP_H_

#include <stdbool.h>

static const char getSection[] = "GET http://www.kizilelma.com HTTP/1.1\r\n";
static const char hostSection[] = "Host: www.kizilelma.com\r\n";
static const char contentTypeSection[] = "Content-type: application/x-www-form-urlencoded\r\n";
static const char contentLengthSection[] = "Content-length: 1453\r\n";

bool sendHTTPRequest(char*);


#endif