/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check-my-libft.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:46:00 by aradix            #+#    #+#             */
/*   Updated: 2023/11/28 21:10:10 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_MY_LIBFT_H
# define CHECK_MY_LIBFT_H

# include "libft.h"
# include <bsd/string.h>
# include <ctype.h>
# include <malloc.h>
# include <setjmp.h>
# include <signal.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define RED "\x1B[31m"
# define GREEN "\x1B[32m"

extern sigjmp_buf	env;

void				signal_handler(int signo);

#endif
