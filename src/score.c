#include "score.h"

void update_score(Game *game, SDL_Window * window)
{
      static int prev_score = -1;
    if(prev_score == game->global_score)
    {
    // -- nothing to update
    return;
    }

    // -- create new string
    char str[45];
    sprintf(str, "Snake                  Score:  %d", game->global_score);
    SDL_SetWindowTitle(window, str);
    return;
}
