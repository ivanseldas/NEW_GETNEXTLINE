/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanisp <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 22:21:03 by ivanisp           #+#    #+#             */
/*   Updated: 2023/01/17 18:28:02 by iseldas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*store;
	int			end;
	char		*line;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	end = 0;
	store = ft_get_blocks(fd, store, buffer);
	if (!store)
		return (NULL);
	end = ft_detector(store);
	if (store[0] == '\0')
	{
		free(store);
		return (NULL);
	}
	line = ft_substr(store, 0, end + 1);
	store = ft_substr_swap_store(store, end);
	return (line);
}

char	*ft_get_blocks(int fd, char *store, char *buffer)
{
	char	*temp;
	int		i;

	i = read(fd, buffer, BUFFER_SIZE);
	while (1)
	{
		if (i == -1)
		{
			free(buffer);
			return (NULL);
		}
		if (i == 0)
			break ;
		buffer[i] = '\0';
		if (!store)
			store = ft_strdup("");
		temp = store;
		store = ft_strjoin(temp, buffer);
		free(temp);
		if (ft_detector(buffer) < i)
			break ;
		i = read(fd, buffer, BUFFER_SIZE);
	}
	free (buffer);
	return (store);
}

int	ft_detector(char *buffer)
{
	int	j;

	j = 0;
	while (buffer[j] != '\0')
	{
		if (buffer[j] == '\n')
			break ;
		j++;
	}
	return (j);
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
