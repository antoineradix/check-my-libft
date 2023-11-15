/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isalpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:51:27 by aradix            #+#    #+#             */
/*   Updated: 2023/11/15 13:57:28 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check-my-libft.h"

void	test_ft_isalpha(void)
{
	int	c;
	int	value;
	int	expected_value;

	printf("ft_isalpha:        ");
	/* TEST WITH ASCII */
	c = 0;
	while (c <= 127)
	{
		value = ft_isalpha(c);
		expected_value = isalpha(c);
		if ((value == 0 && expected_value != 0) || (value > 0
				&& expected_value <= 0))
			break ;
		c++;
	}
	(c == 128) ? printf("%s [OK]", GREEN) : printf("%s [KO]", RED);
	/* TEST WITH EXTENDED ASCII */
	while (c <= 200)
	{
		value = ft_isalpha(c);
		expected_value = isalpha(c);
		if ((value == 0 && expected_value != 0) || (value > 0
				&& expected_value <= 0))
			break ;
		c++;
	}
	(c == 201) ? printf("%s [OK]\n", GREEN) : printf("%s [KO]\n", RED);
}
