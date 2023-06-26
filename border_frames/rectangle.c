#include <rectangle.h>
#include <stdio.h>

void rectangle_box() {
    int x, y;

    coord_xy(5, 2);
    display_date();

    // Top edge
    coord_xy(1, 1);
    printf("╔");
    for (x = 2; x < 110; x++) {
        coord_xy(x, 1);
        printf("═");
    }
    printf("╗");

    // Right and left edges
    for (y = 2; y < 25; y++) {
        coord_xy(1, y);
        printf("║");
        coord_xy(110, y);
        printf("║");
    }

    // Bottom edge
    coord_xy(1, 25);
    printf("╚");
    for (x = 2; x < 110; x++) {
        coord_xy(x, 25);
        printf("═");
    }
    printf("╝");

    // Remove overlapping corners
    coord_xy(110, 1);
    printf(" ");

    coord_xy(110, 25);
    printf(" ");

    // Remove overlapping vertical lines
    for (y = 24; y >= 2; y--) {
        coord_xy(110, y);
        printf(" ");
        coord_xy(1, y);
        printf(" ");
    }
}
