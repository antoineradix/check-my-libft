/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strjoin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 17:59:36 by aradix            #+#    #+#             */
/*   Updated: 2023/11/19 18:12:36 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check-my-libft.h"

static bool	cmp_output(char *s1, char *s2, char *expected_ret, size_t cmp_size)
{
	char	*ret;
	size_t	mem_size;
	size_t	expected_mem_size;

	ret = ft_strjoin(s1, s2);
	if (ret == NULL && expected_ret == NULL)
		return (true);
	if ((ret == NULL && expected_ret != NULL) || (ret != NULL
			&& expected_ret == NULL))
		return (false);
	mem_size = malloc_size(ret);
	expected_mem_size = malloc_size(expected_ret);
	if (mem_size == expected_mem_size
			&& memcmp(ret, expected_ret, cmp_size) == 0)
		return (true);
	return (false);
	/* ! return without free */
}

void	test_ft_strjoin(void)
{
	/* -------------------- TEST 01 -------------------- */
	if (cmp_output("abcd", "efgh", strdup("abcdefgh"), 9))
		printf("%s 1:[OK]", GREEN);
	else
		printf("%s 1:[KO]", RED);
	/* -------------------- TEST 02 -------------------- */
	if (cmp_output("abcd", "", strdup("abcd"), 5))
		printf("%s 2:[OK]", GREEN);
	else
		printf("%s 2:[KO]", RED);
	/* -------------------- TEST 03 -------------------- */
	if (cmp_output("", "abcd", strdup("abcd"), 5))
		printf("%s 3:[OK]", GREEN);
	else
		printf("%s 3:[KO]", RED);
	/* -------------------- TEST 04 -------------------- */
	if (cmp_output("\0", "\0", strdup("\0"), 3))
		printf("%s 4:[OK]", GREEN);
	else
		printf("%s 4:[KO]", RED);
	/* -------------------- TEST 05 -------------------- */
	if (cmp_output("\0", "\0", strdup("\0"), 1))
		printf("%s 4:[OK]", GREEN);
	else
		printf("%s 4:[KO]", RED);
	/* -------------------------------------------------- */
	printf("\x1b[0m\n");
}
