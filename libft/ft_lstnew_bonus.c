/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:33:18 by echoo             #+#    #+#             */
/*   Updated: 2025/11/25 16:59:43 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>

t_list	*ft_lstnew(void *content);

t_list	*ft_lstnew(void *content)
{
	t_list	*to_return;

	to_return = malloc(sizeof(t_list));
	if (to_return == NULL)
		return (NULL);
	to_return->content = content;
	to_return->next = NULL;
	return (to_return);
}
