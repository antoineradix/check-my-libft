/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlcpy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 19:48:08 by aradix            #+#    #+#             */
/*   Updated: 2023/11/15 20:52:47 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check-my-libft.h"

void	test_ft_strlcpy(void)
{
	char				*dest;
	char				*expected_dest;
	size_t				ret;
	size_t				expected_ret;
	struct sigaction	sa;
	struct sigaction	old_sa;

	dest = (char *)malloc(sizeof(char) * 25);
	if (!dest)
		return ;
	expected_dest = (char *)malloc(sizeof(char) * 25);
	if (!expected_dest)
	{
		free(dest);
		return ;
	}
	dest = memcpy(dest, "test fghij 12345678942 !\0", 25);
	expected_dest = memcpy(dest, "test fghij 12345678942 !\0", 25);
	/* BASIC INPUT TEST */
	ret = ft_strlcpy(dest, "abcdexxxxxxxxxxx", 6);
	expected_ret = strlcpy(expected_dest, "abcdexxxxxxxxxxx", 6);
	if (ret == expected_ret && memcmp(dest, expected_dest, 25) == 0)
		printf("%s [OK]", GREEN);
	else
		printf("%s [KO]", RED);
	/* WITH SIZE 0 */
	ret = ft_strlcpy(dest, "---", 0);
	expected_ret = strlcpy(expected_dest, "---", 0);
	if (ret == expected_ret && memcmp(dest, expected_dest, 25) == 0)
		printf("%s [OK]", GREEN);
	else
		printf("%s [KO]", RED);
	/* FILL WHOLE DST */
	ret = ft_strlcpy(dest, "01234567890123456789abcd", 100);
	expected_ret = strlcpy(expected_dest, "01234567890123456789abcd", 100);
	if (ret == expected_ret && memcmp(dest, expected_dest, 25) == 0)
		printf("%s [OK]", GREEN);
	else
		printf("%s [KO]", RED);
	/* TEST WITH EMPTY STRING */
	ret = ft_strlcpy(dest, "", 1);
	expected_ret = strlcpy(expected_dest, "", 1);
	if (ret == expected_ret)
		printf("%s [OK]", GREEN);
	else
		printf("%s [KO]", RED);
	/* WITH SIZE 0 AND DEST == NULL (MUST NOT CRASH) */
	sigaction(SIGSEGV, NULL, &old_sa);
	sa.sa_handler = segfault_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGSEGV, &sa, NULL);
	if (setjmp(jump_buffer) == 0)
	{
		ret = ft_strlcpy(NULL, "--", 0);
		expected_ret = strlcpy(NULL, "--", 0);
		if (ret == expected_ret)
			printf("%s [OK]", GREEN);
		else
			printf("%s [KO]", RED);
	}
	else
		printf("%s [KO]", RED);
	segfault_occurred = 0;
	sigaction(SIGSEGV, &old_sa, NULL);
	sigprocmask(SIG_SETMASK, &old_sa.sa_mask, NULL);
	/* WITH SIZE > 0 AND DEST == NULL (MUST NOT CRASH) */
	sigaction(SIGSEGV, NULL, &old_sa);
	sa.sa_handler = segfault_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGSEGV, &sa, NULL);
	if (setjmp(jump_buffer) == 0)
	{
		ft_strlcpy(NULL, "--", 1);
		printf("%s [KO]", RED);
	}
	else
		printf("%s [OK]", GREEN);
	segfault_occurred = 0;
	sigaction(SIGSEGV, &old_sa, NULL);
	sigprocmask(SIG_SETMASK, &old_sa.sa_mask, NULL);
	/* WITH SIZE 0 AND DEST == NULL */
	sigaction(SIGSEGV, NULL, &old_sa);
	sa.sa_handler = segfault_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGSEGV, &sa, NULL);
	if (setjmp(jump_buffer) == 0)
	{
		ft_strlcpy(NULL, "---", 0);
		printf("%s [OK]", GREEN);
	}
	else
		printf("%s [KO]", RED);
	segfault_occurred = 0;
	sigaction(SIGSEGV, &old_sa, NULL);
	sigprocmask(SIG_SETMASK, &old_sa.sa_mask, NULL);
	printf("\x1b[0m\n");
}
