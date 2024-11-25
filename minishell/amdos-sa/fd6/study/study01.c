#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int	main(void)
{
	pid_t	pid;
	int		fd[2];

	pipe(fd);
	pid = fork();

	if (pid == 0)
	{
		char	c;
		close(fd[1]);
		while (read(fd[0], &c, 1) > 0)
		{
			fprintf(stdout, "Proc. Filho escreve: %c\n", c);
			sleep(1);
		}
		exit (1);
	}
	close(fd[0]);
	write(fd[1], "Hello!\n",7);
	close(fd[1]);
	waitpid(pid, NULL, 0);
	printf("Saindo do programa...\n");
	return (0);
}
