PKGS=sdl2
CFLAGS=-Wall -ggdb -std=c11 -pedantic `pkg-config --cflags sdl2`
LIBS=`pkg-config --libs sdl2`

main: 
	$(CC) $(CFLAGS) -o play credit.c food.c game.c obstacle.c rendering.c score.c snake.c main.c $(LIBS)