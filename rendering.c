#include "rendering.h"

void scc(int code) 
{
    if (code < 0)
    {
        printf("SDL error: %s\n", SDL_GetError());
        exit(1);
    }
    return;
}

void *scp(void *ptr)
{
  if (ptr == NULL)
  {
    printf("SDL error: %s\n", SDL_GetError());
    exit(1);
  }
  return ptr;
}


void render_board(SDL_Renderer *renderer)
{
  scc(SDL_SetRenderDrawColor(renderer, HEX_COLOR(GRID_COLOR)));
  
  for(int x = 0; x < BOARD_WIDTH; x++)
  {
    SDL_RenderDrawLine(renderer,
		       x * CELL_WIDTH, 0,             // starting (x_1, y_1)
		       x * CELL_WIDTH, SCREEN_HEIGHT  // ending   (x_2, y_2)
		       );
  }

  for(int y = 0; y < BOARD_HEIGHT; y++)
  {
    SDL_RenderDrawLine(renderer,
		       0, y * CELL_HEIGHT,	      // starting (x_1, y_1)
		       SCREEN_WIDTH, y * CELL_HEIGHT  // ending   (x_2, y_2)
		       );
  }
}

void render_square(SDL_Renderer *renderer, Pos pos, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
  scc(SDL_SetRenderDrawColor(renderer, r, g, b, a));
  
  SDL_Rect rect = {
    (int) floorf(pos.x * CELL_WIDTH),
    (int) floorf(pos.y * CELL_HEIGHT),
    (int) floorf(CELL_WIDTH),
    (int) floorf(CELL_HEIGHT),
  };

  scc(SDL_RenderFillRect(renderer, &rect));
}
