/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:04:04 by aradix            #+#    #+#             */
/*   Updated: 2023/12/06 17:17:02 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check-my-libft.h"

static bool	cmp_output(int n)
{
	t_list	*head;

	head = ft_lstnew(&n);
	if ((*(int *)(head->content)) == n)
		{
			free(head);
			return (true);
		}
	free(head);
	return (false);
}

int	main(void)
{
	printf("ft_lstnew:           ");
	/* -------------------- TEST 01 -------------------- */
	if (cmp_output(42))
		printf("%s 1:[OK]", GREEN);
	else
		printf("%s 1:[KO]", RED);
	/* -------------------------------------------------- */
	printf("\x1b[0m\n");
}
