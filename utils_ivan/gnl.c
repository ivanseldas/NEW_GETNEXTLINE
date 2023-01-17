/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanisp <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 18:53:20 by ivanisp           #+#    #+#             */
/*   Updated: 2023/01/08 17:45:14 by ivanisp          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		line[70000];
	char		buffer;
	int			i;
	char		*str;
	int		ini;
	static int	end;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	i = read(fd, &buffer, 1);
	if (!end)
		end = 0;
	ini = end;
	while (i > 0)
	{
		line[end] = buffer;
		if (buffer == '\n')
			break ;
		i = read(fd, &buffer, 1);
		end++;
	}
	printf("INI = %i\n", ini);
	printf("END = %i\n", end);
	line[end] = '\0';
	if (i <= 0)
		return (NULL);
	str = ft_substr(line, ini, end - ini);
	return (str);
}
