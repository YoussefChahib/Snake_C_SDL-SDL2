#include <sys/time.h>
#include "snake.h"
#include "rendering.h"

Pos *get_snake_head(Snake *snake) 
{
  return &snake->body[snake->length - 1];
}

int allow_snake_movement(int manual, Game *game)
{
    static struct timeval old_t = {0};
    static struct timeval new_t = {0};
    static int init = -1;
    double time_elapsed = -1;

    if (init == -1)
    {
        // -- first call to function
        init = 1;
        gettimeofday(&old_t, NULL);
        return manual ? 1 : 0;
    }
        
    gettimeofday(&new_t, NULL);
    time_elapsed = (double) (new_t.tv_usec - old_t.tv_usec) / 1000000 +
        (double) (new_t.tv_sec - old_t.tv_sec);
    
    if (!manual && time_elapsed < game->game_speed)
    {
        // not enough time has passed for automatic movement
        return 0;
    } 
    else
    {
        old_t = new_t;
        return 1;
    }
}

Pos peak_next_pos(Snake *snake, Dir new_dir)
{
    Pos new_pos;
    Pos *head_pos = get_snake_head(snake);

    switch(new_dir)
    {
    case DIR_RIGHT:
        new_pos.x = (head_pos->x + 1) % BOARD_WIDTH;
        new_pos.y = head_pos->y;
        break;
        
    case DIR_LEFT:
        new_pos.x = head_pos->x == 0 ? BOARD_WIDTH - 1 : head_pos->x - 1;
        new_pos.y = head_pos->y;
        break;

    case DIR_UP:
        new_pos.x = head_pos->x;    
        new_pos.y = head_pos->y == 0 ? BOARD_HEIGHT - 1 : head_pos->y - 1;
        break;

    case DIR_DOWN:
        new_pos.x = head_pos->x;    
        new_pos.y = (head_pos->y + 1) % BOARD_HEIGHT;
        break;
    }
    return new_pos;
}

void move_snake(Game *game, Dir new_dir, int manual)
{
    if(!allow_snake_movement(manual, game))
    {
        return;
    }

    Snake *snake = &game->snake;
    Pos new_pos = peak_next_pos(snake, new_dir);

    // cant move back to snake's own tail
    if (snake->length >= 2 &&
        new_pos.x == snake->body[snake->length - 2].x &&
        new_pos.y == snake->body[snake->length - 2].y)
        {
            return;
        }

    // perform movement
    Pos *head_pos = get_snake_head(snake);
    Pos old_pos = *head_pos;
    Pos tmp_pos = old_pos;

    *head_pos = new_pos;
    snake->dir = new_dir;

    for (int i = snake->length -2 ; i >= 0; i--)
    {
        tmp_pos = snake->body[i];
        snake->body[i] = old_pos;
        old_pos = tmp_pos;
    }
}

void render_snake(SDL_Renderer *renderer, Game *game)
{
    for (int i = game->snake.length - 1; i >= 0; i--)
    {
        render_square(renderer, game->snake.body[i], HEX_COLOR(SNAKE_COLOR));
    }
}
