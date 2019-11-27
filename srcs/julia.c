/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   julia.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmienk <lsmienk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/17 12:18:34 by lsmienk        #+#    #+#                */
/*   Updated: 2019/07/15 12:44:48 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			julia(t_mlx *mlx, float x, float y)
{
	int			i;
	float		xtemp;
	float		x0;
	float		y0;

	i = 0;
	x0 = -0.8 + (((float)mlx->setup->x / (float)SCREEN_WIDTH) * 2) - 1;
	y0 = 0.156 + (((float)mlx->setup->y / (float)SCREEN_WIDTH) * 2) - 1;
	x = (((x / SCREEN_WIDTH) * 3) - 1.5) * mlx->key.zoom;
	y = (((y / SCREEN_HEIGHT) * 2) - 1) * mlx->key.zoom;
	while (((x * x) + (y * y)) <= 4 && i < mlx->setup->itter)
	{
		xtemp = (x * x) - (y * y) + x0;
		y = ((2 * x * y) + y0);
		x = (xtemp);
		i++;
	}
	return (i);
}
