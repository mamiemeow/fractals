/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuvalis <kkuvalis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 20:23:30 by kkuvalis          #+#    #+#             */
/*   Updated: 2019/05/22 17:07:38 by kkuvalis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H
# include <stdlib.h>
# include <math.h>
# include "mlx.h"
# include "libft/includes/libft.h"
# include "pthread.h"
# define SIZEX				800
# define SIZEY				800
# define DEPTH				200
# define THREAD_WIDTH		1
# define THREAD_NUMBER		60

# define LESS				43
# define MORE				47
# define ONE				83
# define TWO				84
# define UP					126
# define DOWN				125
# define LEFT_ARR			123
# define RIGHT_ARR			124

typedef struct	s_img
{
	int			*data;
	int			bits_per_pixel;
	int			size_line;
	int			end;
}				t_img;

typedef struct	s_win
{
	void		*mlx;
	void		*win;
	void		*img;
}				t_win;

typedef struct	s_mouse
{
	int			x;
	int			y;
	int			prex;
	int			prey;
}				t_mouse;

typedef struct	s_fractal
{
	double		zi;
	double		zr;
	double		ci;
	double		cr;
	double		zoom;
	double		x1;
	double		y1;
	int			x;
	int			y;
	double		prex;
	double		prey;
	int			mouseflag;
	int			flag;
	int			colour;
}				t_fractal;

typedef struct	s_global
{
	t_img		img;
	t_win		win;
	t_fractal	f;
	t_mouse		mouse;
}				t_global;

void			key_press(int key, t_global *global);
void			draw(t_global *global);
void			mouse_first(int button, int x, int y, t_global *global);
void			mouse_route(int x, int y, void *param);
void			mouse_key(int button, int x, int y, t_global *global);
void			mouse_scroll(int button, int x, int y, t_global *global);
void			mouse_move(int x, int y, t_global *global);
void			key_press(int key, t_global *global);
void			alg_move(int x, int y, t_global *global);
int				expose(void *param);
int				*mandelbrot(t_global *global);
void			mandel_struct(t_global *global);
void			mandel_calc(t_global *global);
void			mandel_pthread(t_global *global);
void			julia_struct(t_global *global);
int				*julia(t_global *global);
void			julia_calc(t_global *global);
void			julia_pthread(t_global *global);
int				*ship(t_global *global);
void			ship_calc(t_global *global);
void			ship_struct(t_global *global);
void			ship_pthread(t_global *global);
void			put_pxl_to_img(t_global *global, int i);
void			controls(t_global *global);
int				change_fractal(char **argv, t_global *global);
int				main(int argc, char **argv);

#endif
