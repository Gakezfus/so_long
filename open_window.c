/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elkan Choo <echoo@42mail.sutd.edu.sg>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 12:25:03 by elkan             #+#    #+#             */
/*   Updated: 2026/01/07 18:37:28 by Elkan Choo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"
#include "libft.h"

#include <stdlib.h>
#include <stdio.h>

//-I.mlx -L./.mlx -lmlx -lXext -lX11

typedef struct parameters
{
	void	*mlx;
	void	*window;
	char	**map;
	int		width;
	int		height;
}	t_pars;

int		open_window(char **map, int width, int height);
int		handle_keys(int keycode, void *p_ptr);
int		handle_mouse(int button, int x, int y, void *p_ptr);
int		close_window(void *p_ptr);
void	setup(t_pars *param, int width, int height);

// int	main(void)
// {
// 	char	**map = {0};

// 	open_window(map);
// }

int	open_window(char **map, int width, int height)
{
	void	*mlx;
	void	*window;
	t_pars	*param;

	mlx = mlx_init();
	param = malloc(sizeof(t_pars));
	if (mlx == NULL || param == NULL)
		return (free(mlx), 1);
	param->mlx = mlx;
	param->map = map;
	window = mlx_new_window(mlx, width * 50,
			height * 50, "Window");
	if (window == NULL)
		return (1);
	param->window = window;
	setup(param, width, height);
	mlx_key_hook(window, handle_keys, (void *)param);
	mlx_mouse_hook(window, handle_mouse, (void *)param);
	mlx_hook(window, 17, 0, close_window, (void *)param);
	mlx_loop(mlx);
	return (0);
}

void	setup(t_pars *param, int width, int height)
{
	int		index;
	int		index_2;

	param->width = width;
	param->height = height;
	index = 0;
	while (index < param->height * 50)
	{
		index_2 = 0;
		while (index_2 < param->width * 50)
		{
			if (param->map[index / 50][index_2 / 50] == '0')
				mlx_pixel_put(param->mlx, param->window, index_2, index, 0x000077AA);
			else if (param->map[index / 50][index_2 / 50] == '1')
				mlx_pixel_put(param->mlx, param->window, index_2, index, 0x00555555);
			else if (param->map[index / 50][index_2 / 50] == 'P')
				mlx_pixel_put(param->mlx, param->window, index_2, index, 0x00999900);
			else if (param->map[index / 50][index_2 / 50] == 'C')
				mlx_pixel_put(param->mlx, param->window, index_2, index, 0x00005500);
			else if (param->map[index / 50][index_2 / 50] == 'E')
				mlx_pixel_put(param->mlx, param->window, index_2, index, 0x00550055);
			index_2++;
		}
		index++;
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
	t_pars	*param;

	param = (t_pars *)p_ptr;
	mlx_destroy_window(param->mlx, param->window);
	exit(0);
}

int	handle_keys(int keycode, void *p_ptr)
{
	t_pars	*param;

	param = (t_pars *)p_ptr;
	if (keycode == 0xff1b)
	{
		mlx_destroy_window(param->mlx, param->window);
		exit(0);
	}
	return (0);
}
