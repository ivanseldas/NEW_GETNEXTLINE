/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iseldas- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:41:07 by iseldas-          #+#    #+#             */
/*   Updated: 2023/01/17 17:55:50 by iseldas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include <stdio.h>

typedef struct s_list
{
	char	store[70000];
	int		end;
}			t_list;
char	*get_next_line(int fd);
int		ft_detector(char *store);
char	*ft_init(char *buffer, char *str_block, int fd);
char	*ft_get_line(char *store);
char	*ft_clean_this_up(char *str_block, char *str_line);
char	*ft_strjoin(const char *s1, const char *s2);
int		ft_strlen(const char *str);
char	*ft_strdup(const char *s);
char	*ft_joinfree(char *str_block, char *buffer);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_substr_swap_line(char *store, int *end);
char	*ft_substr_swap_store(char *store, int end);
char	*ft_get_blocks(int fd, char *store, char *buffer);

#endif
