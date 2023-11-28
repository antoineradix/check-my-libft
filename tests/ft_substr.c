/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 21:37:28 by aradix            #+#    #+#             */
/*   Updated: 2023/11/28 22:23:32 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check-my-libft.h"

static bool	is_segfault(char *s, unsigned int start, unsigned int len)
{
	if (signal(SIGSEGV, signal_handler) == SIG_ERR)
	{
		fprintf(stderr, "Failed to set up signal handler\n");
		exit(1);
	}
	if (sigsetjmp(env, 1) == 0)
	{
		ft_substr(s, start, len);
		return (0);
	}
	return (1);
}

static bool	cmp_output(char *s, unsigned int start, unsigned int len,
		char *expected_ret, size_t cmp_size)
{
	char	*ret;
	size_t	mem_size;
	size_t	expected_mem_size;

	ret = ft_substr(s, start, len);
	if (ret == NULL && expected_ret == NULL)
		return (true);
	if ((ret == NULL && expected_ret != NULL) || (ret != NULL
			&& expected_ret == NULL))
		return (false);
	mem_size = malloc_usable_size(ret);
	expected_mem_size = malloc_usable_size(expected_ret);
	if (mem_size == expected_mem_size && memcmp(ret, expected_ret, cmp_size) == 0)
	{
		free(ret);
		free(expected_ret);
		return (true);
	}
	free(ret);
	free(expected_ret);
	return (false);
}

int	main(void)
{
	printf("ft_substr:           ");
	/* -------------------- TEST 01 -------------------- */
	if (cmp_output("Hello World\n", 1, 2, strdup("el"), 3))
		printf("%s 1:[OK]", GREEN);
	else
		printf("%s 1:[KO]", RED);
	/* -------------------- TEST 02 -------------------- */
	if (cmp_output("Hello World\n", 0, 5000, strdup("Hello World\n"), 13))
		printf("%s 2:[OK]", GREEN);
	else
		printf("%s 2:[KO]", RED);
	/* -------------------- TEST 03 -------------------- */
	if (cmp_output("Hello", 4, 1, strdup("o"), 2))
		printf("%s 3:[OK]", GREEN);
	else
		printf("%s 3:[KO]", RED);
	/* -------------------- TEST 04 -------------------- */
	if (cmp_output("Hello", 8, 2, strdup("\0"), 1))
		printf("%s 4:[OK]", GREEN);
	else
		printf("%s 4:[KO]", RED);
	/* -------------------- TEST 05 -------------------- */
	if (cmp_output("", 0, 1, strdup(""), 1))
		printf("%s 5:[OK]", GREEN);
	else
		printf("%s 5:[KO]", RED);
	/* -------------------- TEST 06 -------------------- */
	if (cmp_output("aaa", 0, 0, strdup(""), 1))
		printf("%s 6:[OK]", GREEN);
	else
		printf("%s 6:[KO]", RED);
	/* -------------------- TEST 07 -------------------- */
	if (cmp_output(NULL, 0, 0, strdup(""), 1))
		printf("%s 7:[OK]", GREEN);
	else
		printf("%s 7:[KO]", RED);
	/* -------------------- TEST 08 -------------------- */
	if (is_segfault(NULL, 10, 0))
		printf("%s 8:[KO]", RED);
	else
		printf("%s 8:[OK]", GREEN);
	/* -------------------- TEST 09 -------------------- */
	if (is_segfault(NULL, 0, 1))
		printf("%s 9:[💥]", GREEN);
	else
		printf("%s 9:[🛡️]", GREEN);
	/* -------------------- TEST 10 -------------------- */
	if (is_segfault(NULL, 10, 1))
		printf("%s 10:[💥]", GREEN);
	else
		printf("%s 10:[🛡️]", GREEN);
	/* -------------------------------------------------- */
	printf("\x1b[0m\n");
}
