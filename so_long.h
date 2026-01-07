/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elkan <elkan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 13:12:23 by elkan             #+#    #+#             */
/*   Updated: 2026/01/07 12:32:12 by elkan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <stddef.h>

typedef struct coordinates
{
	int	x;
	int	y;
}	t_pos;

// from check_path.c
int		check_path(char **map, int width, int height, int cols);

// from search_path.c
int		search_path(char **map, t_pos player_pos, int cols);

// from so_long_utils.c
size_t	ft_map_len(char *str);

// from ope_window.c
int		open_window(char **map);

#endif
