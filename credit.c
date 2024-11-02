#include <stdbool.h>
#include "constant.h"
#include "rendering.h"

void credit(void)
{
    SDL_Init( SDL_INIT_VIDEO );
    SDL_Window *const window = scp(SDL_CreateWindow("حازوقات", 0, 0, SCREEN_WIDTH - 10, SCREEN_HEIGHT - 10, SDL_WINDOW_SHOWN)); 
    SDL_Surface* gScreenSurface = SDL_GetWindowSurface( window );
    SDL_Surface* gHelloWorld = SDL_LoadBMP( "credit.bmp" );
    SDL_BlitSurface( gHelloWorld, NULL, gScreenSurface, NULL );			
    SDL_UpdateWindowSurface( window );
    SDL_Event e; bool quit = false; while( quit == false ){ while( SDL_PollEvent( &e ) ){ if( e.type == SDL_QUIT ) quit = true; } }
	SDL_FreeSurface( gHelloWorld );
	gHelloWorld = NULL;
	SDL_DestroyWindow( window );

	//Quit SDL subsystems
	SDL_Quit();
    return;
}



