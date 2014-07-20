/*
* @Author: BERTEAUX
* @Date:   2014-07-16 14:59:54
* @Last Modified by:   ahemt_s
* @Last Modified time: 2014-07-20 20:06:17
*/

#include      "../headers/main.h"

void          init_ship(t_SDL_objects *SDL)
{
  SDL->ship = malloc(sizeof(t_ship));

	/*Position de base*/
	SDL->ship->x = 0;
  SDL->ship->y = 0;
  SDL->ship->num_frame = 0;

  /*Taille d'un déplacement*/
  SDL->ship->width	= 150;
  SDL->ship->height	= 121;

  /*Config*/
  SDL->ship->image = IMG_Load("assets/images/dracaufeu.png");
  if(!SDL->ship->image)
  {
    printf("Image non chargée");
    exit(EXIT_FAILURE);
  }

  /*Animation*/
  SDL->ship->animation.nb_frames = 12;
}

void          move_ship(int direction, t_SDL_objects *SDL)
{
	switch (direction)
  {
    case SDLK_DOWN:
      SDL->ship->y += 50;
      break;
    case SDLK_UP:
      if (SDL->ship->y - 50 >= 0) SDL->ship->y -= 50;
      break;
    case SDLK_RIGHT:
      SDL->ship->x += 50;
      break;
    case SDLK_LEFT:
      if (SDL->ship->x - 50 >= 0) SDL->ship->x -= 50;
      break;
  }
}

void          print_ship(t_SDL_objects *SDL)
{
  SDL_Rect    sourc;
  SDL_Rect    dest;
  SDL_Texture *texture;

  sourc.x = SDL->ship->width * SDL->ship->num_frame;
  sourc.y = 0;
  sourc.w = SDL->ship->width;
  sourc.h = SDL->ship->height;

  dest.x = SDL->ship->x;
  dest.y = SDL->ship->y;
  dest.w = SDL->ship->width;
  dest.h = SDL->ship->height;

  if (SDL->ship->num_frame < SDL->ship->animation.nb_frames)
  {
    SDL->ship->num_frame++;
  }
  else
  {
    SDL->ship->num_frame = 0;
  }

  texture = SDL_CreateTextureFromSurface(SDL->renderer,SDL->ship->image);

  if (texture < 0)
  {
    printf("Texture non chargée dans print_ship");
    exit(EXIT_FAILURE);
  }

  if (SDL_RenderCopy(SDL->renderer, texture, &sourc, &dest) < 0)
  {
    printf("RenderCopy non chargée dans print_ship");
    exit(EXIT_FAILURE);
  }
}