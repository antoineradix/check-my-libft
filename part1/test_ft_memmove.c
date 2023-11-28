/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memmove.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 18:25:36 by aradix            #+#    #+#             */
/*   Updated: 2023/11/16 21:21:23 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check-my-libft.h"

static bool	is_segfault(char *dest, char *src, size_t size)
{
	struct sigaction	sa;
	struct sigaction	old_sa;
	bool				ret;

	sa.sa_handler = segfault_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGSEGV, NULL, &old_sa);
	sigaction(SIGSEGV, &sa, NULL);
	if (setjmp(jump_buffer) == 0)
	{
		ft_memmove(dest, src, size);
		ret = false;
	}
	else
		ret = true;
	segfault_occurred = 0;
	sigaction(SIGSEGV, &old_sa, NULL);
	sigprocmask(SIG_SETMASK, &old_sa.sa_mask, NULL);
	return (ret);
}

static bool	cmp_output(char *dest, char *expected_dest, char *src,
		char *expected_src, size_t size, size_t cmp_size)
{
	char	*ret;
	char	*expected_ret;

	ret = ft_memmove(dest, src, size);
	expected_ret = memmove(expected_dest, expected_src, size);
	if (ret == NULL && expected_ret == NULL)
		return (true);
	if ((ret == NULL && expected_ret != NULL) || (ret != NULL
			&& expected_ret == NULL))
		return (false);
	if (memcmp(ret, expected_ret, cmp_size) == 0)
		return (true);
	return (false);
}

void	test_ft_memmove(void)
{
	char	dest[6] = "lol";
	char	expected_dest[6] = "lol";

	/* -------------------- TEST 01 -------------------- */
	if (cmp_output(dest, expected_dest, "abcde", "abcde", 5, 6))
		printf("%s 1:[OK]", GREEN);
	else
		printf("%s 1:[KO]", RED);
	/* -------------------- TEST 02 -------------------- */
	if (cmp_output(dest, expected_dest, dest + 1, expected_dest + 1, 3, 6))
		printf("%s 2:[OK]", GREEN);
	else
		printf("%s 2:[KO]", RED);
	/* -------------------- TEST 03 -------------------- */
	if (cmp_output(dest + 2, expected_dest + 2, dest, expected_dest, 3, 3))
		printf("%s 3:[OK]", GREEN);
	else
		printf("%s 3:[KO]", RED);
	/* -------------------- TEST 04 -------------------- */
	if (is_segfault(dest, dest, 50000000))
		printf("%s 4:[KO]", RED);
	else
		printf("%s 4:[OK]", GREEN);
	/* -------------------- TEST 05 -------------------- */
	if (is_segfault(dest, NULL, 0))
		printf("%s 5:[KO]", RED);
	else
		printf("%s 5:[OK]", GREEN);
	/* -------------------- TEST 06 -------------------- */
	if (is_segfault(NULL, NULL, 0))
		printf("%s 6:[KO]", RED);
	else
		printf("%s 6:[OK]", GREEN);
	/* -------------------- TEST 07 -------------------- */
	if (is_segfault(NULL, NULL, 5))
		printf("%s 7:[OK]", GREEN);
	else
		printf("%s 7:[KO]", RED);
	/* -------------------- TEST 08 -------------------- */
	if (is_segfault(dest, NULL, 1))
		printf("%s 8:[OK]", GREEN);
	else
		printf("%s 8:[KO]", RED);
	/* -------------------- TEST 09 -------------------- */
	if (is_segfault(NULL, dest, 1))
		printf("%s 9:[OK]", GREEN);
	else
		printf("%s 9:[KO]", RED);
	/* -------------------------------------------------- */
	printf("\x1b[0m\n");
}
