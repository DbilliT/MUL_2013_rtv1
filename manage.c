/*
** manage.c for manage in /home/bechad_p/MUL_2013_rtv1
** 
** Made by bechade_pierre
** Login   <bechad_p@epitech.net>
** 
** Started on  Sun Mar 16 22:44:36 2014 bechade_pierre
** Last update Sun Mar 16 23:25:00 2014 bechade_pierre
*/

#include "mlx.h"
#include "rtv1.h"

int	gere_key(int keycode, t_mlx *mlx)
{
  if (keycode == 65307)
    {
      mlx_destroy_window(mlx->ptr.mlx_ptr, mlx->ptr.win_ptr);
      exit(EXIT_SUCCESS);
    }
  return (0);
}

int     gere_expose(void *param)
{
  t_mlx	*mlx;

  mlx = (t_mlx*)param;
  mlx_put_image_to_window(mlx->ptr.mlx_ptr, mlx->ptr.win_ptr, mlx->ptr.picture, 0, 0);
  return (0);
}
