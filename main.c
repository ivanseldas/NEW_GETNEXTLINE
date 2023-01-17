/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iseldas- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 14:55:45 by iseldas-          #+#    #+#             */
/*   Updated: 2023/01/17 18:10:17 by iseldas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <string.h>

void	hola(void)
{
	system("leaks a.out");
}

int	main(void)
{
	int		fd;
	int		i;
	char	*str;

	atexit(hola);
	fd = open("gnlTester/files/empty", O_RDONLY);
	i = 0;
	while (i < 3)
	{
		str = get_next_line(fd);
		printf("%s", str);
		i++;
	}
	free(str);
	close(fd);
	return (0);
}
