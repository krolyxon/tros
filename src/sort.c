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

int get_max(int a[], int n) {
  int max = a[0];
  int i;
  for (i = 1; i < n; i++)
    if (a[i] > max)
      max = a[i];
  return max;
}
void radixsort(int a[], int n) {
  int bucket[10][10], bucket_cnt[10];
  int i, j, k, r, NOP = 0, divisor = 1, lar, pass;
  lar = get_max(a, n);
  while (lar > 0) {
    NOP++;
    lar /= 10;
  }
  for (pass = 0; pass < NOP; pass++) {
    for (i = 0; i < 10; i++) {
      bucket_cnt[i] = 0;
    }
    for (i = 0; i < n; i++) {
      r = (a[i] / divisor) % 10;
      bucket[r][bucket_cnt[r]] = a[i];
      bucket_cnt[r] += 1;
    }
    i = 0;
    for (k = 0; k < 10; k++) {
      for (j = 0; j < bucket_cnt[k]; j++) {
        a[i] = bucket[k][j];
        i++;
      }
    }
    divisor *= 10;
    printarr(a, n);
    printf("\n");
  }
}
