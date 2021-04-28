/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdulcie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 22:16:20 by mdulcie           #+#    #+#             */
/*   Updated: 2020/12/10 22:16:24 by mdulcie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

	if (size < 1)
		return (NULL);
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

int		free_all(char *str, char *buff, char *end)
{
	if (str != NULL)
	{
		free(str);
		str = NULL;
	}
	if (buff != NULL)
	{
		free(buff);
		buff = NULL;
	}
	if (end != NULL)
	{
		free(end);
		end = NULL;
	}
	return (-1);
}
