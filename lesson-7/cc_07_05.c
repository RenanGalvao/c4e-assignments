#include <stdio.h>

int main() {
  int i, v, n, arr[10];
  for (i = 0; i < 10; i++)
    scanf("%d", &arr[i]);

  for (--i; i >= 0; i--)
    printf("numb[%d] = %d\n", i, arr[i]);

  printf("\nSearching for entries equal to 100\n\n");

  for (i = n = 0; i < 10; i++)
    if (arr[i] == 100) {
      printf("Found 100 at %d\n", i);
      n++;
    }

  printf("\nFound %d entries with 100\n", n);
}
