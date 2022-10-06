/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlima-se <dlima-se@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 18:31:34 by dlima-se          #+#    #+#             */
/*   Updated: 2022/09/30 23:02:47 by dlima-se         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

#define RES(string)	"\033[1m\033[38;5;199m" string "\033[0m"
#define SEP(string)	"\033[38;5;75m" string "\033[0m"
# define BUFFER_SIZE 20
//#define RES(string)		"\033[38;5;75m" string "\033[0m"
#define ST(string)		"\033[38;5;43m" string "\033[0m"
#define HEAD(string)	"\033[1m\033[37m" string "\033[0m"

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

char	*ft_strjoin(char *s1, char const *s2)
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
	dest = (char *)malloc((len + 1) * (sizeof(char)));
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*get_next_line(int fd)
{
	int			count;
	char		*res;
	char		*tmp_st;
	static char	*st_str;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (!st_str)
		st_str = (char *)ft_calloc(BUFFER_SIZE, sizeof(char));
	tmp_st = (char *)ft_calloc(1, sizeof(char));
	res = (char *)ft_calloc(1, sizeof(char));
	printf(HEAD("FUNCTION CALL\n"));
	if (ft_strchr(st_str, '\n'))
	{
		if (st_str[0] == '\n' && st_str[1] == '\n')
		{
			ft_strcpy(st_str, (st_str + 1));
			if (res)
				free(res);
			res = (char *)ft_calloc(2, 1);
			res[0] = '\n';
			return (res);
		}
		if (res)
			free(res);
		res = ft_strdup(ft_strchr(st_str, '\n') + 1);
		printf(RES("res inicial =	%s\n"), res);
		if (ft_strchr(res, '\n'))
			tmp_st = ft_strdup(ft_strchr(res, '\n'));
	}
	while (!(ft_strchr(st_str, '\n')))
	{
		count = read(fd, st_str, BUFFER_SIZE);
		if (count < 0)
		{
			free(res);
			return (NULL);
		}
		res = ft_strjoin(res, st_str);
		if (count == 0)
			break ;
		if (count < BUFFER_SIZE)
			st_str[count] = '\0';
		printf("STATIC LIDA: %s", st_str);
	}
	if (tmp_st)
	{
		tmp_st = ft_strjoin(tmp_st, st_str);
		res = ft_strdup(tmp_st);
		free(tmp_st);
	}
	else
		res = ft_strjoin(res, st_str);
	if (ft_strchr(res, '\n'))
		res = ft_substr(res, 0, ft_strlen(res) - ft_strlen(ft_strchr(res, '\n')) + 1);
	else
		res = ft_substr(res, 0, ft_strlen(res) + 1);
	printf(ST("res fim =	%s\n"), res);
	st_str = ft_strchr(st_str, '\n');
	printf(ST("st_str final = %5s\n"), st_str);
	if (res == NULL)
		free(res);
	return (res);
}

/*
Read line: correct behavior 
NULL: there is nothing else to read,or an error occurred
read, malloc, free


	if (res[0] == '\n')
	{
		ft_strcpy(st_str, (st_str + 1));
		printf(ST("st_str final = %5s\n"), st_str);
		return ("\n");
	}

		
*/