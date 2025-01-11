#include "../header/header.h"

// one
static void	process_ev_aux(t_vars *vars)
{
	vars->var_len = 0;
	while (vars->start[vars->var_len] && (ft_isalnum(vars->start[vars->var_len])
			|| vars->start[vars->var_len] == '_'))
		vars->var_len++;
}

static int	process_env_variable(char *input, char **result, int *i, int *j)
{
	t_vars	*vars;

	vars = malloc(sizeof(t_vars));
	vars->start = &input[*i + 1];
	process_ev_aux(vars);
	if (vars->var_len > 0)
	{
		vars->var_name = malloc(vars->var_len + 1);
		if (!vars->var_name)
			return (0);
		ft_strncpy(vars->var_name, vars->start, vars->var_len);
		vars->var_name[vars->var_len] = '\0';
		vars->env_value = getenv(vars->var_name);
		free(vars->var_name);
		if (vars->env_value)
		{
			ft_strcpy(&(*result)[*j], vars->env_value);
			*j += ft_strlen(vars->env_value);
		}
		*i += vars->var_len + 1;
		return (1);
	}
	return (0);
}

static char	*remove_quotes(char *input)
{
	char	*result;
	int		i;
	int		j;
	int		in_single_quote;
	int		in_double_quote;

	i = 0;
	j = 0;
	in_single_quote = 0;
	in_double_quote = 0;
	result = malloc(ft_strlen(input) + 1);
	if (!result)
		return (NULL);
	while (input[i])
	{
		if (input[i] == '\'' && !in_double_quote)
			in_single_quote = !in_single_quote;
		else if (input[i] == '"' && !in_single_quote)
			in_double_quote = !in_double_quote;
		else if (input[i] == '$' && in_double_quote)
		{
			if (process_env_variable(input, &result, &i, &j))
				continue ;
		}
		else
			result[j++] = input[i];
		i++;
	}
	result[j] = '\0';
	if (in_single_quote || in_double_quote)
	{
		printf("Error: Unclosed quotes\n");
		free(result);
		return (NULL);
	}
	return (result);
}

static char	*without_qoutes(char *input)
{
	return (remove_quotes(input));
}
//one

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
	char	*new_str;
	char	**env;

	new_str = without_qoutes(vars->args[0]);
	executable = find_executable(new_str, vars->path);
	free(new_str);
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
