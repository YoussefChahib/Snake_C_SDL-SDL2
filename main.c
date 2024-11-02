#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <time.h>
#include "SDL2/SDL.h"
#include "constant.h"
#include "rendering.h"
#include "snake.h"
#include "game.h"
#include "food.h"
#include "obstacle.h"
#include "credit.h"


Game GAME = {0};
void update_game_state(Game *game)
{
    move_snake(&GAME, GAME.snake.dir, 0);
    GAME.quit |= check_for_obstacles(&GAME);    
    Food *f = check_for_food(&GAME);
    if (f)
    {
        eat_food(&GAME, f);
        update_food(&GAME);  
    }
}


int main(int argc, char const *argv[])
{
    int difficulty = -1;
    if (argc != 2)
    {
        printf("Usage: ./play option\nTo see available run the following command: ./play help\n");
        return 1;
    }
    
    else if (strcasecmp(argv[1], "0") * strcasecmp(argv[1], "1") * strcasecmp(argv[1], "2") * strcasecmp(argv[1], "3") == 0) 
    {
        difficulty = (int)(atoi(argv[1]));
    }
    
    else if (strcasecmp(argv[1], "help") == 0)
    {
        printf("To play this game run the following command: ./play option\n");
        printf("Available options: \n");
        printf("          0: slow snake, no obstacles, no borders\n");
        printf("          1: slow snake, no obstacles, borders\n");
        printf("          2: slow snake, obstacles, borders\n");
        printf("          3: fast snake, obstacles, borders\n");
        printf("          credit: to see the creators of this game\n");
        printf("          help: to display this help message\n");
        return 0;
    }

    else if (strcasecmp(argv[1], "credit") == 0)
    {
        credit();
        return 0;
    }
    
    else
    {
        printf("Usage: ./play option\nTo see available run the following command: ./play help\n");
        return 1;
    }

    double speed;
    int OBSTACLE_FLAG, BORDER_FLAG;

    switch (difficulty)
    {
        case 0:
            speed = 0.3;
            OBSTACLE_FLAG = 0;
            BORDER_FLAG = 0;
            break;
        case 1:
            speed = 0.3;
            OBSTACLE_FLAG = 0;
            BORDER_FLAG = 1;
            break;
        case 2:
            speed = 0.3;
            OBSTACLE_FLAG = 1;
            BORDER_FLAG = 1;
            break;
        case 3:
            speed = 0.15;
            OBSTACLE_FLAG = 1;
            BORDER_FLAG = 1;
            break;
    }

    srand(time(0));

    // init classic SDL
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *const window = scp(SDL_CreateWindow("Snake                  Score: 0", 0, 0, SCREEN_WIDTH - 10, SCREEN_HEIGHT - 10, SDL_WINDOW_SHOWN)); 
    SDL_Renderer *const renderer = scp(SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED));

    init_game(&GAME, OBSTACLE_FLAG, BORDER_FLAG, speed);

  while(!GAME.quit) {
    SDL_Event event;

    // event handling
    while(SDL_PollEvent(&event)) 
    {
        if (event.type == SDL_QUIT)
        {
            GAME.quit = 1;
        }

        if (event.type == SDL_KEYDOWN)
        {
            if (event.key.keysym.sym == SDLK_UP && (GAME.snake.dir == 0 || GAME.snake.dir == 2))
            {
                move_snake(&GAME, DIR_UP, 1);
                break;
            }

            if (event.key.keysym.sym == SDLK_DOWN && (GAME.snake.dir == 0 || GAME.snake.dir == 2))
            {
                move_snake(&GAME, DIR_DOWN, 1);
                break;  
            }

            if (event.key.keysym.sym == SDLK_LEFT && (GAME.snake.dir == 1 || GAME.snake.dir == 3))
            {
                move_snake(&GAME, DIR_LEFT, 1);
                break;
            }

            if (event.key.keysym.sym == SDLK_RIGHT && (GAME.snake.dir == 1 || GAME.snake.dir == 3))
            {
                move_snake(&GAME, DIR_RIGHT, 1);
                break;
            }	  
        }
    }

    // main logic loop

    update_game_state(&GAME);
    // rendering stuff
    render_game(renderer, &GAME, window);
  }


  SDL_Quit();
  
  return 0;
}
