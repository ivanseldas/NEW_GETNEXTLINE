/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanisp <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 22:21:03 by ivanisp           #+#    #+#             */
/*   Updated: 2023/01/11 11:18:28 by ivanisp          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*store[1025];
	int			end;
	char		*line;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	end = 0;
	store[fd] = ft_get_blocks(fd, store[fd], buffer);
	if (!store[fd])
		return (NULL);
	end = ft_counter(store[fd]);
	line = ft_substr(store[fd], 0, end + 1);
	if (line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	store[fd] = ft_substr_swap_store(store[fd], end);
	return (line);
}

char	*ft_get_blocks(int fd, char *store, char *buffer)
{
	char	*temp;
	int		i;

	i = BUFFER_SIZE;
	while (i > 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[i] = '\0';
		if (!store)
			store = ft_strdup("");
		if (i == 0)
			break ;
		temp = store;
		store = ft_strjoin(temp, buffer);
		free(temp);
		if (ft_detector(buffer, i) < i)
			break ;
	}
	free (buffer);
	return (store);
}

int	ft_detector(char *buffer, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		if (buffer[j] == '\n')
			break ;
		j++;
	}
	return (j);
}

int	ft_counter(char *store)
{
	int	i;

	i = 0;
	while (store[i] != '\0')
	{
		if (store[i] == '\n')
			break ;
		i++;
	}
	return (i);
}

char	*ft_substr_swap_store(char *store, int end)
{
	char	*temp;
	int		len;

	len = ft_strlen(store);
	if (end == len - 1)
	{
		free(store);
		return (ft_strdup(""));
	}
	temp = ft_substr(store, end + 1, len - end);
	free(store);
	store = NULL;
	return (temp);
}
