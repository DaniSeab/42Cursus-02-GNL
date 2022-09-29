#include "get_next_line.h"

#define RES(string)	"\033[1m\033[38;5;199m" string "\033[0m"
#define SEP(string)	"\033[38;5;75m" string "\033[0m"


int main()
{
	int	fd;
	int i = 0;
	char *str;
	
	fd = open("txt_files/t_ptiprinc.txt", O_RDONLY);
	printf("> fd = %d\n", fd);
	while (i < 15)
	{
		str = get_next_line(fd);
		printf(RES("%s"), str);
		if (str == "\n")
			printf(RES("\\n"));
		printf(SEP("\n\n-----------------------------------------------\n\n"));
		i++;
	}
	close(fd);
	return (0);
}
