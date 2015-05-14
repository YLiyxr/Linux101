#include "big.h"

#include <stdio.h>
#include <string.h>

void big_zero(int *a) {
    memset(a, 0, BIG_N * sizeof(int));
}

void big_copy(int *a, int *b) {
    memcpy(a, b, BIG_N * sizeof(int));
}

void big_read(int *a) {
    char buff[BIG_N];
    if (scanf("%s", buff) < 0)
        return;
    int n = (int) strlen(buff);
    big_zero(a);
    
    for (int i = 0; i < n; ++i) {
        a[n - i - 1] = buff[i] - '0';
    }
}

void big_print(int *a) {
    int first = 1;
    for (int i = BIG_N - 1; i >= 0; --i) {
        if (first != 1 || a[i] != 0) {
            printf("%d", a[i]);
            first = 0;
        }
    }

    if (first == 1) {
        printf("0");
    }
}

int big_compare(int *a, int *b) {
    for (int i = BIG_N - 1; i >= 0; --i) {
        if (a[i] < b[i]) return -1;
        if (a[i] > b[i]) return 1;
    }
    return 0;
}

void big_add(int *a, int *b) {
    int carry = 0;
    for (int i = 0; i < BIG_N; ++i) {
        a[i] += b[i] + carry;
        carry = a[i] / 10;
        a[i] = a[i] % 10;
    }
}

void big_shift(int *a, int k) {
    for (int i = BIG_N - 1; i >= k; --i) {
        a[i] = a[i - k];
    }
    for (int i = k - 1; i >= 0; --i) {
        a[i] = 0;
    }
}

void big_sqrt(int *a) {
    int root[BIG_N], sqr[BIG_N];
    big_zero(root);
    
    int t[BIG_N], last_t[BIG_N];
    big_zero(t);

    for (int i = (BIG_N - 1) / 2; i >= 0; --i) {
        for (int j = 1; j <= 9; ++j) {
            big_copy(last_t, t);

            /* (r+1)^2 = r^2 + (r) + (r+1) */
            big_add(t, root);
            ++root[i];
            big_add(t, root);

            /* (r * 10^i)^2 = (r^2 * 10^i) * 10^i */
            big_copy(sqr, t);
            big_shift(sqr, i);

            if (big_compare(a, sqr) < 0) {
                --root[i];
                big_copy(t, last_t);
                break;
            }
        }
        
        /* (r^2 * 10^i) = (r^2 * 10^(i-1)) * 10 */
        big_shift(t, 1);
    }

    big_copy(a, root);
}

