/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:38:18 by aradix            #+#    #+#             */
/*   Updated: 2023/12/07 18:54:54 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check-my-libft.h"

void	del(void	*content)
{
	(void)content;
}

static bool	cmp_output(void)
{
	t_list	*head;
	int		a;
	int		b;

	a = 2;
	b = 1;
	head = ft_lstnew(&a);
	ft_lstadd_front(&head, ft_lstnew(&b));
	ft_lstclear(&head, &del);
	if (head == NULL)
		return (true);
	else
		return (false);
}

int	main(void)
{
	printf("ft_lstadd_clear:    ");
	/* -------------------- TEST 01 -------------------- */
	if (cmp_output())
		printf("%s 1:[OK]", GREEN);
	else
		printf("%s 1:[KO]", RED);
	/* -------------------------------------------------- */
	printf("\x1b[0m\n");
}
