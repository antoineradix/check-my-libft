/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 22:14:08 by aradix            #+#    #+#             */
/*   Updated: 2023/11/22 23:16:55 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check-my-libft.h"

static bool	cmp_output(char *s, char *expected_s, int c, size_t size, size_t cmp_size)
{
	char	*ret;
	char	*expected_ret;

	ret = ft_memset(s, c, size);
	expected_ret = memset(expected_s, c, size);
	if (ret == NULL && expected_ret == NULL)
		return (true);
	if ((ret == NULL && expected_ret != NULL) || (ret != NULL
			&& expected_ret == NULL))
		return (false);
	if (memcmp(ret, expected_ret, cmp_size) == 0)
		return (true);
	return (false);
}

int		main(void)
{
	char	*s;
	char	*expected_s;

	printf("ft_memset:           ");
	s = (char *)malloc(sizeof(char) * 10);
	expected_s = (char *)malloc(sizeof(char) * 10);
	if (s == NULL || expected_s == NULL)
	{
		free(s);
		free(expected_s);
		perror("Memory allocation error\n");
		exit(EXIT_FAILURE);
	}
	/* -------------------- TEST 01 -------------------- */
	if (cmp_output(s, expected_s, 163, 1, 10))
		printf("%s 1:[OK]", GREEN);
	else
		printf("%s 1:[KO]", RED);
	/* -------------------- TEST 02 -------------------- */
	if (cmp_output(s, expected_s, 'e', 10, 10))
		printf("%s 2:[OK]", GREEN);
	else
		printf("%s 2:[KO]", RED);
	/* -------------------- TEST 03 -------------------- */
	if (cmp_output(s, expected_s, -120, 3, 10))
		printf("%s 3:[OK]", GREEN);
	else
		printf("%s 3:[KO]", RED);
	/* -------------------------------------------------- */
	free(s);
	free(expected_s);
	printf("\x1b[0m\n");
}
