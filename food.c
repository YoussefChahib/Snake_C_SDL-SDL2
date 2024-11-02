#include "rendering.h"
#include "food.h"
#include "snake.h"
// #include "game.h"

int random_int_range(int low, int high) 
{
    return (rand() % (high - low)) + low;
}
Pos random_board_pos(void)
{
  Pos p = {0};
  p.x = random_int_range(0, BOARD_WIDTH);
  p.y = random_int_range(0, BOARD_HEIGHT);

  return p;
}

Pos random_empty_board_pos(Game *game)
{
  Pos p = {0};
  do {
    p = random_board_pos();
  } while (pos_is_not_empty(game, p));

  return p;
}

void init_food(Game *game)
{
  for (int i = 0; i < FOODS_COUNT; i++) {
    game->food[i].score = 1;
    game->food[i].pos = random_empty_board_pos(game);
  }

  return;

}


Food *check_for_food(Game *game)
{
    Snake *snake = &game->snake;
    Pos head_pos = *get_snake_head(snake);
    for (int i = 0; i < FOODS_COUNT; i++)
    {
        Food *f = &game->food[i];

        if(f->pos.x == head_pos.x && f->pos.y == head_pos.y && f->score > 0)
        {
            return f;
        }
    }

    return NULL;
}

void update_food(Game *game)
{
    init_food(game);
    return;
}

void eat_food(Game *game, Food *f)
{
  Snake *snake = &game->snake;

  // eat food
  game->global_score += f->score;
  f->score = 0;

  // grow snake's body
  Pos new_pos = peak_next_pos(snake, snake->dir);
  snake->length += 1;
  snake->body[snake->length - 1] = new_pos;

  return;
}

void render_food(SDL_Renderer *renderer, Game *game) 
{
  for (int i = 0; i < FOODS_COUNT; i++)
  {
    if (game->food[i].score == 0)
    {
        continue; // Skip foods that have already been eaten
    }
    render_square(renderer, game->food[i].pos, HEX_COLOR(FOOD_COLOR));
  }
}

int pos_is_not_empty(Game *game, Pos p)
{
    // Food is here?
    for (int i = 0; i < FOODS_COUNT; i++) {
        if (p.x == game->food[i].pos.x && p.y == game->food[i].pos.y)
        return 1;
    }

    for (int i = 0; i < game->snake.length; i++) {
        if (p.x == game->snake.body[i].x &&
        p.y == game->snake.body[i].y)
        return 1;
    }  

    for (int i = 0; i < OBSTACLES_COUNT; i++) {
        if (p.x == game->obs[i].pos.x && p.y == game->obs[i].pos.y)
        return 1;
    }  

    return 0;
}
