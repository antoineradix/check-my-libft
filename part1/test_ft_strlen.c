/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:34:13 by aradix            #+#    #+#             */
/*   Updated: 2023/11/15 18:21:47 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check-my-libft.h"

void	test_ft_strlen(void)
{
	size_t				value;
	size_t				expected_value;
	struct sigaction	sa;
	struct sigaction	old_sa;

	/* TEST WITH BASIC STRING */
	value = ft_strlen("Hello World ! :)");
	expected_value = strlen("Hello World ! :)");
	if (value == expected_value)
		printf("%s [OK]", GREEN);
	else
		printf("%s [KO]", RED);
	/* TEST WITH EMPTY STRING */
	value = ft_strlen("");
	expected_value = strlen("");
	if (value == expected_value)
		printf("%s [OK]", GREEN);
	else
		printf("%s [KO]", RED);
	/* TEST WITH 0 IN THE MIDDLE */
	value = ft_strlen("aaaa\0bbbbb");
	expected_value = strlen("aaaa\0bbbbb");
	if (value == expected_value)
		printf("%s [OK]", GREEN);
	else
		printf("%s [KO]", RED);
	/* TEST CRASH WITH NULL */
	sigaction(SIGSEGV, NULL, &old_sa);
	sa.sa_handler = segfault_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGSEGV, &sa, NULL);
	if (setjmp(jump_buffer) == 0)
	{
		ft_strlen(NULL);
		printf("%s [KO]", RED);
	}
	else
		printf("%s [OK]", GREEN);
	segfault_occurred = 0;
	sigaction(SIGSEGV, &old_sa, NULL);
	sigprocmask(SIG_SETMASK, &old_sa.sa_mask, NULL);
	printf("\x1b[0m\n");
}
