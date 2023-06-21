#ifndef LINUXUTIL_H
#define LINUXUTIL_H

#include <stdio.h>

void coord_xy(short x, short y) {
    printf("\033[%d;%dH", y, x);
}

// Other Linux-specific functions

#endif /* LINUXUTIL_H */
