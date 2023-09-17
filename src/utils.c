#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

void printarr(int a[], int n) {
  for (int i = 0; i < n; i++) {
    printf(COLOR_BOLD "%d " COLOR_OFF, a[i]);
  }
}


void swap(int a[], int i, int j) {
  int tmp = a[i];
  a[i] = a[j];
  a[j] = tmp;
}


void clearscreen(void) {
#ifdef _WIN32
    system("cls");
#elif defined(unix) || defined(__unix__) || defined(__unix) ||                 \
    (defined(__APPLE__) && defined(__MACH__))
    system("clear");
#else
#error "OS not supported."
#endif
}

