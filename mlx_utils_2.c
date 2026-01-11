/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elkan <elkan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 01:48:43 by elkan             #+#    #+#             */
/*   Updated: 2026/01/12 00:22:48 by elkan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"
#include "libft.h"

#include <stdlib.h>
#include <sys/time.h>

void	config_steps(t_pars *par);
void	delay(long miliseconds, t_pars *par);
void	end_program(t_pars *par, int code);

void	config_steps(t_pars *par)
{
	char	*num;

	num = ft_itoa(par->steps);
	if (num == NULL)
		end_program(par, 1);
	ft_strlcpy(par->steps_str + 7, num, 11);
	free(num);
	mlx_put_image_to_window(par->mlx, par->wind, par->w_img->img_ptr,
		(par->width / 2 - 1) * SIZE, 0);
	mlx_put_image_to_window(par->mlx, par->wind, par->w_img->img_ptr,
		(par->width / 2) * SIZE, 0);
	mlx_put_image_to_window(par->mlx, par->wind, par->w_img->img_ptr,
		(par->width / 2 + 1) * SIZE, 0);
	mlx_put_image_to_window(par->mlx, par->wind, par->w_img->img_ptr,
		(par->width / 2 + 2) * SIZE, 0);
	mlx_string_put(par->mlx, par->wind, par->width * SIZE / 2 - 28,
		23, 0x00FFFF00, par->steps_str);
}

void	delay(long miliseconds, t_pars *par)
{
	struct timeval	*time;
	suseconds_t		init_time;

	time = malloc(sizeof(struct timeval));
	if (time == NULL)
		end_program(par, 1);
	gettimeofday(time, NULL);
	init_time = time->tv_usec + time->tv_sec * 1000000L;
	while (time->tv_usec + time->tv_sec * 1000000L - init_time < miliseconds)
	{
		gettimeofday(time, NULL);
	}
	free(time);
}

void	end_program(t_pars *par, int code)
{
	t_img	*images[6];
	int		index;

	index = 0;
	images[0] = par->p_img;
	images[1] = par->w_img;
	images[2] = par->s_img;
	images[3] = par->c_img;
	images[4] = par->e_img;
	images[5] = par->a_img;
	while (index < 5)
	{
		if (images[index]->img_ptr)
		{
			mlx_destroy_image(par->mlx, images[index]->img_ptr);
		}
		free(images[index]);
		index++;
	}
	ft_free_arrays((void **)par->map);
	mlx_destroy_window(par->mlx, par->wind);
	free(par->mlx);
	free(par);
	exit(code);
}
