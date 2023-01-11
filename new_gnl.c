/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_gnl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanisp <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 18:53:20 by ivanisp           #+#    #+#             */
/*   Updated: 2023/01/08 18:01:14 by ivanisp          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_list	*data;
	char		buffer;
	int			i;
	char		*line;
	int		ini;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	i = read(fd, &buffer, 1);
	if (!data->end)
		data->end = 0;
	ini = data->end;
	printf("INI = %i\n", ini);
	while (i > 0)
	{
		data->store[data->end] = buffer;
		if (buffer == '\n')
			break ;
		i = read(fd, &buffer, 1);
		(data->end)++;
	}
	data->store[data->end] = '\0';
	if (i <= 0)
		return (NULL);
	line = ft_substr(data->store, ini, data->end - ini);
	return (line);
}
