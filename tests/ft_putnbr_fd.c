/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:20:37 by aradix            #+#    #+#             */
/*   Updated: 2023/12/06 14:39:30 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check-my-libft.h"

static bool	cmp_output(int n, char *expected_ret)
{
	int		fd;
	char	buff[100];
	size_t	size;

	fd = open("tmp", O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if (fd == -1)
	{
		perror("Error opening file");
		return (false);
	}
	ft_putnbr_fd(n, fd);
	lseek(fd, 0, SEEK_SET);
	size = read(fd, buff, 98);
	close(fd);
	buff[size] = '\0';
	if (strcmp(buff, expected_ret) == 0)
		return (true);
	return (false);
}

int	main(void)
{
	printf("ft_putnbr_fd:        ");
	/* -------------------- TEST 01 -------------------- */
	if (cmp_output(0, "0"))
		printf("%s 1:[OK]", GREEN);
	else
		printf("%s 1:[KO]", RED);
	/* -------------------- TEST 02 -------------------- */
	if (cmp_output(42, "42"))
		printf("%s 2:[OK]", GREEN);
	else
		printf("%s 2:[KO]", RED);
	/* -------------------- TEST 03 -------------------- */
	if (cmp_output(-42, "-42"))
		printf("%s 3:[OK]", GREEN);
	else
		printf("%s 3:[KO]", RED);
	/* -------------------- TEST 04 -------------------- */
	if (cmp_output(2147483647, "2147483647"))
		printf("%s 4:[OK]", GREEN);
	else
		printf("%s 4:[KO]", RED);
	/* -------------------- TEST 05 -------------------- */
	if (cmp_output(-2147483648, "-2147483648"))
		printf("%s 5:[OK]", GREEN);
	else
		printf("%s 5:[KO]", RED);
	/* -------------------------------------------------- */
	printf("\x1b[0m\n");
}
