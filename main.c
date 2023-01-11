/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iseldas- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 14:55:45 by iseldas-          #+#    #+#             */
/*   Updated: 2023/01/11 00:46:36 by ivanisp          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <string.h>

int	main(void)
{
	int		fd;
	int	i;
	char	*str[3];

	fd = open("test_qv", O_RDONLY);
	i = 0;
	while (i < 3)
	{
		str[i] = get_next_line(fd);
		printf("GET NEXT LINE es: %s\n\n", str[i]);
		i++;
	}
	i = 0;
	while (i < 3)
	{
		free(str[i]);
		i++;
	}
	close(fd);
//	printf("GET NEXT LINE 1:%s\n\n\n-------------------\n", str);
//	str = get_next_line(fd);
//	printf("GET NEXT LINE 2:%s\n\n\n-------------------\n", str);
//	str = get_next_line(fd);
//	printf("GET NEXT LINE 3:%s\n\n\n-------------------\n", str);
	return (0);
}
