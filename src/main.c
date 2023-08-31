#include "sort.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// https://texteditor.com/multiline-text-art/
const int EASY_SCORE_DECREMENT = 10;
const int MEDIUM_SCORE_DECREMENT = 20;
const int LOWER = 1;
const int UPPER = 3;

enum Difficulty {
  Easy,
  Medium,
  Hard,
};

int list[] = {40, 78, 94, 62, 68, 74, 56, 55, 88, 55, 59, 73,
              19, 32, 81, 95, 71, 63, 15, 41, 11, 38, 86};

int score = 100;

void decrement_score(enum Difficulty diff);
enum Difficulty get_difficulty();

int main(int argc, char *argv[]) {
  // Get a random number to run a random algorithm
  int guess;
  srand(time(0));
  int random_number = (rand() % (UPPER - LOWER + 1)) + LOWER;

  printf(COLOR_RED);
  print_ascii("./assets/banner.txt");
  int size;
  enum Difficulty diff = get_difficulty();
  switch (diff) {
  case Easy:
    size = 5;
    break;
  case Medium:
    size = 10;
    break;
  case Hard:
    size = 23;
    break;
  }

  printf(BAR);
  switch (random_number) {
  case 1:
    bubblesort(list, size);
    break;
  case 2:
    insertionsort(list, size);
    break;
  case 3:
    selectionsort(list, size);
    break;
  // case 4: radixsort(list); break;
  default:
    break;
  }

  printf(BAR);
  printf("1. BubbleSort\n");
  printf("2. InsertionSort\n");
  printf("3. SelectionSort\n");
  printf("4. RadixSort\n");
  printf("Enter your guess: ");
  scanf("%d", &guess);
  if (guess == random_number) {
    printf("Congratulations!!! Your answer was right!!\n");
    score += 10;
  } else {
    decrement_score(diff);
  }
  printf("Score: %d\n", score);
  return 0;
}

void decrement_score(enum Difficulty diff) {
  if (diff == Easy) {
    printf("Wrong Answer!! The score will be decremented by 10\n");
    score -= EASY_SCORE_DECREMENT;
  } else if (diff == Medium) {
    printf("Wrong Answer!! The score will be decremented by 20\n");
    score -= MEDIUM_SCORE_DECREMENT;
  } else {
    printf("Wrong Answer!! The score will be reseted to 0\n");
    score = 0;
  }
}

enum Difficulty get_difficulty() {
  int choice;
  enum Difficulty difficulty;
  printf(COLOR_CYAN "       CHOOSE DIFFICULTY\n" COLOR_OFF);
  printf(COLOR_RED BAR COLOR_OFF);
  printf("1. Easy\n");
  printf("2. Medium\n");
  printf("3. Hard\n");
  printf(BAR);
  printf("Enter difficulty: ");
  scanf("%d", &choice);
  switch (choice) {
  case 1:
    difficulty = Easy;
    break;
  case 2:
    difficulty = Medium;
    break;
  case 3:
    difficulty = Hard;
    break;
  }
  return difficulty;
}
