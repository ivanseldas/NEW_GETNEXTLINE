/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanisp <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 19:25:59 by ivanisp           #+#    #+#             */
/*   Updated: 2023/01/04 23:37:53 by ivanisp          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char	*str_block;
	char		*str_line;
	char		*buffer;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (0);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	str_block = ft_init(buffer, str_block, fd);
//	printf("STORE_BLOCK 2: %s\n", str_block);
	str_line = ft_get_line(str_block);
//	printf("STR_LINE: %s\n", str_line);
	str_block = ft_clean_this_up(str_block, str_line);
//	printf("REST: %s\n", str_block);
	return (str_line);
}

int	ft_detector(char *str_block)
{
	int	i;

	i = 0;
	while (str_block[i] != '\n' && i < ft_strlen(str_block))
		i++;
	if (i < ft_strlen(str_block))
		return (i);
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
		buffer[init] = '\0';
//		printf("BUFFER: %s\n", buffer);
		str_block = ft_store_blocks(str_block, buffer);
		if (ft_detector(str_block) > 0)
			break ;
	}
	free(buffer);
	return (str_block);
}

char	*ft_get_line(char *str_block)
{
	int		i;
	int		len;
	char	*str_line;

	len = ft_detector(str_block);
	str_line = malloc(sizeof(char) * (len + 1));
	if (!str_line)
	{
		free(str_block);
		return (0);
	}
	i = 0;
	while (i < len)
	{
		str_line[i] = str_block[i];
		i++;
	}
	str_line[i] = '\0';
	return (str_line);
}

char	*ft_clean_this_up(char *str_block, char *str_line)
{
	char	*temp;
	int		len_line;
	int		len_block;
	int		i;

	len_line = ft_strlen(str_line);
	len_block = ft_strlen(str_block);
	temp = malloc(sizeof(char) * (len_block - len_line));
	if (!temp)
	{
		free(str_line);
		free(str_block);
		return (NULL);
	}
	i = 0;
	while (len_block > len_line)
		temp[i++] = str_block[++len_line];
	temp[len_line] = '\0';
	free(str_block);
	return (temp);
}
