// Defining snake's functionnality
#ifndef SNAKE_H
#define SNAKE_H

#include "structure.h"
#include "SDL2/SDL.h"



// Prototypes
Pos *get_snake_head(Snake *snake);
int allow_snake_movement(int manual, Game *game);
Pos peak_next_pos(Snake *snake, Dir new_dir);
void move_snake(Game *game, Dir new_dir, int manual);
void render_snake(SDL_Renderer *renderer, Game *game);


#endif // SNAKE_H
