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

int list[35];

int score = 100;
int level = 1;
int size = 5;

void decrement_score(enum Difficulty diff);
void level_up();
void level_down();
int getrand();
void getarr(int size);
enum Difficulty get_difficulty();

int main(int argc, char *argv[]) {
  // Get a random number to run a random algorithm
  srand(time(0));
  int guess;

  printf(COLOR_RED);
  print_ascii("./assets/banner.txt");
  enum Difficulty diff = get_difficulty();

  while (level > 0 && level <= 10) {
  int random_number = getrand();
    printf(BAR);
    switch (random_number) {
    case 1:
      getarr(size);
      bubblesort(list, size);
      break;
    case 2:
      getarr(size);
      insertionsort(list, size);
      break;
    case 3:
      getarr(size);
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
      level_up();
    } else {
      decrement_score(diff);
      level_down();
    }
    printf("Score: %d\n", score);
  }
  return 0;
}

int getrand() {
  return (rand() % (UPPER - LOWER + 1)) + LOWER;
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

void level_up() {
  if (level == 10) {
    printf("Congratulations!! You WON the game");
    exit(1);
  }
  level++;
  size += 3;
  printf(COLOR_BOLD COLOR_RED
         "You have been leveled up to Level %d\n" COLOR_OFF,
         level);
}

void level_down() {
  if (level >= 2) {
    level--;
    size -= 3;
  } else {
    printf("Too many wrong answers!!, You Lose!");
    exit(1);
  }
}

void getarr(int size) {
  for (int i = 0; i < size; i++) {
    list[i] = rand() % 100;
  }
}
