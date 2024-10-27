/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_shell.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcatete <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 09:13:32 by vcatete           #+#    #+#             */
/*   Updated: 2024/10/16 09:13:34 by vcatete          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_SHELL_H
# define MINI_SHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <limits.h>
# include <unistd.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <time.h>
# include <fcntl.h>
# include <term.h>
# include <signal.h>
# include <dirent.h>
# include <sys/wait.h>
# include <errno.h>

typedef struct s_command
{
	const char	*command;
	void		(*handler)(char *entrada);
	int			require_argument;
}	t_Command;

typedef struct s_prev
{
	char	*previous_dir;
}	t_prev;

// funções auxiliares

void	ft_putchar(char c);

char	*ft_strcpy(char *s1, char *s2);
char	*ft_strcat(char *s1, char *s2);
char	*ft_strstr(char *str, char *to_find);
char	*ft_strchr(char *s, int i);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strdup(char	*str);
char	**ft_split(char *str, char delimiter);
char	*ft_strtok(char *str, const char *delim);
char	**parse_input(char *input);
char	*ft_copiar(char *str2, char *str);
char	*epur(char *str);

int		count_spaces(char *str);
int		is_executable(char *path);
int		ft_strlen(const char *s);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, int n);
int		ft_access(const char *filename);

// redirecionamente de entrada e saída

void	handle_output_redirection(char *filename, int append);
void	handle_input_redirection(char *filename);
void	handle_heredoc(char *delimiter);
void	handle_fork(pid_t pid, char *filename, char *argv[4], int append);
void	handle_fork_2(pid_t pid, char *filename, char *argv[4]);
void	handle_fork_3(pid_t pid, char *filename, char *argv[4]);
void	execute_command_with_redirection(char *cmd);
void	redirect_function(int pid, char *filename, char **argv, char *cmd);
void	handle_replace_line(char *entrada);
void	handle_clear_history(char *entrada);

// executar comando com pipeline

void	handle_ls(char *entrada);
void	pipeline(int pipe_fd[], char **commands, int i, int fd_in);
void	execute_pipeline(char **commands);
void	execute_command_with_pipes(char *input);

//echo

void	handle_echo_2(char *entrada);
void	handle_echo(char *entrada);
void	handle_signal(int signo);
void	handle_signal_shell(char *entrada);

// variaveis de ambiente

void	handle_env(char	*entrada);
void	add_env_var(const char *name, const char *value, char **environ);
void	handle_setenv(char *entrada);
void	remove_env_var(char *name);
void	handle_unsetenv(char *entrada);

// cd

char	*handle_specific_dir(char *dir, char *temp_path);
void	handle_cd(char *entrada);

// funções de comandos

void	execute_command(char *entrada, t_Command commands[]);
void	much_command(char *entrada);
void	executar_comando(char *command, char *const argv[]);
void	command_init(t_Command commands[]);

#endif
