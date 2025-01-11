#include "../header/header.h"

static char	*without_qoutes(char *input, t_vars *vars)
{
	return (remove_quotes(input, vars));
}

char	*build_executable_path(char *dir, char *command)
{
	char	executable_path[256];

	executable_path[0] = '\0';
	sncat(executable_path, dir,
		sizeof(executable_path) - ft_strlen(executable_path) - 1);
	sncat(executable_path, "/", 1);
	sncat(executable_path, command,
		sizeof(executable_path) - ft_strlen(executable_path) - 1);
	return (ft_strdup(executable_path));
}

char	*find_executable(char *command, char *path, t_vars *vars)
{
	if (command[0] == '/' || command[0] == '.'
		|| (command[0] == '.' && command[1] == '.'))
	{
		if (access(command, X_OK) == 0)
			return (ft_strdup(command));
		else
			return (NULL);
	}
	vars->path_copy = ft_strdup(path);
	vars->dir = ft_strtok(vars->path_copy, ":");
	while (vars->dir)
	{
		vars->executable = build_executable_path(vars->dir, command);
		if (access(vars->executable, X_OK) == 0)
		{
			free(vars->path_copy);
			return (vars->executable);
		}
		free(vars->executable);
		vars->dir = ft_strtok(NULL, ":");
	}
	free(vars->path_copy);
	return (NULL);
}

static void	execute_aux(t_vars *vars)
{
	vars->args[0] = vars->executablee;
	vars->envv = convert_env_list(vars->env_ref);
	execve(vars->executablee, vars->args, vars->envv);
	perror("execv falhou");
	free(vars->copy_input);
	free(vars->input);
	free(vars->executablee);
}

void	execute_path(t_vars *vars)
{
	vars->new_strr = without_qoutes(vars->args[0], vars);
	vars->executablee = find_executable(vars->new_strr, vars->path, vars);
	free(vars->new_strr);
	if (!vars->executablee)
	{
		printf("%s: command not found\n", vars->input);
		free(vars->copy_input);
		free(vars->input);
		exit(127);
	}
	else if (vars->executablee == NULL)
	{
		printf("minishell: %s: No such file or directory\n", vars->input);
		free(vars->copy_input);
		free(vars->input);
		exit(1);
	}
	else
	{
		execute_aux(vars);
		exit(0);
	}
}
