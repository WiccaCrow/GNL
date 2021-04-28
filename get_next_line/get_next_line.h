/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdulcie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 08:07:27 by mdulcie           #+#    #+#             */
/*   Updated: 2020/12/17 23:31:24 by mdulcie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

int		get_next_line(int fd, char **line);
char	*check_remain(char **end);
int		free_all(char *str_1, char *buff, char *end);
char	*ft_strjoin(char *s1, char **s2);
char	*ft_calloc(size_t count, size_t size);
char	*ft_strdup_free(const char *s1, char *str2, int flag);
char	*ft_strdup(const char *s1);
int		ft_strlen(const char *s);
int		ft_strchr_i(const char *s, int c);
int		ft_memchr_i(char *s, char c, int n);
char	*fill_in_line(char **str, char **buff, char **end, int ret);

#endif
