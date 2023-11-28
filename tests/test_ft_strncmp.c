/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strncmp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 23:17:44 by aradix            #+#    #+#             */
/*   Updated: 2023/11/22 23:19:03 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check-my-libft.h"

static bool	cmp_output(char *s1, char *s2, size_t n)
{
	int	ret;
	int	expected_ret;

	ret = ft_strncmp(s1, s2, n);
	expected_ret = strncmp(s1, s2, n);
	if (ret == expected_ret)
		return (true);
	return (false);
}

int		main(void)
{
	printf("ft_strncmp:          ");
	/* -------------------- TEST 01 -------------------- */
	if (cmp_output("hello world !", "hello world !", 100))
		printf("%s 1:[OK]", GREEN);
	else
		printf("%s 1:[KO]", RED);
	/* -------------------- TEST 02 -------------------- */
	if (cmp_output("hello world !", "helo world !", 100))
		printf("%s 2:[OK]", GREEN);
	else
		printf("%s 2:[KO]", RED);
	/* -------------------- TEST 03 -------------------- */
	if (cmp_output("hello world !", "helo world !", 2))
		printf("%s 3:[OK]", GREEN);
	else
		printf("%s 3:[KO]", RED);
	/* -------------------- TEST 04 -------------------- */
	if (cmp_output("", "", 1))
		printf("%s 4:[OK]", GREEN);
	else
		printf("%s 4:[KO]", RED);
	/* -------------------- TEST 05 -------------------- */
	if (cmp_output("b", "a", 0))
		printf("%s 5:[OK]", GREEN);
	else
		printf("%s 5:[KO]", RED);
	/* -------------------------------------------------- */
	printf("\x1b[0m\n");
}
