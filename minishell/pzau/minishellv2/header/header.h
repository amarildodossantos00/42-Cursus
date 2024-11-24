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

typedef struct	s_env
{
	char	*var;
	char	*value;
	struct s_env	*next;
}	t_env;

typedef struct s_vars
{
	char	**env;
	char	**matrix;
	char	**args;
    char	*input;
	char	*path;
	char	*home;
	int		terminal;
	t_env	*env_ref;
	size_t	cargs;
}	t_vars;

//pzau
void    start_promp(t_vars *vars);
void    append_output(char *file);
void    only_comands(t_vars *vars);
void    redirect_output(char *file);
void    read_readline(t_vars *vars);
void    read_readline(t_vars *vars);
void    build_builtins(t_vars *vars);
void    redirecionamento(t_vars *vars);
void    redirect_herdoc(char *delimiter);
char	*get_path(t_vars *vars);
char	**org_red(const char *input);
int		redirect_input(char *file);
int     cheack_input_red(t_vars *vars, char *str, char **redic);
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
void	remove_deli(char *s);
void	env(t_vars *vars);
void	ft_export(t_vars *vars, char **args);
void	print_env(t_env *env_list);
void	init_env(t_vars *vars);
void	add_and_update(t_env **env_list, char *var, char *value);
t_env	*sort_list(t_env *list);
t_env	*creat_node(char *var, char *value);
t_env	*ft_unset(t_env *head, char **vars);
int	count_variables(char **environ);
//cc

#endif
