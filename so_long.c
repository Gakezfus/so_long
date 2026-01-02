/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elkan <elkan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 19:09:26 by Elkan Choo        #+#    #+#             */
/*   Updated: 2026/01/02 23:40:18 by elkan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ".mlx/mlx.h"
#include "libft/libft.h"

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int	validate_input(char *input, char ***map);
int	check_chars(char *line);
int	validate_map(map, width);

int	main(int argc, char *argv[])
{
	int		file_name_len;
	char	**map;
	int		fd;

	if (argc != 2)
		return (1);
	fd = open(input, O_RDONLY);
	file_name_len = ft_strlen(argv[1]);
	if (file_name_len < 4 || ft_strncmp(argv[1] + file_name_len - 4, ".ber", 4)
		|| validate_input(argv[1], &map))
		return (close(fd), 1);
	close(fd);
	return (0);
}

int	validate_input(char *input, char ***map)
{
	int			str_len;
	char		*line;
	char		*map_str;

	map_str = malloc(1);
	line = get_next_line(fd);
	if (line == NULL || map_str == NULL)
		return (write(2, "Error\nMemory insufficient\n", 26), 1);
	map_str[0] = '\0';
	str_len = ft_strlen(line);
	while (line)
	{
		if (!(str_len == ft_strlen(line)))
			return (free(line), write(2, "Error\nMap not rectangle\n", 26), 1);
		if (check_chars(line) || ft_merge_strings(&map_str, line))
			return (free(line), 1);
		free(line);
		line = get_next_line(fd);
	}
	*map = ft_split(map_str, '\n');
	if (map == NULL || validate_map(map, str_len))
		return (1);
	return (0);
}

int	validate_map(map, width)
{
	static int	index = 0;
	int	height;

	while (map[index])
	{
		if (map[index][0] != '1' || map[index][width] != '1')
			return (write(2, "Error\nWalls don't cover map\n", 27), 1)
		index++;
	}
	height = index;
	index = 0;
	while (map[0][index])
	{
		if (map[0][index] != '1' || map[height][index] != '1')
			return (write(2, "Error\nWalls don't cover map\n", 27), 1)
	}
	if (check_path(map. width, height))
		return (write(2, "Error\nPath not found\n", 1));
	// TODO: Write a program to check the path!
}

int	check_chars(char *line)
{
	static int	e_count = 0;
	static int	p_count = 0;
	int			i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (!(line[i] == '0' || line[i] == '1' || line[i] == 'C'
				|| line[i] == 'E' || line[i] == 'P'))
			return (write(2, "Error\nInvalid characters in map\n", 32), 1);
		if (line[i] == 'E')
			e_count++;
		if (line[i] == 'P')
			e_count++;
		i++;
	}
	if (e_count > 1 || p_count > 1)
		return (write(2, "Error\nMultipler players or exits\n", 33), 1);
	return (0);
}
