#include "obstacle.h"
#include "snake.h"
#include "rendering.h"

int off = 0;
void init_wall_obstacle(Game *game)
{
    VERTICAL_WALL_OBSACLE(game, off, 0, 0);
    VERTICAL_WALL_OBSACLE(game, off, 25, 0);
    HORIZONTAL_WALL_OBSACLE(game, off, 0, 0);
    HORIZONTAL_WALL_OBSACLE(game, off, 0, 25);
    return;
}
void init_plus_obstacle(Game *game)
{
    SMALL_PLUS_OBSTACLE(game, off, 3, 2);
    SMALL_PLUS_OBSTACLE(game, off, 22, 2);
    SMALL_PLUS_OBSTACLE(game, off, 3, 21);
    SMALL_PLUS_OBSTACLE(game, off, 22, 21);
    BIG_PLUS_OBSTACLE(game, off, 12, 6);
    BIG_PLUS_OBSTACLE(game, off, 12, 14);
    return;
}


// Function that renders obstacles
void render_obstacles(SDL_Renderer *renderer, Game *game)
{
    scc(SDL_SetRenderDrawColor(renderer, HEX_COLOR(OBSTACLE_COLOR)));
    for (int i = 0; i < OBSTACLES_COUNT; i++)
    {
        Obstacle ob = game->obs[i];
        // do not render Uninitialized obstacles 
        if (!ob.init)
        {
        continue;
        }
        render_square(renderer, ob.pos, HEX_COLOR(OBSTACLE_COLOR));
        }
  return;
}

int check_for_obstacles(Game *game) {
  Snake *s = &game->snake;
  Pos head_pos = *get_snake_head(s);

  // did we go into our own tail?
  for (int i = 0; i < s->length - 2; i++) {
    if (s->body[i].x == head_pos.x && s->body[i].y == head_pos.y)
    {
      printf("You lost!\nYour score is : %i\n", game->global_score);
      return 1;
    }
  }

  // or against an initialized obstacle?
  for (int i = 0; i < OBSTACLES_COUNT; i++) {
    Obstacle ob = game->obs[i];
    if (ob.init && ob.pos.x == head_pos.x && ob.pos.y == head_pos.y)
    {
      printf("You lost!\nYour score is : %i\n", game->global_score);
      return 1;
    }
  }

  return 0;
}
