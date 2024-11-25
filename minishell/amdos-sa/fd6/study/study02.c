#include <stdio.h>
#include <unistd.h>

int	main (int ac, char *av[])
{
	int fd[2];
	if (pipe(fd) == -1)
	{
		printf("Error on the pipe()\n");
		return (1);
	}

	int id = fork();
	if (id == 0)
	{
		close(fd[0]);
		int x;
		printf("Input a number: ");
		scanf("%d", &x);
		write(fd[1], &x, sizeof(int));
		close(fd[1]);
	}
	else
	{
		close(fd[1]);
		int y;
		read(fd[0], &y, sizeof(int));
		close(fd[0]);
		printf("Got from child process %d\n", y);
	}
	return (0);
}
