/*
** Igraph_test.c for Igrah_test in /home/bechad_p/Igraph
** 
** Made by bechade_pierre
** Login   <bechad_p@epitech.net>
** 
** Started on  Mon Feb 24 15:42:16 2014 bechade_pierre
** Last update Sun Mar 16 23:32:31 2014 bechade_pierre
*/

#include <math.h>
#include "mlx.h"
#include "rtv1.h"

void	my_pixel_to_picture(t_mlx *mlx, int color, int x, int y)
{
  int	i;
  char	*my_color = (char *)&color;

  i = (x * 4) + (y * 4 * SIZE_X);
  mlx->ptr.adresse_p[i] = my_color[0];
  mlx->ptr.adresse_p[i + 1] = my_color[1];
  mlx->ptr.adresse_p[i + 2] = my_color[2];
}

void	my_window_colorv2(t_mlx *mlx, int x, int y)
{
  mlx->k.kS = inter_sphere(mlx);
  mlx->k.kP = inter_plan(mlx);
  mlx->k.kO = inter_cone(mlx);
  mlx->k.kC = inter_cylindre(mlx);
  if (mlx->k.kS < 0)
    mlx->k.kS = 900;
  if (mlx->k.kP < 0)
    mlx->k.kP = 900;
  if (mlx->k.kC < 0)
    mlx->k.kC = 900;
  if (mlx->k.kO < 0)
    mlx->k.kO = 900;
  if (mlx->k.kS > 0 && mlx->k.kS < mlx->k.kP 
      && mlx->k.kS < mlx->k.kC && mlx->k.kS < mlx->k.kO)
    my_pixel_to_picture(mlx, light_color(0xC03000, mlx, 1), x, y);
  else if (mlx->k.kP > 0 && mlx->k.kP < mlx->k.kS 
	   && mlx->k.kP < mlx->k.kC && mlx->k.kP < mlx->k.kO)
    my_pixel_to_picture(mlx, light_color(0x40411E, mlx, 3), x, y);
  else if (mlx->k.kC > 0 && mlx->k.kC < mlx->k.kS 
	   && mlx->k.kC < mlx->k.kP && mlx->k.kC < mlx->k.kO)
    my_pixel_to_picture(mlx, light_color(0x4BB5C1, mlx, 2), x, y);
  else if (mlx->k.kO > 0 && mlx->k.kO < mlx->k.kS 
	   && mlx->k.kO < mlx->k.kC && mlx->k.kO < mlx->k.kP)
    my_pixel_to_picture(mlx, light_color(0xD90063, mlx, 4), x, y);
}

void	my_window_color(t_mlx *mlx)
{
  int	x;
  int	y;

  x = 0;
  y = 0;
  while ((x != SIZE_X) && (y != SIZE_Y))
    {
      mlx->vec.Vy = (SIZE_X / 2.0) - x;
      mlx->vec.Vz = (SIZE_Y / 2.0) - y;
      my_window_colorv2(mlx, x, y);
      x++;
      if (x == SIZE_X)
	{
	  y++;
	  x = 0;
	}
    }
  mlx_put_image_to_window(mlx->ptr.mlx_ptr, mlx->ptr.win_ptr, mlx->ptr.picture, 0, 0);
}

int	main()
{
  t_mlx		mlx;

  mlx.oeil.x0 = X0;
  mlx.oeil.z0 = Z0;
  mlx.oeil.y0 = Y0;
  mlx.vec.Vx = 100.0;
  mlx.ptr.mlx_ptr = mlx_init();
  if (mlx.ptr.mlx_ptr == NULL)
    return (0);
  mlx.ptr.win_ptr = mlx_new_window(mlx.ptr.mlx_ptr, SIZE_X, SIZE_Y, "RTV1");
  mlx.ptr.picture = mlx_new_image(mlx.ptr.mlx_ptr, SIZE_X, SIZE_Y);
  mlx.ptr.adresse_p = mlx_get_data_addr(mlx.ptr.picture, &mlx.ptr.bpp, &mlx.ptr.sizeline, &mlx.ptr.endian);
  my_window_color(&mlx);
  mlx_key_hook(mlx.ptr.win_ptr, &gere_key, &mlx);
  mlx_expose_hook(mlx.ptr.win_ptr, &gere_expose, &mlx);
  mlx_loop(mlx.ptr.mlx_ptr);
  return (0);
}
