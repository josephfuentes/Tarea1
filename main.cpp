
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<iostream>

SDL_Window* window;
SDL_Renderer* renderer;
SDL_Event Event;
SDL_Texture *background,*character;
SDL_Rect rect_background,rect_character;



int main( int argc, char* args[] )
{
    //Init SDL
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        return 10;
    }
    //Creates a SDL Window
    if((window = SDL_CreateWindow("Tarea 1", 100, 100, 500/*WIDTH*/, 250/*HEIGHT*/, SDL_WINDOW_RESIZABLE | SDL_RENDERER_PRESENTVSYNC)) == NULL)
    {
        return 20;
    }
    //SDL Renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED );
    if (renderer == NULL)
    {
        std::cout << SDL_GetError() << std::endl;
        return 30;
    }

    //Init textures
    int w=0,h=0;
    background = IMG_LoadTexture(renderer,"fondo.png");
    SDL_QueryTexture(background, NULL, NULL, &w, &h);
    rect_background.x = 0; rect_background.y = 0; rect_background.w = w; rect_background.h = h;

    character = IMG_LoadTexture(renderer, "personaje.png");
    SDL_QueryTexture(character, NULL, NULL, &w, &h);
    rect_character.x = 0; rect_character.y = 100; rect_character.w = w; rect_character.h = h;

    //Main Loop
    while(true)
    {
        while(SDL_PollEvent(&Event))
        {
            if(Event.type == SDL_QUIT)
            {
                return 0;
            }
            if(Event.type == SDL_KEYDOWN)
            {
                if(Event.key.keysym.sym == SDLK_d) //codigo que se ejecuta cuando, en el evento se presiona la tecla d
                if(rect_character.x<(rect_background.w-rect_character.w)-15) //esta condicion realiza la accion solo si la posicion del personaje es menor a la resta de la anchura del fondo y el personaje, tambien se le restan otros 15.
                    rect_character.x+=15; //realiza la accion de movimiento sobre el eje X

                if(Event.key.keysym.sym ==SDLK_a) //codigo que se ejecuta cuando, en el evento se presiona la tecla a
                if(rect_character.x>0) //se ejecutara el movimiento solo si la posicion del personaje es mayor a 0, ya que el plano comienza en 0
                rect_character.x-=15; //realiza el movimiento hacia la izquierda sobre el eje X;

                  if(Event.key.keysym.sym ==SDLK_s) //codigo que se ejecuta cuando, en el evento se presiona la tecla s
                if(rect_character.y<(rect_background.h-rect_character.h)) //se realiza el movimiento solo si la posicion del personaje en el eje y es menor a la resta de las alturas del fondo y del mismo personaje.
                rect_character.y+=15; //realiza el movimiento sobre el eje y, hacia abajo

                if(Event.key.keysym.sym ==SDLK_w) //codigo que se ejecuta cuando, en el evento se presiona la tecla w
                if(rect_character.y>0) //se ejecutara el movimiento solo si la posicion del personaje es mayor a 0, ya que el plano comienza en 0
                rect_character.y-=15; //realiza el movimiento sobre el eje y, hacia arriba


            }
        }

        SDL_RenderCopy(renderer, background, NULL, &rect_background);
        SDL_RenderCopy(renderer, character, NULL, &rect_character);
        SDL_RenderPresent(renderer);
    }

	return 0;
}
