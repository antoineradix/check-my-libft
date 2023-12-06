/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 19:31:29 by aradix            #+#    #+#             */
/*   Updated: 2023/12/06 10:10:06 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check-my-libft.h"

static bool	is_segfault(char *s, char c)
{
	if (signal(SIGSEGV, signal_handler) == SIG_ERR)
	{
		fprintf(stderr, "Failed to set up signal handler\n");
		exit(1);
	}
	if (sigsetjmp(env, 1) == 0)
	{
		ft_split(s, c);
		return (0);
	}
	return (1);
	/* MEMORY LEAKS */
}

static bool	cmp_output(char *s, char c, char **expected_ret)
{
	char	**ret;
	size_t	len;
	size_t	expected_len;

	ret = ft_split(s, c);
	len = 0;
	expected_len = 0;
	if (ret == NULL && expected_ret == NULL)
		return (true);
	else if ((ret == NULL && expected_ret != NULL) || (ret != NULL
			&& expected_ret == NULL))
		return (false);
	while (ret[len] && expected_ret[expected_len])
	{
		if (strcmp(ret[len], expected_ret[expected_len]) != 0)
			return (false);
		len++;
		expected_len++;
	}
	while (ret[len])
		len++;
	while (expected_ret[expected_len])
		expected_len++;
	if (len == expected_len)
		return (true);
	return (false);
	/* MEMORY LEAKS */
}

int	main(void)
{
	printf("ft_split:            ");
	/* -------------------- TEST 01 -------------------- */
	if (cmp_output("Hello", 'X', (char *[]){"Hello", NULL}))
		printf("%s 1:[OK]", GREEN);
	else
		printf("%s 1:[KO]", RED);
	/* -------------------- TEST 02 -------------------- */
	if (cmp_output("HelloXWorld", 'X', (char *[]){"Hello", "World", NULL}))
		printf("%s 2:[OK]", GREEN);
	else
		printf("%s 2:[KO]", RED);
	/* -------------------- TEST 03 -------------------- */
	if (cmp_output("XHXelloXWorldX!X", 'X', (char *[]){"H", "ello", "World",
			"!", NULL}))
		printf("%s 3:[OK]", GREEN);
	else
		printf("%s 3:[KO]", RED);
	/* -------------------- TEST 04 -------------------- */
	if (cmp_output("HXXXXXXelloXXXXXWorldXXXX!XXXXX", 'X', (char *[]){"H",
			"ello", "World", "!", NULL}))
		printf("%s 4:[OK]", GREEN);
	else
		printf("%s 4:[KO]", RED);
	/* -------------------- TEST 05 -------------------- */
	if (cmp_output("XXXXXXXXXXXXXXXXX", 'X', (char *[]){NULL}))
		printf("%s 5:[OK]", GREEN);
	else
		printf("%s 5:[KO]", RED);
	/* -------------------- TEST 06 -------------------- */
	if (cmp_output("", 'X', (char *[]){NULL}))
		printf("%s 6:[OK]", GREEN);
	else
		printf("%s 6:[KO]", RED);
	/* -------------------- TEST 07 -------------------- */
	if (is_segfault(NULL, 'e'))
		printf("%s 7:[💥]", GREEN);
	else
		printf("%s 7:[🛡️ ]", GREEN);
	/* -------------------------------------------------- */
	printf("\x1b[0m\n");
}
