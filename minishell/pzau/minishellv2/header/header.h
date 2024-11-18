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
	char	**env;
	char	**matrix;
	char	**args;
    char	*input;
	char	*path;
	char	*home;
	int		terminal;
	size_t	cargs;
}	t_vars;

//pzau
void    start_promp(t_vars *vars);
void    read_readline(t_vars *vars);
void	get_path(t_vars *vars);
void    read_readline(t_vars *vars);
void    only_comands(t_vars *vars);
void    build_builtins(t_vars *vars);
void    redirecionamento(t_vars *vars);
void    redirect_output(char *file);
int		redirect_input(char *file);
void    redirect_herdoc(char *delimiter);
void    append_output(char *file);
char	**org_red(const char *input);
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
void	env(t_vars *vars);
//cc

#endif
