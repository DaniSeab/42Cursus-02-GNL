/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlima-se <dlima-se@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 18:31:34 by dlima-se          #+#    #+#             */
/*   Updated: 2022/09/26 23:11:32 by dlima-se         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int	count;
	static int	i;
	int	j;
	char	*str;
	char	*res;
	
	if (fd < 0)
		return ((void *)0);
	str = (char *)ft_calloc(BUFFER_SIZE, sizeof(char));
	if (!str)
		return ((void *)0);
	count = read(fd, str, BUFFER_SIZE);
	j = i;
	if (count >= 0)
	{
		while (str[j] != '\n')
			j++;
	}
	res = substr(str, i, j - i + 1);
	free(str);
	i = j + 1;
	reurn (res);
}
/*
Read line: correct behavior 
NULL: there is nothing else to read,or an error occurred
read, malloc, free
*/