/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlima-se <dlima-se@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 18:30:38 by dlima-se          #+#    #+#             */
/*   Updated: 2022/10/01 12:05:35 by dlima-se         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 200
#endif

size_t	ft_strlen(const char *s);
void	ft_bzero(void *dest, size_t len);
char	*ft_calloc(size_t nitems, size_t size);
char	*ft_strchr(const char *str, int ch);
char	*ft_substr(char *s);
char	*ft_strjoin(char *s1, char const *s2);
void	ft_strcpy(char *dest, const char *src);
char	*ft_strdup(char *src);
char	*get_next_line(int fd);

#endif