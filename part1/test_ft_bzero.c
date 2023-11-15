/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_bzero.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:10:06 by aradix            #+#    #+#             */
/*   Updated: 2023/11/15 17:36:23 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check-my-libft.h"

void	test_ft_bzero(void)
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
	str = memset(str, 'x', 10);
	expected_str = memset(expected_str, 'x', 10);
	/* TEST WITH SIMPLE STRING */
	ft_bzero(str, 5);
	bzero(expected_str, 5);
	if (memcmp(str, expected_str, 10) == 0)
		printf("%s [OK]", GREEN);
	else
		printf("%s [KO]", RED);
	/* TEST WITH LEN 0 */
	*str = 'a';
	*expected_str = 'a';
	ft_bzero(str, 0);
	bzero(expected_str, 0);
	if (memcmp(str, expected_str, 2) == 0)
		printf("%s [OK]\n", GREEN);
	else
		printf("%s [KO]\n", RED);
	free(str);
	free(expected_str);
	printf("\x1b[0m");
}
