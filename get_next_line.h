/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlima-se <dlima-se@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 18:30:38 by dlima-se          #+#    #+#             */
/*   Updated: 2022/10/25 18:32:26 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <unistd.h>
# include <stdlib.h>

// ft_strlen is used to find the length of a string.
size_t	ft_strlen(const char *str);

// 	ft_calloc is used to allocate memory for a string while cleaning the memory
//  trash by filling each byte found there with zeros. It then returns a pointer
//  to the allocated memory.	
char	*ft_calloc(size_t nitems, size_t size);

// ft_strchr is used to find a character in a string.
char	*ft_strchr(char *str, int ch);

// ft_strdup is used to duplicate a string, allocate the memory the duplicate
// needs and then return a pointer to the newly allocated memory cointaining it.
char	*ft_strdup(char *st_free, char *st_src);

// ft_strdup_gnl_nl duplicates input string until \n is found.
char	*ft_strdup_gnl_nl(char *src);

// ft_strjoin_gnl 2 strings and frees the first so that 's1 = join(s1, s2)'
// becomes possible.
// because s1's address would be lost if not freed within ft_strjoin_gnl's
// scope.
char	*ft_strjoin_gnl(char *s1, char *s2);

// The read_file function reads fd and joins what was read into the static char*
// str_read it does so by joining the string stored on static from the last
// read, with the newly created one; attributing the new string to str_read and
// then returning str_read.
char	*read_file(int fd, char *str_read);

// Each time get_next_line is called it returns a new line from the file
// descriptor (fd). It reads as many bytes from fd as is defined by the
// BUFFER_SIZE macro, so it doesnt read line by line, but has to return line by
// line. A static variable was used to implement this, since the number of chars
// determined by BUFFER_SIZE is fixed but the number of chars in a line isn't.
// The static var stores anything read in excess to be returned only in the next 
// call of the function.
char	*get_next_line(int fd);

#endif
