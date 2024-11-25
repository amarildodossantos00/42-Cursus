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
//files 1


/*files 2
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
//file 2*/

static char *add_spaces_around_operators(const char *input)
{
    const char *operators = "><";
    size_t len = strlen(input);
    char *output = malloc(len * 3 + 1); // Aloca espaço extra para os novos espaços
    int j = 0;

    for (size_t i = 0; i < len; i++) {
        if (strchr(operators, input[i])) { // Detecta operadores
            if (j > 0 && output[j - 1] != ' ') // Adiciona espaço antes
                output[j++] = ' ';
            output[j++] = input[i];
            if (input[i + 1] == input[i]) { // Detecta operadores duplos
                output[j++] = input[i++];
            }
            if (input[i + 1] != ' ') // Adiciona espaço depois
                output[j++] = ' ';
        } else {
            output[j++] = input[i]; // Copia caracteres normais
        }
    }

    output[j] = '\0';
    return output;
}

char **org_red(const char *input)
{
    char **result = NULL;
    int count = 0;
    char *normalized_input = add_spaces_around_operators(input); // Normaliza a entrada
    char *input_copy = strdup(normalized_input); // Cria uma cópia da entrada normalizada
    char *token = strtok(input_copy, " ");
    char buffer[256] = {0}; // Buffer para manter o grupo atual
    int buffer_filled = 0;  // Indica se o buffer já está preenchido
    char *prev = NULL;      // Armazena o último argumento ou operador

    while (token) {
        int is_operator = (strcmp(token, ">") == 0 || strcmp(token, "<") == 0 || 
                           strcmp(token, ">>") == 0 || strcmp(token, "<<") == 0);

        if (is_operator) {
            if (prev) {
                result = realloc(result, (count + 1) * sizeof(char *));
                result[count++] = strdup(buffer); // Armazena o grupo atual
            }
            snprintf(buffer, sizeof(buffer), "%s", prev ? prev : ""); // Reinicia o buffer
            strncat(buffer, " ", sizeof(buffer) - strlen(buffer) - 1);
            strncat(buffer, token, sizeof(buffer) - strlen(buffer) - 1);
            buffer_filled = 1;
        } else {
            if (buffer_filled) {
                strncat(buffer, " ", sizeof(buffer) - strlen(buffer) - 1);
                strncat(buffer, token, sizeof(buffer) - strlen(buffer) - 1);
            } else {
                snprintf(buffer, sizeof(buffer), "%s", token); // Inicia o primeiro grupo
                buffer_filled = 1;
            }
        }

        prev = token; // Atualiza o último token processado
        token = strtok(NULL, " ");

        if (!token && buffer_filled) { // Se é o último grupo
            result = realloc(result, (count + 1) * sizeof(char *));
            result[count++] = strdup(buffer); // Armazena o último grupo
        }
    }

    result = realloc(result, (count + 1) * sizeof(char *));
    result[count] = NULL;

    free(input_copy);
    free(normalized_input);
    return result;
}

//file 2 test

//file 2 test

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
        if (str[i] == '<' && str[i + 1] == '<' && str[i + 2] != '<')
            return (2);
        i++;
    }
    free(str);
    return (0);
}

int    cheack_input_red(t_vars *vars, char *str, char **redic)
{
    //int     i;
    char    *str1;
    //char    **new;

    if (more_than_two(str))
    {
        printf("minishell: syntax error near unexpected token `>'\n");
        return (1);
    }
    //i = 0;
    /*while (redic[i])
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
            redirect_herdoc(str1);
            free(str1);
        }
        i++;
    }*/
}
// files 3
