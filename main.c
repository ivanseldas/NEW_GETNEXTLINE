/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iseldas- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 14:55:45 by iseldas-          #+#    #+#             */
/*   Updated: 2023/01/04 23:36:56 by ivanisp          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <string.h>

int	main(void)
{
	int		fd;
	char	*str;

	fd = open("test", O_RDONLY);
	str = get_next_line(fd);
	printf("GET NEXT LINE 1: %s\n", str);
	str = get_next_line(fd);
	printf("GET NEXT LINE 2:%s\n", str);
	str = get_next_line(fd);
	printf("GET NEXT LINE 3:%s\n", str);
	free(str);
	close(fd);
	return (0);
}
