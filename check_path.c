/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elkan <elkan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 12:37:10 by elkan             #+#    #+#             */
/*   Updated: 2026/01/07 12:28:58 by elkan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

#include <stdlib.h>

t_pos	find_player(char **map, int width, int height);

int	check_path(char **map, int width, int height, int cols)
{
	t_pos	player_pos;
	int		path;

	player_pos = find_player(map, width, height);
	path = search_path(map, player_pos, cols);
	return (path);
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
