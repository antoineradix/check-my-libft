/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 22:45:39 by aradix            #+#    #+#             */
/*   Updated: 2023/11/28 21:10:17 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check-my-libft.h"

/* jmp_buf	env; */
sigjmp_buf	env;

void	signal_handler(int signo)
{
	(void)signo;
	/* longjmp(env, 1); */
	siglongjmp(env, 1);
}
