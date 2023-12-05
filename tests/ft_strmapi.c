/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:12:52 by aradix            #+#    #+#             */
/*   Updated: 2023/12/05 22:05:36 by aradix           ###   ########.fr       */
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

static bool	cmp_output(char *s, char (*f)(unsigned int, char), char *expected_ret)
{
	char	*ret;
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
	printf("ft_strmapi:           ");
	/* -------------------- TEST 01 -------------------- */
	if (cmp_output("Hello World !")
		printf("%s 1:[OK]", GREEN);
	else
		printf("%s 1:[KO]", RED);
	/* -------------------------------------------------- */
	printf("\x1b[0m\n");
}

