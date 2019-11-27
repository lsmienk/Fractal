/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tricorn.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmienk <lsmienk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/05 11:51:30 by lsmienk        #+#    #+#                */
/*   Updated: 2019/07/15 12:45:06 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		tricorn(t_mlx *mlx, float x, float y)
{
	int			i;
	float		xtemp;
	float		x0;
	float		y0;

	i = 0;
	x = (((x / SCREEN_WIDTH) * 3.5) - 2.5) * mlx->key.zoom;
	y = (((y / SCREEN_HEIGHT) * 2) - 1) * mlx->key.zoom;
	x0 = x;
	y0 = y;
	while (((x * x) + (y * y)) <= 4 && i < mlx->setup->itter)
	{
		xtemp = (x * x) - (y * y) + x0;
		y = ((-2 * x * y) + y0);
		x = (xtemp);
		i++;
	}
	return (i);
}
