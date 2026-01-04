/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elkan <elkan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 13:12:23 by elkan             #+#    #+#             */
/*   Updated: 2026/01/04 22:25:00 by elkan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <stddef.h>

// from check_path.c
int	check_path(char **map, int width, int height, int cols);

// from so_long_utils.c
size_t ft_map_len(char *s);

typedef struct coordinates
{
	int	x;
	int	y;
}	t_pos;

#endif
