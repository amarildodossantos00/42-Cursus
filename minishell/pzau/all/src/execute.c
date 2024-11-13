#include "../header/header.h"

char	*build_executable_path(char *dir, char *command)
{
	char	executable_path[256];

	executable_path[0] = '\0';
	sncat(executable_path, dir,
		sizeof(executable_path) - strlen(executable_path) - 1);
	sncat(executable_path, "/", 1);
	sncat(executable_path, command,
		sizeof(executable_path) - strlen(executable_path) - 1);
	return (ft_strdup(executable_path));
}

char	*find_executable(char *command, char *path)
{
	char	*dir;
	char	*executable;
	char	*path_copy;

	path_copy = ft_strdup(path);
	if (!path_copy)
		return (NULL);
	dir = ft_strtok(path_copy, ":");
	while (dir)
	{
		executable = build_executable_path(dir, command);
		if (access(executable, X_OK) == 0)
		{
			free(path_copy);
			return(executable);
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

	executable =  find_executable(vars->args[0], vars->path);
	if (executable)
	{
		vars->args[0] = executable;
		vars->last_command = executable;
		execv(executable, vars->args);
		perror("execv falhou");
		free(executable);
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("%s: command not found\n", vars->args[0]);
		exit(EXIT_FAILURE);
	}
}
