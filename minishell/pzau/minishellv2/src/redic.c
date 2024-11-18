#include "../header/header.h"

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

void    redirect_herdoc(char *delimiter)
{
    int pipe_fd[2];
    char    buffer[1024];
    size_t	bytes_read;
    size_t	delimiter_len;

    delimiter_len = ft_strlen(delimiter);
    if (pipe(pipe_fd) < 0)
    {
        perror("pipe");
        return ;
    }
    while (1)
    {
        bytes_read = read(STDIN_FILENO, buffer, sizeof(buffer) - 1);
        if (bytes_read <= 0)
            break ;
        buffer[bytes_read] = '\0';
        if (ft_strncmp(buffer, delimiter, delimiter_len) == 0)
            break ;
        write(pipe_fd[1], buffer, bytes_read);
    }
    close(pipe_fd[1]);
    dup2(pipe_fd[0], STDIN_FILENO);
    close(pipe_fd[0]);
}

static char *add_spaces_around_operators(const char *input)
{
    const char *operators = "><";
    size_t len = strlen(input);
    char *output = malloc(len * 3 + 1);
    int j = 0;

    for (size_t i = 0; i < len; i++) {
        if (strchr(operators, input[i])) {
            if (j > 0 && output[j - 1] != ' ')
                output[j++] = ' ';
            output[j++] = input[i];
            if (input[i + 1] == input[i]) {
                output[j++] = input[i++];
            }
            if (input[i + 1] != ' ')
                output[j++] = ' ';
        } else {
            output[j++] = input[i];
        }
    }

    output[j] = '\0';
    return output;
}

char **org_red(const char *input)
{
    char **result = NULL;
    int count = 0;
    char *normalized_input = add_spaces_around_operators(input);
    char *input_copy = strdup(normalized_input);
    char *token = strtok(input_copy, " ");
    char *prev = NULL;

    while (token) {
        int is_operator = (strcmp(token, ">") == 0 || strcmp(token, "<") == 0 || 
                           strcmp(token, ">>") == 0 || strcmp(token, "<<") == 0);

        if (is_operator && prev) {
            char *next = strtok(NULL, " ");
            if (next) {
                char buffer[256];
                snprintf(buffer, sizeof(buffer), "%s %s %s", prev, token, next);

                result = realloc(result, (count + 1) * sizeof(char *));
                result[count++] = strdup(buffer);

                prev = next;
            }
        } else if (!is_operator) {
            prev = token;
        }

        token = strtok(NULL, " ");
    }

    result = realloc(result, (count + 1) * sizeof(char *));
    result[count] = NULL;

    free(input_copy);
    free(normalized_input);
    return result;
}

