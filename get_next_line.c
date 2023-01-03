/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iseldas- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 14:18:37 by iseldas-          #+#    #+#             */
/*   Updated: 2023/01/03 16:22:18 by iseldas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*line_remaining;
	char		*line_return;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	if (!line_remaining)
	{
		line_remaining = ft_calloc(1, sizeof(char));
		line_remaining[0] = 0;
	}
	line_remaining = ft_initialiser(line_remaining, fd);
	line_return = ft_detector(line_remaining);
	line_remaining = ft_remove_line(line_remaining, line_return);
	return (line_return);
}

char	*ft_initialiser(char *line_remaining, int fd)
{
	int		i;
	char	*temp;

	temp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!temp)
		return (0);
	if (read(fd, temp, BUFFER_SIZE) < 0)
	{
		free(temp);
		return (0);
	}
	i = 0;
	while (line_remaining[i] != '\n' && i < ft_strlen(line_remaining))
	{
		line_remaining = ft_strjoin(line_remaining, temp);
		read(fd, temp, BUFFER_SIZE);
		i++;
	}
	return (line_remaining);
}

char	*ft_detector(char *line_remaining)
{
	int		i;
	char	*sentence;

	i = 0;
	while (|| line_remaining[i] != '\n')
		i++;
	if (line_remaining[ft_strlen(line_remaining)] == '\0')
		sentence = malloc(sizeof(char) * (i + 1));
	if (line_remaining[ft_strlen(line_remaining)] == '\n')
		sentence = malloc(sizeof(char) * (i + 2));
	if (!sentence)
	{
		free(line_remaining);
		return (0);
	}
	i = 0;
	while ((line_remaining[i] != '\n' || line_remaining[i] != '\0'))
	{
		sentence[i] = line_remaining[i];
		i++;
	}
	if (line_remaining[i++] == '\n')
		sentence[i] = line_remaining[i];
	sentence[i] = '\0';
	return (sentence);
}

char	*ft_remove_line(char *line_remaining, char *line_return)
{
	int		i;
	int		j;
	char	*temp;

	i = ft_strlen(line_return);
	temp = ft_calloc(ft_strlen(line_remaining) - i + 1, sizeof(char));
	if (!temp)
	{
		free(line_remaining);
		free(line_return);
		return (0);
	}
	j = 0;
	while (i < ft_strlen(line_remaining))
		temp[j] = line_remaining[j];
	temp[j] = '\0';
	free(line_remaining);
	return (temp);
}		
