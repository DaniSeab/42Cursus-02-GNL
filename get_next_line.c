/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlima-se <dlima-se@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 18:31:34 by dlima-se          #+#    #+#             */
/*   Updated: 2022/10/01 01:06:48 by dlima-se         ###   ########.fr       */
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
	static char	*st_str;
	static int	i; //para contar calls
	
	i++; //para contar calls
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (!st_str)
		st_str = (char *)ft_calloc(BUFFER_SIZE, sizeof(char));
	res = (char *)ft_calloc(1, sizeof(char));
	//printf(HEAD("FUNCTION CALL %d \n"), i);
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
		res = ft_strdup(ft_strchr(st_str, '\n') + 1);
		//printf(RES("res inicial =	%s\n"), res);
		free(st_str);
		if (ft_strchr(res, '\n'))
			st_str = ft_strdup(ft_strchr(res, '\n'));
		else
			st_str = (char *)ft_calloc(BUFFER_SIZE, sizeof(char));
	}
	while (!(ft_strchr(st_str, '\n')))
	{
		count = read(fd, st_str, BUFFER_SIZE);
		if (count < 0)
		{
			return (NULL);
			free(res);
			free(st_str);
		}
		res = ft_strjoin(res, st_str);
		if (count == 0)
			break ;
		if (count < BUFFER_SIZE)
			st_str[count] = '\0';
		//printf("STATIC LIDA: %s", st_str);
	}
	res = ft_strjoin(res, st_str);
	if (ft_strchr(res, '\n'))
		res = ft_substr(res, 0, ft_strlen(res) - ft_strlen(ft_strchr(res, '\n')) + 1);
	else
		res = ft_substr(res, 0, ft_strlen(res) + 1);
	//printf(ST("res fim =	%s\n"), res);
	//st_str = ft_strchr(st_str, '\n');
	//printf(ST("st_str final = %5s\n"), st_str);
	if (!res)
	{
		free(res);
		free(st_str);
	}
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