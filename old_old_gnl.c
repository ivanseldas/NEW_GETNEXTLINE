/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanisp <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 19:25:59 by ivanisp           #+#    #+#             */
/*   Updated: 2023/01/06 21:02:42 by ivanisp          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char	*str_block;
	char		*str_line;
	char		*buffer;

	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, 0, 0) < 0)
		return (0);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	str_block = ft_init(buffer, str_block, fd);
//	printf("STORE_BLOCK 2: %s\n", str_block);
	str_line = ft_get_line(str_block);
//	printf("STR_LINE: %s\n", str_line);
	str_block = ft_clean_this_up(str_block, str_line);
//	printf("REST CLEANT: %s\n", str_block);
	return (str_line);
}

int	ft_detector(char *str_block)
{
	int	i;

	i = 0;
	while (str_block[i])
	{
		if (str_block[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}

char	*ft_init(char *buffer, char *str_block, int fd)
{
	int	init;

	init = BUFFER_SIZE;
	while (init > 0)
	{
		init = read(fd, buffer, BUFFER_SIZE);
		if (init == -1)
		{
			free(buffer);
			return (0);
		}
//		printf("INI es: %i\n", init);
		buffer[init] = '\0';
//		printf("BUFFER: %s\n", buffer);
		str_block = ft_store_blocks(str_block, buffer);
		if (ft_detector(buffer) > 0)
			break ;
	}
	free(buffer);
	return (str_block);
}

char	*ft_get_line(char *str_block)
{
	int		i;
	int		len;
	char	*line;

	len = ft_detector(str_block);
//	printf("LEN = %i\n", len);
	if (!str_block[0])
	{
		free(str_block);
		return (NULL);
	}
	line = (char *)malloc(sizeof(char) * (len + 1));
	if (!line)
	{
		free(str_block);
		return (0);
	}
	i = 0;
	while (i < len)
	{
		line[i] = str_block[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_clean_this_up(char *str_block, char *str_line)
{
	char	*temp;
	int		len_line;
	int		len_block;
	int		i;

	len_line = ft_strlen(str_line);
//	printf("len_line = %i\n", len_line);
	len_block = ft_strlen(str_block);
//	printf("len_block = %i\n", len_block);
	temp = (char *)malloc(sizeof(char) * (len_block - len_line));
	if (!temp)
	{
		free(str_line);
		free(str_block);
		return (NULL);
	}
	i = 0;
//	printf("str_block[len_line] = %c\n", str_block[len_line]);
	len_line++;
	while (str_block[len_line] != '\0')
	{
		temp[i] = str_block[len_line];
		i++;
		len_line++;
	}
	temp[i] = '\0';
	free(str_block);
	return (temp);
}
