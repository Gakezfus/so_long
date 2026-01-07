/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elkan <elkan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 12:25:03 by elkan             #+#    #+#             */
/*   Updated: 2026/01/07 12:28:21 by elkan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"

#include <stdlib.h>
#include <stdio.h>

//-I.mlx -L./.mlx -lmlx -lXext -lX11

typedef struct parameters
{
	void	*mlx;
	void	*window;
	char	**map;
} t_pars;

int		open_window(char **map);
int		handle_keys(int keycode, void *p_ptr);
int		handle_mouse(int button, int x, int y, void *p_ptr);
int		close_window(void *p_ptr);

// int	main(void)
// {
// 	char	**map = {0};

// 	open_window(map);
// }

int	open_window(char **map)
{
	void 	*mlx;
	void	*window;
	t_pars	*param;

	mlx = mlx_init();
	if (mlx == NULL)
		return (1);
	window = mlx_new_window(mlx, 800, 600, "Window");
	if (window == NULL)
		return (1);
	param = malloc(sizeof(t_pars));
	param->mlx = mlx;
	param->window = window;
	param->map = map;
	mlx_key_hook(window, handle_keys, (void *)param);
	mlx_mouse_hook(window, handle_mouse, (void *)param);
	mlx_hook(window, 17, 0, close_window, (void *)param);
	mlx_loop(mlx);
	free(param);
	return (0);
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
