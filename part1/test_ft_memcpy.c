/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memcpy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:27:58 by aradix            #+#    #+#             */
/*   Updated: 2023/11/15 18:21:47 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check-my-libft.h"

void	test_ft_memcpy(void)
{
	char				*dest;
	char				*expected_dest;
	struct sigaction	sa;
	struct sigaction	old_sa;
	char				*src;

	dest = (char *)malloc(sizeof(char) * 25);
	if (!dest)
		return ;
	expected_dest = (char *)malloc(sizeof(char) * 25);
	if (!expected_dest)
	{
		free(dest);
		return ;
	}
	dest = memset(dest, 'p', 25);
	expected_dest = memset(expected_dest, 'p', 25);
	/* BASIC STRING */
	dest = ft_memcpy(dest, "hello", 2);
	expected_dest = memcpy(dest, "hello", 3);
	if (memcmp(dest, expected_dest, 25) == 0)
		printf("%s [OK]", GREEN);
	else
		printf("%s [KO]", RED);
	/* TEST MEM OVERLAPPING */
	dest = ft_memcpy(dest, dest + 1, 5);
	expected_dest = memcpy(expected_dest, expected_dest + 1, 5);
	if (memcmp(dest, expected_dest, 25) == 0)
		printf("%s [OK]", GREEN);
	else
		printf("%s [KO]", RED);
	/* TEST WITH SIZE ZERO */
	dest = ft_memcpy(dest, "", 0);
	if (dest == NULL)
		printf("%s [KO]", RED);
	else
		printf("%s [OK]", GREEN);
	/* TEST CRASH WITH NULL */
	dest = NULL;
	src = NULL;
	sigaction(SIGSEGV, NULL, &old_sa);
	sa.sa_handler = segfault_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGSEGV, &sa, NULL);
	if (setjmp(jump_buffer) == 0)
	{
		ft_memcpy(NULL, NULL, 10);
		printf("%s [KO]", RED);
	}
	else
		printf("%s [OK]", GREEN);
	segfault_occurred = 0;
	sigaction(SIGSEGV, &old_sa, NULL);
	sigprocmask(SIG_SETMASK, &old_sa.sa_mask, NULL);
	/* TEST NO CRASH WITH NULL AND 0 */
	sigaction(SIGSEGV, NULL, &old_sa);
	sa.sa_handler = segfault_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGSEGV, &sa, NULL);
	if (setjmp(jump_buffer) == 0)
	{
		ft_memcpy(dest, src, 0);
		printf("%s [OK]", GREEN);
	}
	else
		printf("%s [KO]", RED);
	segfault_occurred = 0;
	sigaction(SIGSEGV, &old_sa, NULL);
	sigprocmask(SIG_SETMASK, &old_sa.sa_mask, NULL);
	printf("\x1b[0m\n");
}
