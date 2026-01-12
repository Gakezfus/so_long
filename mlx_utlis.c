/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utlis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elkan <elkan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 21:14:53 by elkan             #+#    #+#             */
/*   Updated: 2026/01/12 22:31:08 by elkan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"
#include "libft.h"

#include <stdlib.h>
#include <stdio.h>

int		handle_keys(int keycode, void *p_ptr);
int		close_window(void *p_ptr);
void	move_player(t_pars *par, unsigned char move_no);
void	check_end(t_pars *par);
void	draw_and_set_pos(t_pars *par, char c, int x, int y);

int	handle_keys(int keycode, void *p_ptr)
{
	t_pars	*par;

	par = (t_pars *)p_ptr;
	if (keycode == 0xff1b)
	{
		end_program(par, 0);
	}
	if (keycode == 0x64 || keycode == 0xff53)
		move_player(par, 0);
	else if (keycode == 0x73 || keycode == 0xff54)
		move_player(par, 1);
	else if (keycode == 0x61 || keycode == 0xff51)
		move_player(par, 2);
	else if (keycode == 0x77 || keycode == 0xff52)
		move_player(par, 3);
	return (0);
}

int	close_window(void *p_ptr)
{
	t_pars	*par;

	par = (t_pars *)p_ptr;
	end_program(par, 0);
	return (0);
}

// move_no == 0 moves right, move_no == 1 moves down,
// move_no == 2 moves left, move_no == 3 moves up
// Second part checks if the player tries to go to the exit before it's
// collected all collectibles.
void	move_player(t_pars *par, unsigned char move_no)
{
	t_pos	new;

	new.x = par->p_pos.x + (move_no == 0) - (move_no == 2);
	new.y = par->p_pos.y + (move_no == 1) - (move_no == 3);
	if (par->p_rot != move_no)
		player_rotation(par, move_no);
	if (par->map[new.y][new.x] == '1' ||
			(par->map[new.y][new.x] == 'E' && par->cols))
		return ;
	else
	{
		if (par->map[new.y][new.x] == 'C')
		{
			par->cols--;
			check_end(par);
		}
		if (par->map[new.y][new.x] == 'E')
			end_program(par, 0);
		par->map[new.y][new.x] = 'P';
		par->map[par->p_pos.y][par->p_pos.x] = '0';
		move(move_no, par);
		set_pos(&(par->p_pos), new.x, new.y);
		config_steps(par, 1);
	}
}

void	draw_and_set_pos(t_pars *par, char c, int x, int y)
{
	if (c == 'P')
	{
		set_pos(&(par->p_pos), x, y);
		mlx_put_image_to_window(par->mlx, par->wind,
			par->p_img->img_ptr, x * SIZE, y * SIZE);
	}
	else if (c == 'E')
	{
		set_pos(&(par->e_pos), x, y);
		mlx_put_image_to_window(par->mlx, par->wind,
			par->e_img->img_ptr, x * SIZE, y * SIZE);
	}
}

void	check_end(t_pars *par)
{
	if (par->cols == 0)
	{
		mlx_destroy_image(par->mlx, par->e_img->img_ptr);
		par->e_img->img_ptr = mlx_xpm_file_to_image(par->mlx,
			"./textures/exit_rdy.xpm", &par->e_img->x, &par->e_img->y);
		mlx_put_image_to_window(par->mlx, par->wind, par->e_img->img_ptr,
			par->e_pos.x * SIZE, par->e_pos.y * SIZE);
	}
}
