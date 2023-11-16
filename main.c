/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:33:29 by aradix            #+#    #+#             */
/*   Updated: 2023/11/16 18:15:50 by aradix           ###   ########.fr       */
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

int	main(void)
{
	// PART 1
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
	return (0);
}
