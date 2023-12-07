/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:35:38 by aradix            #+#    #+#             */
/*   Updated: 2023/12/07 13:41:06 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check-my-libft.h"

static bool	cmp_output(void)
{
	t_list	*head;
	int		a;
	int		b;

	a = 2;
	b = 1;
	head = ft_lstnew(&a);
	ft_lstadd_front(&head, ft_lstnew(&b));
	if (ft_lstsize(head) == 2)
		return (true);
	return (false);
	/* MEMORY LEAKS */
}

int	main(void)
{
	printf("ft_lstsize:          ");
	/* -------------------- TEST 01 -------------------- */
	if (cmp_output())
		printf("%s 1:[OK]", GREEN);
	else
		printf("%s 1:[KO]", RED);
	/* -------------------------------------------------- */
	printf("\x1b[0m\n");
}
