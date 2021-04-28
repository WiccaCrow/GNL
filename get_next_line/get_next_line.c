/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdulcie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 05:12:53 by mdulcie           #+#    #+#             */
/*   Updated: 2020/12/17 23:29:19 by mdulcie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	static char	*end;
	char		*buff;
	char		*str;
	int			ret;
	int			i;

	str = NULL;
	buff = ft_calloc(BUFFER_SIZE, sizeof(char));
	if (!line || fd < 0 || !buff || !(str = check_remain(&end)))
		return (free_all(str, buff, end));
	ret = 1;
	while ((i = ft_strchr_i(buff, '\n')) < 0 && ret && !end)
	{
		if ((ret = read(fd, buff, BUFFER_SIZE)) < 0 || BUFFER_SIZE <= 0)
			return (free_all(str, buff, end));
		if ((i = ft_strchr_i(buff, '\n')) >= 0 && ret > 0)
			if (!(end = ft_strdup_free(&buff[i + 1], end, 1)))
				return (free_all(str, buff, end));
		end ? buff[i] = '\0' : 0;
		if (!(str = ft_strjoin(str, &buff)) && ret > 0)
			return (free_all(str, buff, end));
	}
	if (!(*line = fill_in_line(&str, &buff, &end, ret)))
		return (-1);
	return ((end == NULL) && (ret == 0) ? 0 : 1);
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
	if ((c_copy = ft_calloc(len, sizeof(char))) == 0)
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

char	*ft_strjoin(char *s1, char **s2)
{
	char	*join;
	int		i;
	int		j;

	i = ft_strlen(s1) + ft_strlen(*s2);
	if (!(join = ft_calloc(i + 1, sizeof(char))))
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

char	*fill_in_line(char **str, char **buff, char **end, int ret)
{
	char	*line;

	line = ft_strdup_free(*str, NULL, 2);
	if (*buff)
	{
		free(*buff);
		*buff = NULL;
	}
	free(*str);
	*str = NULL;
	if (*end && ret == 0)
	{
		free(*end);
		*end = NULL;
	}
	return (line);
}
