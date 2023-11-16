/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlcat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 20:55:48 by aradix            #+#    #+#             */
/*   Updated: 2023/11/16 14:44:14 by aradix           ###   ########.fr       */
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
		strlcat(dest, src, size);
		ret = false;
	}
	else
		ret = true;
	segfault_occurred = 0;
	sigaction(SIGSEGV, &old_sa, NULL);
	sigprocmask(SIG_SETMASK, &old_sa.sa_mask, NULL);
	return (ret);
}

static bool	cmp_output(char *dest, char *expected_dest, char *src, size_t size,
		short cmp_size)
{
	size_t	ret;
	size_t	expected_ret;

	ret = ft_strlcat(dest, src, size);
	expected_ret = strlcat(expected_dest, src, size);
	if ((ret == expected_ret) && memcmp(dest, expected_dest, cmp_size) == 0)
		return (true);
	else
		return (false);
}

void	test_ft_strlcat(void)
{
	char	*dest;
	char	*expected_dest;

	dest = (char *)malloc(sizeof(char) * 55);
	expected_dest = (char *)malloc(sizeof(char) * 55);
	if (dest == NULL || expected_dest == NULL)
	{
		free(dest);
		free(expected_dest);
		perror("Memory allocation error\n");
		exit(EXIT_FAILURE);
	}
	/* -------------------- TEST 01 -------------------- */
	if (cmp_output(dest, expected_dest, "eoooooooo", 500, 10))
		printf("%s 1:[OK]", GREEN);
	else
		printf("%s 1:[KO]", RED);
	/* -------------------- TEST 02 -------------------- */
	if (cmp_output(dest, expected_dest, "abcdefg42", 19, 20))
		printf("%s 2:[OK]", GREEN);
	else
		printf("%s 2:[KO]", RED);
	/* -------------------------------------------------- */
	memset(dest, 'a', 5);
	memset(expected_dest, 'a', 5);
	dest[5] = '\0';
	expected_dest[5] = '\0';
	/* -------------------- TEST 03 -------------------- */
	if (cmp_output(dest, expected_dest, "bbbbb", 10, 10))
		printf("%s 3:[OK]", GREEN);
	else
		printf("%s 3:[KO]", RED);
	/* -------------------- TEST 04 -------------------- */
	if (cmp_output(dest, expected_dest, "ccccccccc", 8, 8))
		printf("%s 4:[OK]", GREEN);
	else
		printf("%s 4:[KO]", RED);
	/* -------------------------------------------------- */
	memset(dest, 0, 50);
	memset(expected_dest, 0, 50);
	/* -------------------- TEST 05 -------------------- */
	if (cmp_output(dest, expected_dest, "a", 1, 10))
		printf("%s 5:[OK]", GREEN);
	else
		printf("%s 5:[KO]", RED);
	/* -------------------- TEST 06 -------------------- */
	if (cmp_output(dest, expected_dest, "a", 2, 2))
		printf("%s 6:[OK]", GREEN);
	else
		printf("%s 6:[KO]", RED);
	/* -------------------- TEST 07 -------------------- */
	if (cmp_output(dest, expected_dest, "a", 0, 2))
		printf("%s 7:[OK]", GREEN);
	else
		printf("%s 7:[KO]", RED);
	/* -------------------- TEST 08 -------------------- */
	if (is_segfault(dest, NULL, 0))
		printf("%s 8:[OK]", GREEN);
	else
		printf("%s 8:[KO]", RED);
	/* -------------------- TEST 09 -------------------- */
	if (is_segfault(NULL, "src not empty", 0))
		printf("%s 9:[KO]", RED);
	else
		printf("%s 9:[OK]", GREEN);
	/* -------------------- TEST 10 -------------------- */
	if (is_segfault(NULL, "src not empty", 5))
		printf("%s 10:[OK]", GREEN);
	else
		printf("%s 10:[KO]", RED);
	/* -------------------------------------------------- */
	free(dest);
	free(expected_dest);
	printf("\x1b[0m\n");
}
