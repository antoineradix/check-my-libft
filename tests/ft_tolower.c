/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 23:09:35 by aradix            #+#    #+#             */
/*   Updated: 2023/11/22 23:09:57 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check-my-libft.h"

int		main(void)
{
	int	c;

	printf("ft_tolower:          ");
	/* -------------------- TEST 01 -------------------- */
	c = -200;
	while (c <= 200)
	{
		if (ft_tolower((unsigned char)c) != tolower((unsigned char)c))
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
