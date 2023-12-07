/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:52:57 by aradix            #+#    #+#             */
/*   Updated: 2023/12/07 15:42:49 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check-my-libft.h"

static bool	cmp_output(void)
{
	t_list	*head;
	t_list	*tmp;
	int		a;
	int		b;

	a = 2;
	b = 1;
	head = ft_lstnew(&a);
	ft_lstadd_front(&head, ft_lstnew(&b));
	if ((*(int *)(head->content)) != b)
		return (false);
	tmp = head;
	head = head->next;
	if ((*(int *)(head->content)) != a)
	{
		free_lst(&tmp);
		return (false);
	}
	free_lst(&tmp);
	return (true);
}

int	main(void)
{
	printf("ft_lstadd_front:     ");
	/* -------------------- TEST 01 -------------------- */
	if (cmp_output())
		printf("%s 1:[OK]", GREEN);
	else
		printf("%s 1:[KO]", RED);
	/* -------------------------------------------------- */
	printf("\x1b[0m\n");
}
