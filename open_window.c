/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elkan <elkan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 12:25:03 by elkan             #+#    #+#             */
/*   Updated: 2026/01/13 17:18:31 by elkan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"
#include "libft.h"

#include <stdlib.h>
#include <stdio.h>

//-I.mlx -L./.mlx -lmlx -lXext -lX11

int		open_window(char **map, int width, int height, int cols);
void	setup(t_pars *par, int cols);
void	initial_window_colouring(t_pars *par, int x, int y);
void	redraw_window(t_pars *p_ptr, int x, int y);
int		redraw(void *p_ptr);

int	open_window(char **map, int width, int height, int cols)
{
	void		*mlx;
	static void	*window = NULL;
	t_pars		*par;

	mlx = mlx_init();
	if (mlx == NULL)
		return (1);
	par = malloc(sizeof(t_pars));
	if (par == NULL)
		return (mlx_destroy_display(mlx), free(mlx), 1);
	par->mlx = mlx;
	par->map = map;
	par->width = width;
	par->height = height;
	window = mlx_new_window(mlx, width * SIZE,
			height * SIZE, "Window");
	if (window == NULL)
		return (mlx_destroy_display(mlx), free(mlx), free(par), 1);
	par->wind = window;
	setup(par, cols);
	mlx_key_hook(window, handle_keys, (void *)par);
	mlx_hook(window, 17, 0, close_window, (void *)par);
	mlx_expose_hook(window, redraw, par);
	mlx_loop(mlx);
	return (0);
}

// Collectible is picture of: Mode Angel Dust Roll On Glitter HYPERSONIC
// Holographic Blue Sparkling High Performance 3D Loose Glitters for
// Face and Body, Spill Proof Bottle, Cruelty Free, Vegan, Made in NY USA

// Wall is picture of: LG Marble/Stone Real Concrete (Dark Gray) ML61

// Exit is picture from: <a href="https://www.flaticon.com/free-icons/letter-e"
// title="letter e icons">Letter e icons created by Hight Quality Icons -
// Flaticon</a>

void	setup(t_pars *par, int cols)
{
	par->steps = 0;
	par->cols = cols;
	par->p_rot = 3;
	par->p_img = ft_calloc(1, sizeof(t_img));
	par->s_img = ft_calloc(1, sizeof(t_img));
	par->w_img = ft_calloc(1, sizeof(t_img));
	par->c_img = ft_calloc(1, sizeof(t_img));
	par->e_img = ft_calloc(1, sizeof(t_img));
	par->a_img = ft_calloc(1, sizeof(t_img));
	if (!par->p_img || !par->s_img || !par->w_img
		|| !par->c_img || !par->e_img || !par->a_img)
		end_program(par, 1);
	par->p_img->img_ptr = mlx_xpm_file_to_image(par->mlx,
			"./textures/player/player_r24.xpm", &par->p_img->x, &par->p_img->y);
	par->s_img->img_ptr = mlx_xpm_file_to_image(par->mlx,
			"./textures/space.xpm", &par->p_img->x, &par->p_img->y);
	par->w_img->img_ptr = mlx_xpm_file_to_image(par->mlx,
			"./textures/wall.xpm", &par->p_img->x, &par->p_img->y);
	par->c_img->img_ptr = mlx_xpm_file_to_image(par->mlx,
			"./textures/cols.xpm", &par->p_img->x, &par->p_img->y);
	par->e_img->img_ptr = mlx_xpm_file_to_image(par->mlx,
			"./textures/exit.xpm", &par->p_img->x, &par->p_img->y);
	ft_strlcpy(par->steps_str, "moves: ", 8);
	initial_window_colouring(par, -1, -1);
	config_steps(par, 0);
}

int	redraw(void *p_ptr)
{
	t_pars		*par;

	par = (t_pars *)p_ptr;
	par->redraw = 1;
	redraw_window(par, -1, -1);
	config_steps(par, 0);
	return (0);
}

void	redraw_window(t_pars *par, int x, int y)
{
	while (++y < par->height)
	{
		x = -1;
		while (++x < par->width)
		{
			if (par->map[y][x] == '0')
				mlx_put_image_to_window(par->mlx, par->wind,
					par->s_img->img_ptr, x * SIZE, y * SIZE);
			else if (par->map[y][x] == '1')
				mlx_put_image_to_window(par->mlx, par->wind,
					par->w_img->img_ptr, x * SIZE, y * SIZE);
			else if (par->map[y][x] == 'P')
				mlx_put_image_to_window(par->mlx, par->wind,
					par->p_img->img_ptr, x * SIZE, y * SIZE);
			else if (par->map[y][x] == 'C')
				mlx_put_image_to_window(par->mlx, par->wind,
					par->c_img->img_ptr, x * SIZE, y * SIZE);
			else if (par->map[y][x] == 'E')
				mlx_put_image_to_window(par->mlx, par->wind,
					par->e_img->img_ptr, x * SIZE, y * SIZE);
		}
	}
}

void	initial_window_colouring(t_pars *par, int x, int y)
{
	while (++y < par->height)
	{
		x = -1;
		while (++x < par->width)
		{
			if (par->map[y][x] == '0')
				mlx_put_image_to_window(par->mlx, par->wind,
					par->s_img->img_ptr, x * SIZE, y * SIZE);
			else if (par->map[y][x] == '1')
				mlx_put_image_to_window(par->mlx, par->wind,
					par->w_img->img_ptr, x * SIZE, y * SIZE);
			else if (par->map[y][x] == 'P')
				draw_and_set_pos(par, 'P', x, y);
			else if (par->map[y][x] == 'C')
				mlx_put_image_to_window(par->mlx, par->wind,
					par->c_img->img_ptr, x * SIZE, y * SIZE);
			else if (par->map[y][x] == 'E')
				draw_and_set_pos(par, 'E', x, y);
		}
	}
}
