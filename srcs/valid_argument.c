/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   valid_argument.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmienk <lsmienk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/25 14:38:19 by lsmienk        #+#    #+#                */
/*   Updated: 2019/07/15 13:16:21 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	compare(char *s1, char *s2, int len)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && len)
	{
		i++;
		len--;
	}
	if (s1[i] == s2[i])
		return (1);
	else
		return (0);
}

int			valid_argument(char *str, t_mlx *mlx)
{
	if (compare(str, "julia", ft_strlen("julia")))
		mlx->setup->fractol = julia;
	else if (compare(str, "mandelbrot", ft_strlen("mandelbrot")))
		mlx->setup->fractol = mandelbrot;
	else if (compare(str, "burningship", ft_strlen("burningship")))
		mlx->setup->fractol = burningship;
	else if (compare(str, "tricorn", ft_strlen("tricorn")))
		mlx->setup->fractol = tricorn;
	else
		return (0);
	return (1);
}
