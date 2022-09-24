#include "get_next_line.h"

int main()
{
	int	fd;
	char *str;
	
	fd = open("txt_files/t_empty.txt", O_RDONLY);
	printf("> fd = %d\n", fd);
	str = get_next_line(fd);
	print("%s\n", str);
	str = get_next_line(fd);
	print("%s\n", str);
	str = get_next_line(fd);
	print("%s\n", str);
	str = get_next_line(fd);
	print("%s\n", str);
	str = get_next_line(fd);
	print("%s\n", str);	
	close(fd);
}