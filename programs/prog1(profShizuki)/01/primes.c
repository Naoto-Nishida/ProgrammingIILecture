#include <stdio.h>

/*
 * primes.c: generates prime numbers.
 */

int main(void)
{
  int i, j, max;

  max = 10000;

  for (i = 2; i <= max; i++) {
    for (j = i-1; j > 1; j--)
      if (i%j == 0)
	break;
    if (j == 1)
      printf(" %d", i);
  }

  return 0;
}

/* eof */
