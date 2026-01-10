/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elkan <elkan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 15:52:18 by Elkan Choo        #+#    #+#             */
/*   Updated: 2026/01/10 16:28:06 by elkan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

#include <stdlib.h>

int		search_path(char **map, t_pos player_pos, int cols);
int		explore(char **map, t_list **frontier, int *to_find);
void	check_sides(char ***map, t_pos location,
			t_list **frontier, int *to_find);
t_pos	side(t_pos location, int dir);

int	search_path(char **map, t_pos player_pos, int cols)
{
	int		to_find;
	t_list	*frontier;
	t_pos	*new;

	to_find = 1 + cols;
	new = malloc(sizeof(t_pos));
	if (new == NULL)
		return (1);
	new->x = player_pos.x;
	new->y = player_pos.y;
	frontier = ft_lstnew(new);
	map[player_pos.y][player_pos.x] = '1';
	while (to_find && frontier)
	{
		explore(map, &frontier, &to_find);
	}
	return (ft_lstclear(&frontier, free), to_find);
}

// Gets the first coordinates in frontier, stores it, and removes it from the
// frontier.
int	explore(char **map, t_list **frontier, int *to_find)
{
	t_pos	location;
	t_list	*tmp;

	tmp = *frontier;
	location = *(t_pos *)((*frontier)->content);
	*frontier = (*frontier)->next;
	ft_lstdelone(tmp, free);
	check_sides(&map, location, frontier, to_find);
	return (0);
}

// Checks each side. Adds them to frontier if they are not explored or already
// on the frontier. Changes value on map to '1' to mark that they have been
// placed on the frontier.
void	check_sides(char ***map, t_pos location,
			t_list **frontier, int *to_find)
{
	int		index;
	char	item;
	t_pos	*to_check;

	index = -1;
	while (++index < 4)
	{
		to_check = malloc(sizeof(t_pos));
		if (to_check == NULL)
			return ;
		*to_check = side(location, index);
		item = (*map)[to_check->y][to_check->x];
		if (item != '1')
		{
			ft_lstadd_back(frontier, ft_lstnew(to_check));
			if (item == 'E' || item == 'C')
				(*to_find)--;
			(*map)[to_check->y][to_check->x] = '1';
		}
		else
			free(to_check);
	}
}

// When dir = 0, return the location one step East.
// When dir = 1, return the location one step South.
// When dir = 2, return the location one step West.
// When dir = 3, return the location one step North.
// Other values are not supposed to enter.
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
