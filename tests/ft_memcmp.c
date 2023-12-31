/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:17:58 by aradix            #+#    #+#             */
/*   Updated: 2023/11/28 19:21:10 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check-my-libft.h"

static bool	is_segfault(char *s1, char *s2, size_t n)
{
	if (signal(SIGSEGV, signal_handler) == SIG_ERR)
	{
		fprintf(stderr, "Failed to set up signal handler\n");
		exit(1);
	}
	if (sigsetjmp(env, 1) == 0)
	{
		ft_memcmp(s1, s2, n);
		return (0);
	}
	return (1);
}

static bool	cmp_output(char *s1, char *s2, size_t n)
{
	int	ret;
	int	expected_ret;

	ret = ft_memcmp(s1, s2, n);
	expected_ret = memcmp(s1, s2, n);
	if (ret == expected_ret)
		return (true);
	return (false);
}

int	main(void)
{
	printf("ft_memcmp:           ");
	/* -------------------- TEST 01 -------------------- */
	if (cmp_output("hello world", "hello world", 12))
		printf("%s 1:[OK]", GREEN);
	else
		printf("%s 1:[KO]", RED);
	/* -------------------- TEST 02 -------------------- */
	if (cmp_output("hello a", "hello b", 5))
		printf("%s 2:[OK]", GREEN);
	else
		printf("%s 2:[KO]", RED);
	/* -------------------- TEST 03 -------------------- */
	if (cmp_output("ahell", "bhell", 5))
		printf("%s 3:[OK]", GREEN);
	else
		printf("%s 3:[KO]", RED);
	/* -------------------- TEST 04 -------------------- */
	if (cmp_output("", "", 1))
		printf("%s 4:[OK]", GREEN);
	else
		printf("%s 4:[KO]", RED);
	/* -------------------- TEST 05 -------------------- */
	if (is_segfault(NULL, "loooooool", 5))
		printf("%s 5:[OK]", GREEN);
	else
		printf("%s 5:[KO]", RED);
	/* -------------------- TEST 06 -------------------- */
	if (is_segfault(NULL, NULL, 0))
		printf("%s 6:[KO]", RED);
	else
		printf("%s 6:[OK]", GREEN);
	/* -------------------------------------------------- */
	printf("\x1b[0m\n");
}
