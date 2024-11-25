#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

void execute_command(char *cmd, char *args[]) {
	if (execve(cmd, args, NULL) == -1)
	{
		perror("execve");
		exit(1);
	}
}

int main() {
	int fd[2];
	if (pipe(fd) == -1)
	{
		perror("pipe");
		exit(1);
	}

	pid_t pid1 = fork();
	if (pid1 == -1)
	{
		perror("fork");
		exit(1);
	}

	if (pid1 == 0)
	{ // Primeiro filho
		close(fd[0]); // Fechar leitura do pipe
		dup2(fd[1], STDOUT_FILENO); // Redirecionar stdout para escrita do pipe
		close(fd[1]); // Fechar o descritor duplicado

		// Executar o primeiro comando
		char *cmd1 = "/bin/ls";
		char *args1[] = {"ls", NULL};
		execute_command(cmd1, args1);
	}

	pid_t pid2 = fork();
	if (pid2 == -1)
	{
		perror("fork");
		exit(1);
	}

	if (pid2 == 0)
	{ // Segundo filho
		close(fd[1]); // Fechar escrita do pipe
		dup2(fd[0], STDIN_FILENO); // Redirecionar stdin para leitura do pipe
		close(fd[0]); // Fechar o descritor duplicado

		// Executar o segundo comando
		char *cmd2 = "/bin/grep";
		char *args2[] = {"grep", ".c", NULL};
		execute_command(cmd2, args2);
	}

	// Fechar ambos os lados do pipe no processo pai
	close(fd[0]);
	close(fd[1]);

	// Esperar pelos filhos
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);

	return 0;
}

