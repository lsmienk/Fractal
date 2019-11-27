/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   magic_loop.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmienk <lsmienk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/27 13:23:15 by lsmienk        #+#    #+#                */
/*   Updated: 2019/07/15 12:59:46 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		inbounds(int x, int y)
{
	if (x >= 0 && y >= 0 && x < SCREEN_WIDTH && y < SCREEN_HEIGHT)
		return (1);
	return (0);
}

static void		plotpoint(int x, int y, int colour, void *img_add)
{
	int *i_img;

	i_img = (int*)img_add;
	if (inbounds(x, y))
		ft_memcpy(&i_img[(y * SCREEN_WIDTH) + x], &colour, 4);
}

void			magic_loop(t_mlx *mlx)
{
	int x;
	int y;
	int i;
	int	colour;

	y = 0;
	while (y < SCREEN_HEIGHT)
	{
		x = 0;
		while (x < SCREEN_WIDTH)
		{
			colour = BLACK;
			i = mlx->setup->fractol(mlx, x + mlx->key.w, y + mlx->key.h);
			if (i < mlx->setup->itter)
				colour = colour_convert(mlx, (float)i, mlx->setup->colour);
			plotpoint((float)x, (float)y, colour, mlx->img_add);
			x++;
		}
		y++;
	}
}
