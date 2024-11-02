#include "SDL2/SDL.h"
#include "game.h"
#include "obstacle.h"
#include "snake.h"
#include "rendering.h"
#include "score.h"
#include "food.h"




void init_game(Game *game, int OBSTACLE_FLAG, int BORDER_FLAG, double speed)
{
    // -- init snake
    Pos p1 = {12, 12};
    Pos p0 = {13, 12};
    game->snake.body[0] = p0;
    game->snake.body[1] = p1;
    game->snake.length = 2;
    game->snake.dir = 2;
    
    init_food(game);

    // init obstacles
    if (OBSTACLE_FLAG == 1)
    {
        init_plus_obstacle(game);
    }
    if (BORDER_FLAG == 1)
    {
        init_wall_obstacle(game);
    }
    
    
    game->quit = 0;
    game->global_score = 0;
    game->game_speed = speed;
}




void render_game(SDL_Renderer *renderer, Game *game, SDL_Window * window)
{
    scc(SDL_SetRenderDrawColor(renderer, HEX_COLOR(BACKGROUND_COLOR)));
    SDL_RenderClear(renderer);
    
    render_snake(renderer, game);
    render_food(renderer, game);
    render_obstacles(renderer, game);
    update_score (game, window);
    SDL_RenderPresent(renderer);
    return;
}
