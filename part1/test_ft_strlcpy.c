/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlcpy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 19:48:08 by aradix            #+#    #+#             */
/*   Updated: 2023/11/16 21:44:02 by aradix           ###   ########.fr       */
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
		ft_strlcpy(dest, src, size);
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

	ret = ft_strlcpy(dest, src, size);
	expected_ret = strlcpy(expected_dest, src, size);
	if ((ret == expected_ret) && memcmp(dest, expected_dest, cmp_size) == 0)
		return (true);
	return (false);
}

void	test_ft_strlcpy(void)
{
	char	*dest;
	char	*expected_dest;

	dest = (char *)malloc(sizeof(char) * 25);
	expected_dest = (char *)malloc(sizeof(char) * 25);
	if (dest == NULL || expected_dest == NULL)
	{
		free(dest);
		free(expected_dest);
		perror("Memory allocation error\n");
		exit(EXIT_FAILURE);
	}
	dest = memcpy(dest, "test fghij 12345678942 !\0", 25);
	expected_dest = memcpy(dest, "test fghij 12345678942 !\0", 25);
	/* -------------------- TEST 01 -------------------- */
	if (cmp_output(dest, expected_dest, "abcdexxxxxxxxxxx", 6, 25))
		printf("%s 1:[OK]", GREEN);
	else
		printf("%s 1:[KO]", RED);
	/* -------------------- TEST 02 -------------------- */
	if (cmp_output(dest, expected_dest, "---", 0, 25))
		printf("%s 2:[OK]", GREEN);
	else
		printf("%s 2:[KO]", RED);
	/* -------------------- TEST 03 -------------------- */
	if (cmp_output(dest, expected_dest, "01234567890123456789", 100, 25))
		printf("%s 3:[OK]", GREEN);
	else
		printf("%s 3:[KO]", RED);
	/* -------------------- TEST 04 -------------------- */
	if (cmp_output(dest, expected_dest, "", 1, 25))
		printf("%s 4:[OK]", GREEN);
	else
		printf("%s 4:[KO]", RED);
	/* -------------------- TEST 05 -------------------- */
	if (is_segfault(NULL, "--", 0))
		printf("%s 5:[KO]", RED);
	else
		printf("%s 5:[OK]", GREEN);
	/* -------------------- TEST 06 -------------------- */
	if (is_segfault(NULL, "--", 1))
		printf("%s 6:[OK]", GREEN);
	else
		printf("%s 6:[KO]", RED);
	/* -------------------- TEST 07 -------------------- */
	if (is_segfault("--", NULL, 0))
		printf("%s 7:[OK]", GREEN);
	else
		printf("%s 7:[KO]", RED);
	/* -------------------------------------------------- */
	free(dest);
	/* free(expected_dest); error if enable :( */
	printf("\x1b[0m\n");
}
