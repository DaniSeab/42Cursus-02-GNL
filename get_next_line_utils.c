/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlima-se <dlima-se@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 18:32:21 by dlima-se          #+#    #+#             */
/*   Updated: 2022/10/10 03:34:08 by dlima-se         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;
	int		i;

	len = 0;
	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		len++;
		i++;
	}
	return (len);
}

char	*ft_calloc(size_t nitems, size_t size)
{
	void	*p;
	size_t	i;

	i = 0;
	if (nitems == 0 || size == 0 || nitems >= 2147483647 / size)
		return (NULL);
	p = (char *)malloc(size * nitems);
	if (!p)
		return (NULL);
	while (i < size * nitems)
	{
		((char *)p)[i] = '\0';
		i++;
	}
	return (p);
}

char	*ft_strchr(char *str, int ch)
{
	char	c;

	c = (char)ch;
	while (*str)
	{
		if ((char)*str == c)
			return ((char *)str);
		str++;
	}
	if (ch == 0)
		return ((char *)str);
	return (0);
}

char	*ft_strdup(char *st_free, char *st_src)
{
	char	*dest;
	int		len;
	int		i;

	if (!st_src[0])
		return (NULL);
	i = 0;
	len = ft_strlen(ft_strchr(st_src, '\n'));
	dest = (char *)ft_calloc((len + 1), (sizeof(char)));
	while (st_src[i])
	{
		dest[i] = st_src[i];
		i++;
	}
	free(st_free);
	st_free = NULL;
	return (dest);
}
