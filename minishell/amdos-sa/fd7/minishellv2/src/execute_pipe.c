#include "../header/header.h"

// Divide o input pelo caractere `|`
char **split_pipe(char *input)
{
	return ft_split(input, "|");
}

void execute_pipe(char *input)
{
	char	**commands;
	char	*cmd;
	int		num_cmds;
	int		i;
	int		fd[2];
	int		input_fd;
	pid_t	pid;

	commands = split_pipe(input);
	num_cmds = 0;
	i = 0;
	input_fd = 0;

	// Conta o número de comandos
	while (commands[num_cmds])
		num_cmds++;

	i = 0;
	while (i < num_cmds)
	{
		pipe(fd); // Cria o pipe

		if ((pid = fork()) == 0)
		{ // Processo filho
			dup2(input_fd, STDIN_FILENO); // Redireciona entrada
			if (commands[i + 1]) // Se não é o último comando
				dup2(fd[1], STDOUT_FILENO); // Redireciona saída para o pipe
			close(fd[0]); // Fecha leitura do pipe

			// Preparar os argumentos para o execve
			cmd = commands[i]; // O comando a ser executado
			char *args[] = {"/bin/sh", "-c", cmd, NULL}; // Os argumentos para o execve

			// Executa o comando usando execve
			execve("/bin/sh", args, NULL); // execve exige o caminho completo do executável
			perror("execve"); // Em caso de erro
			exit(1);
		}
		else if (pid < 0)
		{
			perror("fork");
			exit(1);
		}
		close(fd[1]);    // Fecha escrita no pipe no processo pai
		input_fd = fd[0]; // Atualiza a entrada para o próximo comando
		i++; // Incrementa o índice
	}

	// Espera todos os processos terminarem
	i = 0;
	while (i < num_cmds)
	{
		wait(NULL);
		i++; // Incrementa o índice
	}

	// Libera a memória dos comandos
	free(commands);
}
