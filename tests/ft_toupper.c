/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 23:07:37 by aradix            #+#    #+#             */
/*   Updated: 2023/11/28 15:21:34 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check-my-libft.h"

int	main(void)
{
	int	c;

	printf("ft_toupper:          ");
	/* -------------------- TEST 01 -------------------- */
	c = -200;
	while (c <= 200)
	{
		if (ft_toupper((unsigned char)c) != toupper((unsigned char)c))
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
