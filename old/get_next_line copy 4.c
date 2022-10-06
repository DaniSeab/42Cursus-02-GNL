/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlima-se <dlima-se@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 18:31:34 by dlima-se          #+#    #+#             */
/*   Updated: 2022/10/04 17:51:51 by dlima-se         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int			bytes_read;
	char		*res;
	char		*tmp;
	static char	*st_str;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (!st_str)
		st_str = (char *)ft_calloc(BUFFER_SIZE, sizeof(char));
	if (!st_str)
		return (NULL);
	tmp = (char *)ft_calloc(1, sizeof(char));
	if (!tmp)
		return (NULL);
	res = (char *)ft_calloc(1, sizeof(char));
	if (!res)
		return (NULL);
	if (ft_strchr(st_str, '\n'))
	{
		if (st_str[0] == '\n' && st_str[1] == '\n')
		{
			ft_strcpy(st_str, (st_str + 1));
			free(res);
			res = (char *)ft_calloc(2, 1);
			res[0] = '\n';
			return (res);
		}
		free(res);
		res = (ft_strchr(st_str, '\n') + 1);
		if (ft_strchr(res, '\n'))
		{
			if (tmp)
				free(tmp);
			tmp = ft_strchr(res, '\n');
			ft_strcpy(st_str, tmp);
			free(tmp);
		}
	}
	while (!(ft_strchr(st_str, '\n')))
	{
		bytes_read = read(fd, st_str, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(res);
			return (NULL);
		}
		tmp = ft_strjoin(res, st_str);
		//free(res);
		res = tmp;
		//free(tmp);
		if (bytes_read == 0)
			break ;
		while (bytes_read++ <= BUFFER_SIZE)
			st_str[bytes_read] = '\0';
	}
	return (ft_substr(res));
}

