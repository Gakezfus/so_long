/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_steps.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elkan <elkan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 22:10:32 by elkan             #+#    #+#             */
/*   Updated: 2026/01/12 22:31:37 by elkan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"
#include "libft.h"

void	config_steps(t_pars *par, int step)
{
	if (step)
	{
		par->steps++;
		ft_printf("Moves: %i\n", par->steps);
	}
}
		
