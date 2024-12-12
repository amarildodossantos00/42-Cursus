#include "../header/header.h"

char	**split_pipe(char *input)
{
	return (ft_split_del(input, "|"));
}

void execute_pipe(t_vars *vars)
{
	char *executable;
	char **args;
	int num_cmds;
	int i;

	vars->commands = split_pipe(vars->input);
	num_cmds = 0;
	while (vars->commands[num_cmds])
		num_cmds++;

	vars->input_fd = STDIN_FILENO;  // Entrada padrão inicial

	i = 0;
	while (i < num_cmds) {
		// Verificar redirecionamento antes de processar o comando
		if (cheack_red(vars->commands[i]) > 0) {
			vars->input = vars->commands[i];
			redirecionamento(vars, 1);
			printf("ok\n");
    		exit(1);  // Encerra o programa completamente
		}

		if (pipe(vars->fd) == -1) {
			perror("pipe");
			exit(1);
		}

		vars->pid = fork();
		if (vars->pid == 0) {
			// Processo filho
			dup2(vars->input_fd, STDIN_FILENO);  // Entrada do pipe
			if (vars->commands[i + 1]) {
				dup2(vars->fd[1], STDOUT_FILENO);  // Saída do pipe
			}
			close(vars->fd[0]);
			close(vars->fd[1]);

			args = ft_split_del(vars->commands[i], " ");
			executable = find_executable(args[0], vars->path);
			if (!executable) {
				printf("%s: command not found\n", args[0]);
				exit(127);
			}
			execve(executable, args, vars->env);
			perror("execve");
			exit(1);
		} else if (vars->pid < 0) {
			// Erro no fork
			perror("fork");
			exit(1);
		}

		// Processo pai
		close(vars->fd[1]);  // Fechar a escrita no pipe
		vars->input_fd = vars->fd[0];  // Atualizar entrada para o próximo comando

		i++;
	}

	i = 0;
	while (i < num_cmds) {
		wait(NULL);  // Aguarda o término dos processos filhos
		i++;
	}

	free(vars->commands);
}
