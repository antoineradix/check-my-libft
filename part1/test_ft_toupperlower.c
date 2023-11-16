/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_toupperlower.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:14:16 by aradix            #+#    #+#             */
/*   Updated: 2023/11/16 15:19:39 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check-my-libft.h"

void	test_ft_toupperlower(int (*implem)(int), int (*original)(int))
{
	int	c;

	/* -------------------- TEST 01 -------------------- */
	c = -200;
	while (c <= 200)
	{
		if (implem((unsigned char)c) != original((unsigned char)c))
			break ;
		c++;
	}
	if (c == 201)
		printf("%s 1:[OK]", GREEN);
	else
		printf("%s 1:[KO]", RED);
	/* -------------------------------------------------- */
	printf("\x1b[0m\n");
}
