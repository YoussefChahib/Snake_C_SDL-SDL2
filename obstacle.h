// Declares obstacle's functionality
#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "SDL2/SDL.h"
#include "structure.h"

// Defining vertical borders
#define VERTICAL_WALL_OBSACLE(game, off, x, y)\
    (game)->obs[off++] = (Obstacle){(Pos) {x, y + 0}, 1};\
    (game)->obs[off++] = (Obstacle){(Pos) {x, y + 1}, 1};\
    (game)->obs[off++] = (Obstacle){(Pos) {x, y + 2}, 1};\
    (game)->obs[off++] = (Obstacle){(Pos) {x, y + 3}, 1};\
    (game)->obs[off++] = (Obstacle){(Pos) {x, y + 4}, 1};\
    (game)->obs[off++] = (Obstacle){(Pos) {x, y + 5}, 1};\
    (game)->obs[off++] = (Obstacle){(Pos) {x, y + 6}, 1};\
    (game)->obs[off++] = (Obstacle){(Pos) {x, y + 7}, 1};\
    (game)->obs[off++] = (Obstacle){(Pos) {x, y + 8}, 1};\
    (game)->obs[off++] = (Obstacle){(Pos) {x, y + 9}, 1};\
    (game)->obs[off++] = (Obstacle){(Pos) {x, y + 10}, 1};\
    (game)->obs[off++] = (Obstacle){(Pos) {x, y + 11}, 1};\
    (game)->obs[off++] = (Obstacle){(Pos) {x, y + 12}, 1};\
    (game)->obs[off++] = (Obstacle){(Pos) {x, y + 13}, 1};\
    (game)->obs[off++] = (Obstacle){(Pos) {x, y + 14}, 1};\
    (game)->obs[off++] = (Obstacle){(Pos) {x, y + 15}, 1};\
    (game)->obs[off++] = (Obstacle){(Pos) {x, y + 16}, 1};\
    (game)->obs[off++] = (Obstacle){(Pos) {x, y + 17}, 1};\
    (game)->obs[off++] = (Obstacle){(Pos) {x, y + 18}, 1};\
    (game)->obs[off++] = (Obstacle){(Pos) {x, y + 19}, 1};\
    (game)->obs[off++] = (Obstacle){(Pos) {x, y + 20}, 1};\
    (game)->obs[off++] = (Obstacle){(Pos) {x, y + 21}, 1};\
    (game)->obs[off++] = (Obstacle){(Pos) {x, y + 22}, 1};\
    (game)->obs[off++] = (Obstacle){(Pos) {x, y + 23}, 1};\
    (game)->obs[off++] = (Obstacle){(Pos) {x, y + 24}, 1};\
    (game)->obs[off++] = (Obstacle){(Pos) {x, y + 25}, 1};

// Defining horizontal borders
#define HORIZONTAL_WALL_OBSACLE(game, off, x, y)	 \
    (game)->obs[off++] = (Obstacle){(Pos) {x + 1, y}, 1};\
    (game)->obs[off++] = (Obstacle){(Pos) {x + 2, y}, 1};\
    (game)->obs[off++] = (Obstacle){(Pos) {x + 3, y}, 1};\
    (game)->obs[off++] = (Obstacle){(Pos) {x + 4, y}, 1};\
    (game)->obs[off++] = (Obstacle){(Pos) {x + 5, y}, 1};\
    (game)->obs[off++] = (Obstacle){(Pos) {x + 6, y}, 1};\
    (game)->obs[off++] = (Obstacle){(Pos) {x + 7, y}, 1};\
    (game)->obs[off++] = (Obstacle){(Pos) {x + 8, y}, 1};\
    (game)->obs[off++] = (Obstacle){(Pos) {x + 9, y}, 1};\
    (game)->obs[off++] = (Obstacle){(Pos) {x + 10, y}, 1};\
    (game)->obs[off++] = (Obstacle){(Pos) {x + 11, y}, 1};\
    (game)->obs[off++] = (Obstacle){(Pos) {x + 12, y}, 1};\
    (game)->obs[off++] = (Obstacle){(Pos) {x + 13, y}, 1};\
    (game)->obs[off++] = (Obstacle){(Pos) {x + 14, y}, 1};\
    (game)->obs[off++] = (Obstacle){(Pos) {x + 15, y}, 1};\
    (game)->obs[off++] = (Obstacle){(Pos) {x + 16, y}, 1};\
    (game)->obs[off++] = (Obstacle){(Pos) {x + 17, y}, 1};\
    (game)->obs[off++] = (Obstacle){(Pos) {x + 18, y}, 1};\
    (game)->obs[off++] = (Obstacle){(Pos) {x + 19, y}, 1};\
    (game)->obs[off++] = (Obstacle){(Pos) {x + 20, y}, 1};\
    (game)->obs[off++] = (Obstacle){(Pos) {x + 21, y}, 1};\
    (game)->obs[off++] = (Obstacle){(Pos) {x + 22, y}, 1};\
    (game)->obs[off++] = (Obstacle){(Pos) {x + 23, y}, 1};\
    (game)->obs[off++] = (Obstacle){(Pos) {x + 24, y}, 1};

