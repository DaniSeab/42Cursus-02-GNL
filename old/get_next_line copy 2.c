/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlima-se <dlima-se@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 18:31:34 by dlima-se          #+#    #+#             */
/*   Updated: 2022/10/01 00:33:58 by dlima-se         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#define RES(string)		"\033[38;5;75m" string "\033[0m"
#define ST(string)		"\033[38;5;43m" string "\033[0m"
#define HEAD(string)	"\033[1m\033[37m" string "\033[0m"

char	*get_next_line(int fd)
{
	int			count;
	char		*res;
	char		*tmp_res;
	char		*tmp_st;
	char		*tmp_st2;
	static char	*st_str;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (!st_str)
	{
		st_str = (char *)ft_calloc(BUFFER_SIZE, sizeof(char));
		if (!st_str)
			return (NULL);
	}
	tmp_st = (char *)ft_calloc(1, sizeof(char));
	if (!tmp_st)
		return (NULL);
	tmp_res = (char *)ft_calloc(1, sizeof(char));
	if (!tmp_res)
		return (NULL);
	if (!res)
		res = (char *)ft_calloc(1, sizeof(char));
	if (!res)
		return (NULL);
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
		free(res);
		res = ft_strdup(ft_strchr(st_str, '\n') + 1);
		if (ft_strchr(res, '\n'))
		{
			tmp_st = ft_strdup(ft_strchr(res, '\n'));
			ft_strcpy(st_str, tmp_st);
			free(tmp_st);
		}
	}
	while (!(ft_strchr(st_str, '\n')))
	{
		count = read(fd, st_str, BUFFER_SIZE);
		if (count < 0)
		{
			free(res);
			return (NULL);
		}
		if (tmp_st)
		{
			tmp_st2 = ft_strjoin(tmp_st, st_str);
			free(tmp_st);
			tmp_res = ft_strjoin(res, tmp_st2);
			free(tmp_st2);
			res = ft_strdup(tmp_res);
			free(tmp_res);
		}
		tmp_res = ft_strjoin(res, st_str);
		res = ft_strdup(tmp_res);
		free(tmp_res);
		if (count == 0)
			break ;
		while (count++ <= BUFFER_SIZE)
			st_str[count] = '\0';
	}
//	tmp_res = ft_strjoin(res, st_str);
//	res = ft_strdup(tmp_res);
//	free(tmp_res);
	if (ft_strchr(res, '\n'))
	{
		tmp_res = ft_substr(res, 0, ft_strlen(res) - ft_strlen(ft_strchr(res, '\n')) + 1);
		res = ft_strdup(tmp_res);
		free(tmp_res);
	}
//	else
//	{
//		tmp_res = ft_substr(res, 0, ft_strlen(res) + 1);
//		res = ft_strdup(tmp_res);
//		free(tmp_res);
//	}
	//çç;
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