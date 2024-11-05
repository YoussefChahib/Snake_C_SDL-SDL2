// Defining every used structure in the program

#ifndef STRUCTURE_H
#define STRUCTURE_H

#include "constant.h"

// Structures
typedef enum {
  DIR_RIGHT = 0,
  DIR_UP,
  DIR_LEFT,
  DIR_DOWN,
} Dir;

typedef struct {
  int x;
  int y;
} Pos;

typedef struct {
  Pos pos;
  int score;
} Food;

typedef struct {
  Pos pos;
  int init;
} Obstacle;

typedef struct {
  Pos body[MAX_SNAKE_LENGTH];
  int length;
  Dir dir;
} Snake;

typedef struct {
  Snake snake;
  Food food[FOODS_COUNT];
  Obstacle obs[OBSTACLES_COUNT];
  double game_speed;
  int quit;
  int global_score;
} Game;

#endif // STRUCTURE_H
