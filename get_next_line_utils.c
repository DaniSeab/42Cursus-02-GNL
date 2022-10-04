/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlima-se <dlima-se@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 18:32:21 by dlima-se          #+#    #+#             */
/*   Updated: 2022/10/04 02:14:29 by dlima-se         ###   ########.fr       */
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
	p = malloc(size * nitems);
	if (!p)
		return (NULL);
	while (i < size * nitems)
	{
		((char *)p)[i++] = '\0';
		i++;
	}
	return (p);
}

void	ft_strcpy(char *dest, char *src)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	// while (dest)
	// {
	dest[i] = '\0';
	// 	i++;	
	// }
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

char	*ft_substr(char *s, unsigned int start, size_t len)
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

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	int		i;

	i = 0;
	res = ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
	if (!res)
		return (0);
	if (!(s1 == NULL))
		while (*s1)
			res[i++] = *s1++;
	while (*s2)
		res[i++] = *s2++;
	return (res);
}

char	*ft_strdup(char *src)
{
	char	*dest;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(src);
	dest = (char *)ft_calloc((ft_strlen(src) - 
	ft_strlen(ft_strchr(src, '\n')) + 1), (sizeof(char)));
	while (src[i] && src[i] != '\n')
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}
