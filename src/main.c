#include "sort.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// https://texteditor.com/multiline-text-art/

static const int EASY_SCORE_DECREMENT = 10;
static const int MEDIUM_SCORE_DECREMENT = 20;
static const int LOWER = 1;
static const int UPPER = 4;

typedef enum Difficulty {
  Easy,
  Medium,
  Hard,
} Difficulty;

int list[35];

static int score = 0;
static int level = 1;
static int size = 5;

// Declaring Functions
void decrement_score(Difficulty diff);
void level_up();
void level_down();
int getrand();
void getarr(int size);
Difficulty get_difficulty();

int main(int argc, char *argv[]) {
  // Get a random number to run a random algorithm
  srand(time(0));
  int guess;

  clearscreen();
  printf(COLOR_CYAN);
  print_ascii("./assets/banner.txt");
  Difficulty diff = get_difficulty();

  while (level > 0 && level <= 10) {
    int random_number = getrand();
    printf(COLOR_GREEN BAR COLOR_OFF);
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
    case 4:
      getarr(size);
      radixsort(list, size);
      break;
    default:
      break;
    }

    printf(COLOR_GREEN BAR COLOR_OFF);
    printf(COLOR_BOLD "[1] " COLOR_OFF "Bubble Sort\n");
    printf(COLOR_BOLD "[2] " COLOR_OFF "Insertion Sort\n");
    printf(COLOR_BOLD "[3] " COLOR_OFF "Selection Sort\n");
    printf(COLOR_BOLD "[4] " COLOR_OFF "Radix Sort\n");
    printf("Enter your guess: ");
    scanf("%d", &guess);
    if (guess == random_number) {
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

int getrand() { return (rand() % (UPPER - LOWER + 1)) + LOWER; }

void decrement_score(Difficulty diff) {
  if (diff == Easy) {
    printf(COLOR_BOLD COLOR_RED "Wrong Answer!!" COLOR_OFF
                                "The score will be decremented by 10\n");
    score -= EASY_SCORE_DECREMENT;
  } else if (diff == Medium) {
    printf("Wrong Answer!! The score will be decremented by 20.\n");
    score -= MEDIUM_SCORE_DECREMENT;
  } else {
    printf(COLOR_RED COLOR_BOLD "Wrong Answer!! You Lose!!\n" COLOR_OFF);
    exit(1);
  }
}

Difficulty get_difficulty() {
  int choice;
  Difficulty difficulty;
  printf(COLOR_BOLD COLOR_RED "       CHOOSE DIFFICULTY\n");
  printf(COLOR_GREEN BAR COLOR_OFF);
  printf(COLOR_BOLD "[1]" COLOR_OFF " Easy\n");
  printf(COLOR_BOLD "[2]" COLOR_OFF " Medium\n");
  printf(COLOR_BOLD "[3]" COLOR_OFF " Hard\n" COLOR_OFF);
  printf(COLOR_GREEN BAR COLOR_OFF);
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
    default:
    printf(COLOR_RED "Invalid Choice. Defaulting to Medium\n" COLOR_OFF);
    difficulty = Medium;
    break;
  }
  return difficulty;
}

void level_up() {
  if (level == 10) {
    printf(COLOR_YELLOW);
    print_ascii("./assets/winner.txt");
    printf(COLOR_OFF);
    printf("Congratulations!! You WON the game");
    exit(1);
  }
  level++;
  size += 3;
  printf(COLOR_BOLD COLOR_GREEN BAR
         "You have been leveled up to Level %d\n" COLOR_OFF,
         level);
}

void level_down() {
  if (level >= 2) {
    level--;
    size -= 3;
  } else {
    printf("Too many wrong answers!! " COLOR_RED COLOR_BOLD "You Lose!!\n" COLOR_OFF);
    exit(1);
  }
}

void getarr(int size) {
  for (int i = 0; i < size; i++) {
    list[i] = rand() % 100;
  }
}
