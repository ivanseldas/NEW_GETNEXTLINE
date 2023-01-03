/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iseldas- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 14:55:45 by iseldas-          #+#    #+#             */
/*   Updated: 2023/01/03 08:06:47 by iseldas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*str;

	fd = open("test", O_RDONLY);
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
	close(fd);
	return (0);
}
