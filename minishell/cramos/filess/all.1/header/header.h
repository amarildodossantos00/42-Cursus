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

typedef struct s_env
{
	char	*key;
	char	*value;
	struct s_env *next;
}t_env;

typedef struct s_vars
{
        char	*input;
	char	*path;
	char	**variables;
	char	**matrix;
	t_env	*env_list;
}	t_vars;

void	call_prompt(t_vars *vars);

//pzau
void	get_variables(t_vars *vars, char **environ);
void    remove_variable(t_vars *vars, const char *var_name);
void    add_variables(t_vars *vars, char *new_str);
void    print_variables(t_vars *vars);
void    liberar(t_vars *vars);
void    get_path(t_vars *vars);
//pzau

//cc
void	cd(t_vars *vars);
void    pwd(t_vars *vars);
void	ft_exit(t_vars *vars);
void	echo(t_vars *vars);
//cc
void    free_env_node(t_env *node);
t_env   *unset_env(t_env *head, const char *key);
t_env   *add_env(t_env *head, const char *key, const char *value);
t_env   *init_env_list(char **envp);
void    free_matrix(char **matrix);

#endif
