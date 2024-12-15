#ifndef HEADER_H
# define HEADER_H

# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <signal.h>
# include <sys/stat.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../libx/libx.h"

typedef struct s_env
{
	char			*var;
	char			*value;
	int				exported;
	struct s_env	*next;
}	t_env;

typedef struct s_vars
{
	char			**env;
	char			**matrix;
	char			**args;
	char			**redic_filter;
	char			*input;
	char			*copy_input;
	char			*path;
	char			*home;
	char			**commands;
	size_t			cargs;
	int				terminal;
	int				exit_status;
	int				val_red;
	int				input_fd;
	int				fd[2];
	pid_t			pid;
	t_env			*env_ref;
}	t_vars;

void	start_promp(t_vars *vars);
void	append_output(char *file);
void	only_comands(t_vars *vars);
void	redirect_output(char *file);
void	read_readline(t_vars *vars);
void	build_builtins(t_vars *vars);
void	redirecionamento(t_vars *vars, int status);
void	redirect_herdoc(t_vars *vars, char *delimiter);
void	write_and_close(int fd);
void	write_heredoc(t_vars *vars, char *cmd, int fd);
void	free_convert_env_list(char **env);
void	free_env(t_env *env);
void	free_split(char **str);
void	execute_path(t_vars *vars);
void	ensure_term_variable(t_vars *vars);
void	execute_pipe(t_vars *vars);
void	cd(t_vars *vars);
void	pwd(t_vars *vars);
void	ft_exit(t_vars *vars);
void	echo(t_vars *vars);
void	remove_deli(char *s);
void	env(t_vars *vars);
void	ft_export(t_vars *vars, char **args);
void	print_env(t_env *env_list);
void	init_env(t_vars *vars);
void	add_and_update(t_env **env_list, char *var, char *value, int exported);
void	execute_command(t_vars *vars, char *command);
void	expand_exit_status(t_vars *vars);
char	*get_path(t_vars *vars);
char	*return_name(char *str);
char	**org_red(char *input);
char	*gen_tmpfile_name(int cmd_nbr);
char	*ler_arquivo(char *caminho_arquivo);
char	**create_args(char *input);
char	**convert_env_list(t_env *env_list);
char	**split_pipe(char *input);
char	*find_executable(char *command, char *path);
size_t	count_digit_base(unsigned long n, unsigned int base);
t_env	*creat_node(char *var, char *value);
t_env	*ft_unset(t_env *head, char **vars);
t_env	*sort_list(t_env *list);
int		redirect_input(char *file);
int		cheack_input_red(t_vars *vars, char *str, char **redic);
int		cheack_red(char *str);
int		count_args(char *input);
int		count_variables(char **environ);
int		is_valid_identifier(const char *var);
int		expand_var(t_vars *vars);
int		search_var(t_vars *vars, char *var, int *p, int len);
int		trigger_promp(int val);

#endif
