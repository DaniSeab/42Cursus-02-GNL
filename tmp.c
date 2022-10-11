# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
#include <stdio.h>

void    ft_free(char *str)
{
    if (str != NULL)
    {
        free(str);
        str = NULL;
    }
}

char    *ft_strdup(char *st_free, char *st_src)
{
    char    *dest;
    int        len;
    int        i;

    if (!st_src[0] || !st_free)
        return (NULL);
    i = 0;
    len = strlen(st_src);
    dest = (char *)calloc((len + 1), (sizeof(char)));
    while (st_src[i])
    {
        dest[i] = st_src[i];
        i++;
    }
    ft_free(st_free);
    return (dest);
}


char    *ft_strjoin_gnl(char *s1, char *s2)
{
    char    *res;
    int        i;
    int        j;

    i = 0;
    res = (char *)calloc((strlen(s1) + strlen(s2) + 1), sizeof(char));
    if (!res || !s1 || !s2)
        return (NULL);
    while (s1[i] != 0)
    {
        res[i] = s1[i];
        i++;
    }
    j = 0;
    while (s2[j] != 0)
    {
        res[i] = s2[j];
        i++;
        j++;
    }
    ft_free(s1);
    return (res);
}


char    *ft_strdup_gnl_nl(char *src)
{
    char    *dest;
    int        i;

    i = 0;
    if (src[0] == '\0')
        return (NULL);
    dest = calloc(strlen(src) - strlen(ft_strchr(src, '\n')) + 2, 1);
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


char    *read_file(int fd, char *str_read)
{
    int        bytes_read;
    char    *temp;

    if (!str_read)
        str_read = calloc(1, sizeof(char));
    if (!str_read)
        return (NULL);
    temp = calloc(42 + 1, sizeof(char));
    if (!temp)
        return (NULL);
    bytes_read = 1;
    while (bytes_read > 0)
    {
        bytes_read = read(fd, temp, 42);
        if (bytes_read < 0)
        {
            ft_free(temp);
            return (NULL);
        }
        temp[bytes_read] = '\0';
        str_read = ft_strjoin_gnl(str_read, temp);
        if (strchr(temp, '\n'))
            break ;
    }
    free(temp);
    return (str_read);
}

char    *get_next_line(int fd)
{
    char        *res;
    static char    *st_str;

    if (fd < 0 || read(fd, 0, 0) < 0)
        return (NULL);
    st_str = read_file(fd, st_str);
    if (!st_str)
        return (NULL);
    res = ft_strdup_gnl_nl(st_str);
    if (strchr(st_str, '\n') && (strchr(st_str, '\n') + 1))
        st_str = ft_strdup(st_str, strchr(st_str, '\n') + 1);
    else
        ft_free(st_str);
    return (res);
}

int main()
{
    int    fd = 1;
    char *str;
    
    str = get_next_line(fd);
    ft_free(str);
     str = get_next_line(fd);
    ft_free(str);
    str = get_next_line(fd);
    ft_free(str);
    return (0);
}