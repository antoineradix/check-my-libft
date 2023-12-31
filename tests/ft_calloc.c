/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 19:35:01 by aradix            #+#    #+#             */
/*   Updated: 2023/11/28 21:07:06 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check-my-libft.h"

static bool	is_segfault(size_t nmemb, size_t size)
{
	char	*ret;

	if (signal(SIGSEGV, signal_handler) == SIG_ERR)
	{
		fprintf(stderr, "Failed to set up signal handler\n");
		exit(1);
	}
	if (sigsetjmp(env, 1) == 0)
	{
		ret = ft_calloc(nmemb, size);
		free(ret);
		return (0);
	}
	return (1);
}

static bool	cmp_output(size_t nmemb, size_t size)
{
	void	*ret;
	void	*expected_ret;
	size_t	mem_size;
	size_t	expected_mem_size;

	ret = ft_calloc(nmemb, size);
	expected_ret = calloc(nmemb, size);
	if (ret == NULL && expected_ret == NULL)
		return (true);
	if ((ret == NULL && expected_ret != NULL) || (ret != NULL
			&& expected_ret == NULL))
		return (false);
	mem_size = malloc_usable_size(ret);
	expected_mem_size = malloc_usable_size(expected_ret);
	if (mem_size == expected_mem_size && memcmp(ret, expected_ret, (nmemb * size)) == 0)
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
	size_t	i;

	printf("ft_calloc:           ");
	/* -------------------- TEST 01 -------------------- */
	i = 0;
	while (i++ < 100)
		if (cmp_output(1000, i) == false)
			break ;
	if (i == 101)
		printf("%s 1:[OK]", GREEN);
	else
		printf("%s 1:[KO]", RED);
	/* -------------------- TEST 02 -------------------- */
	if (cmp_output(42, sizeof(long int)))
		printf("%s 2:[OK]", GREEN);
	else
		printf("%s 2:[KO]", RED);
	/* -------------------- TEST 03 -------------------- */
	if (cmp_output(1, sizeof(int)))
		printf("%s 3:[OK]", GREEN);
	else
		printf("%s 3:[KO]", RED);
	/* -------------------- TEST 04 -------------------- */
	if (cmp_output(0, SIZE_MAX))
		printf("%s 4:[OK]", GREEN);
	else
		printf("%s 4:[KO]", RED);
	/* -------------------- TEST 05 -------------------- */
	if (is_segfault(SIZE_MAX, 0))
		printf("%s 5:[KO]", RED);
	else if (cmp_output(SIZE_MAX, 0))
		printf("%s 5:[OK]", GREEN);
	else
		printf("%s 5:[KO]", RED);
	/* -------------------- TEST 06 -------------------- */
	if (is_segfault(SIZE_MAX, SIZE_MAX))
		printf("%s 6:[KO]", RED);
	else if (cmp_output(SIZE_MAX, SIZE_MAX))
		printf("%s 6:[OK]", GREEN);
	else
		printf("%s 6:[KO]", RED);
	/* -------------------- TEST 07 -------------------- */
	if (cmp_output(0, 0))
		printf("%s 7:[OK]", GREEN);
	else
		printf("%s 7:[KO]", RED);
	/* -------------------------------------------------- */
	printf("\x1b[0m\n");
}
