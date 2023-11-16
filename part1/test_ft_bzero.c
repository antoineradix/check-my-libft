/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_bzero.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:10:06 by aradix            #+#    #+#             */
/*   Updated: 2023/11/16 22:04:33 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check-my-libft.h"

static bool	is_segfault(char *s, size_t n)
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
		ft_bzero(s, n);
		ret = false;
	}
	else
		ret = true;
	segfault_occurred = 0;
	sigaction(SIGSEGV, &old_sa, NULL);
	sigprocmask(SIG_SETMASK, &old_sa.sa_mask, NULL);
	return (ret);
}

static bool	cmp_output(char *s, char *expected_s, size_t n, size_t cmp_size)
{
	ft_bzero(s, n);
	bzero(expected_s, n);
	if (memcmp(s, expected_s, cmp_size) == 0)
		return (true);
	return (false);
}

void	test_ft_bzero(void)
{
	char	*s;
	char	*expected_s;

	s = (char *)malloc(sizeof(char) * 10);
	expected_s = (char *)malloc(sizeof(char) * 10);
	if (s == NULL || expected_s == NULL)
	{
		free(s);
		free(expected_s);
		perror("Memory allocation error\n");
		exit(EXIT_FAILURE);
	}
	s = memset(s, 'x', 10);
	expected_s = memset(expected_s, 'x', 10);
	/* -------------------- TEST 01 -------------------- */
	if (cmp_output(s, expected_s, 5, 10))
		printf("%s 1:[OK]", GREEN);
	else
		printf("%s 1:[KO]", RED);
	/* -------------------------------------------------- */
	*s = 'a';
	*expected_s = 'a';
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
	free(s);
	free(expected_s);
	printf("\x1b[0m\n");
}
