/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 22:14:08 by aradix            #+#    #+#             */
/*   Updated: 2023/11/28 19:08:50 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check-my-libft.h"

static bool	is_segfault(char *s, int c, size_t size)
{
	if (signal(SIGSEGV, signal_handler) == SIG_ERR)
	{
		fprintf(stderr, "Failed to set up signal handler\n");
		exit(1);
	}
	if (sigsetjmp(env, 1) == 0)
	{
		ft_memset(s, c, size);
		return (0);
	}
	return (1);
}

static bool	cmp_output(char *s, char *expected_s, int c, size_t size,
		size_t cmp_size)
{
	char	*ret;
	char	*expected_ret;

	ret = ft_memset(s, c, size);
	expected_ret = memset(expected_s, c, size);
	if (ret == NULL && expected_ret == NULL)
		return (true);
	if ((ret == NULL && expected_ret != NULL) || (ret != NULL
			&& expected_ret == NULL))
		return (false);
	if (memcmp(ret, expected_ret, cmp_size) == 0)
		return (true);
	return (false);
}

int	main(void)
{
	char	s[10];
	char	expected_s[10];

	printf("ft_memset:           ");
	bzero(s, 10);
	bzero(expected_s, 10);
	/* -------------------- TEST 01 -------------------- */
	if (cmp_output(s, expected_s, 163, 1, 10))
		printf("%s 1:[OK]", GREEN);
	else
		printf("%s 1:[KO]", RED);
	/* -------------------- TEST 02 -------------------- */
	if (cmp_output(s, expected_s, 'e', 10, 10))
		printf("%s 2:[OK]", GREEN);
	else
		printf("%s 2:[KO]", RED);
	/* -------------------- TEST 03 -------------------- */
	if (cmp_output(s, expected_s, -120, 3, 10))
		printf("%s 3:[OK]", GREEN);
	else
		printf("%s 3:[KO]", RED);
	/* -------------------- TEST 04 -------------------- */
	if (is_segfault(NULL, 'b', 0) == true)
		printf("%s 4:[KO]", RED);
	else
		printf("%s 4:[OK]", GREEN);
	/* -------------------- TEST 05 -------------------- */
	if (is_segfault(NULL, 'b', 1) == true)
		printf("%s 5:[OK]", GREEN);
	else
		printf("%s 5:[KO]", RED);
	/* -------------------------------------------------- */
	printf("\x1b[0m\n");
}
