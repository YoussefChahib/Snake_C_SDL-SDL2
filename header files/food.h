// Defining food's functionnality
#ifndef FOOD_H
#define FOOD_H

#include "SDL2/SDL.h"
#include "structure.h"

// Prototypes
Pos random_empty_board_pos(Game *game);
Pos random_board_pos(void);
int random_int_range(int low, int high);

void eat_food(Game *game, Food *f);
void init_food(Game *game);
Food *check_for_food(Game *game);
void update_food(Game *game);
void render_food(SDL_Renderer *renderer, Game *game);
int pos_is_not_empty(Game *game, Pos p);

#endif // FOOD_H
