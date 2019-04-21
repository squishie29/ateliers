#include "SDL/SDL.h"
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>





int main(int argc, char *argv[])
{
int continuer=1,j=0;
 SDL_Surface *ecran = NULL, *background = NULL;
 SDL_Rect poscam,poscam2,test;
 SDL_Rect *posecran1=NULL;
 SDL_Event event;
    posecran1=&test;
    poscam.x=0;
    poscam.y=0;
    poscam2.x=0;
    poscam2.y=0;
    posecran1->x=500;
    posecran1->y=0;
  SDL_Init(SDL_INIT_VIDEO);

    ecran = SDL_SetVideoMode(1000,400,32, SDL_HWSURFACE|SDL_DOUBLEBUF | SDL_RESIZABLE);
    poscam.h=ecran->h;
    poscam.w=ecran->w/2;
    poscam2.h=ecran->h;
    poscam2.w=ecran->w/2;
    SDL_WM_SetCaption("game", NULL);

background=IMG_Load("map2.png");
SDL_BlitSurface(background, &poscam ,ecran, NULL);
SDL_BlitSurface(background, &poscam2 ,ecran, posecran1);
SDL_EnableKeyRepeat(1, 1);
while (continuer)
   {

    SDL_WaitEvent(&event) ;

    SDL_Flip(ecran);
    switch(event.type)
        {

            case SDL_QUIT:

                continuer = 0;

                break;
                case SDL_KEYDOWN  :
                {
                  Uint8 *keystates = SDL_GetKeyState( NULL );
                  if( keystates[ SDLK_LEFT ] )
                  {
                    if(poscam.x<(background->w-ecran->w/2))
                    {
                      poscam.x+=10;
                      SDL_BlitSurface(background, &poscam ,ecran,NULL);
                      SDL_Flip(ecran);
                    }
                  }
                  if( keystates[ SDLK_RIGHT ] )
                  {
                    if (poscam2.x<(background->w-ecran->w/2))
                    {
                      poscam2.x+=10;
                      SDL_BlitSurface(background, &poscam2 ,ecran,posecran1);
                      SDL_Flip(ecran);
                    }
                  }
                }
              case SDL_KEYUP : {
                j=0;
              }
                }







//SDL_BlitSurface(background, &poscam ,ecran,NULL);

    SDL_Flip(ecran);



  }
}
