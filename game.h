// Defining game's functionnality
#ifndef GAME_H
#define GAME_H

#include "structure.h"
#include "SDL2/SDL.h"

// Protypes
void init_game(Game *game, int OBSTACLE_FLAG, int BORDER_FLAG, double speed);
void render_game(SDL_Renderer *renderer, Game *game, SDL_Window * window);




#endif // SNAKE_H