// Defining small plus obstacle
#define SMALL_PLUS_OBSTACLE(game, off, x, y)				         \
    (game)->obs[off++] = (Obstacle){(Pos) {x, y}, 1};    \
    (game)->obs[off++] = (Obstacle){(Pos) {x - 1, y + 1}, 1};\
    (game)->obs[off++] = (Obstacle){(Pos) {x, y + 1}, 1};\
    (game)->obs[off++] = (Obstacle){(Pos) {x + 1, y + 1}, 1};\
    (game)->obs[off++] = (Obstacle){(Pos) {x, y + 2}, 1}; 

// Defining big plus obstacle
#define BIG_PLUS_OBSTACLE(game, off, x, y)					\
    (game)->obs[off++] = (Obstacle){(Pos) {x, y}, 1};\
    (game)->obs[off++] = (Obstacle){(Pos) {x + 1, y}, 1};\
    (game)->obs[off++] = (Obstacle){(Pos) {x, y + 1}, 1};\
    (game)->obs[off++] = (Obstacle){(Pos) {x + 1, y + 1}, 1};\
    (game)->obs[off++] = (Obstacle){(Pos) {x - 2, y + 2}, 1};\
    (game)->obs[off++] = (Obstacle){(Pos) {x - 1, y + 2}, 1};\
    (game)->obs[off++] = (Obstacle){(Pos) {x, y + 2}, 1};\
    (game)->obs[off++] = (Obstacle){(Pos) {x + 1, y + 2}, 1};\
    (game)->obs[off++] = (Obstacle){(Pos) {x + 2, y + 2}, 1};\
    (game)->obs[off++] = (Obstacle){(Pos) {x + 3, y + 2}, 1};\
    (game)->obs[off++] = (Obstacle){(Pos) {x - 2, y + 3}, 1};\
    (game)->obs[off++] = (Obstacle){(Pos) {x - 1, y + 3}, 1};\
    (game)->obs[off++] = (Obstacle){(Pos) {x, y + 3}, 1};\
    (game)->obs[off++] = (Obstacle){(Pos) {x + 1, y + 3}, 1};\
    (game)->obs[off++] = (Obstacle){(Pos) {x + 2, y + 3}, 1};\
    (game)->obs[off++] = (Obstacle){(Pos) {x + 3, y + 3}, 1};\
    (game)->obs[off++] = (Obstacle){(Pos) {x, y + 4}, 1};\
    (game)->obs[off++] = (Obstacle){(Pos) {x + 1, y + 4}, 1};\
    (game)->obs[off++] = (Obstacle){(Pos) {x, y + 5}, 1};\
    (game)->obs[off++] = (Obstacle){(Pos) {x + 1, y + 5}, 1};


// Prototypes
int check_for_obstacles(Game *game);
void render_obstacles(SDL_Renderer *renderer, Game *game);
void init_wall_obstacle(Game *game);
void init_plus_obstacle(Game *game);

#endif // OBSTACLE_H
