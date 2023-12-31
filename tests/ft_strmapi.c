/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:12:52 by aradix            #+#    #+#             */
/*   Updated: 2023/12/06 11:05:00 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check-my-libft.h"

char	fn(unsigned int n, char c)
{
	if (n % 2 != 0)
	{
		if (c >= 'A' && c <= 'Z')
			return (c + 32);
		return (c);
	}
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

static bool	is_segfault(char *s, char (*f)(unsigned int, char))
{
	if (signal(SIGSEGV, signal_handler) == SIG_ERR)
	{
		fprintf(stderr, "Failed to set up signal handler\n");
		exit(1);
	}
	if (sigsetjmp(env, 1) == 0)
	{
		ft_strmapi(s, f);
		free(s);
		return (0);
	}
	return (1);
}

static bool	cmp_output(char *s, char *expected_ret)
{
	char	*ret;
	size_t	mem_size;
	size_t	expected_mem_size;

	ret = ft_strmapi(s, &fn);
	if (ret == NULL && expected_ret == NULL)
		return (true);
	else if ((ret == NULL && expected_ret != NULL) || (ret != NULL
			&& expected_ret == NULL))
		return (false);
	mem_size = malloc_usable_size(ret);
	expected_mem_size = malloc_usable_size(expected_ret);
	if ((mem_size == expected_mem_size) && (strcmp(ret, expected_ret) == 0))
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
	printf("ft_strmapi:          ");
	/* -------------------- TEST 01 -------------------- */
	if (cmp_output("Hello World !", strdup("HeLlO WoRlD !")))
		printf("%s 1:[OK]", GREEN);
	else
		printf("%s 1:[KO]", RED);
	/* -------------------- TEST 02 -------------------- */
	if (cmp_output("a", strdup("A")))
		printf("%s 2:[OK]", GREEN);
	else
		printf("%s 2:[KO]", RED);
	/* -------------------- TEST 03 -------------------- */
	if (cmp_output("A", strdup("A")))
		printf("%s 3:[OK]", GREEN);
	else
		printf("%s 3:[KO]", RED);
	/* -------------------- TEST 04 -------------------- */
	if (cmp_output("aaweflkmewlkmewfmfqlkemlkwfmlkqewmflkeq42ew",
			strdup("AaWeFlKmEwLkMeWfMfQlKeMlKwFmLkQeWmFlKeQ42eW")))
		printf("%s 4:[OK]", GREEN);
	else
		printf("%s 4:[KO]", RED);
	/* -------------------- TEST 05 -------------------- */
	if (cmp_output("", strdup("")))
		printf("%s 5:[OK]", GREEN);
	else
		printf("%s 5:[KO]", RED);
	/* -------------------- TEST 06 -------------------- */
	if (is_segfault(NULL, &fn))
		printf("%s 6:[💥]", GREEN);
	else
		printf("%s 6:[🛡️ ]", GREEN);
	/* -------------------- TEST 07 -------------------- */
	if (is_segfault("e", NULL))
		printf("%s 7:[💥]", GREEN);
	else
		printf("%s 7:[🛡️ ]", GREEN);
	/* -------------------------------------------------- */
	printf("\x1b[0m\n");
}
