#include "../../header/header.h"

static int	processar_redic(t_vars *vars, char **redic)
{
	int		i;

	i = 0;
	while (redic[i])
	{
		vars->command = ft_split_red(redic[i]);
		vars->str_space = ft_space(vars->command[1]);
		if (count_words(vars->command[1]) > 1)
		{
			vars->str_split = ft_strjoin(" a ", vars->command[1]);
			free_split(vars->command);
			vars->command = ft_split(vars->str_split);
			free(vars->str_split);
		}
		if (!executar_redic(vars, redic[i], vars->str_space))
		{
			free_split(vars->command);
			break ;
		}
		free_process_red(vars->str_space, vars->command);
		i++;
	}
	free(vars->str_space);
	return (0);
}

static void	executar_comando_redic(t_vars *vars, char *comando)
{
	char	*str2;
	char	**str1;

	str2 = find_executable(comando, vars->path, vars);
	str1 = malloc(sizeof(char *) * 2);
	str1[0] = comando;
	str1[1] = NULL;
	execve(str2, str1, NULL);
	free(str1);
	free(str2);
	exit(EXIT_FAILURE);
}

static int	process_val_red(t_vars *vars, char **redic, int status)
{
	int		fd;
	int		pid;
	char	*val_itoa;
	char	*file;

	if (vars->val_red > 0 && redic[0] != NULL && status != 1)
	{
		val_itoa = ft_itoa(vars->val_red);
		file = ft_strjoin("/tmp/", val_itoa);
		pid = fork();
		if (pid == 0)
		{
			fd = open(file, O_RDONLY);
			if (fd < 0)
				perror("Error opening the file");
			dup2(fd, 0);
			close(fd);
			executar_comando_redic(vars, redic[0]);
		}
		else
			wait(NULL);
		free(val_itoa);
		free(file);
	}
	return (0);
}

static void	finalizar_redirecionamento(t_vars *vars,
	char **redic, int fd_terminal)
{
	free_split(redic);
	dup2(fd_terminal, STDOUT_FILENO);
	close(fd_terminal);
}

void	redirecionamento(t_vars *vars, int status)
{
	char	**redic;
	int		fd_terminal;

	fd_terminal = dup(STDOUT_FILENO);
	redic = org_red(vars->input);
	if (!redic || cheack_input_red(vars, vars->input, redic))
	{
		finalizar_redirecionamento(vars, redic, fd_terminal);
		return ;
	}
	if (process_val_red(vars, redic, status) == 1)
	{
		finalizar_redirecionamento(vars, redic, fd_terminal);
		return ;
	}
	processar_redic(vars, redic);
	atualizar_input(vars, redic);
	if (!check_one_red(redic))
		only_comands(vars);
	finalizar_redirecionamento(vars, redic, fd_terminal);
}
