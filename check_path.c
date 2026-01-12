/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elkan <elkan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 12:37:10 by elkan             #+#    #+#             */
/*   Updated: 2026/01/12 11:54:47 by elkan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

#include <stdlib.h>

t_pos	find_player(char **map, int width, int height);

int	check_path(char **og_map, int width, int height, int cols)
{
	t_pos	player_pos;
	char	**dup_map;
	int		path;
	int		index;

	dup_map = malloc((height + 1) * sizeof(char *));
	if (dup_map == NULL)
		return (1);
	index = 0;
	while (index < height)
	{
		dup_map[index] = ft_strdup(og_map[index]);
		index++;
	}
	dup_map[index] = NULL;
	player_pos = find_player(dup_map, width, height);
	path = search_path(dup_map, player_pos, cols);
	ft_free_arrays((void **)dup_map);
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
