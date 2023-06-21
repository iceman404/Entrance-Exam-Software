#ifndef WINDOWSUTIL_H
#define WINDOWSUTIL_H

#include <windows.h>

void coord_xy(short x, short y) {
    COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

// Other Windows-specific functions

#endif /* WINDOWSUTIL_H */
