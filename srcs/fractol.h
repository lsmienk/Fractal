/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmienk <lsmienk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/15 12:49:27 by lsmienk        #+#    #+#                */
/*   Updated: 2019/07/15 13:13:57 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "mlx.h"
# include "values.h"
# include "keycode.h"
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>

typedef struct s_setting	t_setting;

typedef struct	s_key
{
	double		zoom;
	int			on;
	int			w;
	int			h;
}				t_key;

typedef struct	s_mlx
{
	void		*info;
	void		*win;
	void		*img;
	void		*img_add;
	t_key		key;
	t_setting	*setup;
}				t_mlx;

struct			s_setting
{
	int			colour;
	int			itter;
	int			x;
	int			y;
	int			(*fractol)(t_mlx *mlx, float x, float y);
};

void			controls(t_mlx *mlx);
void			drawinfo(t_mlx *mlx, int colour);
int				valid_argument(char *str, t_mlx *mlx);
int				julia(t_mlx *mlx, float x, float y);
int				mandelbrot(t_mlx *mlx, float x, float y);
void			magic_loop(t_mlx *mlx);
int				colour_convert(t_mlx *mlx, float i, int colour);
int				fractol_loop(void *param);
int				burningship(t_mlx *mlx, float x, float y);
int				tricorn(t_mlx *mlx, float x, float y);
void			mouse_control(t_mlx *mlx);
void			basic_setup(t_mlx *mlx);

#endif
