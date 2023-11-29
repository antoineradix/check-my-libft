/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:41:10 by aradix            #+#    #+#             */
/*   Updated: 2023/11/29 18:19:33 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check-my-libft.h"

static bool	is_segfault(char *s1, char *set)
{
	if (signal(SIGSEGV, signal_handler) == SIG_ERR)
	{
		fprintf(stderr, "Failed to set up signal handler\n");
		exit(1);
	}
	if (sigsetjmp(env, 1) == 0)
	{
		ft_strtrim(s1, set);
		return (0);
	}
	return (1);
}

static bool	cmp_output(char *s1, char *set, char *expected_ret)
{
	char	*ret;
	size_t	mem_size;
	size_t	expected_mem_size;

	ret = ft_strtrim(s1, set);
	if (ret == NULL && expected_ret == NULL)
		return (true);
	if ((ret == NULL && expected_ret != NULL) || (ret != NULL
			&& expected_ret == NULL))
		return (false);
	mem_size = malloc_usable_size(ret);
	expected_mem_size = malloc_usable_size(expected_ret);
	if (mem_size == expected_mem_size && strcmp(ret, expected_ret) == 0)
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
	printf("ft_strtrim:          ");
	/* -------------------- TEST 01 -------------------- */
	if (cmp_output("Hello World123456789abcdefghijklmnopqrtstuvwxyz!", "*",
			ft_strdup("Hello World123456789abcdefghijklmnopqrtstuvwxyz!")))
		printf("%s 1:[OK]", GREEN);
	else
		printf("%s 1:[KO]", RED);
	/* -------------------- TEST 02 -------------------- */
	if (cmp_output("Hello World123456789abcdefghijklmnopqrtstuvwxyz   !",
			"H !le", ft_strdup("o World123456789abcdefghijklmnopqrtstuvwxyz")))
		printf("%s 2:[OK]", GREEN);
	else
		printf("%s 2:[KO]", RED);
	/* -------------------- TEST 03 -------------------- */
	if (cmp_output("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
			"x",
			ft_strdup("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa")))
		printf("%s 3:[OK]", GREEN);
	else
		printf("%s 3:[KO]", RED);
	/* -------------------- TEST 04 -------------------- */
	if (cmp_output("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
			"a", ft_strdup("")))
		printf("%s 4:[OK]", GREEN);
	else
		printf("%s 4:[KO]", RED);
	/* -------------------- TEST 05 -------------------- */
	if (cmp_output("XXXXXXXxxxaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
			"Xx",
			ft_strdup("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa")))
		printf("%s 5:[OK]", GREEN);
	else
		printf("%s 5:[KO]", RED);
	/* -------------------- TEST 06 -------------------- */
	if (cmp_output("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaXXXxxxx",
			"Xx",
			ft_strdup("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa")))
		printf("%s 6:[OK]", GREEN);
	else
		printf("%s 6:[KO]", RED);
	/* -------------------- TEST 07 -------------------- */
	if (cmp_output("qqqq aaaa qqqqq", "abcdefghijklmnopq", ft_strdup(" aaaa ")))
		printf("%s 7:[OK]", GREEN);
	else
		printf("%s 7:[KO]", RED);
	/* -------------------- TEST 08 -------------------- */
	if (cmp_output("abcxdef", "abcdef", ft_strdup("x")))
		printf("%s 8:[OK]", GREEN);
	else
		printf("%s 8:[KO]", RED);
	/* -------------------- TEST 09 -------------------- */
	if (cmp_output("a", "a", ft_strdup("")))
		printf("%s 9:[OK]", GREEN);
	else
		printf("%s 9:[KO]", RED);
	/* -------------------- TEST 10 -------------------- */
	if (cmp_output("a", "x", ft_strdup("a")))
		printf("%s 10:[OK]", GREEN);
	else
		printf("%s 10:[KO]", RED);
	/* -------------------- TEST 11 -------------------- */
	if (cmp_output("", "abc", ft_strdup("")))
		printf("%s 11:[OK]", GREEN);
	else
		printf("%s 11:[KO]", RED);
	/* -------------------- TEST 12 -------------------- */
	if (is_segfault(NULL, "abc"))
		printf("%s 12:[💥]", GREEN);
	else
		printf("%s 12:[🛡️]", RED);
	/* -------------------- TEST 13 -------------------- */
	if (is_segfault("ee", NULL))
		printf("%s 13:[💥]", GREEN);
	else
		printf("%s 13:[🛡️]", RED);
	/* -------------------------------------------------- */
	printf("\x1b[0m\n");
}
