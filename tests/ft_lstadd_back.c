/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:57:39 by aradix            #+#    #+#             */
/*   Updated: 2023/12/07 14:26:38 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check-my-libft.h"

static bool	cmp_output(void)
{
	t_list	*head;
	int		a;
	int		b;
	int		c;

	a = 2;
	b = 1;
	c = 3;
	head = ft_lstnew(&a);
	ft_lstadd_front(&head, ft_lstnew(&b));
	ft_lstadd_back(&head, ft_lstnew(&c));
	head = head->next;
	head = head->next;
	if ((*(int *)(head->content)) == c)
		return (true);
	return (false);
	/* MEMORY LEAKS */
}

int	main(void)
{
	printf("ft_lstadd_back:      ");
	/* -------------------- TEST 01 -------------------- */
	if (cmp_output())
		printf("%s 1:[OK]", GREEN);
	else
		printf("%s 1:[KO]", RED);
	/* -------------------------------------------------- */
	printf("\x1b[0m\n");
}
