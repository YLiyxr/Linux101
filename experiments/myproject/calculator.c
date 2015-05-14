#include "big.h"
#include "fancy.h"

#include <stdio.h>

int main(void) {
    int a[BIG_N], b[BIG_N];
    draw_barrier();
    puts("\nWelcome to Big Number Square Rooter !");
    draw_barrier();
    draw_cat();

    for (;;) {
        draw_barrier();
        puts("Input a non-negative integer X:");
        big_read(a);
        big_copy(b, a);
        big_sqrt(a);
        draw_barrier();
        draw_cat();
        draw_barrier();
        printf("sqrt(");
        big_print(b);
        printf(") = ");
        big_print(a);
        puts("");
    }
    return 0;
}

