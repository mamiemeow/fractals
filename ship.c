/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ship.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuvalis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 19:00:37 by kkuvalis          #+#    #+#             */
/*   Updated: 2019/05/22 16:07:14 by kkuvalis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void			ship_struct(t_global *global)
{
	global->f.x = 0;
	global->f.y = 0;
	global->f.x1 = -2.5;
	global->f.y1 = -2.2;
	global->f.zoom = 200;
	global->f.mouseflag = 0;
	global->f.flag = 0;
	global->f.colour = 256;
}

void			ship_calc(t_global *global)
{
	double		tmp;

	tmp = global->f.zi;
	global->f.zi = fabs((double)global->f.zr * global->f.zi\
			+ global->f.zr * global->f.zi + global->f.ci);
	global->f.zr = fabs((double)global->f.zr * global->f.zr\
			- tmp * tmp + global->f.cr);
}

int				*ship(t_global *global)
{
	int			i;

	global->f.y = 0;
	while (global->f.y < SIZEY)
	{
		global->f.x = 0;
		while (global->f.x < SIZEX)
		{
			global->f.cr = global->f.x / global->f.zoom + global->f.x1;
			global->f.ci = global->f.y / global->f.zoom + global->f.y1;
			global->f.zr = global->f.cr;
			global->f.zi = global->f.ci;
			i = 0;
			while (global->f.zr * global->f.zr + global->f.zi\
					* global->f.zi < 4 && i++ < DEPTH)
				ship_calc(global);
			put_pxl_to_img(global, i);
			global->f.x++;
		}
		global->f.y++;
	}
	return (0);
}

void			ship_pthread(t_global *global)
{
	t_global	flow[THREAD_NUMBER];
	pthread_t	t[THREAD_NUMBER];
	int			i;

	i = 0;
	while (i < THREAD_NUMBER)
	{
		ft_memcpy((void*)&flow[i], (void*)global, sizeof(t_global));
		flow[i].f.y = THREAD_WIDTH * i;
		pthread_create(&t[i], NULL, (void *)ship, &flow[i]);
		i++;
	}
	while (i--)
		pthread_join(t[i], NULL);
	mlx_put_image_to_window(global->win.mlx,\
			global->win.win, global->win.img, 0, 0);
}
