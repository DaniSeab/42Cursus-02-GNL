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

//joins 2 strings and frees the first, to allow us to return value to the same pointer
char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	res = (char *)ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
	if (!res || !s1 || !s2)
		return (NULL);
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	//s1 is the same pointer as str_read, so we free it so we can change its value to the returned value
	free(s1);
	s1 = NULL;
	return (res);
}

//duplicates input string until \n is found
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

//reads fd and joins read results into static char str_read
char	*read_file(int fd, char *str_read)
{
	int		bytes_read;
	char	*temp;

	if (!str_read)
		str_read = ft_calloc(1, sizeof(char));
	temp = malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!temp || !str_read)
		return (NULL);
	bytes_read = 1;
	//when theres nothing else to read, bytes_read will be 0
	while (bytes_read > 0)
	{
		bytes_read = read(fd, temp, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(temp);
			temp = NULL;
			return (NULL);
		}
		//set byte after last one read to \0 to close string
		temp[bytes_read] = '\0';
		//joins string just read with value held on static char, which was copied into str_read
		str_read = ft_strjoin_gnl(str_read, temp);
		//stop reading when it finds a \n
		if (ft_strchr(temp, '\n'))
			break ;
	}
	free(temp);
	return (str_read);
}

//each time its called it returns a new line from file of input fd
char	*get_next_line(int fd)
{
	char		*res;
	static char	*st_str;

	//tests if inputs are valid
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	//reads the file and sets static variable st_str to its return
	st_str = read_file(fd, st_str);
	if (!st_str)
		return (NULL);
	//output string will be read string up until \n
	res = ft_strdup_gnl_nl(st_str);
	//if theres an \n in st_str and theres something other than \0 after it
	if (ft_strchr(st_str, '\n') && *(ft_strchr(st_str, '\n') + 1) != '\0')
		//substitute the value in st_str for the value after \n
		st_str = ft_strdup(st_str, ft_strchr(st_str, '\n') + 1);
	else
	{
		//if there's nothing to hold in st_str, free st_str and set it to NULL to avoid dangling pointer
		free(st_str);
		st_str = NULL;
	}
	//returns read string up until \n, and holds in st_str everything after it for the next call
	return (res);
}
