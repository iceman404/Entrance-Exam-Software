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

void *timer1(void *timeset){  //definition of timer function.
	pthread_mutex_init(&mut1,NULL);
	pthread_t id2;
	id2 = pthread_self();
	int h=0,m=0,sec=0; 
	int *s = timeset;
	sec = *s * 60;
	if(sec>=60){
		m=sec/60;
		sec = sec-(m*60);
		if(m>=60){
			h=m/60;
			m = m-(h*60);
		}
	}
	fflush(stdin);
	while(h>0||m>0||sec>0){
				while(m>0||sec>0){
					while(sec>0){
						sleep(1);
						coord_xy(27,22);
						coord_xy(80,3);printf("%.2d : ",h);
						coord_xy(27,22);
						coord_xy(90,3);printf("%.2d : ",m);
						coord_xy(27,22);
						coord_xy(101,3);printf("%.2d",sec);
						coord_xy(27,22);
						if(time_to_exit==1){
							pthread_exit(&id2);
						}
						sec--;
						}
					if(m>0){
					sec=60;
					m--;
					}
				}
			if(h>0){
			m=60;
			h--;
		}
	}
	
	pthread_mutex_lock(&mut1);
	if(sec == 0){
		time_to_exit=1;
	}
	pthread_mutex_unlock(&mut1);
	
	pthread_mutex_destroy(&mut1);
}

