/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   burningship.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmienk <lsmienk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/28 15:05:54 by lsmienk        #+#    #+#                */
/*   Updated: 2019/07/15 12:45:38 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				burningship(t_mlx *mlx, float x, float y)
{
	int		i;
	float	xtemp;
	float	x0;
	float	y0;

	i = 0;
	x = ((((x / SCREEN_WIDTH)) * 3.5) - 2.5) * mlx->key.zoom;
	y = ((((y / SCREEN_HEIGHT)) * 2) - 1) * mlx->key.zoom;
	x0 = 0;
	y0 = 0;
	while (((x0 * x0) + (y0 * y0)) <= 4 && i < mlx->setup->itter)
	{
		xtemp = (x0 * x0) - (y0 * y0) + x;
		y0 = 2 * fabs(x0 * y0) + y;
		x0 = fabs(xtemp);
		i++;
	}
	return (i);
}
