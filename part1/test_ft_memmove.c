/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memmove.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 18:25:36 by aradix            #+#    #+#             */
/*   Updated: 2023/11/15 19:44:50 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check-my-libft.h"

void	test_ft_memmove(void)
{
	char				src[] = "abcde";
	char				dest[6] = "lol";
	char				expected_dest[6] = "lol";
	struct sigaction	old_sa;
	struct sigaction	sa;

	/* BASIC MOVE */
	ft_memmove(dest, src, 5);
	memmove(expected_dest, src, 5);
	if (memcmp(dest, expected_dest, 6) == 0)
		printf("%s [OK]", GREEN);
	else
		printf("%s [KO]", RED);
	/* TEST OVERLAP */
	ft_memmove(dest, dest + 1, 3);
	memmove(expected_dest, expected_dest + 1, 3);
	if (memcmp(dest, expected_dest, 6) == 0)
		printf("%s [OK]", GREEN);
	else
		printf("%s [KO]", RED);
	/* TEST OVERLAP */
	ft_memmove(dest + 2, dest, 3);
	memmove(expected_dest + 2, expected_dest, 3);
	if (memcmp(dest, expected_dest, 6) == 0)
		printf("%s [OK]", GREEN);
	else
		printf("%s [KO]", RED);
	/* TEST SAME */
	if (memcmp(dest, expected_dest, 6) == 0)
		printf("%s [OK]", GREEN);
	else
		printf("%s [KO]", RED);
	/* NO CRASH IF =  */
	sigaction(SIGSEGV, NULL, &old_sa);
	sa.sa_handler = segfault_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGSEGV, &sa, NULL);
	if (setjmp(jump_buffer) == 0)
	{
		ft_memmove(dest, dest, 50000);
		printf("%s [OK]", GREEN);
	}
	else
		printf("%s [KO]", RED);
	segfault_occurred = 0;
	sigaction(SIGSEGV, &old_sa, NULL);
	sigprocmask(SIG_SETMASK, &old_sa.sa_mask, NULL);
	/* NO CRASH WITH NULL IF 0 */
	sigaction(SIGSEGV, NULL, &old_sa);
	sa.sa_handler = segfault_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGSEGV, &sa, NULL);
	if (setjmp(jump_buffer) == 0)
	{
		ft_memmove(dest, NULL, 0);
		printf("%s [OK]", GREEN);
	}
	else
		printf("%s [KO]", RED);
	segfault_occurred = 0;
	sigaction(SIGSEGV, &old_sa, NULL);
	sigprocmask(SIG_SETMASK, &old_sa.sa_mask, NULL);
	/* NO CRASH WITH NULL == NULL */
	sigaction(SIGSEGV, NULL, &old_sa);
	sa.sa_handler = segfault_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGSEGV, &sa, NULL);
	if (setjmp(jump_buffer) == 0)
	{
		ft_memmove(NULL, NULL, 5);
		printf("%s [OK]", GREEN);
	}
	else
		printf("%s [KO]", RED);
	segfault_occurred = 0;
	sigaction(SIGSEGV, &old_sa, NULL);
	sigprocmask(SIG_SETMASK, &old_sa.sa_mask, NULL);
	printf("\x1b[0m\n");
}
