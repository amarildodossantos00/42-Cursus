#include "../header/header.h"

static char *without_qoutes(char *input)
{
    char *result = malloc(ft_strlen(input) + 1);
    if (!result)
        return NULL;

    int i = 0, j = 0;
    int in_single_quote = 0;
    int in_double_quote = 0;

    while (input[i])
	{
        if (input[i] == '\'' && !in_double_quote)
		{
            in_single_quote = !in_single_quote;
            i++;
            continue;
        } else if (input[i] == '"' && !in_single_quote)
		{
            in_double_quote = !in_double_quote;
            i++;
            continue;
        } else if (input[i] == '$' && in_double_quote)
		{
            char *start = &input[i + 1];
            int var_len = 0;
            while (start[var_len] && (ft_isalnum(start[var_len]) || start[var_len] == '_'))
                var_len++;
            if (var_len > 0)
			{
                char var_name[var_len + 1];
                ft_strncpy(var_name, start, var_len);
                var_name[var_len] = '\0';

                char *env_value = getenv(var_name);
                if (env_value)
				{
                    ft_strcpy(&result[j], env_value);
                    j += ft_strlen(env_value);
                }

                i += var_len + 1;
                continue;
            }
        }

        result[j++] = input[i++];
    }

    result[j] = '\0';
    if (in_single_quote || in_double_quote)
	{
        printf("Error: Unclosed quotes\n");
        free(result);
        return (NULL);
    }

    return result;
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
