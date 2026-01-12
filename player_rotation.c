/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elkan Choo <echoo@42mail.sutd.edu.sg>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 15:26:18 by elkan             #+#    #+#             */
/*   Updated: 2026/01/12 16:51:09 by Elkan Choo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"
#include "mlx.h"

#include <stdlib.h>
#include <stdio.h>

int		calc_dir(unsigned char og, unsigned char new);
void	get_filename(char *filename, int num);
void	player_rotation(t_pars *par, unsigned char move_no);

// The loop relies on unsigned char overflow to be able to move in either
// direction
void	player_rotation(t_pars *par, unsigned char move_no)
{
	char			filename[31];
	unsigned char	index;
	int				dir;

	dir = calc_dir(par->p_rot, move_no);
	index = par->p_rot * 64 + 8 * dir;
	while ((index != (unsigned char)(move_no * 64 + 8 * dir)))
	{
		get_filename(filename, index / 8);
		mlx_destroy_image(par->mlx, par->p_img->img_ptr);
		par->p_img->img_ptr = mlx_xpm_file_to_image(par->mlx,
				filename, &par->p_img->x, &par->p_img->y);
		delay(15000L, par);
		mlx_put_image_to_window(par->mlx, par->wind,
			par->p_img->img_ptr, par->p_pos.x * SIZE, par->p_pos.y * SIZE);
		index += 8 * dir;
	}
	par->p_rot = move_no;
}

int	calc_dir(unsigned char og, unsigned char new)
{
	unsigned char	c_wise_dist;
	unsigned char	ac_wise_dist;

	c_wise_dist = new * 64 - og * 64;
	ac_wise_dist = og * 64 - new * 64;
	if (c_wise_dist > ac_wise_dist)
		return (-1);
	return (1);
}

void	get_filename(char *filename, int num)
{
	ft_strlcpy(filename, "./textures/player/player_r00.xpm", 33);
	filename[26] = num / 10 + '0';
	filename[27] = num % 10 + '0';
}
