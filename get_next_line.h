/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlima-se <dlima-se@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 18:30:38 by dlima-se          #+#    #+#             */
/*   Updated: 2022/10/10 22:34:38 by dlima-se         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <unistd.h>
# include <stdlib.h>

size_t	ft_strlen(const char *str);
char	*ft_calloc(size_t nitems, size_t size);
char	*ft_strchr(char *str, int ch);
char	*ft_strdup(char *st_free, char *st_src);
char	*ft_strdup_gnl_nl(char *src);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*read_file(int fd, char *str_read);
char	*get_next_line(int fd);

#endif
