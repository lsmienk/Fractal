/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol_loop.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmienk <lsmienk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/27 17:33:56 by lsmienk        #+#    #+#                */
/*   Updated: 2019/07/05 15:02:40 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		fractol_loop(void *param)
{
	t_mlx			*mlx;

	mlx = (t_mlx *)param;
	magic_loop(mlx);
	mlx_put_image_to_window(mlx->info, mlx->win, mlx->img, 0, 0);
	drawinfo(mlx, IMRE_PINK);
	return (1);
}
