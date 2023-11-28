/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 19:07:33 by aradix            #+#    #+#             */
/*   Updated: 2023/11/28 19:15:38 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check-my-libft.h"

static bool	is_segfault(char *s, int c, size_t n)
{
	if (signal(SIGSEGV, signal_handler) == SIG_ERR)
	{
		fprintf(stderr, "Failed to set up signal handler\n");
		exit(1);
	}
	if (sigsetjmp(env, 1) == 0)
	{
		ft_memchr(s, c, n);
		return (0);
	}
	return (1);
}

static bool	cmp_output(char *s, int c, size_t n)
{
	char	*ret;
	char	*expected_ret;

	ret = ft_memchr(s, c, n);
	expected_ret = memchr(s, c, n);
	if (ret == NULL && expected_ret == NULL)
		return (true);
	if ((ret == NULL && expected_ret != NULL) || (ret != NULL
			&& expected_ret == NULL))
		return (false);
	if (strcmp(ret, expected_ret) == 0)
		return (true);
	return (false);
}

int	main(void)
{
	printf("ft_memchr:           ");
	/* -------------------- TEST 01 -------------------- */
	if (cmp_output("hello '\0' world !", 'w', 15))
		printf("%s 1:[OK]", GREEN);
	else
		printf("%s 1:[KO]", RED);
	/* -------------------- TEST 02 -------------------- */
	if (cmp_output("hello '\0' world !", 'w', 5))
		printf("%s 2:[OK]", GREEN);
	else
		printf("%s 2:[KO]", RED);
	/* -------------------- TEST 03 -------------------- */
	if (cmp_output("q", 'w', 1))
		printf("%s 3:[OK]", GREEN);
	else
		printf("%s 3:[KO]", RED);
	/* -------------------- TEST 04 -------------------- */
	if (cmp_output("w", 'w', 0))
		printf("%s 4:[OK]", GREEN);
	else
		printf("%s 4:[KO]", RED);
	/* -------------------- TEST 05 -------------------- */
	if (cmp_output("a!", -223, 2))
		printf("%s 5:[OK]", GREEN);
	else
		printf("%s 5:[KO]", RED);
	/* -------------------- TEST 06 -------------------- */
	if (cmp_output("aaa", 'a', 2))
		printf("%s 6:[OK]", GREEN);
	else
		printf("%s 6:[KO]", RED);
	/* -------------------- TEST 07 -------------------- */
	if (is_segfault(NULL, 'a', 0))
		printf("%s 7:[KO]", RED);
	else
		printf("%s 7:[OK]", GREEN);
	/* -------------------- TEST 08 -------------------- */
	if (is_segfault(NULL, 'a', 1))
		printf("%s 8:[OK]", GREEN);
	else
		printf("%s 8:[KO]", RED);
	/* -------------------------------------------------- */
	printf("\x1b[0m\n");
}
