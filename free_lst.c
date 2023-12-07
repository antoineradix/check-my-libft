/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:15:22 by aradix            #+#    #+#             */
/*   Updated: 2023/12/07 15:36:33 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check-my-libft.h"

void	free_lst(t_list **list)
{
	t_list	*ptr;

	while (*list != NULL)
	{
		ptr = (*list)->next;
		free(*list);
		*list = ptr;
	}
	*list = NULL;
}
