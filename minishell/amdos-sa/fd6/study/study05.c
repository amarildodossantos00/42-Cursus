#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

int	main(int ac, char *av[])
{
	int	fd[2];
	int	pid1;
	int	pid2;
	if (pipe(fd) == -1)
		return (2);
	pid1 = fork();
	if (pid1 < 0)
		return (2);
	if (pid1 == 0)
	{
		// child process 1 (ping)
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		execlp("ping", "ping", "-c", "5", "google.com", NULL);
	}
	pid2 = fork();
	if (pid2 < 0)
		return (2);
	if (pid2 == 0)
	{
		//child process 2 (grap)
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		close(fd[1]);
		execlp("grep", "grep", "rtt", NULL);
	}
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}
