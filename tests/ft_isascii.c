/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 22:15:55 by aradix            #+#    #+#             */
/*   Updated: 2023/11/28 15:08:42 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check-my-libft.h"

static bool	cmp_output(int c)
{
	int	ret;
	int	expected_ret;

	ret = ft_isascii(c);
	expected_ret = isascii(c);
	if ((ret == 0 && expected_ret == 0) || (ret > 0 && expected_ret > 0))
		return (true);
	return (false);
}

int	main(void)
{
	int	c;

	printf("ft_isascii:          ");
	/* -------------------- TEST 01 -------------------- */
	c = 0;
	while (c <= 127 && cmp_output(c))
		c++;
	if (c == 128)
		printf("%s 1:[OK]", GREEN);
	else
		printf("%s 1:[KO]", RED);
	/* -------------------- TEST 02 -------------------- */
	while (c <= 200 && cmp_output(c))
		c++;
	if (c == 201)
		printf("%s 2:[OK]", GREEN);
	else
		printf("%s 2:[KO]", RED);
	/* -------------------------------------------------- */
	printf("\x1b[0m\n");
}
