/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mouse_control.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmienk <lsmienk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/03 13:26:02 by lsmienk        #+#    #+#                */
/*   Updated: 2019/07/15 13:14:02 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		mouse_zoom(int keycode, int x, int y, void *param)
{
	t_mlx *mlx;

	x -= y;
	mlx = (t_mlx*)param;
	if (keycode == 4)
		mlx->key.zoom *= 1.1;
	else if (keycode == 5)
		mlx->key.zoom /= 1.1;
	return (0);
}

static int		mouse_move(int x, int y, void *param)
{
	t_mlx *mlx;

	mlx = (t_mlx*)param;
	if (mlx->key.on == 1)
	{
		mlx->setup->x = x;
		mlx->setup->y = y;
	}
	return (0);
}

void			mouse_control(t_mlx *mlx)
{
	mlx_hook(mlx->win, MOVE_EVENT, NULL_MASK, mouse_move, (void*)mlx);
	mlx_mouse_hook(mlx->win, mouse_zoom, mlx);
}
