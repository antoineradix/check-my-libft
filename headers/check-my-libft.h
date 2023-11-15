/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check-my-libft.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:46:00 by aradix            #+#    #+#             */
/*   Updated: 2023/11/15 15:46:33 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_MY_LIBFT_H
# define CHECK_MY_LIBFT_H

# include "libft.h"
# include <ctype.h>
# include <setjmp.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <string.h>

# define RED "\x1B[31m"
# define GREEN "\x1B[32m"

// Global flag to indicate whether a segfault occurred
extern volatile sig_atomic_t	segfault_occurred;
// Buffer to store the jump location for setjmp/longjmp
extern jmp_buf					jump_buffer;

// Custom signal handler for SIGSEGV
void							segfault_handler(int signo);

void							test_ft_is(int (*implem)(int),
									int (*original)(int));
void							test_ft_strlen(void);
void							test_ft_memset(void);

#endif
