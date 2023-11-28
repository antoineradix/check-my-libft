/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 22:58:35 by aradix            #+#    #+#             */
/*   Updated: 2023/11/28 15:08:14 by aradix           ###   ########.fr       */
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
		ft_memcpy(dest, src, size);
		return (0);
	}
	return (1);
}

static bool	cmp_output(char *dest, char *expected_dest, char *src, size_t size,
		size_t cmp_size)
{
	char	*ret;
	char	*expected_ret;

	ret = ft_memcpy(dest, src, size);
	expected_ret = memcpy(expected_dest, src, size);
	if (ret == NULL && expected_ret == NULL)
		return (true);
	if ((ret == NULL && expected_ret != NULL) || (ret != NULL
			&& expected_ret == NULL))
		return (false);
	if (memcmp(ret, expected_ret, cmp_size) == 0)
		return (true);
	return (false);
}

int	main(void)
{
	char	dest[26] = "abcdefghijklmnopqrstuvwxyz";
	char	expected_dest[26] = "abcdefghijklmnopqrstuvwxyz";

	printf("ft_memcpy:           ");
	/* -------------------- TEST 01 -------------------- */
	if (cmp_output(dest, expected_dest, "hello", 3, 26))
		printf("%s 1:[OK]", GREEN);
	else
		printf("%s 1:[KO]", RED);
	/* -------------------- TEST 02 -------------------- */
	if (cmp_output(dest, expected_dest, "", 0, 26))
		printf("%s 2:[OK]", GREEN);
	else
		printf("%s 2:[KO]", RED);
	/* -------------------- TEST 03 -------------------- */
	if (cmp_output(dest, expected_dest, "", 1, 26))
		printf("%s 3:[OK]", GREEN);
	else
		printf("%s 3:[KO]", RED);
	/* -------------------- TEST 04 -------------------- */
	if (is_segfault(NULL, NULL, 0))
		printf("%s 4:[KO]", RED);
	else
		printf("%s 4:[OK]", GREEN);
	/* -------------------- TEST 05 -------------------- */
	if (is_segfault(NULL, NULL, 1))
		printf("%s 5:[OK]", GREEN);
	else
		printf("%s 5:[KO]", RED);
	/* -------------------------------------------------- */
	printf("\x1b[0m\n");
}
