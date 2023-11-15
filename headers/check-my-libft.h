/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check-my-libft.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:46:00 by aradix            #+#    #+#             */
/*   Updated: 2023/11/15 14:24:56 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_MY_LIBFT_H
# define CHECK_MY_LIBFT_H

# include "libft.h"
# include <ctype.h>
# include <stdbool.h>
# include <stdio.h>

# define RED "\x1B[31m"
# define GREEN "\x1B[32m"

void	test_ft_is(int (*implem)(int), int (*original)(int));

#endif
