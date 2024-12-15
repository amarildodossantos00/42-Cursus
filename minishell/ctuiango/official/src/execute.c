#include "../header/header.h"

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

char	*find_executable(char *command, char *path)
{
	char	*dir;
	char	*executable;
	char	*path_copy;

	if (command[0] == '/' || command[0] == '.'
		|| (command[0] == '.' && command[1] == '.'))
	{
		if (access(command, X_OK) == 0)
			return (ft_strdup(command));
		else
			return (NULL);
	}
	path_copy = ft_strdup(path);
	dir = ft_strtok(path_copy, ":");
	while (dir)
	{
		executable = build_executable_path(dir, command);
		if (access(executable, X_OK) == 0)
		{
			free(path_copy);
			return (executable);
		}
		free(executable);
		dir = ft_strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}

void	execute_path(t_vars *vars)
{
	char	*executable;
	char	**env;

	executable = find_executable(vars->args[0], vars->path);
	if (!executable)
	{
		printf("%s: command not found\n", vars->input);
		free(vars->copy_input);
		free(vars->input);
		exit(127);
	}
	else if (executable == NULL)
	{
		printf("minishell: %s: No such file or directory\n", vars->input);
		free(vars->copy_input);
		free(vars->input);
		exit(1);
	}
	else
	{
		vars->args[0] = executable;
		env = convert_env_list(vars->env_ref);
		execve(executable, vars->args, env);
		perror("execv falhou");
		free(vars->copy_input);
		free(vars->input);
		free(executable);
		exit(0);
	}
}