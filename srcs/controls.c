/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   controls.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmienk <lsmienk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/15 13:49:37 by lsmienk        #+#    #+#                */
/*   Updated: 2019/07/15 13:15:10 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		swap_fractol(t_mlx *mlx)
{
	if (mlx->setup->fractol == mandelbrot)
		mlx->setup->fractol = julia;
	else if (mlx->setup->fractol == julia)
		mlx->setup->fractol = burningship;
	else if (mlx->setup->fractol == burningship)
		mlx->setup->fractol = tricorn;
	else if (mlx->setup->fractol == tricorn)
		mlx->setup->fractol = mandelbrot;
}

static void		swap_colour(t_mlx *mlx)
{
	if (mlx->setup->colour == IMRE_PINK)
		mlx->setup->colour = VELA;
	else if (mlx->setup->colour == VELA)
		mlx->setup->colour = LIGHT_GREEN;
	else if (mlx->setup->colour == LIGHT_GREEN)
		mlx->setup->colour = LIGHT_BLUE;
	else if (mlx->setup->colour == LIGHT_BLUE)
		mlx->setup->colour = IMRE_PINK;
}

static void		arrow_control(t_mlx *mlx, int key)
{
	int i;

	i = 0;
	if (mlx->key.zoom < 1)
		i = 20;
	else
		i = 5;
	if (key == KEY_DOWN)
		mlx->key.h -= i;
	else if (key == KEY_UP)
		mlx->key.h += i;
	else if (key == KEY_RIGHT)
		mlx->key.w -= i;
	else if (key == KEY_LEFT)
		mlx->key.w += i;
}

static int		keycontrol(int key, void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx*)param;
	if (key == KEY_ESC)
		closeprogram(param);
	else if (key == KEY_C)
		swap_colour(mlx);
	else if (key == KEY_F)
		swap_fractol(mlx);
	else if (key == KEY_R)
		basic_setup(mlx);
	else if (key == KEY_UP || key == KEY_DOWN || key == KEY_RIGHT ||
	key == KEY_LEFT)
		arrow_control(mlx, key);
	else if (key == KEY_MIN)
		mlx->setup->itter -= 1;
	else if (key == KEY_PLUS)
		mlx->setup->itter += 2;
	else if (key == KEY_SPACE && mlx->key.on == 1)
		mlx->key.on = 0;
	else if (key == KEY_SPACE && mlx->key.on == 0)
		mlx->key.on = 1;
	return (0);
}

void			controls(t_mlx *mlx)
{
	mlx_hook(mlx->win, KEY_PRESS_EVENT, NULL_MASK, keycontrol, (void*)mlx);
	mlx_hook(mlx->win, CLOSE_EVENT, NULL_MASK, closeprogram, NULL);
}
