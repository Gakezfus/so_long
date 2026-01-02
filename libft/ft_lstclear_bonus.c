/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 19:03:08 by echoo             #+#    #+#             */
/*   Updated: 2025/11/25 17:57:08 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*copy;
	t_list	*nxt;

	if (lst == NULL || *lst == NULL || del == NULL)
		return ;
	copy = *lst;
	while (copy != NULL)
	{
		nxt = copy->next;
		ft_lstdelone(copy, del);
		copy = nxt;
	}
	*lst = NULL;
}
