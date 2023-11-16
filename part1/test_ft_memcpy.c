/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memcpy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:27:58 by aradix            #+#    #+#             */
/*   Updated: 2023/11/16 21:35:53 by aradix           ###   ########.fr       */
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
		ft_memcpy(dest, src, size);
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

	ret = ft_memcpy(dest, src, size);
	expected_ret = memcpy(expected_dest, expected_src, size);
	if (ret == NULL && expected_ret == NULL)
		return (true);
	if ((ret == NULL && expected_ret != NULL) || (ret != NULL
			&& expected_ret == NULL))
		return (false);
	if (memcmp(ret, expected_ret, cmp_size) == 0)
		return (true);
	return (false);
}

void	test_ft_memcpy(void)
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
		return ;
	}
	dest = memset(dest, 'p', 25);
	expected_dest = memset(expected_dest, 'p', 25);
	/* -------------------- TEST 01 -------------------- */
	if (cmp_output(dest, expected_dest, "hello", "hello", 3, 25))
		printf("%s 1:[OK]", GREEN);
	else
		printf("%s 1:[KO]", RED);
	/* -------------------- TEST 02 -------------------- */
	if (cmp_output(dest, expected_dest, dest + 1, expected_dest + 1, 5, 25))
		printf("%s 2:[OK]", GREEN);
	else
		printf("%s 2:[KO]", RED);
	/* -------------------- TEST 03 -------------------- */
	if (cmp_output(dest, expected_dest, "", "", 0, 1))
		printf("%s 3:[OK]", GREEN);
	else
		printf("%s 3:[KO]", RED);
	/* -------------------- TEST 04 -------------------- */
	if (is_segfault(NULL, NULL, 10))
		printf("%s 4:[OK]", GREEN);
	else
		printf("%s 4:[KO]", RED);
	/* -------------------- TEST 05 -------------------- */
	if (is_segfault(NULL, NULL, 0))
		printf("%s 5:[KO]", RED);
	else
		printf("%s 5:[OK]", GREEN);
	/* -------------------------------------------------- */
	free(dest);
	free(expected_dest);
	printf("\x1b[0m\n");
}
