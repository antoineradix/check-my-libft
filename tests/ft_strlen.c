/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 22:37:54 by aradix            #+#    #+#             */
/*   Updated: 2023/11/28 15:08:27 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check-my-libft.h"

static bool	is_segfault(char *s)
{
	if (signal(SIGSEGV, signal_handler) == SIG_ERR)
	{
		fprintf(stderr, "Failed to set up signal handler\n");
		exit(1);
	}
	if (sigsetjmp(env, 1) == 0)
	{
		ft_strlen(s);
		return (0);
	}
	return (1);
}

static bool	cmp_output(char *s)
{
	size_t	ret;
	size_t	expected_ret;

	ret = ft_strlen(s);
	expected_ret = strlen(s);
	if (ret == expected_ret)
		return (true);
	return (false);
}

int	main(void)
{
	printf("ft_strlen:           ");
	/* -------------------- TEST 01 -------------------- */
	if (cmp_output("Hello World ! :)"))
		printf("%s 1:[OK]", GREEN);
	else
		printf("%s 1:[KO]", RED);
	/* -------------------- TEST 02 -------------------- */
	if (cmp_output(""))
		printf("%s 2:[OK]", GREEN);
	else
		printf("%s 2:[KO]", RED);
	/* -------------------- TEST 03 -------------------- */
	if (cmp_output("Hello \0 Wirkd ! :)"))
		printf("%s 3:[OK]", GREEN);
	else
		printf("%s 3:[KO]", RED);
	/* -------------------- TEST 04 -------------------- */
	if (is_segfault(NULL))
		printf("%s 4:[OK]", GREEN);
	else
		printf("%s 4:[KO]", RED);
	/* -------------------- TEST 05 -------------------- */
	if (cmp_output("wedmwewmflwmflwmflmfmw'lmme wqmg mqregm ermgmr;lmre;lmre;lmg;lremqg;ler;gl;rmgmql;emgl;remgl;mktrjio5jtiojjoijfregr4g6549946er4g65e4r5grgr4654r654f"))
		printf("%s 5:[OK]", GREEN);
	else
		printf("%s 5:[KO]", RED);
	/* -------------------------------------------------- */
	printf("\x1b[0m\n");
}
