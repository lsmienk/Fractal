/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   colour_convert.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmienk <lsmienk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/13 11:12:33 by lsmienk        #+#    #+#                */
/*   Updated: 2019/07/15 12:59:46 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				colour_convert(t_mlx *mlx, float i, int colour)
{
	int		red;
	int		green;
	int		blue;
	long	hex;

	i = i / mlx->setup->itter;
	red = ((colour >> 16) & 0xFF) * i;
	green = ((colour >> 8) & 0xFF) * i;
	blue = (colour & 0xFF) * i;
	hex = (red << 16L);
	hex += green << 8L;
	hex += blue;
	return ((int)hex);
}
