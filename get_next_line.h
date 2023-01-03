/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iseldas- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:41:07 by iseldas-          #+#    #+#             */
/*   Updated: 2023/01/03 15:55:36 by iseldas-         ###   ########.fr       */
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

char	*get_next_line(int fd);
char	*ft_initialiser(char *line_remaining, int fd);
char	*ft_detector(char *line_remaining);
char	*ft_remove_line(char *line_remaining, char *line_return);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strlen(const char *str);
int		ft_strchr_gnl(const char *s, int c);

#endif
