/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 11:22:23 by aradix            #+#    #+#             */
/*   Updated: 2023/12/06 14:42:20 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check-my-libft.h"

static bool	cmp_output(char c)
{
	int		fd;
	char	buff[2];

	fd = open("tmp", O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if (fd == -1)
	{
		perror("Error opening file");
		return (false);
	}
	ft_putchar_fd(c, fd);
	lseek(fd, 0, SEEK_SET);
	read(fd, buff, 1);
	close(fd);
	buff[1] = '\0';
	if (buff[0] == c)
		return (true);
	return (false);
}

int	main(void)
{
	printf("ft_putchar_fd:       ");
	/* -------------------- TEST 01 -------------------- */
	if (cmp_output('a'))
		printf("%s 1:[OK]", GREEN);
	else
		printf("%s 1:[KO]", RED);
	/* -------------------- TEST 02 -------------------- */
	if (cmp_output('x'))
		printf("%s 2:[OK]", GREEN);
	else
		printf("%s 2:[KO]", RED);
	/* -------------------------------------------------- */
	printf("\x1b[0m\n");
}
