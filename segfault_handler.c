/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   segfault_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 22:45:39 by aradix            #+#    #+#             */
/*   Updated: 2023/11/22 22:46:03 by aradix           ###   ########.fr       */
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
