#include "../header/header.h"

// files 1
void    redirect_output(char *file)
{
    int fd;

    fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644); 
    if (fd < 0)
    {
        perror("open");
        return ;
    }
    dup2(fd, STDOUT_FILENO);
    close(fd);
}

void    append_output(char *file)
{
    int fd;

    fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (fd < 0)
    {
        perror("open");
        return ;
    }
    dup2(fd, STDOUT_FILENO);
    close(fd);
}

int    redirect_input(char *file)
{
    int     fd;

    if (access(file, F_OK) != 0)
        return (1);      
    if (access(file, R_OK) != 0)
        return (1);
    fd = open(file, O_RDONLY);
    if (fd < 0)
    {
        printf("open");
        return (2);
    }
    dup2(fd, STDIN_FILENO);
    close(fd);
    return (0);
}

//files 1

static char *add_spaces_around_operators(char *input)
{
    char *operators;
    size_t len;
    char *output;
    int j;
    int i;

    operators = "><";
    len = ft_strlen(input);
    output = malloc(len * 3 + 1);
    j = 0;
    i = 0;
    while (i < len)
    {
        if (ft_strchr(operators, input[i]))
        {
            if (j > 0 && output[j - 1] != ' ')
                output[j++] = ' ';
            output[j++] = input[i];
            if (input[i + 1] == input[i])
                output[j++] = input[i++];
            if (input[i + 1] != ' ')
                output[j++] = ' ';
        }
        else
            output[j++] = input[i];
        i++;
    }
    output[j] = '\0';
    return (output);
}

char **org_red(char *input)
{
    char **result;
    int count;
    char *normalized_input;
    char *input_copy;
    char *token;
    char buffer[256];
    int buffer_filled;
    char *prev;

    result = NULL;
    count = 0;
    normalized_input = add_spaces_around_operators(input);
    input_copy = ft_strdup(normalized_input);
    token = ft_strtok(input_copy, " ");
    ft_memset(buffer, 0, ft_strlen(buffer));
    buffer_filled = 0;
    prev = NULL;
    while (token)
    {
        int is_operator = (ft_strcmp(token, ">") == 0 || ft_strcmp(token, "<") == 0 || 
                           ft_strcmp(token, ">>") == 0 || ft_strcmp(token, "<<") == 0);
        if (is_operator)

        {
            if (prev)
            {
                result = realloc(result, (count + 1) * sizeof(char *));
                result[count++] = ft_strdup(buffer);
            }
            snprintf(buffer, sizeof(buffer), "%s", prev ? prev : "");
            strncat(buffer, " ", sizeof(buffer) - ft_strlen(buffer) - 1);
            strncat(buffer, token, sizeof(buffer) - ft_strlen(buffer) - 1);
            buffer_filled = 1;
        }
        else
        {
            if (buffer_filled)
            {
                strncat(buffer, " ", sizeof(buffer) - ft_strlen(buffer) - 1);
                strncat(buffer, token, sizeof(buffer) - ft_strlen(buffer) - 1);
            } else
            {
                snprintf(buffer, sizeof(buffer), "%s", token);
                buffer_filled = 1;
            }
        }

        prev = token;
        token = ft_strtok(NULL, " ");

        if (!token && buffer_filled)
        {
            result = realloc(result, (count + 1) * sizeof(char *));
            result[count++] = ft_strdup(buffer);
        }
    }

    result = realloc(result, (count + 1) * sizeof(char *));
    result[count] = NULL;

    free(input_copy);
    free(normalized_input);
    return result;
}

//files 3
static int more_than_two(char *new)
{
    int i;
    char *str;

    i = 0;
    str = ft_space(new);
    while (str[i])
    {
        if (str[i] == '>' && str[i + 1] == '>' && str[i + 2] == '>')
            return (1);
        if (str[i] == '<' && str[i + 1] == '<' && str[i + 2] == '<')
            return (1);
        i++;
    }
    free(str);
    return (0);
}

static int  cheack_in_tree(char *new)
{
    char    *str;
    int     i;

    i = 0;
    str = ft_space(new);
    while (str[i])
    {
        if (str[i] == '<' && str[i + 1] == '<' && str[i + 2] == '<')
            return (1);
        else if (str[i] == '<' && str[i + 1] == '<' && str[i + 2] != '<')
            return (2);
        i++;
    }
    free(str);
    return (0);
}

int    cheack_input_red(t_vars *vars, char *str, char **redic)
{
    int     i;
    char    *str1;
    char    **new;
    char    *tmp_file;
    int     heredoc_fd;

    if (more_than_two(str))
    {
        printf("minishell: syntax error near unexpected token `>'\n");
        return (1);
    }
    int child = fork();
    if (child == 0)
    {
        i = 0;
        while (redic[i])
        {
            new = ft_split_red(redic[i]);
            if (cheack_in_tree(redic[i]) == 1)
            {
                i++;
                continue ;
            }
            if (cheack_in_tree(redic[i]) == 2)
            {
                str1 = ft_space(new[1]);
                tmp_file = gen_tmpfile_name(i);
                heredoc_fd = open(tmp_file, O_CREAT | O_RDWR | O_TRUNC, 0777);
                write_heredoc(vars, str1, heredoc_fd);
                free(str1);
            }
            i++;
        }
        exit(0);
    }
    int status;
    wait(&status);
    i = 0;
    vars->val_red = 0;
    while (redic[i])
    {
        if (cheack_in_tree(redic[i]) == 2)
            vars->val_red = i;
        i++;
    }
    return (0);
}

void	write_heredoc(t_vars *vars, char *cmd, int fd)
{
	char			*line;
	unsigned int	size;

	line = readline("> ");
	while (ft_strcmp(line, cmd))
	{
		size = ft_strlen(line);
		if (size == 0)
			write(fd, "\n", 1);
		else
			write(fd, line, ft_strlen(line));
		free(line);
		line = readline("> ");
		if (!ft_strcmp(line, cmd))
		{
			free(line);
			write_and_close(fd);
			break ;
		}
	}
}
// files 3
