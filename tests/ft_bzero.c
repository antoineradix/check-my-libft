/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 22:55:37 by aradix            #+#    #+#             */
/*   Updated: 2023/11/28 15:08:20 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check-my-libft.h"

static bool	is_segfault(char *s, size_t n)
{
	if (signal(SIGSEGV, signal_handler) == SIG_ERR)
	{
		fprintf(stderr, "Failed to set up signal handler\n");
		exit(1);
	}
	if (sigsetjmp(env, 1) == 0)
	{
		ft_bzero(s, n);
		return (0);
	}
	return (1);
}

static bool	cmp_output(char *s, char *expected_s, size_t n, size_t cmp_size)
{
	ft_bzero(s, n);
	bzero(expected_s, n);
	if (memcmp(s, expected_s, cmp_size) == 0)
		return (true);
	return (false);
}

int	main(void)
{
	char	s[10] = "abcdefghij";
	char	expected_s[10] = "abcdefghij";

	printf("ft_bzero:            ");
	/* -------------------- TEST 01 -------------------- */
	if (cmp_output(s, expected_s, 5, 10))
		printf("%s 1:[OK]", GREEN);
	else
		printf("%s 1:[KO]", RED);
	/* -------------------------------------------------- */
	*s = 'x';
	*expected_s = 'x';
	/* -------------------- TEST 02 -------------------- */
	if (cmp_output(s, expected_s, 0, 10))
		printf("%s 2:[OK]", GREEN);
	else
		printf("%s 2:[KO]", RED);
	/* -------------------- TEST 03 -------------------- */
	if (is_segfault(NULL, 0) == true)
		printf("%s 3:[KO]", RED);
	else
		printf("%s 3:[OK]", GREEN);
	/* -------------------- TEST 04 -------------------- */
	if (is_segfault(NULL, 1) == true)
		printf("%s 4:[OK]", GREEN);
	else
		printf("%s 4:[KO]", RED);
	/* -------------------------------------------------- */
	printf("\x1b[0m\n");
}
