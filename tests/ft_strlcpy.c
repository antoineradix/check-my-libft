/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 23:04:01 by aradix            #+#    #+#             */
/*   Updated: 2023/11/28 15:08:04 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check-my-libft.h"

static bool	is_segfault(char *dest, char *src, size_t size)
{
	if (signal(SIGSEGV, signal_handler) == SIG_ERR)
	{
		fprintf(stderr, "Failed to set up signal handler\n");
		exit(1);
	}
	if (sigsetjmp(env, 1) == 0)
	{
		ft_strlcpy(dest, src, size);
		return (0);
	}
	return (1);
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

int	main(void)
{
	char	dest[26] = "abcdefghijklmnopqrstuvwxyz";
	char	expected_dest[26] = "abcdefghijklmnopqrstuvwxyz";

	printf("ft_strlcpy:          ");
	/* -------------------- TEST 01 -------------------- */
	if (cmp_output(dest, expected_dest, "abcdexxxxxxxxxxx", 6, 26))
		printf("%s 1:[OK]", GREEN);
	else
		printf("%s 1:[KO]", RED);
	/* -------------------- TEST 02 -------------------- */
	if (cmp_output(dest, expected_dest, "---", 0, 26))
		printf("%s 2:[OK]", GREEN);
	else
		printf("%s 2:[KO]", RED);
	/* -------------------- TEST 03 -------------------- */
	if (cmp_output(dest, expected_dest, "01234567890123456789", 100, 26))
		printf("%s 3:[OK]", GREEN);
	else
		printf("%s 3:[KO]", RED);
	/* -------------------- TEST 04 -------------------- */
	if (cmp_output(dest, expected_dest, "", 1, 26))
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
	printf("\x1b[0m\n");
}
