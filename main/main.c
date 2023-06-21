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
#else
    #include <unistd.h>
    // Add any additional Unix-specific headers here
#endif
