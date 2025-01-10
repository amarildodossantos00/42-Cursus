#include "../../header/header.h"

void	cntrl_d(char *str, char *cmd, int fd)
{
	if (str == NULL)
	{
		write(2, "warning: here-document delimited by end (wanted `", 49);
		write(2, cmd, ft_strlen(cmd));
		write(2, "')\n", 3);
		close(fd);
		exit(0);
	}
}

void	cntrl_cntrl_c(int sig)
{
	g_sig = sig;
	write(1, "\n", 1);
	close(0);
}

void	write_heredoc(t_vars *vars, char *cmd, int fd)
{
	char	*line;

	while (1)
	{
		signal(SIGINT, cntrl_cntrl_c);
		line = readline("> ");
		cntrl_d(line, cmd, fd);
		if (ft_strcmp(line, cmd) == 0)
		{
			free(line);
			close(fd);
			exit (0);
		}
		if (g_sig == 2)
		{
			free(line);
			close(fd);
			exit(32);
		}
		write(fd, line, ft_strlen(line));
		write (fd, "\n", 1);
		free(line);
	}
}

int	free_and_return(char **news, int ret_value)
{
	free_split(news);
	return (ret_value);
}

int	cleanup_and_return(char **news, char *tmp_file, int ret_value)
{
	free(tmp_file);
	free_split(news);
	return (ret_value);
}
