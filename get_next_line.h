/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iseldas- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:41:07 by iseldas-          #+#    #+#             */
/*   Updated: 2023/01/04 23:18:31 by ivanisp          ###   ########.fr       */
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
int		ft_detector(char *str_block);
char	*ft_init(char *buffer, char *str_block, int fd);
char	*ft_get_line(char *str_block);
char	*ft_store_blocks(char *str_block, char *buffer);
char	*ft_clean_this_up(char *str_block, char *str_line);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strlen(const char *str);
char	*ft_strdup(const char *s);

#endif
