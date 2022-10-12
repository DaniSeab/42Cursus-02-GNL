/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlima-se <dlima-se@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 16:58:30 by dlima-se          #+#    #+#             */
/*   Updated: 2022/10/11 20:30:06 by dlima-se         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# ifndef FD_MAX
#  define FD_MAX 1048576
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