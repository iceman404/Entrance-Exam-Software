#include <rectangle.h>
#include <stdio.h>

#include <stdio.h>

void drawHorizontalLine(char edge, char fill, int length) {
    printf("%c", edge);
    for (int i = 0; i < length - 2; i++) {
        printf("%c", fill);
    }
    printf("%c", edge);
}

void rectangle_box() {
    int x, y;

    coord_xy(5, 2);
    display_date();

    // Top edge
    coord_xy(1, 1);
    drawHorizontalLine('╔', '═', 110);

    // Right and left edges
    for (y = 2; y < 25; y++) {
        coord_xy(1, y);
        printf("║");
        coord_xy(110, y);
        printf("║");
    }

    // Bottom edge
    coord_xy(1, 25);
    drawHorizontalLine('╚', '═', 110);

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

