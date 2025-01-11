#include "../../header/header.h"

void	handle_child_proces(t_vars *vars, char *str1, char *tmp_file)
{
	int	heredoc_fd;

	heredoc_fd = open(tmp_file, O_CREAT | O_RDWR | O_TRUNC, 0777);
	write_heredoc(vars, str1, heredoc_fd);
	exit(0);
}

int	handle_parent_proces(t_vars *vars, char *str1, int child)
{
	signal(SIGINT, SIG_IGN);
	waitpid(child, &vars->exit_status, 0);
	if (WIFEXITED(vars->exit_status))
	{
		vars->exit_status = WEXITSTATUS(vars->exit_status);
		if (vars->exit_status == 32)
		{
			vars->exit_status = 130;
			free(str1);
			return (1);
		}
	}
	else if (WIFSIGNALED(vars->exit_status))
		vars->exit_status = 128 + WTERMSIG(vars->exit_status);
	free(str1);
	return (0);
}

int	process_redirection(t_vars *vars, char *redirection, int index)
{
	char	**new;
	char	*tmp_file;
	char	*str1;
	int		child;

	new = ft_split_red(redirection);
	if (cheack_in_tree(redirection) == 1)
		return (free_and_return(new, 0));
	if (cheack_in_tree(redirection) == 2)
	{
		str1 = ft_space(new[1]);
		tmp_file = gen_tmpfile_name(index);
		child = fork();
		if (child == 0)
			handle_child_proces(vars, str1, tmp_file);
		if (handle_parent_proces(vars, str1, child))
			return (cleanup_and_return(new, tmp_file, 1));
		free(tmp_file);
	}
	free_split(new);
	return (0);
}

void	update_val_red(t_vars *vars, char **redic)
{
	int	i;

	i = 0;
	vars->val_red = 0;
	while (redic[i])
	{
		if (cheack_in_tree(redic[i]) == 2)
			vars->val_red = i;
		i++;
	}
}

int	cheack_input_red(t_vars *vars, char *str, char **redic)
{
	int	i;

	if (more_than_two(str))
		return (handle_syntax_error());
	i = 0;
	while (redic[i])
	{
		if (process_redirection(vars, redic[i], i))
			return (1);
		i++;
	}
	update_val_red(vars, redic);
	return (0);
}
