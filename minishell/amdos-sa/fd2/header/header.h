#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <signal.h>

//pzau testes
# include <string.h>
//pzau testes

# include <readline/readline.h>
# include <readline/history.h>

# include "../libx/libx.h"

typedef struct s_vars
{
	char	*input;
	char	*path;
	char	*last_command;
	char	**variables;
	char	**args;
	size_t	cargs;
}	t_vars;

void	call_prompt(t_vars *vars);

//pzau
void	get_variables(t_vars *vars, char **environ);
void	remove_variable(t_vars *vars, const char *var_name);
void	add_variables(t_vars *vars, char *new_str);
void	print_variables(t_vars *vars);
void	liberar(t_vars *vars);
void	get_path(t_vars *vars);
//pzau
//amdos-sa
char	*ft_strtok(char *str, const char *delim);
char	*sncat(char *dest, const char *src, size_t n);
void	execute_path(t_vars *vars);
int		count_args(char *input);
char	**create_args(char *input);
char	*ft_strcpy(char *dest, const char *src);
//amdos-sa

#endif
