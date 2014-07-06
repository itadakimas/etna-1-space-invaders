#ifndef MAIN_H
#define MAIN_H
  #include        "includes.h"

  typedef         struct
  {
    SDL_Window    *window;
    SDL_Renderer  *renderer;

  }               t_SDL_objects;

  void            clear(t_SDL_objects *);
  void            init_success(t_SDL_objects *);
#endif