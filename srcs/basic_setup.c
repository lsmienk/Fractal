/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   basic_setup.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmienk <lsmienk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/05 16:40:03 by lsmienk        #+#    #+#                */
/*   Updated: 2019/07/15 13:13:57 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		basic_setup(t_mlx *mlx)
{
	mlx->key.zoom = 2;
	mlx->key.on = 1;
	mlx->setup->itter = 42;
	mlx->setup->x = 0;
	mlx->setup->y = 0;
	mlx->key.w = 0;
	mlx->key.h = 0;
}
