#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <fcntl.h>

int	main(int ac, char *av[])
{
	int	pid;
	int	file;
	pid = fork();
	if (pid < 0)
		return (2);
	if (pid == 0)
	{
		file = open("result.txt", O_WRONLY | O_CREAT, 0777);
		if (file == -1)
			return (2);
		dup2(file, STDOUT_FILENO);
		close(file);
		execlp("ls", "ls", NULL);
	}
}
