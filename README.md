# TROS
This is a CLI game where you have to guess the sorting algorithm used to sort a randomly generated list of numbers based on the passes displayed on the screen.
The game has 3 difficulty modes:
1. **Easy**: When you make a wrong guess, your score will be decremented by 10 and level by 1.
2. **Medium**: Score will be decremented by 20 and level by 10.
3. **Hard**: You lose the game when you make a single wrong guess.

## Levels
- There are total 10 levels and the number of elements in the list depends upon it.
- When you reach the level 10 and make the right guess, You win the game.

| Level | Elements |
|-------|----------|
| 1     | 5 Elements       |
| 2     | 8 Elements       |
| 3     | 11 Elements      |
| 4     | 14 Elements      |
| 5     | 17 Elements      |
| 6     | 20 Elements      |
| 7     | 23 Elements      |
| 8     | 26 Elements      |
| 9     | 29 Elements      |
| 10    | 32 Elements      |

At the moment the score system is useless, and doesn't really make a difference on the gameplay, but i do plan on adding features, such as high score.

## Installation
```
  $ git clone --depth=1 https://github.com/krolyxon/tros --branch=master
  $ cd tros
  $ make run
```

## TROS in Action
![](https://raw.githubusercontent.com/krolyxon/tros/master/tros.gif)

# TODO
- [x] Algorithms to be implemented:
    - [x] Bubblesort
    - [x] SelectionSort
    - [x] InsertionSort
    - [x] Radix Sort
- [ ] Score system
    - [x] Implement Score system
    - [ ] Make the score system somewhat useful
- [ ] Code Refactoring/Cleaning
