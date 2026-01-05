/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elkan Choo <echoo@42mail.sutd.edu.sg>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 15:52:18 by Elkan Choo        #+#    #+#             */
/*   Updated: 2026/01/05 19:42:18 by Elkan Choo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

#include <stdlib.h>

int		search_path(char **map, t_pos player_pos, t_pos *collectibles);
int		explore(char **map, t_list **frontier, int *to_find);
int		check_sides(char ***map, t_pos location, t_list **frontier, int *to_find);
t_pos	side(t_pos location, int dir);

int	search_path(char **map, t_pos player_pos, t_pos *collectibles)
{
	int		to_find;
	t_list	*frontier;

	to_find = 0;
	while (collectibles[to_find].x >= 0)
		to_find++;
	to_find++;
	frontier = ft_lstnew(&player_pos);
	map[player_pos.y][player_pos.x] = '1';
	while (to_find && frontier)
	{
		if (explore(map, &frontier, &to_find))
			return (1);
	}
	return (to_find);
}

// Gets the first coordinates in frontier, stores it, and removes it from the
// frontier.
int	explore(char **map, t_list **frontier, int *to_find)
{
	t_pos 	location;
	t_list	*tmp;

	tmp = *frontier;
	location = *(t_pos *)((*frontier)->content);
	*frontier = (*frontier)->next;
	ft_lstdelone(tmp, free);
	return (check_sides(&map, location, frontier, to_find));
}

// Checks each side. Adds them to frontier if they are not explored or already
// on the frontier. Changes value on map to '1' to mark that they have been placed
// on the frontier.
int	check_sides(char ***map, t_pos location, t_list **frontier, int *to_find)
{
	int		index;
	t_pos	to_check;
	char	item;
	t_list	*new;

	index = 0;
	while (index < 4)
	{
		to_check = side(location, index);
		item = *map[to_check.y][to_check.x];
		if (item != '1')
		{
			new = ft_lstnew(&to_check);
			if (new == NULL)
				return (1);
			ft_lstadd_back(frontier, new);
			if (item == 'E' || item == 'C')
				(*to_find)--;
			*map[to_check.y][to_check.x] = '1';
		}
	}
	return (0);
}

t_pos	side(t_pos location, int dir)
{
	if (dir == 0)
	{
		location.x += 1;
		return (location);
	}
	if (dir == 1)
	{
		location.y += 1;
		return (location);
	}
	if (dir == 2)
	{
		location.x -= 1;
		return (location);
	}
	if (dir == 3)
	{
		location.y -= 1;
		return (location);
	}
	return (location);
}
