/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elkan <elkan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 14:37:24 by Elkan Choo        #+#    #+#             */
/*   Updated: 2026/01/09 18:50:03 by elkan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "so_long.h"

size_t	ft_map_len(char *str)
{
	size_t	count;

	count = 0;
	while (str[count] != '\n' && str[count])
		count++;
	return (count);
}

void	set_pos(t_pos *pos, int x, int y)
{
	pos->x = x;
	pos->y = y;
}
