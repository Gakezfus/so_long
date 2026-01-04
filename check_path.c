/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elkan <elkan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 12:37:10 by elkan             #+#    #+#             */
/*   Updated: 2026/01/04 22:38:16 by elkan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/libft.h"

#include <stdlib.h>

t_pos	find_player(char **map, int width, int height);
t_pos	find_exit(char **map, int width, int height);
t_pos	*find_collectibles(char **map, int width, int height, int cols);

int	check_path(char **map, int width, int height, int cols)
{
	t_pos	player_pos;
	t_pos	exit_pos;
	t_pos	*collectibles;

	player_pos = find_player(map, width, height);
	exit_pos = find_exit(map, width, height);
	collectibles = find_collectibles(map, width, height, cols);
	if (collectibles == NULL)
		return (1);
	// path_found(map, player_pos, exit_pos, collectibles);
	// Tested and found the checks work, and the map data is correct
	return (0);
}

t_pos	find_player(char **map, int width, int height)
{
	int		h_index;
	int		w_index;
	t_pos	to_return;

	h_index = 0;
	while (h_index < height)
	{
		w_index = 0;
		while (w_index < width)
		{
			if (map[h_index][w_index] == 'P')
			{
				to_return.x = w_index;
				to_return.y = h_index;
				return (to_return);
			}
			w_index++;
		}
		h_index++;
	}
	to_return.x = -1;
	to_return.y = -1;
	return (to_return);
}

t_pos	find_exit(char **map, int width, int height)
{
	int		h_index;
	int		w_index;
	t_pos	to_return;

	h_index = 0;
	while (h_index < height)
	{
		w_index = 0;
		while (w_index < width)
		{
			if (map[h_index][w_index] == 'E')
			{
				to_return.x = w_index;
				to_return.y = h_index;
				return (to_return);
			}
			w_index++;
		}
		h_index++;
	}
	to_return.x = -1;
	to_return.y = -1;
	return (to_return);
}

t_pos	*find_collectibles(char **map, int width, int height, int total_cols)
{
	static int	h_index = 0;
	static int	col_no = 0;
	int			w_index;
	t_pos		*col_pos;

	col_pos = malloc(total_cols * sizeof(t_pos));
	if (col_pos == NULL)
		return (NULL);
	while (h_index < height)
	{
		w_index = 0;
		while (w_index < width)
		{
			if (map[h_index][w_index] == 'C')
			{
				col_pos[col_no].x = w_index;
				col_pos[col_no].y = h_index;
				col_no++;
			}
			w_index++;
		}
		h_index++;
	}
	return (col_pos);
}
