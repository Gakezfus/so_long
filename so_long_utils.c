/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elkan Choo <echoo@42mail.sutd.edu.sg>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 14:37:24 by Elkan Choo        #+#    #+#             */
/*   Updated: 2026/01/07 14:35:36 by Elkan Choo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_map_len(char *str)
{
	size_t	count;

	count = 0;
	while (str[count] != '\n' && str[count])
		count++;
	return (count);
}
