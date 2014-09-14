/*
* @Author: BERTEAUX
* @Date:   2014-07-16 17:42:16
* @Last Modified by:   alexlezard
* @Last Modified time: 2014-09-07 19:17:16
*/
#ifndef STRUCTURES_H
#define STRUCTURES_H

  typedef struct s_animation t_animation;
  struct                  s_animation
  {
    int                   id ;                 /* Identifiant de l'animation */
    int                   nb_frames;           /* Numéro de frames de l'animation */
    char                  *url_image;
    t_animation           *next;               /*Suite de la liste chainée */
  };

  typedef                 struct
  {
    int                   x;                  /* Coordonnées x */
    int                   y;                  /* Coordonnées y */
    int                   width;              /* Longueur */
    int                   height;             /* Hauteur */
    int                   life;               /* Vie */
    bool                  can_move;           /* Indique si le vaisseau peut bouger */
    bool                  can_shoot;          /* Indique si le vaisseau peut tirer */
    t_animation           *animation;         /* Animation */
    int                   previous_animation; /* ID de l'ancienne animation */
    SDL_Surface           *image;             /* Image */
    int                   num_frame;          /* Numéro du frame en cours de l'image */

  }                       t_ship;

  typedef                 struct s_enemy
  {
    int                   x;
    int                   y;
    int                   width;
    int                   height;
    int                   num_frame;
    int                   level;
    SDL_Surface           *image;
    t_animation           animation;
    struct s_enemy        *next;

  }                       t_enemy;

  typedef                 struct s_rocket
  {
    int                   id;
    int                   x;
    int                   y;
    int                   width;
    int                   height;
    SDL_Surface           *image;
    struct s_rocket       *next;

  }                       t_rocket;

  typedef                 struct
  {
    int                   level1;
    int                   level2;
    int                   level3;

  }                       t_level_event_enemies;

  typedef                 struct
  {
    bool                  triggered;
    char                  type;
    Uint32                timestamp;
    t_level_event_enemies enemies;

  }                       t_level_event;

  typedef                 struct
  {
    int                   eventsCount;
    int                   number;
    bool                  completed;
    Uint32                timestamp;
    t_level_event         **events;

  }                       t_level;

  typedef                 struct
  {
    SDL_Window            *window;
    SDL_Renderer          *renderer;
    t_ship                *ship;
    t_enemy               *enemy;
    t_rocket              *rocket;
    t_level               *level;
    t_animation           *list_animations;       /* Liste chainée des animations */

  }                       t_SDL_objects;

#endif