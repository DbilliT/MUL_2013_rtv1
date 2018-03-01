/*
** my_RTV1.h for my_RTV1 in /home/bechad_p/Igraph/RTV1
** 
** Made by bechade_pierre
** Login   <bechad_p@epitech.net>
** 
** Started on  Tue Feb 25 14:42:28 2014 bechade_pierre
** Last update Sun Mar 16 23:25:50 2014 bechade_pierre
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <math.h>

#ifndef __RTV1__
#define __RTV1__

typedef struct s_vec
{
  double       	Vx;
  double       	Vy;
  double       	Vz;
}		t_vec;

typedef struct s_oeil
{
  double	z0;
  double	y0;
  double	x0;
}		t_oeil;

typedef struct s_light
{
  double	nX;
  double	nY;
  double	nZ;
  double	lX;
  double	lY;
  double	lZ;
}		t_light;
  
typedef struct	s_ptr
{
  void		*mlx_ptr;
  void		*win_ptr;
  void		*picture;
  char		*adresse_p;
  double       	delta;
  int		bpp;
  int		sizeline;
  int		endian; 
}		t_ptr;

typedef struct s_k
{
  double        kS;
  double	kC;
  double	kO;
  double	kP;
}	       t_k;

typedef struct	s_mlx
{
  t_k		k;
  t_vec		vec;
  t_oeil	oeil;
  t_ptr 	ptr;
  t_light	light;
}		t_mlx;

/* Prototype */
double    get_lum_cylindre(t_mlx *mlx);
double     inter_sphere(t_mlx *variable);
double   inter_cylindre(t_mlx *mlx);
double   inter_cone(t_mlx *mlx);
double     inter_plan(t_mlx *variable);
double     calcule_delta(double a, double b, double c);
void    calcule_vecteur(t_mlx *variable, int x, int y);
void    my_pixel_to_picture(t_mlx *, int color, int x, int y);
void    my_window_color(t_mlx *variable);
int     light_color(int color, t_mlx *mlx, int i);
double    get_lum_plan(t_mlx *mlx);
double    get_lum_cone(t_mlx *mlx);
double    get_lum_sphere(t_mlx *mlx);
int     gere_expose(void *param);
int     gere_key(int keycode, t_mlx *mlx);
/* Fin Prototype */

/* TAILLE_FENETRE */
#define SIZE_X 1024
#define SIZE_Y 1024
/* FIN_TAILLE_FENETRE */

/* Distance Oeil */
#define X0 -200
#define Y0 0
#define Z0 30
/* Fin Distance Oeil */

/* Dimension Forme */
#define R_CARRE pow(100, 2.0)
#define R_CYLINDER 40;
#define R_CONE 10;
/*Fin Dimension Forme */

#endif /* __RTV1__ */
