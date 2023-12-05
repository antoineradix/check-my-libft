/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 09:24:32 by aradix            #+#    #+#             */
/*   Updated: 2023/12/05 12:11:43 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check-my-libft.h"

static bool	cmp_output(int n, char *expected_ret)
{
	char	*ret;
	size_t	mem_size;
	size_t	expected_mem_size;

	ret = ft_itoa(n);
	if (ret == NULL && expected_ret == NULL)
		return (true);
	else if ((ret == NULL && expected_ret != NULL) || (ret != NULL
			&& expected_ret == NULL))
		return (false);
	mem_size = malloc_usable_size(ret);
	expected_mem_size = malloc_usable_size(expected_ret);
	if (mem_size == expected_mem_size && strcmp(ret, expected_ret) == 0)
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
	printf("ft_itoa:             ");
	/* -------------------- TEST 01 -------------------- */
	if (cmp_output(0, strdup("0")))
		printf("%s 1:[OK]", GREEN);
	else
		printf("%s 1:[KO]", RED);
	/* -------------------- TEST 02 -------------------- */
	if (cmp_output(42, strdup("42")))
		printf("%s 2:[OK]", GREEN);
	else
		printf("%s 2:[KO]", RED);
	/* -------------------- TEST 03 -------------------- */
	if (cmp_output(-42, strdup("-42")))
		printf("%s 3:[OK]", GREEN);
	else
		printf("%s 3:[KO]", RED);
	/* -------------------- TEST 04 -------------------- */
	if (cmp_output(-1000, strdup("-1000")))
		printf("%s 4:[OK]", GREEN);
	else
		printf("%s 4:[KO]", RED);
	/* -------------------- TEST 05 -------------------- */
	if (cmp_output(2147483647, strdup("2147483647")))
		printf("%s 5:[OK]", GREEN);
	else
		printf("%s 5:[KO]", RED);
	/* -------------------- TEST 06 -------------------- */
	if (cmp_output(-2147483648, strdup("-2147483648")))
		printf("%s 6:[OK]", GREEN);
	else
		printf("%s 6:[KO]", RED);
	/* -------------------------------------------------- */
	printf("\x1b[0m\n");
}
