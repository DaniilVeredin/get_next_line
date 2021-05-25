/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zurag <zurag@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 15:25:56 by zurag             #+#    #+#             */
/*   Updated: 2021/05/18 13:26:51 by zurag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i])
	{
		i++;
	}
	return (i);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (src == NULL && dest == NULL)
		return (NULL);
	while (i < n)
	{
		((char *)dest)[i] = ((char *)src)[i];
		i++;
	}
	return (dest);
}

char	*ft_strdup(const char *s)
{
	int		len;
	char	*copy;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	copy = malloc((len + 1) * sizeof(char));
	if (copy == NULL)
		return (NULL);
	ft_memcpy(copy, s, len);
	copy[len] = '\0';
	return (copy);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*array;
	size_t	i;

	i = 0;
	array = malloc(nmemb * size);
	if (array == NULL)
		return (NULL);
	while (i < (nmemb * size))
	{
		array[i] = '\0';
		i++;
	}
	return (array);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	str = ft_calloc(sizeof(char), (len_s1 + len_s2 + 1));
	if (str == NULL)
		return (NULL);
	ft_memcpy(str, s1, len_s1);
	while (str[i] && i < len_s2 + len_s1 + 1)
		i++;
	while ((i + j + 1 < len_s2 + len_s1 + 1) && (s2[j]))
	{
		str[i + j] = s2[j];
		j++;
	}
	if (s1)
		ft_free(s1);
	return (str);
}
