/*
    Author: [John Subba]
    Date: Original-[November-11, 2021]
    Refactor Date: [June-21, 2023]
    Description: [This is the main file of Entrance Prep Software]
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <pthread.h>

#ifdef _WIN32
    #include <conio.h> 
    #include <windows.h>
    #include "window_util_headers/windowsutil.h"

#elif defined(__linux__) || defined(__unix__)
    // Linux/Unix implementation
    #include <stdio.h>
    #include "unix_linux_util_headers/linuxutil.h"

#else
    #error Unsupported operating system
#endif


/* Main Program with default command line argument convention */
int main(int argc, char* argv[]) {
    // Access and process command-line arguments
    for (int i = 0; i < argc; i++) {
        printf("Argument %d: %s\n", i, argv[i]);
    }

    // Rest of your code

    return 0;
}
