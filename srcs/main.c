/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmienk <lsmienk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/15 12:48:15 by lsmienk        #+#    #+#                */
/*   Updated: 2019/07/15 13:44:02 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		setup(t_mlx *mlx)
{
	int tmp;

	tmp = 0;
	mlx->img = mlx_new_image(mlx->info, SCREEN_WIDTH, SCREEN_HEIGHT);
	mlx->img_add = mlx_get_data_addr(mlx->img, &tmp, &tmp, &tmp);
	mlx->setup->colour = IMRE_PINK;
	basic_setup(mlx);
	controls(mlx);
	mouse_control(mlx);
	mlx_loop_hook(mlx->info, fractol_loop, (void*)mlx);
}

int				main(int argc, char **argv)
{
	t_mlx		mlx;
	t_setting	setting;

	if (argc == 2)
	{
		mlx.setup = &setting;
		if (!valid_argument(argv[1], &mlx))
			ft_putendl("options julia, mandelbrot, burningship, tricorn");
		else
		{
			mlx.info = mlx_init();
			mlx.win = mlx_new_window(mlx.info, SCREEN_WIDTH, SCREEN_HEIGHT,
				"Fractol Magic");
			setup(&mlx);
			mlx_loop(mlx.info);
			argv[1] = NULL;
		}
	}
	else
	{
		ft_putendl("usage : ./fractol <valid_fractol>");
		ft_putendl("options julia, mandelbrot, burningship, tricorn");
	}
	return (0);
}
