/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iseldas- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 14:18:37 by iseldas-          #+#    #+#             */
/*   Updated: 2023/01/04 19:13:00 by ivanisp          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char	*line_remaining;
	char		*line_return;
	char		*buffer;
	int		i;
	int		ini;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (0);
	ini = 1;
	while (ini > 0)
	{
		i = 0;
		ini = read(fd, buffer, BUFFER_SIZE);
		if (ini <= 0)
		{
			free(buffer);
			return (0);
		}
		printf("BUFFER = %s\n", buffer);
		printf("ini = %i\n", ini);
		printf("i = %i\n", i);
		while (buffer[i] != '\0' && buffer[i] != '\n' && i < BUFFER_SIZE)
			i++;
		printf("i despues de contador = %i\n", i);
		if (!line_remaining)
			line_remaining = ft_strdup("");
		printf("line_remaining = %s\n", line_remaining);
		if ((buffer[i] == '\0' || buffer[i] == '\n') && i < BUFFER_SIZE)
		{
			line_remaining = ft_substr(buffer, i, BUFFER_SIZE - i);
			line_return = ft_strjoin(line_return, ft_substr(buffer, 0, i));
			printf("line_return(in) %s\n", line_return);
			break ;
		}
		else
			line_return = ft_strjoin(line_return, buffer);
		printf("line_return(out) = %s\n", line_return);
	}
	free(buffer);
	return (line_return);
}

/*char	*ft_initialiser(char *line_remaining, int fd)
{
	char	*temp;
	int		ini;

	temp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!temp)
		return (0);
	temp = NULL;
	ini = 1;
	while (ini > 0 && ft_strchr_gnl(temp, '\n') != 1 && ft_strchr_gnl(temp, '\0') != 1)
	{
		ini = read(fd, temp, BUFFER_SIZE);
		printf("%s", temp);
		line_remaining = ft_strjoin(line_remaining, temp);
		printf("%s", line_remaining);
	}
	free(temp);
	return (line_remaining);
}

char	*ft_detector(char *line_remaining)
{
	int		i;
	char	*sentence;

	i = 0;
	while (line_remaining[i] != '\0' || line_remaining[i] != '\n')
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

char	*ft_strdup(const char *s)
{
	char	*str;
	size_t	len;
	size_t	i;

	len = ft_strlen(s);
	str = (char *)malloc((len + 1) * sizeof(*s));
	if (!str)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}*/
