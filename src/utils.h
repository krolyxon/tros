#include <stdio.h>

#define MAX_LEN 128
#define BAR "────────────────────────────────\n"

// COLORS
#define COLOR_RED "\x1b[31m"
#define COLOR_GREEN "\x1b[32m"
#define COLOR_YELLOW "\x1b[33m"
#define COLOR_BLUE "\x1b[34m"
#define COLOR_MAGENTA "\x1b[35m"
#define COLOR_CYAN "\x1b[36m"
#define COLOR_RESET "\x1b[0m"
#define COLOR_BOLD "\e[1m"
#define COLOR_OFF "\e[m"

void printarr(int a[], int n);
void print_ascii(char *filename);
void swap(int a[], int i, int j);
