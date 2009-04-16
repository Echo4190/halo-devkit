#ifndef DEBUG_H
#define DEBUG_H

#include <windows.h>
#include <time.h>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#define LOGNAME "halo_sdk.log"

void __cdecl DEBUG(const char* fmt, ...);
char *GetDirectoryFile(char* filename);
void InitDebug(HMODULE hModule);
void ExitDebug();

#endif /* DEBUG_H */