// Defining rendering's functionnality
#ifndef RENDERING_H
#define RENDERING_H

#include <stdint.h>
#include "SDL2/SDL.h"
#include "structure.h"

// Prototypes
void scc(int code);
void *scp(void *ptr);
void render_square(SDL_Renderer *renderer, Pos pos, Uint8 r, Uint8 g, Uint8 b, Uint8 a);
void render_board(SDL_Renderer *renderer);
#endif // RENDERING_H

