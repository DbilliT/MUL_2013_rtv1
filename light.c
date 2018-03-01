/*
** light.c for light in /home/bechad_p/Igraph/RTV1
** 
** Made by bechade_pierre
** Login   <bechad_p@epitech.net>
** 
** Started on  Sun Mar 16 16:46:15 2014 bechade_pierre
** Last update Sun Mar 16 22:23:27 2014 bechade_pierre
*/

#include "rtv1.h"
#include "mlx.h"

double	  get_lum_sphere(t_mlx *mlx) 
{ 
  double	vl; 
  double	vn; 
  double	a;
  
  mlx->light.nX = mlx->vec.Vx * mlx->k.kS + mlx->oeil.x0; 
  mlx->light.nY = mlx->vec.Vy * mlx->k.kS + mlx->oeil.y0; 
  mlx->light.nZ = mlx->vec.Vz * mlx->k.kS + mlx->oeil.z0;
  mlx->light.lX = -300 - mlx->light.nX; 
  mlx->light.lY = 0 - mlx->light.nY;   
  mlx->light.lZ = 150 - mlx->light.nZ;
  vn = sqrt(pow(mlx->light.nX, 2.0) 
	    + pow(mlx->light.nY, 2.0) 
	    + pow(mlx->light.nZ, 2.0)); 
  vl = sqrt(pow(mlx->light.lX, 2.0) 
	    + pow(mlx->light.lY, 2.0) 
	    + pow(mlx->light.lZ, 2.0)); 
  a = ((mlx->light.nX * mlx->light.lX) 
       + (mlx->light.nY * mlx->light.lY) 
       + (mlx->light.nZ * mlx->light.lZ)) / (vl * vn);
  if (a > 0 && a < 1) 
    return (a); 
  else 
    return (0); 
}

int	light_color(int color, t_mlx *mlx, int i) 
{
  double	R; 
  double	G; 
  double	B; 
  double	a;
  
  if (i == 1)
    a = get_lum_sphere(mlx);
  else if (i == 2)
    a = get_lum_cylindre(mlx);
  else if (i == 3)
    a = get_lum_plan(mlx);
  else if (i == 4)
    a = get_lum_cone(mlx);
  R = ((color >> 16) & 0x000000FF) * a; 
  G = ((color >> 8) & 0x000000FF) * a; 
  B = ((color) & 0x000000FF) * a; 
  return (((int)R << 16) + ((int)G << 8) + ((int)B)); 
}


double    get_lum_cylindre(t_mlx *mlx)
{
  double        vl;
  double        vn;
  double        a;

  mlx->light.nX = mlx->vec.Vx * mlx->k.kC 
    + mlx->oeil.x0;
  mlx->light.nY = mlx->vec.Vy * mlx->k.kC 
    + mlx->oeil.y0;
  mlx->light.nZ = 0;
  mlx->light.lX = -300 - mlx->light.nX;
  mlx->light.lY = 0 - mlx->light.nY;
  vn = sqrt(pow(mlx->light.nX, 2.0) 
	    + pow(mlx->light.nY, 2.0));
  vl = sqrt(pow(mlx->light.lX, 2.0) 
	    + pow(mlx->light.lY, 2.0));
  a = ((mlx->light.nX * mlx->light.lX) 
       + (mlx->light.nY * mlx->light.lY)) / (vl * vn);
  if (a > 0 && a < 1)
    return (a);
  else
    return (0);
}

double    get_lum_plan(t_mlx *mlx)
{
  double        vl;
  double        vn;
  double        a;

  mlx->light.nX = mlx->vec.Vx * mlx->k.kP + mlx->oeil.x0;
  mlx->light.nY = mlx->vec.Vy * mlx->k.kP + mlx->oeil.y0;
  mlx->light.nZ = mlx->vec.Vz * mlx->k.kP + mlx->oeil.z0;
  mlx->light.lX = -300 - mlx->light.nX;
  mlx->light.lY = 0 - mlx->light.nY;
  mlx->light.lZ = 150 - mlx->light.nZ;
  vn = sqrt(pow(mlx->light.nX, 2.0) 
	    + pow(mlx->light.nY, 2.0) 
	    + pow(mlx->light.nZ, 2.0));
  vl = sqrt(pow(mlx->light.lX, 2.0) + pow(mlx->light.lY, 2.0) 
	    + pow(mlx->light.lZ, 2.0));
  a = ((mlx->light.nX * mlx->light.lX) 
       + (mlx->light.nY * mlx->light.lY) 
       + (mlx->light.nZ * mlx->light.lZ)) / (vl * vn);
  if (a > 0 && a < 1)
    return (a);
  else
    return (0);
}

double    get_lum_cone(t_mlx *mlx)
{
  double        vl;
  double        vn;
  double        a;

  mlx->light.nX = mlx->vec.Vx * mlx->k.kO + mlx->oeil.x0;
  mlx->light.nY = mlx->vec.Vy * mlx->k.kO + mlx->oeil.y0;
  mlx->light.nZ = ((mlx->vec.Vz * mlx->k.kO 
		    + mlx->oeil.z0) * 0.1);
  mlx->light.lX = -300 - mlx->light.nX;
  mlx->light.lY = 0 - mlx->light.nY;
  mlx->light.lZ = 150 - mlx->light.nZ;
  vn = sqrt(pow(mlx->light.nX, 2.0) 
	    + pow(mlx->light.nY, 2.0) 
	    + pow(mlx->light.nZ, 2.0));
  vl = sqrt(pow(mlx->light.lX, 2.0) 
	    + pow(mlx->light.lY, 2.0) 
	    + pow(mlx->light.lZ, 2.0));
  a = ((mlx->light.nX * mlx->light.lX) 
       + (mlx->light.nY * mlx->light.lY) 
       + (mlx->light.nZ * mlx->light.lZ)) / (vl * vn);
  if (a > 0 && a < 1)
    return (a);
  else
    return (0);
}


