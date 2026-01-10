/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_movement.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elkan <elkan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 17:37:31 by elkan             #+#    #+#             */
/*   Updated: 2026/01/10 17:49:21 by elkan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"
#include "libft.h"

#include <stdlib.h>

// void	move(t_pos new, unsigned char move_no)
// {
// 	int	index;
// 	int	x_offset;
// 	int	y_offset;

// 	x_offset = ((move_no == 0) - (move_no == 2)) * size / 10;
// 	y_offset = ((move_no == 1) - (move_no == 3)) * size / 10;
// 	index = 0;
// 	while (index < 10)
// 	{
// 		x_offset = ((move_no == 0) - (move_no == 2)) * index / 10;
// 		y_offset = ((move_no == 1) - (move_no == 3)) * index / 10;
// 		mlx_put_image_to_window(par->mlx, par->wind,
// 			par->p_img->img_ptr, par->p_pos.x, * SIZE + (x_offset + 1),
// 			par->p_pos.y * SIZE + (y_offset + 1));
// 		mlx_put_image_to_window(par->mlx, par->wind,
// 			par->s_img->img_ptr, par->p_pos.x, * SIZE + (x_offset),
// 			par->p_pos.y * SIZE + (y_offset + 1));
// 	}
// }
