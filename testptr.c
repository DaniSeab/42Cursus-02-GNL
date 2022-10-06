#include "get_next_line.h"
#include <sys/errno.h>
#include <unistd.h>
#include <stdio.h>

int ismapped(const void *ptr, int bytes)
{
	if (ptr == NULL)
		return 0;
	
	int	fd[2];
	int	valid = 1;

	pipe(fd);
	if (write(fd[1], ptr, bytes) < 0)
	{
		if (errno = EFAULT)
			valid = 0;
	}
	close(fd[0]);
	close(fd[1]);
	return (valid);
}

void testptr(void *p, int bytes, char *name)
{
	char *valid[6];

	if (ismapped(p, bytes) == 1)
		ft_strcpy(valid, "TRUE-");
	else
		ft_strcpy(valid, "FALSE");

	printf("%s:\t%s\t%p\n", name, &valid, p);
}