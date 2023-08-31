#include "utils.h"
#include <stdio.h>
void bubblesort(int a[], int n) {
  int comparisons = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 1; j < n - i; j++) {
      comparisons++;
      if (a[j - 1] > a[j]) {
        swap(a, j, j - 1);
      }
    }
    printarr(a, n);
    printf("\n");
  }
}

void selectionsort(int a[], int n) {
  for (int i = 0; i < n; i++) {
    int small = i;
    for (int j = i; j < n; j++) {
      if (a[j] < a[small]) {
        small = j;
      }
    }
    swap(a, i, small);
    printarr(a, n);
    printf("\n");
  }
}

void insertionsort(int a[], int n) {
  for (int i = 1; i < n; i++) {
    int j = i;
    while (j > 0 && a[j - 1] > a[j]) {
      swap(a, j, j - 1);
      j--;
    }
    printarr(a, n);
    printf("\n");
  }
}
