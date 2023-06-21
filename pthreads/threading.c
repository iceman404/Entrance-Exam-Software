#ifdef _WIN32
    // Include Windows-specific headers for threading
    #include <windows.h>
#else
    // Include Unix-specific headers for threading
    #include <pthread.h>
#endif

#include "threading.h"

pthread_mutex_t mut1, mut2;  // Declare mutex variables

int time_to_exit = 0;  // Define the global variable

/* Function definitions for threading functionality */

/* For displaying the date function */
void *getCurrentDate(d1 *exam_date){
    time_t t1;
    const char* monthNames[] = {"January", "February", "March", "April", "May", "June",
                          "July", "August", "September", "October", "November", "December"};
    t1 = time(NULL);
    struct tm time1 = *localtime(&t1);
    int m = time1.tm_mon;
    strcpy(exam_date->month, monthNames[m]);
    exam_date->day=time1.tm_mday;
    exam_date->year=(time1.tm_year+1900);
  return NULL;
}

/* Definition of Timer Funciton */
void* timer1(void* timeset) {
    pthread_t id2 = pthread_self();
    int* s = (int*)timeset;
    int sec = (*s) * 60;

    int h = sec / 3600;
    int m = (sec % 3600) / 60;
    sec = sec % 60;

    while (h > 0 || m > 0 || sec > 0) {
        sleep(1);
        coord_xy(27, 22);
        coord_xy(80, 3);
        printf("%.2d : ", h);
        coord_xy(27, 22);
        coord_xy(90, 3);
        printf("%.2d : ", m);
        coord_xy(27, 22);
        coord_xy(101, 3);
        printf("%.2d", sec);
        coord_xy(27, 22);

        if (time_to_exit == 1) {
            pthread_exit(&id2);
        }

        if (sec > 0) {
            sec--;
        } else if (m > 0) {
            sec = 59;
            m--;
        } else if (h > 0) {
            sec = 59;
            m = 59;
            h--;
        }
    }

    return NULL;
}


