/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:19:31 by aradix            #+#    #+#             */
/*   Updated: 2023/11/15 18:21:47 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check-my-libft.h"

void	test_ft_memset(void)
{
	char	*str;
	char	*expected_str;

	str = (char *)malloc(sizeof(char) * 10);
	if (!str)
		return ;
	expected_str = (char *)malloc(sizeof(char) * 10);
	if (!expected_str)
	{
		free(str);
		return ;
	}
	/* TEST WITH SINGLE CHAR */
	str = ft_memset(str, 163, 1);
	expected_str = memset(str, 163, 1);
	if (*str == *expected_str)
		printf("%s [OK]", GREEN);
	else
		printf("%s [KO]", RED);
	/* TEST WITH BASIC VALUE */
	str = ft_memset(str, 'e', 10);
	expected_str = memset(str, 'e', 10);
	if (memcmp(str, expected_str, 10) == 0)
		printf("%s [OK]", GREEN);
	else
		printf("%s [KO]", RED);
	/* WITH NEGATIVE VALUE */
	str = ft_memset(str, -120, 3);
	expected_str = memset(str, -120, 3);
	if (memcmp(str, expected_str, 10) == 0)
		printf("%s [OK]", GREEN);
	else
		printf("%s [KO]", RED);
	/* free here */
	free(expected_str);
	printf("\x1b[0m\n");
}
