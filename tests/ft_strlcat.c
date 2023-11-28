/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 23:05:33 by aradix            #+#    #+#             */
/*   Updated: 2023/11/28 15:20:03 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check-my-libft.h"
#include <stdio.h>
#include <strings.h>

static bool	is_segfault(char *dest, char *src, size_t size)
{
	if (signal(SIGSEGV, signal_handler) == SIG_ERR)
	{
		fprintf(stderr, "Failed to set up signal handler\n");
		exit(1);
	}
	if (sigsetjmp(env, 1) == 0)
	{
		ft_strlcat(dest, src, size);
		return (0);
	}
	return (1);
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
	return (false);
}

int	main(void)
{
	char	dest[55];
	char	expected_dest[55];

	printf("ft_strlcat:          ");
	bzero(dest, 55);
	bzero(expected_dest, 55);
	/* -------------------- TEST 01 -------------------- */
	if (cmp_output(dest, expected_dest, "eoooooooo", 500, 55))
		printf("%s 1:[OK]", GREEN);
	else
		printf("%s 1:[KO]", RED);
	/* -------------------- TEST 02 -------------------- */
	if (cmp_output(dest, expected_dest, "abcdefg42", 19, 55))
		printf("%s 2:[OK]", GREEN);
	else
		printf("%s 2:[KO]", RED);
	/* -------------------------------------------------- */
	memset(dest, 'a', 5);
	memset(expected_dest, 'a', 5);
	dest[5] = '\0';
	expected_dest[5] = '\0';
	/* -------------------- TEST 03 -------------------- */
	if (cmp_output(dest, expected_dest, "bbbbb", 10, 55))
		printf("%s 3:[OK]", GREEN);
	else
		printf("%s 3:[KO]", RED);
	/* -------------------- TEST 04 -------------------- */
	if (cmp_output(dest, expected_dest, "ccccccccc", 8, 55))
		printf("%s 4:[OK]", GREEN);
	else
		printf("%s 4:[KO]", RED);
	/* -------------------------------------------------- */
	bzero(dest, 55);
	bzero(expected_dest, 55);
	/* -------------------- TEST 05 -------------------- */
	if (cmp_output(dest, expected_dest, "a", 1, 55))
		printf("%s 5:[OK]", GREEN);
	else
		printf("%s 5:[KO]", RED);
	/* -------------------- TEST 06 -------------------- */
	if (cmp_output(dest, expected_dest, "a", 2, 55))
		printf("%s 6:[OK]", GREEN);
	else
		printf("%s 6:[KO]", RED);
	/* -------------------- TEST 07 -------------------- */
	if (cmp_output(dest, expected_dest, "a", 0, 55))
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
	printf("\x1b[0m\n");
}
