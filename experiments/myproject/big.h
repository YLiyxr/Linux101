/*
 * Sample C Program
 * By Xinru Yang
 * 2015-5-15
 *
 * Problem: Big Integer Utilities
 *
 */

#define BIG_N 1000

/* Set zero to a big integer */
void big_zero(int *a);

/* Big integer a = b */
void big_copy(int *a, int *b);

/* Converts an input string to a big integer. */
void big_read(int *a);

/* Outputs an big integer */
void big_print(int *a);

/* Compares two big integer, returns Sign(a-b) */
int big_compare(int *a, int *b);

/* Addition a = a + b */
void big_add(int *a, int *b);

/* Decimal shift a = a * 10^k */
void big_shift(int *a, int k);

/* Floor of big integer's square root a = sqrt(a)*/
void big_sqrt(int *a); 
