#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
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
	char	*home;
	char	**variables;
	char	**matrix;
	char	*last_command;
	char	**args;
	size_t	cargs;
	int		ok;
}	t_vars;

void	call_prompt(t_vars *vars);

//pzau
void	get_variables(t_vars *vars, char **environ);
void    update_last_comand(t_vars *vars);
void    remove_variable(t_vars *vars, const char *var_name);
void    add_variables(t_vars *vars, char *new_str);
void    print_variables(t_vars *vars);
void    liberar(t_vars *vars);
void    redirect_output(char *file);
void    append_output(char *file);
void    get_path(t_vars *vars);
int		filter_commands(t_vars *vars);
void    red_and_pipes(t_vars *vars);
//pzau

//amdos-sa
void	execute_path(t_vars *vars);
int		count_args(char *input);
char	**create_args(char *input);
//amdos-sa

//cc
void	cd(t_vars *vars);
void    pwd(t_vars *vars);
void	ft_exit(t_vars *vars);
void	echo(t_vars *vars);
//cc

#endif
