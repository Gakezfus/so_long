/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elkan <elkan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 17:37:31 by elkan             #+#    #+#             */
/*   Updated: 2026/01/12 01:13:21 by elkan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"
#include "libft.h"

void	draw_frame(unsigned char move_no, t_pars *par, int index);

void	move(unsigned char move_no, t_pars *par)
{
	int	index;

	index = -1;
	if (par->a_img->img_ptr)
		mlx_destroy_image(par->mlx, par->a_img->img_ptr);
	if (move_no == 0 || move_no == 2)
		par->a_img->img_ptr = mlx_xpm_file_to_image(par->mlx,
				"./images/space_vert.xpm", &par->a_img->x, &par->a_img->y);
	else
		par->a_img->img_ptr = mlx_xpm_file_to_image(par->mlx,
				"./images/space_horiz.xpm", &par->a_img->x, &par->a_img->y);
	while (++index < FRAMES)
	{
		draw_frame(move_no, par, index);
	}
}

void	draw_frame(unsigned char move_no, t_pars *par, int index)
{
	int	x_offset;
	int	y_offset;

	x_offset = ((move_no == 0) - (move_no == 2)) * SIZE / FRAMES;
	y_offset = ((move_no == 1) - (move_no == 3)) * SIZE / FRAMES;
	mlx_put_image_to_window(par->mlx, par->wind,
		par->p_img->img_ptr, par->p_pos.x * SIZE + x_offset * (index + 1),
		par->p_pos.y * SIZE + y_offset * (index + 1));
	delay(20500L, par);
	mlx_put_image_to_window(par->mlx, par->wind, par->a_img->img_ptr,
		par->p_pos.x * SIZE + x_offset * index + (SIZE * (FRAMES - 1)
			/ FRAMES) * (move_no == 2), par->p_pos.y * SIZE + y_offset
		* index + (SIZE * (FRAMES - 1) / FRAMES) * (move_no == 3));
	mlx_do_sync(par->mlx);
}
