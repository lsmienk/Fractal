/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   drawinfo.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmienk <lsmienk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/17 11:35:54 by lsmienk        #+#    #+#                */
/*   Updated: 2019/07/15 13:21:06 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		drawinfo(t_mlx *mlx, int colour)
{
	mlx_string_put(mlx->info, mlx->win, 1, 1, colour, "Fractol : ");
	if (mlx->setup->fractol == julia)
		mlx_string_put(mlx->info, mlx->win, 100, 1, colour, "Julia");
	else if (mlx->setup->fractol == mandelbrot)
		mlx_string_put(mlx->info, mlx->win, 100, 1, colour, "Mandelbrot");
	else if (mlx->setup->fractol == tricorn)
		mlx_string_put(mlx->info, mlx->win, 100, 1, colour, "Tricorn");
	else if (mlx->setup->fractol == burningship)
		mlx_string_put(mlx->info, mlx->win, 100, 1, colour, "Burningship");
	mlx_string_put(mlx->info, mlx->win, 1, 25, colour, "Change fractol : F");
	mlx_string_put(mlx->info, mlx->win, 1, 45, colour, "Change colour : C");
	mlx_string_put(mlx->info, mlx->win, 1, 65, colour, "Zoom : Mouse Wheel");
	mlx_string_put(mlx->info, mlx->win, 1, 85, colour, "move : Arrows");
	mlx_string_put(mlx->info, mlx->win, 1, 105, colour, "Reset : R");
	mlx_string_put(mlx->info, mlx->win, 1, 125, colour, "Change details : +/-");
	if (mlx->setup->fractol == julia)
		mlx_string_put(mlx->info, mlx->win, 1, 145, \
		colour, "Freeze mouse : space");
}
