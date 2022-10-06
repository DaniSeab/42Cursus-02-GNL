/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlima-se <dlima-se@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 18:32:21 by dlima-se          #+#    #+#             */
/*   Updated: 2022/10/01 12:16:41 by dlima-se         ###   ########.fr       */
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

char	*ft_calloc(size_t nitems, size_t size)
{
	char	*p;

	if (nitems == 0 || size == 0 || nitems >= 2147483647 / size)
		return (NULL);
	p = (char *)malloc(size * nitems);
	if (!p)
		return (NULL);
	ft_bzero(p, nitems * size);
	return (p);
}

void	ft_strcpy(char *dest, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
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

char	*ft_substr(char *s)
{
	char	*res;
	size_t	i;

	i = 0;
	res = ft_calloc((ft_strlen(s) - ft_strlen(ft_strchr(s, '\n') + 2)), sizeof(char));
	if (!res)
		return (0);
	while (s[i] != '\n')
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\n';
	free(s);
	return (res);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*res;
	int		i;

	i = 0;
	res = ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
	if (!res)
		return (0);
	if (!(s1 == NULL))
	{
		while (*s1)
			res[i++] = *s1++;
	}
	if (!(s2 == NULL))
	{
		while (*s2)
			res[i++] = *s2++;
	}
	return (res);
}

char	*ft_strdup(char *src)
{
	char	*dest;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(src);
	dest = (char *)ft_calloc((len + 1), (sizeof(char)));
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
