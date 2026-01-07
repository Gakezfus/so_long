/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elkan <elkan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 12:25:03 by elkan             #+#    #+#             */
/*   Updated: 2026/01/08 01:36:39 by elkan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"
#include "libft.h"

#include <stdlib.h>
#include <stdio.h>

//-I.mlx -L./.mlx -lmlx -lXext -lX11

typedef struct img
{
	void	*name;
	int		x;
	int		y;
}	t_img;

typedef struct pareters
{
	void	*mlx;
	void	*wind;
	char	**map;
	int		width;
	int		height;
	int		size;
	t_img	*player;
}	t_pars;

int		open_window(char **map, int width, int height);
int		handle_keys(int keycode, void *p_ptr);
int		handle_mouse(int button, int x, int y, void *p_ptr);
int		close_window(void *p_ptr);
void	setup(t_pars *par, int width, int height);

// int	main(void)
// {
// 	char	**map = {0};

// 	open_window(map);
// }

int	open_window(char **map, int width, int height)
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
	par->size = 50;
	window = mlx_new_window(mlx, width * par->size,
			height * par->size, "Window");
	if (window == NULL)
		return (1);
	par->wind = window;
	setup(par, width, height);
	mlx_key_hook(window, handle_keys, (void *)par);
	mlx_mouse_hook(window, handle_mouse, (void *)par);
	mlx_hook(window, 17, 0, close_window, (void *)par);
	mlx_loop(mlx);
	return (0);
}

void	setup(t_pars *par, int width, int height)
{
	int		y;
	int		x;

	par->width = width;
	par->height = height;
	y = 0;
	// Causes segfault
	// par->player->name = mlx_xpm_file_to_image(par->mlx, "./images/Roomba.xpm", &par->player->x, &par->player->y);
	while (y < par->height * par->size)
	{
		x = 0;
		while (x < par->width * par->size)
		{
			if (par->map[y / par->size][x / par->size] == '0')
				mlx_pixel_put(par->mlx, par->wind, x, y, 0x000077AA);
			else if (par->map[y / par->size][x / par->size] == '1')
				mlx_pixel_put(par->mlx, par->wind, x, y, 0x00555555);
			// else if (par->map[y / par->size][x / par->size] == 'P')
			// 	mlx_put_image_to_window(par->mlx, par->wind, player, x, y);
			else if (par->map[y / par->size][x / par->size] == 'C')
				mlx_pixel_put(par->mlx, par->wind, x, y, 0x00005500);
			else if (par->map[y / par->size][x / par->size] == 'E')
				mlx_pixel_put(par->mlx, par->wind, x, y, 0x00550055);
			x++;
		}
		y++;
	}
}

int	handle_mouse(int button, int x, int y, void *p_ptr)
{
	(void) button;
	(void) p_ptr;
	printf("Pos: %i, %i\n", x, y);
	return (0);
}

int	close_window(void *p_ptr)
{
	t_pars	*par;

	par = (t_pars *)p_ptr;
	mlx_destroy_window(par->mlx, par->wind);
	exit(0);
}

int	handle_keys(int keycode, void *p_ptr)
{
	t_pars	*par;

	par = (t_pars *)p_ptr;
	if (keycode == 0xff1b)
	{
		mlx_destroy_window(par->mlx, par->wind);
		exit(0);
	}
	return (0);
}
