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
	int		exported;
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
	size_t	cargs;
	t_env	*env_ref;
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
void	remove_deli(char *s);
void	env(t_vars *vars);
void	ft_export(t_vars *vars, char **args);
void	print_env(t_env *env_list);
void	add_and_update(t_env **env_list, char *var, char *value, int exported);
t_env	*sort_list(t_env *list);
t_env	*creat_node(char *var, char *value);
int	count_variables(char **environ);
t_env	*ft_unset(t_env *head, char **vars);
int export_var(t_vars *vars, char *input);
void    expand_var(t_vars *vars);
char    *return_name(char *str);
void    search_var(t_vars *vars, char *var, int *p, int len);

//cc

#endif
