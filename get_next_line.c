/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlima-se <dlima-se@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 23:53:57 by dlima-se          #+#    #+#             */
/*   Updated: 2022/10/25 18:19:29 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//joins 2 strings and frees the first so that 's1 = join(s1, s2)' is possible
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
	// s1's address would be lost if not freed within ft_strjoin_gnl's scope
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

//reads fd and joins what was read into the static char* str_read
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
	//when there's nothing else to read, bytes_read will be 0
	while (bytes_read > 0)
	{
		bytes_read = read(fd, temp, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(temp);
			temp = NULL;
			return (NULL);
		}
		//sets byte after the last char read to \0, closing the string
		temp[bytes_read] = '\0';
		//joins string stored on static from the last read, to the newly created one
		str_read = ft_strjoin_gnl(str_read, temp);
		//stop reading when it finds a \n
		if (ft_strchr(temp, '\n'))
			break ;
	}
	free(temp);
	return (str_read);
}

//each time it's called it returns a new line from the file descriptor (fd)
char	*get_next_line(int fd)
{
	char		*res;
	static char	*st_str;

	//tests if inputs are valid, in which case it returns NULL right away
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	//reads the file and attributes st_str's address to read_file's return 
	st_str = read_file(fd, st_str);
	if (!st_str)
		return (NULL);
	//output string will be read up until \n
	res = ft_strdup_gnl_nl(st_str);
	//if there's a \n in st_str and there's something other than \0 after it...
	if (ft_strchr(st_str, '\n') && *(ft_strchr(st_str, '\n') + 1) != '\0')
		//...  it substitutes the value in st_str for the value after \n
		st_str = ft_strdup(st_str, ft_strchr(st_str, '\n') + 1);
	else
	{
		//if there's nothing to be held in st_str, it frees it and sets it to NULL so it doesn't become a dangling pointer
		free(st_str);
		st_str = NULL;
	}
	//returns read string up until \n, and holds in st_str everything after \n for the next call
	return (res);
}
