/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utlis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elkan <elkan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 21:14:53 by elkan             #+#    #+#             */
/*   Updated: 2026/01/10 16:20:50 by elkan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"
#include "libft.h"

#include <stdlib.h>
#include <stdio.h>

int		handle_keys(int keycode, void *p_ptr);
int		close_window(void *p_ptr);
int		handle_mouse(int button, int x, int y, void *p_ptr);
void	move_player(t_pars *par, unsigned char move_no);
void	colour_square(int x, int y, t_pars *par, int colour);

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
			par->cols--;
		if (par->map[new.y][new.x] == 'E')
			end_program(par, 0);
		par->map[new.y][new.x] = 'P';
		par->map[par->p_pos.y][par->p_pos.x] = '0';
		// Where the animation goes
		mlx_put_image_to_window(par->mlx, par->wind,
			par->p_img->img_ptr, new.x * SIZE, new.y * SIZE);
		colour_square(par->p_pos.x, par->p_pos.y, par, 0x00FFFFFF);
		set_pos(&(par->p_pos), new.x, new.y);
		par->steps++;
		config_steps(par);
	}
}

void	colour_square(int x, int y, t_pars *par, int colour)
{
	int	img_x;
	int	img_y;

	img_x = x * SIZE;
	while (img_x / SIZE == x)
	{
		img_y = y * SIZE;
		while (img_y / SIZE == y)
		{
			mlx_pixel_put(par->mlx, par->wind, img_x, img_y, colour);
			img_y++;
		}
		img_x++;
	}
}
