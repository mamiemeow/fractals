/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuvalis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 17:23:52 by kkuvalis          #+#    #+#             */
/*   Updated: 2019/05/21 17:38:27 by kkuvalis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	draw(t_global *global)
{
	global->win.img = mlx_new_image(global->win.mlx, SIZEX, SIZEY);
	global->img.data = (int *)mlx_get_data_addr(global->win.img,\
			&global->img.bits_per_pixel,\
			&global->img.size_line, &global->img.end);
	if (global->f.flag == 1)
		mandelbrot(global);
	if (global->f.flag == 2)
		julia(global);
	if (global->f.flag == 3)
		ship(global);
	mlx_put_image_to_window(global->win.mlx,\
			global->win.win, global->win.img, 0, 0);
}

void	put_pxl_to_img(t_global *global, int i)
{
	if (global->f.x < SIZEX && global->f.y < SIZEY)
	{
		if (i >= DEPTH)
			global->img.data[global->f.y * SIZEX + global->f.x] = 0x0;
		else
			global->img.data[global->f.y *\
				SIZEX + global->f.x] = i * i + global->f.colour;
	}
}
