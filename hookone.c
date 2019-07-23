/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hookone.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuvalis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 17:59:12 by kkuvalis          #+#    #+#             */
/*   Updated: 2019/05/22 19:12:26 by kkuvalis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractal.h"

void	controls(t_global *global)
{
	mlx_hook(global->win.win, 2, 0, (void *)key_press, global);
	mlx_hook(global->win.win, 17, 0, expose, global);
	mlx_hook(global->win.win, 4, 0, (void *)mouse_first, global);
}

void	key_press(int key, t_global *global)
{
	if (key == 53)
		exit(0);
	if (key == MORE)
		global->f.zoom += 50;
	if (key == LESS)
		global->f.zoom -= 50;
	if (key == UP)
		global->f.y1 += 0.15;
	if (key == DOWN)
		global->f.y1 -= 0.15;
	if (key == LEFT_ARR)
		global->f.x1 += 0.15;
	if (key == RIGHT_ARR)
		global->f.x1 -= 0.15;
	if (key == ONE)
		global->f.colour = 0x2F074B;
	if (key == TWO)
		global->f.colour = 256;
	draw(global);
}

void	alg_move(int x, int y, t_global *global)
{
	if (global->mouse.prex < x)
		global->f.x1 -= fabs((double)(global->mouse.prex - x) / DEPTH) / 1.5;
	if (global->mouse.prex > x)
		global->f.x1 += fabs((double)(x - global->mouse.prex) / DEPTH) / 1.5;
	if (global->mouse.prey > y)
		global->f.y1 += fabs((double)(y - global->mouse.prey) / DEPTH) / 1.5;
	if (global->mouse.prey < y)
		global->f.y1 -= fabs((double)(global->mouse.prey - y) / DEPTH) / 1.5;
}

void	mouse_first(int button, int x, int y, t_global *global)
{
	mouse_scroll(button, x, y, global);
	global->mouse.x = x;
	global->mouse.y = y;
	if (button == 1)
	{
		global->f.mouseflag = 1;
		mlx_hook(global->win.win, 6, 0, (void *)mouse_move, global);
	}
	if (button == 2 && global->f.flag == 2)
	{
		if (global->f.mouseflag == 2)
			global->f.mouseflag = 0;
		else
		{
			global->f.mouseflag = 2;
			mlx_hook(global->win.win, 6, 0, (void *)mouse_route, global);
		}
	}
	draw(global);
}

void	mouse_key(int button, int x, int y, t_global *global)
{
	if (x || y || button)
	{
		if (global->f.mouseflag == 1)
			global->f.mouseflag = 0;
	}
}
