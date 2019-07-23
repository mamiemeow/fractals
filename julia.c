/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuvalis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 18:57:44 by kkuvalis          #+#    #+#             */
/*   Updated: 2019/05/22 15:58:45 by kkuvalis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void			julia_struct(t_global *global)
{
	global->f.x = 0;
	global->f.y = 0;
	global->f.x1 = -2;
	global->f.y1 = -1.9;
	global->f.zoom = 200;
	global->f.cr = 0.8;
	global->f.ci = 0.0;
	global->f.mouseflag = 0;
	global->f.flag = 0;
	global->f.colour = 256;
}

void			julia_calc(t_global *global)
{
	double		tmp;

	tmp = global->f.zr;
	global->f.zr = global->f.zr * global->f.zr\
		- global->f.zi * global->f.zi - global->f.cr;
	global->f.zi = 2 * global->f.zi * tmp + global->f.ci;
}

int				*julia(t_global *global)
{
	int			i;

	global->f.y = 0;
	while (global->f.y < SIZEY)
	{
		global->f.x = 0;
		while (global->f.x < SIZEY)
		{
			global->f.zr = global->f.x / global->f.zoom + global->f.x1;
			global->f.zi = global->f.y / global->f.zoom + global->f.y1;
			i = 0;
			while (global->f.zr * global->f.zr + global->f.zi\
					* global->f.zi < 4 && i++ < DEPTH)
				julia_calc(global);
			put_pxl_to_img(global, i);
			global->f.x++;
		}
		global->f.y++;
	}
	return (0);
}

void			julia_pthread(t_global *global)
{
	t_global	flow[THREAD_NUMBER];
	pthread_t	t[THREAD_NUMBER];
	int			i;

	i = 0;
	while (i < THREAD_NUMBER)
	{
		ft_memcpy((void*)&flow[i], (void*)global, sizeof(t_global));
		flow[i].f.y = THREAD_WIDTH * i;
		pthread_create(&t[i], NULL, (void *)julia, &flow[i]);
		i++;
	}
	while (i--)
		pthread_join(t[i], NULL);
	mlx_put_image_to_window(global->win.mlx,\
			global->win.win, global->win.img, 0, 0);
}
