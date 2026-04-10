#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <limits> // Add this for numeric_limits
#include <cstring>

#ifdef _WIN32
    #include <windows.h>
    #include <conio.h>
#else
    #include <unistd.h>
    #include <termios.h>
    #include <cstdlib>
    #include <AudioToolbox/AudioToolbox.h>
#endif

#define GREEN "\033[32m"
#define RESET "\033[0m"

void gotoxy(int x, int y);
void clear_screen();
void pause_screen();
void Sleep(int milliseconds);
void Beep(float frequency = 1000.0f, float duration = 0.2f);
char _getch();
void Cleaning_Line();

#endif // UTILS_H