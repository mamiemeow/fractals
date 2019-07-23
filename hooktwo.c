/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooktwo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuvalis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 18:01:37 by kkuvalis          #+#    #+#             */
/*   Updated: 2019/05/22 16:19:52 by kkuvalis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void			mouse_move(int x, int y, t_global *global)
{
	global->mouse.prex = global->mouse.x;
	global->mouse.prey = global->mouse.y;
	if (global->f.mouseflag == 1)
	{
		alg_move(x, y, global);
		mlx_hook(global->win.win, 5, 0, (void *)mouse_key, global);
	}
	draw(global);
	global->mouse.x = x;
	global->mouse.y = y;
}

void			mouse_route(int x, int y, void *param)
{
	t_global	*global;

	global = param;
	global->mouse.prex = global->mouse.x;
	global->mouse.prey = global->mouse.y;
	if (global->f.mouseflag == 2)
	{
		global->f.ci = (double)(x - (double)SIZEX / 2) / ((double)SIZEX / 2);
		global->f.cr = (double)(y - (double)SIZEY / 2) / ((double)SIZEY / 2);
	}
	draw(global);
	global->mouse.x = x;
	global->mouse.y = y;
}

void			mouse_scroll(int button, int x, int y, t_global *global)
{
	if (button == 4)
	{
		global->f.prex = (x / global->f.zoom + global->f.x1);
		global->f.prey = (y / global->f.zoom + global->f.y1);
		global->f.zoom *= 1.3;
		global->f.x1 = global->f.prex - (x / global->f.zoom);
		global->f.y1 = global->f.prey - (y / global->f.zoom);
	}
	if (button == 5 && global->f.zoom >= 10)
	{
		global->f.prex = (x / global->f.zoom + global->f.x1);
		global->f.prey = (y / global->f.zoom + global->f.y1);
		global->f.zoom /= 1.3;
		global->f.x1 = global->f.prex - (x / global->f.zoom);
		global->f.y1 = global->f.prey - (y / global->f.zoom);
	}
}

int				expose(void *param)
{
	t_global	*win;

	win = param;
	exit(0);
}
