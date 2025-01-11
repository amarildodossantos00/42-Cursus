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

extern int	g_sig;

typedef struct s_process_context
{
	char		***result;
	char		*buffer;
	int			*count;
}	t_process_context;

typedef struct s_env
{
	int				count;
	int				index;
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
	char			*pos;
	char			*new_input;
	char			*exit;
	char			*temp;
	char			*aux;
	char			*input_copy;
	char			*start;
	char			*result;
	char			*var_name;
	char			*env_value;
	char			*dir;
	char			*executable;
	char			*path_copy;
	char			*executablee;
	char			*new_strr;
	char			*str_space;
	char			*str_split;
	char			**command;
	char			**envv;
	char			**argss;
	char			**commands;
	size_t			cargs;
	size_t			i;
	int				in;
	int				j;
	int				in_single_quote;
	int				in_double_quote;
	int				var_len;
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
void	cntrl_cntrl_c(int sig);
void	init_values(t_vars *vars);
void	cntrl_d(char *str, char *cmd, int fd);
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
void	wait_for_children(int num_cmds);
void	execute_child(t_vars *vars, int index);
void	ft_exit(t_vars *vars);
void	echo(t_vars *vars);
void	remove_deli(char *s);
void	env(t_vars *vars);
void	ft_export(t_vars *vars, char **args);
void	handle_empty_input(t_vars *vars);
void	print_env(t_env *env_list);
void	init_env(t_vars *vars);
void	process_ev_aux(t_vars *vars);
void	process_non_operator(t_process_context *ctx, \
		char *token, int *buffer_filled);
void	process_operator(t_process_context *ctx, char *prev, char *token);
void	init_context(t_process_context *ctx, char ***result, int *count);
void	add_operator_space(char *input, char *output, int *i, int *j);
void	add_and_update(t_env **env_list, char *var, char *value, int exported);
void	execute_command(t_vars *vars, char *command);
void	expand_exit_status(t_vars *vars);
void	remove_qou_aux(t_vars *vars, char *input);
void	expand_no_env(char **str, char *var_name, int *i);
void	process_tokens(char ***result, int *count, char *input_copy);
void	finalize_buffer(t_process_context *ctx, int buffer_filled);
void	free_process_red(char *str_space, char **command);
void	remove_qou_aux1(t_vars *vars);
void	atualizar_input(t_vars *vars, char **redic);
void	handle_invalid_identifier(t_vars *vars, \
		char *arg, char *var, char *value);
void	extract_var_value(char *arg, char **var, char **value);
void	ft_export(t_vars *vars, char **args);
void	process_token(t_process_context *ctx, \
		char *token, char **prev, int *buffer_filled);
char	*get_path(t_vars *vars);
char	*return_name(char *str);
char	**org_red(char *input);
char	*gen_tmpfile_name(int cmd_nbr);
char	*concatenar_strs(char *str, char **commandv2);
char	*processar_redirecionamento(char *input, char **redic);
char	*add_spaces_around_operators(char *input);
char	*ler_arquivo(char *caminho_arquivo);
char	**create_args(t_vars *vars, char *input, size_t k);
char	**convert_env_list(t_env *env_list);
char	**split_pipe(char *input);
char	*ft_var_name(char *str, int n);
char	*remove_quotes(char *input, t_vars *vars);
char	*find_executable(char *command, char *path, t_vars *vars);
size_t	count_digit_base(unsigned long n, unsigned int base);
t_env	*creat_node(char *var, char *value);
t_env	*ft_unset(t_env *head, char **vars);
t_env	*sort_list(t_env *list);
int		redirect_input(char *file);
int		check_on(t_vars *vars);
int		count_dollar(t_vars *vars);
int		free_and_return(char **news, int ret_value);
int		cleanup_and_return(char **news, char *tmp_file, int ret_value);
int		handle_syntax_error(void);
int		cheack_input_red(t_vars *vars, char *str, char **redic);
int		executar_redic(t_vars *vars, char *redic, char *str_space);
int		cheack_red(char *str);
int		check_one_red(char **str);
int		more_than_two(char *news);
int		cheack_in_tree(char *news);
int		count_args(char *input);
int		process_input(t_vars *vars);
int		count_variables(char **environ);
int		is_valid_identifier(const char *var);
int		expand_var(t_vars *vars);
int		is_special(char c);
int		is_delimiter(char c);
int		process_env_variable(char *input, char **result, int *i, int *j);
int		search_var(t_vars *vars, char *var, int *p, int len);
int		cheack_build_builtins(t_vars *vars);
int		trigger_promp(int val);
int		get_exit_status(t_vars *vars);
int		count_commands(char **commands);
int		handle_redirection(t_vars *vars, int index);

#endif
