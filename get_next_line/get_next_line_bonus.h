/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdulcie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 00:44:20 by mdulcie           #+#    #+#             */
/*   Updated: 2020/12/18 00:47:44 by mdulcie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct		s_list
{
	char			*end;
	int				fd;
	char			*buff;
	struct s_list	*next;
}					t_list;
t_list				*find_list_fd(int fd, t_list **head, int *ret);
int					get_next_line(int fd, char **line);
char				*check_remain(char **end);
int					free_all(char *str_1, t_list **head);
char				*ft_join_free(char *s1, char **s2);
char				*ft_calloc(size_t count, size_t size);
char				*ft_strdup_free(const char *s1, char *str2, int flag);
char				*ft_strdup(const char *s1);
int					ft_strlen(const char *s);
int					ft_strchr_i(const char *s, int c);
int					ft_memchr_i(char *s, char c, int n);
char				*fill_in_line(char **str, t_list *curr, int ret);

#endif
