/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:44:04 by aradix            #+#    #+#             */
/*   Updated: 2023/12/07 15:45:49 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check-my-libft.h"

static bool	cmp_output(void)
{
	t_list	*ptr;
	t_list	*head;
	int		a;
	int		b;

	a = 2;
	b = 1;
	head = ft_lstnew(&a);
	ft_lstadd_front(&head, ft_lstnew(&b));
	ptr = head;
	head = ft_lstlast(head);
	if ((*(int *)(head->content)) == a)
	{
		free_lst(&ptr);
		return (true);
	}
	free_lst(&head);
	return (false);
}

int	main(void)
{
	printf("ft_lstlast:          ");
	/* -------------------- TEST 01 -------------------- */
	if (cmp_output())
		printf("%s 1:[OK]", GREEN);
	else
		printf("%s 1:[KO]", RED);
	/* -------------------------------------------------- */
	printf("\x1b[0m\n");
}
