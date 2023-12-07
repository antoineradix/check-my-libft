/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:52:00 by aradix            #+#    #+#             */
/*   Updated: 2023/12/07 18:52:47 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check-my-libft.h"

void	del(void *content)
{
	(void)content;
}

static bool	cmp_output(void)
{
	t_list	*head;
	/* t_list	*ptr; */
	int		a;
	/* int		b; */
	/* int		c; */

	a = 2;
	/* b = 1; */
	/* c = 3; */
	head = ft_lstnew(&a);
	/* ft_lstadd_front(&head, ft_lstnew(&b)); */
	/* ft_lstadd_back(&head, ft_lstnew(&c)); */
	/* ptr = head; */
	ft_lstdelone(head, del);
	return (false);
}

int	main(void)
{
	printf("ft_lstdelone:        ");
	/* -------------------- TEST 01 -------------------- */
	if (cmp_output())
		printf("%s 1:[OK]", GREEN);
	else
		printf("%s 1:[KO]", RED);
	/* -------------------------------------------------- */
	printf("\x1b[0m\n");
}
