/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_steps_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elkan <elkan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 22:11:43 by elkan             #+#    #+#             */
/*   Updated: 2026/01/13 10:51:14 by elkan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"
#include "libft.h"

#include <stdlib.h>

void	config_steps(t_pars *par, int step)
{
	char	*num;

	if (step && par->steps < 2147483647)
	{
		par->steps++;
	}
	num = ft_itoa(par->steps);
	if (num == NULL)
		end_program(par, 1);
	ft_strlcpy(par->steps_str + 7, num, 11);
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
	free(num);
}
