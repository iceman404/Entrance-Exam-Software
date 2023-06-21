#ifndef THREADING_H
#define THREADING_H

#ifdef _WIN32
    // Include Windows-specific headers for threading
    #include <windows.h>
#else
    // Include Unix-specific headers for threading
    #include <pthread.h>
#endif

// Global variable declaration
extern int time_to_exit;


/* Declarations and function prototypes related to threading*/
void *timer1(void *time);
void *date(d1 *);  // these are functions related to date and timer of exam.

#endif // THREADING_H

