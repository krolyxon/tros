#include "utils.h"
#include <stdio.h>

void printarr(int a[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", a[i]);
  }
}

void print_ascii(char *filename) {
  char read_string[MAX_LEN];
  FILE *fptr = NULL;
  if ((fptr = fopen(filename, "r")) == NULL) {
    fprintf(stderr, "error opening %s\n", filename);
  }
  while (fgets(read_string, sizeof(read_string), fptr) != NULL) {
    printf("%s", read_string);
  }
  fclose(fptr);
}

void swap(int a[], int i, int j) {
  int tmp = a[i];
  a[i] = a[j];
  a[j] = tmp;
}
