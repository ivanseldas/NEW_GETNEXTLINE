/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanisp <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 22:21:03 by ivanisp           #+#    #+#             */
/*   Updated: 2023/01/10 23:40:43 by ivanisp          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*store;
	int			i;
	int			end;
	char		*buffer;
	char		*line;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	end = 0;
	i = BUFFER_SIZE;
	while (i > 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
		{
			free(buffer);
			return (NULL);
		}
//		printf ("BUFFER = %s\n", buffer);
		buffer[i] = '\0';
		if (!store)
			store = ft_strdup("");
		if (i == 0)
			break ;
		temp = store;
		store = ft_strjoin(temp, buffer);
//		printf("REST_prev = %s\n", store);
		free(temp);
		temp = NULL;
//		printf("I_detector = %i\n", ft_detector(buffer));
		if (ft_detector(buffer, &i) < i)
			break ;
	}
	free(buffer);
	buffer = NULL;
	if (!store)
		return (NULL);
	end = ft_counter(store);
//	printf("END = %i\n", end);
	line = NULL;
	line = ft_substr(store, 0, end + 1);
	if (line[0] == '\0')
	{
		free(line);
		line = NULL;
		return (NULL);
	}
	store = ft_substr_swap_store(store, &end);
//	printf("REST_cleant = %s\n", store);
	return (line);
}

int	ft_detector(char *buffer, int *i)
{
	int	j;

	j = 0;
	while (j < *i)
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

char	*ft_substr_swap_store(char *store, int *end)
{
	char	*temp;
	int		len;

	len = ft_strlen(store);
//	printf("LEN = %i\n", len);
	if (*end == len - 1)
	{
		free(store);
		return (ft_strdup(""));
	}
//	printf("*end = %i\n", *end);
	temp = ft_substr(store, *end + 1, len - *end);
	free(store);
	store = NULL;
	return (temp);
}
