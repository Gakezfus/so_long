/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elkan Choo <echoo@42mail.sutd.edu.sg>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 13:12:23 by elkan             #+#    #+#             */
/*   Updated: 2026/01/12 19:06:58 by Elkan Choo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stddef.h>

// Defines are HARD CODED. DO NOT TOUCH

// Determines pixel size.
# define SIZE 40

// Determines how many frames it takes to move.
# define FRAMES 10

typedef struct coordinates
{
	int	x;
	int	y;
}	t_pos;

typedef struct img
{
	void	*img_ptr;
	int		x;
	int		y;
}	t_img;

typedef struct parameters
{
	void			*mlx;
	void			*wind;
	char			**map;
	int				width;
	int				height;
	int				steps;
	char			steps_str[17];
	int				cols;
	int				redraw;
	unsigned char	p_rot;
	t_img			*a_img;
	t_img			*p_img;
	t_img			*w_img;
	t_img			*s_img;
	t_img			*c_img;
	t_img			*e_img;
	t_pos			p_pos;
	t_pos			e_pos;
}	t_pars;

// from check_path.c
int		check_path(char **map, int width, int height, int cols);

// from search_path.c
int		search_path(char **map, t_pos p_pos, int cols);

// from so_long_utils.c
size_t	ft_map_len(char *str);
void	set_pos(t_pos *pos, int x, int y);

// from open_window.c
int		open_window(char **map, int width, int height, int cols);

// from mlx_utils.c
int		handle_keys(int keycode, void *p_ptr);
int		close_window(void *p_ptr);
void	move_player(t_pars *par, unsigned char move_no);
void	check_end(t_pars *par);
void	draw_and_set_pos(t_pars *par, char c, int x, int y);

// from mlx_utlis_2.c
void	config_steps(t_pars *par);
void	delay(long miliseconds, t_pars *par);
void	end_program(t_pars *par, int code);

// from player_rotation.c
void	player_rotation(t_pars *par, unsigned char move_no);

// from player_movement.c
void	move(unsigned char move_no, t_pars *par);

#endif
