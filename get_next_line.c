/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlima-se <dlima-se@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 23:53:57 by dlima-se          #+#    #+#             */
/*   Updated: 2022/10/10 22:51:50 by dlima-se         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//joins 2 strings and frees the first
char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	res = (char *)ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
	if (!res || !s1 || !s2)
		return (NULL);
	while (s1[i] != 0)
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != 0)
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	//printf("s1       |%s|\n", s1);
	//printf("s2       |%s|\n", s2);
	//free(s1);
	s1 = NULL;
	//printf("res      |%s|\n", res);
	//printf("s1       |%s|\n", s1);
	return (res);
}

//duplicates until nl
char	*ft_strdup_gnl_nl(char *src)
{
	char	*dest;
	int		i;

	i = 0;
	if (src[0] == '\0')
		return (NULL);
	dest = ft_calloc(ft_strlen(src) - ft_strlen(ft_strchr(src, '\n')) + 2, 1);
	while (src[i] && src[i] != '\n')
	{
		dest[i] = src[i];
		i++;
	}
	if (src[i] && src[i] == '\n')
	{
		dest[i] = '\n';
		i++;
	}
	return (dest);
}

//reads fd and joins result into static char *
char	*read_file(int fd, char *str_read)
{
	int		bytes_read;
	char	*temp;

	if (!str_read)
		str_read = ft_calloc(1, sizeof(char));
	if (!str_read)
		return (NULL);
	temp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!temp)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, temp, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			ft_free(temp);
			return (NULL);
		}
		temp[bytes_read] = '\0';
		printf("st       |%s|\n", str_read);
		printf("tmp      |%s|\n", temp);
		str_read = ft_strjoin_gnl(str_read, temp);
		printf("st       |%s|\n", str_read);
		printf("tmp      |%s|\n", temp);
		//printf("str_read   |%s|\n", str_read);
		if (ft_strchr(temp, '\n'))
			break ;
	}
	ft_free(temp);
	return (str_read);
}

char	*get_next_line(int fd)
{
	char		*res;
	static char	*st_str;

	//printf("start st |%s|\n", st_str);
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	st_str = read_file(fd, st_str);
	if (!st_str)
		return (NULL);
	res = ft_strdup_gnl_nl(st_str);
	//printf("res      |%s|\n", res);
	if (ft_strchr(st_str, '\n') && (ft_strchr(st_str, '\n') + 1))
		st_str = ft_strdup(st_str, ft_strchr(st_str, '\n') + 1);
	else
		ft_free(st_str);
	//printf("end st   |%s|\n", st_str);
	return (res);
}
