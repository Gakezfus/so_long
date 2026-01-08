/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elkan <elkan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 01:48:43 by elkan             #+#    #+#             */
/*   Updated: 2026/01/09 02:15:33 by elkan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"
#include "libft.h"

#include <stdlib.h>
#include <stdio.h>

void	config_steps(t_pars *par)
{
	ft_strlcpy(par->steps_str + 7, ft_itoa(par->steps), 11);
	colour_square(par->width / 2 - 1, 0, par, 0x00444444);
	colour_square(par->width / 2, 0, par, 0x00444444);
	colour_square(par->width / 2 + 1, 0, par, 0x00444444);
	colour_square(par->width / 2 + 2, 0, par, 0x00444444);
	mlx_string_put(par->mlx, par->wind, par->width * SIZE / 2 - 28,
		23, 0x00FFFF00, par->steps_str);
}
