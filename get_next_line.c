/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zurag <zurag@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 20:34:20 by zurag             #+#    #+#             */
/*   Updated: 2021/05/18 13:36:45 by zurag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_free(char *str)
{
	if (str)
		free(str);
	str = NULL;
}

int	ft_check_new_line(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	ft_fill(int fd, char **buf, char **str)
{
	int			i;

	*buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!(*buf))
		return (-2);
	if (ft_check_new_line(*str))
	{
		ft_free(*buf);
		return (0);
	}
	i = read(fd, *buf, BUFFER_SIZE);
	if (i <= 0)
	{
		ft_free(*buf);
		return (i);
	}
	(*buf)[i] = '\0';
	*str = ft_strjoin(*str, *buf);
	if (!(*str))
	{
		ft_free(*buf);
		return (-1);
	}
	ft_free(*buf);
	return (i);
}

int	ft_save(char **line, char **str, size_t len, int flag)
{
	char		*tmp;

	*line = ft_calloc(sizeof(char), (len + 1));
	if (!*line)
	{
		ft_free(*(str));
		return (-1);
	}
	if (len == 0 && flag == 0)
	{
		ft_free(*str);
		return (flag);
	}
	ft_memcpy(*line, *str, len);
	tmp = ft_calloc(sizeof(char), ft_strlen(*str) - len + 1);
	if (!tmp)
		return (-1);
	ft_memcpy(tmp, (*str) + len + 1, (ft_strlen(*str) - len));
	free(*str);
	*(str) = NULL;
	if (flag > 0)
		*str = ft_strdup(tmp);
	free(tmp);
	return (flag);
}

int	get_next_line(int fd, char **line)
{
	char		*buf;
	static char	*str;
	int			i;
	size_t		len;
	int			flag;

	flag = 0;
	len = 0;
	i = 1;
	if (BUFFER_SIZE <= 0 || fd < 0 || line == NULL)
		return (-1);
	while (i > 0)
		i = ft_fill(fd, &buf, &str);
	if (i < 0)
		return (-1);
	if (!str)
	{
		*line = ft_strdup("\0");
		return (0);
	}
	while (str[len] != '\n' && str[len] != '\0')
		len++;
	if (str[len] == '\n')
		flag = 1;
	return (ft_save(line, &str, len, flag));
}
