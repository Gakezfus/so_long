/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elkan <elkan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 12:25:03 by elkan             #+#    #+#             */
/*   Updated: 2026/01/09 02:14:55 by elkan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"
#include "libft.h"

#include <stdlib.h>
#include <stdio.h>

//-I.mlx -L./.mlx -lmlx -lXext -lX11

int		open_window(char **map, int width, int height, int cols);
void	setup(t_pars *par, int width, int height, int cols);
void	initial_window_colouring(t_pars *par);
void	redraw_window(t_pars *p_ptr, int x, int y);
int		redraw(void *p_ptr);

// int	main(void)
// {
// 	char	**map = {0};

// 	open_window(map);
// }

int	open_window(char **map, int width, int height, int cols)
{
	void	*mlx;
	void	*window;
	t_pars	*par;

	mlx = mlx_init();
	par = malloc(sizeof(t_pars));
	if (mlx == NULL || par == NULL)
		return (free(mlx), 1);
	par->mlx = mlx;
	par->map = map;
	window = mlx_new_window(mlx, width * SIZE,
			height * SIZE, "Window");
	par->p_img = malloc(sizeof(t_img));
	if (window == NULL || par->p_img == NULL)
		return (1);
	par->wind = window;
	setup(par, width, height, cols);
	mlx_key_hook(window, handle_keys, (void *)par);
	mlx_hook(window, 17, 0, close_window, (void *)par);
	mlx_expose_hook(window, redraw, par);
	mlx_loop(mlx);
	return (0);
}

void	setup(t_pars *par, int width, int height, int cols)
{
	par->width = width;
	par->height = height;
	par->steps = 0;
	par->p_pos.x = -1;
	par->cols = cols;
	par->p_img->img_ptr = mlx_xpm_file_to_image(par->mlx,
			"./images/Roomba-40px.xpm", &par->p_img->x, &par->p_img->y);
	ft_strlcpy(par->steps_str, "steps: ", 8);
	initial_window_colouring(par);
	config_steps(par);
}

int	redraw(void *p_ptr)
{
	t_pars		*par;

	par = (t_pars *)p_ptr;
	par->redraw = 1;
	redraw_window(par, -1, -1);
	config_steps(par);
	return (0);
}

void	redraw_window(t_pars *par, int x, int y)
{
	while (++y < par->height * SIZE)
	{
		x = -1;
		while (++x < par->width * SIZE)
		{
			if (par->map[y / SIZE][x / SIZE] == '0')
				mlx_pixel_put(par->mlx, par->wind, x, y, 0x00FFFFFF);
			else if (par->map[y / SIZE][x / SIZE] == '1')
				mlx_pixel_put(par->mlx, par->wind, x, y, 0x00444444);
			else if (par->redraw && par->map[y / SIZE][x / SIZE] == 'P')
			{
				mlx_put_image_to_window(par->mlx, par->wind,
					par->p_img->img_ptr, x, y);
				par->redraw = 0;
			}
			else if (par->map[y / SIZE][x / SIZE] == 'C')
				mlx_pixel_put(par->mlx, par->wind, x, y, 0x00005500);
			else if (par->map[y / SIZE][x / SIZE] == 'E')
				mlx_pixel_put(par->mlx, par->wind, x, y, 0x00550055);
		}
	}
}

void	initial_window_colouring(t_pars *par)
{
	int			x;
	static int	y = -1;

	while (++y < par->height * SIZE)
	{
		x = -1;
		while (++x < par->width * SIZE)
		{
			if (par->map[y / SIZE][x / SIZE] == '0')
				mlx_pixel_put(par->mlx, par->wind, x, y, 0x00FFFFFF);
			else if (par->map[y / SIZE][x / SIZE] == '1')
				mlx_pixel_put(par->mlx, par->wind, x, y, 0x00444444);
			else if (par->p_pos.x < 0 && par->map[y / SIZE][x / SIZE] == 'P')
			{
				mlx_put_image_to_window(par->mlx, par->wind,
					par->p_img->img_ptr, x, y);
				par->p_pos.x = x / SIZE;
				par->p_pos.y = y / SIZE;
			}
			else if (par->map[y / SIZE][x / SIZE] == 'C')
				mlx_pixel_put(par->mlx, par->wind, x, y, 0x00005500);
			else if (par->map[y / SIZE][x / SIZE] == 'E')
				mlx_pixel_put(par->mlx, par->wind, x, y, 0x00550055);
		}
	}
}
