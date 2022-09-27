/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlima-se <dlima-se@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 18:32:21 by dlima-se          #+#    #+#             */
/*   Updated: 2022/09/26 22:57:05 by dlima-se         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (*str != '\0')
	{
		len++;
		str++;
	}
	return (len);
}

void	ft_bzero(void *dest, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((char *)dest)[i] = '\0';
		i++;
	}
}


void	*ft_calloc(size_t nitems, size_t size)
{
	void	*p;

	if (nitems == 0 || size == 0 || nitems >= 2147483647 / size)
		return (NULL);
	p = malloc(size * nitems);
	if (!p)
		return (NULL);
	ft_bzero(p, nitems * size);
	return (p);
}


char	*ft_strdup(const char *src)
{
	char	*dest;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(src);
	dest = (char *)malloc((len + 1) * (sizeof(char)));
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}


char	*ft_strchr(const char *str, int ch)
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;

	i = 0;
	if (start >= ft_strlen(s))
	{
		res = ft_calloc(1, 1);
		return (res);
	}
	if ((len + (size_t)start) > ft_strlen(s))
		len = ft_strlen(s) - (size_t)start;
	res = ft_calloc(len + 1, sizeof(char));
	if (!res)
		return (0);
	while (i < len)
	{
		res[i] = s[i + start];
		i++;
	}
	return (res);
}
