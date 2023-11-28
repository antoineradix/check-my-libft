/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:33:29 by aradix            #+#    #+#             */
/*   Updated: 2023/11/22 13:29:02 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check-my-libft.h"

volatile sig_atomic_t	segfault_occurred = 0;
jmp_buf					jump_buffer;

void	segfault_handler(int signo)
{
	(void)signo;
	segfault_occurred = 1;
	longjmp(jump_buffer, 1);
}


void part1()
{
	printf("PART 1:\n");
	printf("ft_isalpha:          ");
	test_ft_is(ft_isalpha, isalpha);
	printf("ft_isdigit:          ");
	test_ft_is(ft_isdigit, isdigit);
	printf("ft_isalnum:          ");
	test_ft_is(ft_isalnum, isalnum);
	printf("ft_isascii:          ");
	test_ft_is(ft_isascii, isascii);
	printf("ft_isprint:          ");
	test_ft_is(ft_isprint, isprint);
	printf("ft_strlen:           ");
	test_ft_strlen();
	printf("ft_memset:           ");
	test_ft_memset();
	printf("ft_bzero:            ");
	test_ft_bzero();
	printf("ft_memcpy:           ");
	test_ft_memcpy();
	printf("ft_memmove:          ");
	test_ft_memmove();
	printf("ft_strlcpy:          ");
	test_ft_strlcpy();
	printf("ft_strlcat:          ");
	test_ft_strlcat();
	printf("ft_toupper:          ");
	test_ft_toupperlower(ft_toupper, toupper);
	printf("ft_tolower:          ");
	test_ft_toupperlower(ft_tolower, tolower);
	printf("ft_strchr:           ");
	test_ft_strchr();
	printf("ft_strrchr:          ");
	test_ft_strrchr();
	printf("ft_strncmp:          ");
	test_ft_strncmp();
	printf("ft_memchr:           ");
	test_ft_memchr();
	printf("ft_memcmp:           ");
	test_ft_memcmp();
	printf("ft_strnstr:          ");
	test_ft_strnstr();
	printf("ft_atoi:             ");
	test_ft_atoi();
	printf("ft_calloc:           ");
	test_ft_calloc();
	printf("ft_strdup:           ");
	test_ft_strdup();
	printf("\n\n");
}

void part2()
{
	printf("PART 2:\n");
	printf("ft_substr:           ");
	test_ft_substr();
	printf("ft_strjoin:          ");
	test_ft_strjoin();
	printf("\n\n");
}

int	main()
{
	part1();
	part2();
	return (0);
}
