#include "../../header/header.h"

int	executar_redic(t_vars *vars, char *redic, char *str_space)
{
	int	red_type;

	red_type = cheack_red(redic);
	if (red_type == 2)
		redirect_output(str_space);
	else if (red_type == 1)
		append_output(str_space);
	else if (red_type == 4)
	{
		if (redirect_input(str_space) == 1)
		{
			dup2(vars->terminal, STDOUT_FILENO);
			printf("%s: No such file or directory\n", str_space);
			free(str_space);
			return (0);
		}
	}
	else if (red_type == 3)
		return (0);
	return (1);
}

void	free_process_red(char *str_space, char **command)
{
	free(str_space);
	free_split(command);
}
