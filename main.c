#include "get_next_line.h"
#include <string.h>

#define RES(string)	"\033[1m\033[38;5;199m" string "\033[0m"
#define SEP(string)	"\033[38;5;75m" string "\033[0m"

int main()
{
	int	fd;
	char *str;
	
	fd = open("txt_files/t_n.txt", O_RDONLY);
	printf("> fd = %d\n", fd);
	str = get_next_line(fd);
	printf(RES("--%s--\n\n"), str);
	ft_free(str);
	str = get_next_line(fd);
	printf(RES("--%s--\n\n"), str);
	ft_free(str);
	str = get_next_line(fd);
	printf(RES("--%s--\n\n"), str);
	ft_free(str);
	str = get_next_line(fd);
	printf(RES("--%s--\n\n"), str);
	ft_free(str);
	close(fd);
	ft_strlen(NULL);
	return (0);
}
