/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdulcie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 01:12:57 by mdulcie           #+#    #+#             */
/*   Updated: 2020/12/18 01:12:59 by mdulcie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		get_next_line(int fd, char **line)
{
	static t_list	*head;
	t_list			*cur;
	char			*str;
	int				ret;
	int				i;

	if (fd < 0 || !line || read(fd, NULL, 0) || BUFFER_SIZE < 1 || (str = NULL))
		return (-1);
	cur = find_list_fd(fd, &head, &ret);
	if (!(cur) || !(str = check_remain(&cur->end)))
		return (free_all(str, &head));
	while ((i = ft_strchr_i(cur->buff, '\n')) < 0 && ret && !cur->end)
	{
		if ((ret = read(fd, cur->buff, BUFFER_SIZE)) < 0 || BUFFER_SIZE < 1)
			return (free_all(str, &head));
		if ((i = ft_strchr_i(cur->buff, '\n')) >= 0 && ret > 0)
			if (!(cur->end = ft_strdup_free(&(cur->buff[i + 1]), cur->end, 1)))
				return (free_all(str, &head));
		cur->end ? cur->buff[i] = '\0' : 0;
		if (!(str = ft_join_free(str, &(cur->buff))) && ret > 0)
			return (free_all(str, &head));
	}
	if (!(*line = fill_in_line(&str, cur, ret)))
		return (-1);
	return ((cur->end == NULL) && (ret == 0) ? 0 : 1);
}

t_list	*find_list_fd(int fd, t_list **head, int *ret)
{
	t_list *curr;
	t_list *new;

	*ret = 1;
	curr = NULL;
	if (*head)
	{
		curr = *head;
		while (curr->fd != fd && curr->next)
			curr = curr->next;
		curr->fd == fd ? curr->buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char))
						: 0;
		if (curr->fd == fd)
			return (curr);
	}
	if (!(new = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	new->fd = fd;
	new->end = NULL;
	if (!(new->buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char))))
		return (NULL);
	new->next = NULL;
	(*head) ? curr->next = new : 0;
	!(*head) ? *head = new : 0;
	return (new);
}

char	*check_remain(char **end)
{
	int		i;
	char	*str;

	str = NULL;
	if (!(*end))
		return (ft_strdup_free("", NULL, 2));
	if (*end)
	{
		if ((i = ft_strchr_i(*end, '\n')) >= 0)
		{
			if (!(str = ft_strdup_free(*end, NULL, 0)))
				return (NULL);
			if (!(*end = ft_strdup_free(&(*end)[i + 1], *end, 1)))
				return (NULL);
		}
		else
		{
			if (!(str = ft_strdup_free(*end, NULL, 2)))
				return (NULL);
			*end != NULL ? free(*end) : 0;
			*end = NULL;
		}
	}
	return (str);
}

char	*ft_strdup_free(const char *s1, char *s2, int flag)
{
	char	*c_copy;
	int		len;

	len = (flag == 0 ? ft_strchr_i(s1, '\n') : ft_strlen(s1));
	if ((c_copy = ft_calloc((len + 1), sizeof(char))) == 0)
		return (NULL);
	while (len--)
		c_copy[len] = s1[len];
	if (s2 != NULL && flag == 1)
	{
		free(s2);
		s2 = NULL;
	}
	return (c_copy);
}

char	*ft_join_free(char *s1, char **s2)
{
	char	*join;
	int		i;
	int		j;

	i = ft_strlen(s1) + ft_strlen(*s2);
	if (!(join = ft_calloc((i + 1), sizeof(char))))
		return (NULL);
	i = -1;
	j = -1;
	if (s1)
		while (s1[++i])
			join[i] = s1[i];
	if (*s2)
		while ((*s2)[++j])
			join[i + j] = (*s2)[j];
	join[j + i + 1] = '\0';
	if (s1 != NULL)
	{
		free(s1);
		s1 = NULL;
	}
	i = ft_strlen(*s2);
	while (i--)
		(*s2)[i] = 0;
	return (join);
}

