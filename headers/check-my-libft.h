/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check-my-libft.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:46:00 by aradix            #+#    #+#             */
/*   Updated: 2023/11/16 19:18:46 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_MY_LIBFT_H
# define CHECK_MY_LIBFT_H

# include "libft.h"
# include <bsd/string.h>
# include <ctype.h>
# include <setjmp.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <string.h>

# define RED "\x1B[31m"
# define GREEN "\x1B[32m"

extern volatile sig_atomic_t	segfault_occurred;
extern jmp_buf					jump_buffer;
void							segfault_handler(int signo);

void							test_ft_is(int (*implem)(int), int (*original)(int));
void							test_ft_strlen(void);
void							test_ft_memset(void);
void							test_ft_bzero(void);
void							test_ft_memcpy(void);
void							test_ft_memmove(void);
void							test_ft_strlcpy(void);
void							test_ft_strlcat(void);
void							test_ft_toupperlower(int (*implem)(int), int (*original)(int));
void							test_ft_strchr(void);
void							test_ft_strrchr(void);
void							test_ft_strncmp(void);
void							test_ft_memchr(void);
void							test_ft_memcmp(void);

#endif
