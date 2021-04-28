/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdulcie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 01:12:31 by mdulcie           #+#    #+#             */
/*   Updated: 2020/12/18 01:12:34 by mdulcie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		ft_strchr_i(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != (char)c)
		if (s[i++] == '\0')
			return (-1);
	return (i);
}

int		ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (s)
		while (s[i] != '\0')
			i++;
	return (i);
}

char	*ft_calloc(size_t count, size_t size)
{
	char	*call;
	int		n;
	int		i;

	n = (count + 1) * size;
	i = 0;
	if ((call = malloc(n)))
	{
		while (n--)
			call[i++] = 0;
		return (call);
	}
	return (NULL);
}

int		free_all(char *str, t_list **head)
{
	t_list	*cur;

	if (str != NULL)
	{
		free(str);
		str = NULL;
	}
	cur = *head;
	while (cur)
	{
		cur = (*head)->next;
		if (cur->buff)
		{
			free(cur->buff);
			cur->buff = NULL;
		}
		if (cur->end)
		{
			free(cur->end);
			cur->end = NULL;
		}
		*head = cur;
	}
	head ? head = NULL : 0;
	return (-1);
}

char	*fill_in_line(char **str, t_list *cur, int ret)
{
	char	*line;

	line = ft_strdup_free(*str, NULL, 2);
	if (cur->buff != NULL)
	{
		free(cur->buff);
		cur->buff = NULL;
	}
	free(*str);
	*str = NULL;
	if (cur->end != NULL && ret == 0)
	{
		free(cur->end);
		cur->end = NULL;
	}
	return (line);
}
