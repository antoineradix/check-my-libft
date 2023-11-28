/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_atoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 23:00:33 by aradix            #+#    #+#             */
/*   Updated: 2023/11/16 23:13:29 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check-my-libft.h"

static bool	cmp_output(char *s)
{
	int	ret;
	int	expected_ret;

	ret = ft_atoi(s);
	expected_ret = atoi(s);
	if (ret == expected_ret)
		return (true);
	return (false);
}

void	test_ft_atoi(void)
{
	/* -------------------- TEST 01 -------------------- */
	if (cmp_output("-42"))
		printf("%s 1:[OK]", GREEN);
	else
		printf("%s 1:[KO]", RED);
	/* -------------------- TEST 02 -------------------- */
	if (cmp_output("0"))
		printf("%s 2:[OK]", GREEN);
	else
		printf("%s 2:[KO]", RED);
	/* -------------------- TEST 03 -------------------- */
	if (cmp_output("-------0"))
		printf("%s 3:[OK]", GREEN);
	else
		printf("%s 3:[KO]", RED);
	/* -------------------- TEST 04 -------------------- */
	if (cmp_output("+0x"))
		printf("%s 4:[OK]", GREEN);
	else
		printf("%s 4:[KO]", RED);
	/* -------------------- TEST 05 -------------------- */
	if (cmp_output("     \n\t\v\f\r    +0x"))
		printf("%s 5:[OK]", GREEN);
	else
		printf("%s 5:[KO]", RED);
	/* -------------------- TEST 06 -------------------- */
	if (cmp_output("     +\n\t\v\f\r    0x"))
		printf("%s 6:[OK]", GREEN);
	else
		printf("%s 6:[KO]", RED);
	/* -------------------- TEST 07 -------------------- */
	if (cmp_output("-2147483648"))
		printf("%s 7:[OK]", GREEN);
	else
		printf("%s 7:[KO]", RED);
	/* -------------------- TEST 08 -------------------- */
	if (cmp_output("+2147483647"))
		printf("%s 8:[OK]", GREEN);
	else
		printf("%s 8:[KO]", RED);
	/* -------------------- TEST 09 -------------------- */
	if (cmp_output("+954654654147483648"))
		printf("%s 9:[OK]", GREEN);
	else
		printf("%s 9:[KO]", RED);
	/* -------------------- TEST 10 -------------------- */
	if (cmp_output(""))
		printf("%s 10:[OK]", GREEN);
	else
		printf("%s 10:[KO]", RED);
	/* -------------------------------------------------- */
	printf("\x1b[0m\n");
}
