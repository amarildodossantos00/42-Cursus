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

static char *add_spaces_around_operators(const char *input) {
    const char *operators = "><";
    size_t len = strlen(input);
    char *output = malloc(len * 3 + 1); // Aloca mais espaço para os possíveis novos espaços
    int j = 0;

    for (size_t i = 0; i < len; i++) {
        if (strchr(operators, input[i])) { // Se o caractere for um operador
            if (j > 0 && output[j - 1] != ' ') // Adiciona espaço antes do operador
                output[j++] = ' ';
            output[j++] = input[i];
            if (input[i + 1] == input[i]) { // Trata operadores duplos como ">>" ou "<<"
                output[j++] = input[i++];
            }
            if (input[i + 1] != ' ') // Adiciona espaço depois do operador
                output[j++] = ' ';
        } else {
            output[j++] = input[i]; // Copia o caractere normal
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
    char *prev = NULL;

    while (token) {
        int is_operator = (strcmp(token, ">") == 0 || strcmp(token, "<") == 0 || 
                           strcmp(token, ">>") == 0 || strcmp(token, "<<") == 0);

        if (is_operator && prev) {
            char *next = strtok(NULL, " "); // Obtém o próximo token
            if (next) {
                char buffer[256];
                snprintf(buffer, sizeof(buffer), "%s %s %s", prev, token, next);

                result = realloc(result, (count + 1) * sizeof(char *));
                result[count++] = strdup(buffer);

                prev = next; // Atualiza prev para o último token
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

