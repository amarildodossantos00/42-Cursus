#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	int	fd[2];
	if (pipe(fd) == -1)
		return (1);
	int	pid = fork();
	if (pid == -1)
		return (2);
	if (pid == 0)
	{
		int x;
		read(fd[0], &x, sizeof(x));
		printf("Received %d\n", x);
		x *= 4;
		write(fd[1], &x, sizeof(x));
		printf("Wrote %d\n", x);
	}
	else
	{
		srand(time(NULL));
		int y = rand() % 10;
		write(fd[1], &y, sizeof(y));
		printf("Wrote %d\n", y);
		read(fd[0], &y, sizeof(y));
		printf("Result is %d\n", y);
	}
	close(fd[0]);
	close(fd[1]);
	return (0);
}
