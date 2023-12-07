/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 19:21:47 by aradix            #+#    #+#             */
/*   Updated: 2023/12/07 18:27:23 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check-my-libft.h"

static bool	is_segfault(char *big, char *little, size_t len)
{
	if (signal(SIGSEGV, signal_handler) == SIG_ERR)
	{
		fprintf(stderr, "Failed to set up signal handler\n");
		exit(1);
	}
	if (sigsetjmp(env, 1) == 0)
	{
		ft_strnstr(big, little, len);
		return (0);
	}
	return (1);
}

static bool	cmp_output(char *big, char *little, size_t len)
{
	char	*ret;
	char	*expected_ret;

	ret = ft_strnstr(big, little, len);
	expected_ret = strnstr(big, little, len);
	if (ret == NULL && expected_ret == NULL)
		return (true);
	if ((ret == NULL && expected_ret != NULL) || (ret != NULL
			&& expected_ret == NULL))
		return (false);
	if (strcmp(ret, expected_ret) == 0)
		return (true);
	return (false);
}

int	main(void)
{
	printf("ft_strnstr:          ");
	/* -------------------- TEST 01 -------------------- */
	if (cmp_output("Hello World !", "lo", 100))
		printf("%s 1:[OK]", GREEN);
	else
		printf("%s 1:[KO]", RED);
	/* -------------------- TEST 02 -------------------- */
	if (cmp_output("Hello World !", "lO", 100))
		printf("%s 2:[OK]", GREEN);
	else
		printf("%s 2:[KO]", RED);
	/* -------------------- TEST 03 -------------------- */
	if (cmp_output("Hello World !", "!\0", 100))
		printf("%s 3:[OK]", GREEN);
	else
		printf("%s 3:[KO]", RED);
	/* -------------------- TEST 04 -------------------- */
	if (cmp_output("Hello World !", "!\0", 100))
		printf("%s 4:[OK]", GREEN);
	else
		printf("%s 4:[KO]", RED);
	/* -------------------- TEST 05 -------------------- */
	if (cmp_output("ab", "b", 1))
		printf("%s 5:[OK]", GREEN);
	else
		printf("%s 5:[KO]", RED);
	/* -------------------- TEST 06 -------------------- */
	if (cmp_output("ab", "", 2))
		printf("%s 6:[OK]", GREEN);
	else
		printf("%s 6:[KO]", RED);
	/* -------------------- TEST 07 -------------------- */
	if (cmp_output("", "", 0))
		printf("%s 7:[OK]", GREEN);
	else
		printf("%s 7:[KO]", RED);
	/* -------------------- TEST 08 -------------------- */
	if (cmp_output("aaa\0w", "\0x", 20))
		printf("%s 8:[OK]", GREEN);
	else
		printf("%s 8:[KO]", RED);
	/* -------------------- TEST 09 -------------------- */
	if (is_segfault(NULL, 0, 0))
		printf("%s 9:[OK]", GREEN);
	else
		printf("%s 9:[KO]", RED);
	/* -------------------- TEST 10 -------------------- */
	if (cmp_output("aaa\0w", "w", 20))
		printf("%s 10:[OK]", GREEN);
	else
		printf("%s 10:[KO]", RED);
	/* -------------------------------------------------- */
	printf("\x1b[0m\n");
}
