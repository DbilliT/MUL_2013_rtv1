/*
** calcule_RTV1.c for calcule in /home/bechad_p/Igraph/RTV1
** 
** Made by bechade_pierre
** Login   <bechad_p@epitech.net>
** 
** Started on  Wed Feb 26 09:29:10 2014 bechade_pierre
** Last update Sun Mar 16 22:21:48 2014 bechade_pierre
*/

#include "rtv1.h"
#include "mlx.h"

double    inter_plan(t_mlx *mlx)
{
  return (-(mlx->oeil.z0 / mlx->vec.Vz));
}

double    calcule_delta(double a, double b, double c)
{
  double	delta;
  double	k1;
  double	k2;

  delta = pow(b, 2.0) - (4 * a * c);
  if (delta > 0)
    {
      k1 = ((b * -1) + sqrt(delta)) / (2 * a);
      k2 = ((b * -1) - sqrt(delta)) / (2 * a);
      if (k1 > k2)
	return (k2);
      else if (k1 < k2)
	return (k1);
    }
  else if (delta == 0)
    return (-b / (2 * a));
  return (-1);
}

double	 inter_sphere(t_mlx *mlx)
{
  double	a;
  double	b;
  double	c;

  a = pow(mlx->vec.Vx, 2.0) 
    + pow(mlx->vec.Vy, 2.0) + pow(mlx->vec.Vz, 2.0); 
  b = 2 * ((mlx->oeil.x0 * mlx->vec.Vx) 
	   +(mlx->oeil.y0 * mlx->vec.Vy)
    + (mlx->oeil.z0 * mlx->vec.Vz));
  c = pow(mlx->oeil.x0, 2.0) + pow(mlx->oeil.y0, 2.0) 
    + pow(mlx->oeil.z0, 2.0) - R_CARRE;
  return (calcule_delta(a, b, c));
}

double   inter_cylindre(t_mlx *mlx)
{
  double	a;
  double	b;
  double	c;

  a = pow(mlx->vec.Vx, 2.0) + pow(mlx->vec.Vy, 2.0);
  b = ((2.0 * mlx->vec.Vx * mlx->oeil.x0)
       + (2.0 * mlx->vec.Vy * mlx->oeil.y0));
  c = pow(mlx->oeil.x0, 2.0) 
    + pow(mlx->oeil.y0, 2.0) 
    - pow(40, 2.0);
  return (calcule_delta(a, b, c));
}

double   inter_cone(t_mlx *mlx)
{
  double	a;
  double	b;
  double	c;
  float	R;

  R = 10 * M_PI / 180;
  a = pow(mlx->vec.Vx, 2.0) + pow(mlx->vec.Vy, 2.0) 
    - (pow(mlx->vec.Vz, 2.0) * (pow(tan(R), 2.0)));
  b = (2.0 * mlx->vec.Vx * mlx->oeil.x0) 
    + (2.0 * mlx->vec.Vy * mlx->oeil.y0) 
    - ((2.0 * mlx->vec.Vz * mlx->oeil.z0) * (pow(tan(R), 2.0)));
  c = (pow(mlx->oeil.x0, 2.0) + pow(mlx->oeil.y0, 2.0) 
       - (pow(mlx->oeil.z0, 2.0) * pow(tan(R), 2.0)));
  return (calcule_delta(a, b, c));
}

