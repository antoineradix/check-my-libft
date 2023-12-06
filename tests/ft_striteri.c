/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 10:14:36 by aradix            #+#    #+#             */
/*   Updated: 2023/12/06 11:03:08 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check-my-libft.h"

void	fn(unsigned int i, char *s)
{
	*s += i;
}

static bool	is_segfault(char *ret, void (*f)(unsigned int, char *))
{
	if (signal(SIGSEGV, signal_handler) == SIG_ERR)
	{
		fprintf(stderr, "Failed to set up signal handler\n");
		exit(1);
	}
	if (sigsetjmp(env, 1) == 0)
	{
		ft_striteri(ret, f);
		free(ret);
		return (0);
	}
	return (1);
}

static bool	cmp_output(char *ret, char *expected_ret)
{
	ft_striteri(ret, fn);
	if (strcmp(ret, expected_ret) == 0)
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
	printf("ft_striteri:         ");
	/* -------------------- TEST 01 -------------------- */
	if (cmp_output(strdup("aaaaaaaaaaaaaaa"), strdup("abcdefghijklmno")))
		printf("%s 1:[OK]", GREEN);
	else
		printf("%s 1:[KO]", RED);
	/* -------------------- TEST 02 -------------------- */
	if (cmp_output(strdup("a"), strdup("a")))
		printf("%s 2:[OK]", GREEN);
	else
		printf("%s 2:[KO]", RED);
	/* -------------------- TEST 03 -------------------- */
	if (cmp_output(strdup("Ab"), strdup("Ac")))
		printf("%s 3:[OK]", GREEN);
	else
		printf("%s 3:[KO]", RED);
	/* -------------------- TEST 04 -------------------- */
	if (cmp_output(strdup("00000"), strdup("01234")))
		printf("%s 4:[OK]", GREEN);
	else
		printf("%s 4:[KO]", RED);
	/* -------------------- TEST 05 -------------------- */
	if (cmp_output(strdup(""), strdup("")))
		printf("%s 5:[OK]", GREEN);
	else
		printf("%s 5:[KO]", RED);
	/* -------------------- TEST 06 -------------------- */
	if (is_segfault(NULL, &fn))
		printf("%s 6:[💥]", GREEN);
	else
		printf("%s 6:[🛡️ ]", GREEN);
	/* -------------------- TEST 06 -------------------- */
	if (is_segfault("e", NULL))
		printf("%s 7:[💥]", GREEN);
	else
		printf("%s 7:[🛡️ ]", GREEN);
	/* -------------------------------------------------- */
	printf("\x1b[0m\n");
}
