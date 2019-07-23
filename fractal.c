/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuvalis <kkuvalis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 18:14:28 by kkuvalis          #+#    #+#             */
/*   Updated: 2019/05/22 17:33:48 by kkuvalis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int				change_fractal(char **argv, t_global *global)
{
	if (ft_strcmp(argv[1], "mandelbrot") == 0)
	{
		mandel_struct(global);
		mandel_pthread(global);
		global->f.flag = 1;
	}
	else if (ft_strcmp(argv[1], "julia") == 0)
	{
		julia_struct(global);
		julia_pthread(global);
		global->f.flag = 2;
	}
	else if (ft_strcmp(argv[1], "ship") == 0)
	{
		ship_struct(global);
		ship_pthread(global);
		global->f.flag = 3;
	}
	else
	{
		ft_putstr("available fractals: mandelbrot, julia, ship\n");
		return (0);
	}
	return (1);
}

int				main(int argc, char **argv)
{
	t_global	*global;

	if (argc == 2)
	{
		if (!(global = (t_global *)malloc(sizeof(t_global))))
			return (0);
		global->win.mlx = mlx_init();
		global->win.win = mlx_new_window(global->win.mlx,\
				SIZEX, SIZEY, "fractal");
		global->win.img = mlx_new_image(global->win.mlx,\
				SIZEX, SIZEY);
		global->img.data = (int *)mlx_get_data_addr(global->win.img, \
				&global->img.bits_per_pixel, &global->img.size_line,\
				&global->img.end);
		if (!(change_fractal(argv, global)))
			return (0);
		mlx_put_image_to_window(global->win.mlx,\
				global->win.win, global->win.img, 0, 0);
		controls(global);
		mlx_loop(global->win.mlx);
	}
	else
		ft_putstr("example: ./fractol name\n");
	return (0);
}
