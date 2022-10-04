/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlima-se <dlima-se@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 23:53:57 by dlima-se          #+#    #+#             */
/*   Updated: 2022/10/04 02:14:32 by dlima-se         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int			count;
	char		*res;
	char		*temp;
	static char	*st_str;

	count = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (!st_str)
		st_str = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	res = (char *)ft_calloc(1, sizeof(char));
	temp = "";
	//(char *)ft_calloc(1, sizeof(char));
	//temp = (char *)ft_calloc(1, sizeof(char));
	if (ft_strchr(st_str, '\n'))
	{
		if (st_str[0] == '\n' && st_str[1] == '\n')
		{
			ft_strcpy(st_str, (st_str + 1));
			st_str[ft_strlen(st_str) + 1] = '\0';
			//free(res);
			res = (char *)ft_calloc(2, 1);
			res[0] = '\n';
			return (res);
		}
		free(res);
		res = ft_strdup(ft_strchr(st_str, '\n') + 1);
		//printf("res inicial =	%s\n", res);
		//free(st_str);
		if (ft_strchr(res, '\n'))
			st_str = ft_strdup(ft_strchr(res, '\n'));
		else
			st_str = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	}
	while (!(ft_strchr(st_str, '\n')))
	{
		count = read(fd, st_str, BUFFER_SIZE);
		//printf("STATIC LIDA: %s--- %i\n", st_str, count);
		if (count < 0 || !st_str[0])
		{
			free(res);
			//free(st_str);
			return (NULL);
		}
		// if (count < BUFFER_SIZE)
		// 	st_str[count] = '\0';
		if (ft_strchr(st_str, '\n'))
		{
			temp = (char *)ft_calloc(ft_strlen(res) + 1, sizeof(char));
			ft_strcpy(temp, res);
			free(res);
			res = ft_strjoin(temp, st_str);
			// free(temp);
			// temp = ft_substr(res, 0, (ft_strlen(res) - ft_strlen(ft_strchr(res, '\n') + 1));
			ft_strcpy(st_str, ft_strchr(st_str, '\n') + 1);
			//res = ft_substr(res, 0, ft_strlen(res) - ft_strlen(ft_strchr(res, '\n')) + 1);
			free(temp);
			return (res);
		}
		//res = (char *)ft_calloc(ft_strlen(st_str), sizeof(char));
		//free(temp);
		if (count == 0)
		{
			//ft_strcpy(st_str, ft_strchr(st_str, '\n') + 1);
			//st_str[0] = '\0';
			break ;
		}
		if (count == BUFFER_SIZE)
		{
			temp = (char *)ft_calloc(ft_strlen(res) + 1, sizeof(char));
			ft_strcpy(temp, res);
			free(res);
			res = ft_strjoin(temp, st_str);
			ft_strcpy(st_str, &st_str[BUFFER_SIZE + 1]);
			free(temp);
		}
	}
	// if (count_aux < BUFFER_SIZE)
	// {
	// 	//ft_strcpy(st_str, ft_strchr(st_str, '\n') + 1);
	// 	temp = (char *)ft_calloc(ft_strlen(res) + 1, sizeof(char));
	// 	ft_strcpy(temp, res);
	// 	free(res);
	// 	res = ft_strjoin(temp, st_str);
	// 	free(temp);
	// }
	// st_str[0] = '\0';
	
	if (!res)
	{
		//free(res);
		//free(st_str);
	}
	return (res);
}
