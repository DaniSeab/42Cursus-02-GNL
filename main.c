#include "get_next_line.h"
#include <string.h>

#define RES(string)	"\033[1m\033[38;5;199m" string "\033[0m"
#define SEP(string)	"\033[38;5;75m" string "\033[0m"

int main()
{
	int	fd;
	int i = 0;
	char *str;
	
	fd = open("txt_files/t_n.txt", O_RDONLY);
	printf("> fd = %d\n", fd);
	while (i < 8)
	{
		str = get_next_line(fd);
		printf(RES("--%s--\n\n"), str);
		i++;
		free(str);
	}
	close(fd);
	ft_strlen(NULL);
	return (0);
}
