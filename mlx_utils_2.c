/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elkan <elkan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 01:48:43 by elkan             #+#    #+#             */
/*   Updated: 2026/01/10 13:05:09 by elkan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"
#include "libft.h"

#include <stdlib.h>
#include <sys/time.h>

void	config_steps(t_pars *par)
{
	char	*num;

	num = ft_itoa(par->steps);
	ft_strlcpy(par->steps_str + 7, num, 11);
	free(num);
	colour_square(par->width / 2 - 1, 0, par, 0x00444444);
	colour_square(par->width / 2, 0, par, 0x00444444);
	colour_square(par->width / 2 + 1, 0, par, 0x00444444);
	colour_square(par->width / 2 + 2, 0, par, 0x00444444);
	mlx_string_put(par->mlx, par->wind, par->width * SIZE / 2 - 28,
		23, 0x00FFFF00, par->steps_str);
}

void	delay(long miliseconds)
{
	struct timeval	*time;
	suseconds_t		init_time;

	time = malloc(sizeof(struct timeval));
	if (time == NULL)
		exit(1);
	gettimeofday(time, NULL);
	init_time = time->tv_usec + time->tv_sec * 1000000L;
	while (time->tv_usec + time->tv_sec * 1000000L - init_time < miliseconds)
	{
		gettimeofday(time, NULL);
	}
	free(time);
}
