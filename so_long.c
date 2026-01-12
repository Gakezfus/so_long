/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elkan Choo <echoo@42mail.sutd.edu.sg>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 19:09:26 by Elkan Choo        #+#    #+#             */
/*   Updated: 2026/01/12 19:06:47 by Elkan Choo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "libft.h"
#include "so_long.h"

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int	validate_input(int fd, char ***map, int *cols);
int	check_chars(char *line, int final, int *cols);
int	validate_map(char **map, size_t width, int cols);

int	main(int argc, char *argv[])
{
	int		filename_len;
	char	**map;
	int		fd;
	int		index;
	int		cols;

	if (argc != 2)
		return (write(2, "format: ./so_long <map>\n", 24), 1);
	fd = open(argv[1], O_RDONLY);
	filename_len = ft_strlen(argv[1]);
	if (fd < 0)
		return (write(2, "file cannot be opened\n", 22), 1);
	if (filename_len < 4 || ft_strncmp(argv[1] + filename_len - 4, ".ber", 4))
		return (close(fd), write(2, "invalid file format\n", 20), 1);
	if (validate_input(fd, &map, &cols))
		return (close(fd), 1);
	close(fd);
	index = 0;
	while (map[index])
		index++;
	if (open_window(map, ft_strlen(map[0]), index, cols))
		return (ft_free_arrays((void **)map), 1);
	return (ft_free_arrays((void **)map), 0);
}
// Program is verified to be memory safe until the MinilibX

int	validate_input(int fd, char ***map, int *cols)
{
	size_t	str_len;
	char	*line;
	char	*map_str;

	map_str = ft_calloc(1, sizeof(char));
	line = get_next_line(fd);
	if (line == NULL || map_str == NULL)
		return (free(line), free(map_str), 1);
	str_len = ft_map_len(line);
	if (str_len > 48)
		return(write(2, "Error\nMap too long\n", 19), 1);
	while (line)
	{
		if (!(str_len == ft_map_len(line)))
			return (free(line), free(map_str),
				write(2, "Error\nMap not rectangle\n", 24), 1);
		if (check_chars(line, 0, cols) || ft_merge_strings(&map_str, line))
			return (free(map_str), free(line), 1);
		free(line);
		line = get_next_line(fd);
	}
	*map = ft_split(map_str, '\n');
	if (check_chars(line, 1, cols) || !map
		|| validate_map(*map, str_len, *cols))
		return (free(map_str), ft_free_arrays((void **)(*map)), 1);
	return (free(map_str), 0);
}

// If not final, adds up numbers of exits, players, and collectibles.
int	check_chars(char *line, int final, int *cols)
{
	static int	e_count = 0;
	static int	p_count = 0;
	static int	c_count = 0;
	int			i;

	i = 0;
	while (!final && line[i] && line[i] != '\n')
	{
		if (!(line[i] == '0' || line[i] == '1' || line[i] == 'C'
				|| line[i] == 'E' || line[i] == 'P'))
			return (write(2, "Error\nInvalid characters in map\n", 32), 1);
		if (line[i] == 'E')
			e_count++;
		if (line[i] == 'P')
			p_count++;
		if (line[i] == 'C')
			c_count++;
		i++;
	}
	if (final && (e_count != 1 || p_count != 1 || c_count < 1))
		return (write(2, "Error\nMap must have 1 P, 1 E and > 0 C\n", 39), 1);
	return (*cols = c_count, 0);
}

int	validate_map(char **map, size_t width, int cols)
{
	static int	index = 0;
	int			height;

	while (map[index])
	{
		if (map[index][0] != '1' || map[index][width - 1] != '1')
			return (write(2, "Error\nWalls don't cover map\n", 28), 1);
		index++;
	}
	height = index;
	if (height > 24)
		return (write(2, "Error\nMap too tall\n", 19));
	index = 0;
	while (map[0][index])
	{
		if (map[0][index] != '1' || map[height - 1][index] != '1')
			return (write(2, "Error\nWalls don't cover map\n", 27), 1);
		index++;
	}
	if (check_path(map, width, height, cols))
		return (write(2, "Error\nPath not found\n", 21), 1);
	return (0);
}
