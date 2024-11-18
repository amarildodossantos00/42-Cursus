#include "../header/header.h"

void    free_env_node(t_env *node)
{
    if (node)
    {
        free(node->var);
        free(node->value);
        free(node);
    }
}

t_env   *unset_env(t_env *head, const char *var)
{
    t_env   *current;
    t_env   *previous;

    current = head;
    previous = NULL;
    if (!head || !var)
    {
        printf("unset: parametros invalidos\n");
        return (head);
    }
    while (current)
    {
        if (strcmp(current->var, var) == 0)
        {
            if (previous)
                previous->next = current->next;
            else
                head = current->next;
            free_env_node(current);
            return (head);
        }
        previous = current;
        current = current->next;
    }
    return (head);
}

t_env   *add_env(t_env *head, const char *var, const char *value)
{
    t_env   *new_node;

    new_node = malloc(sizeof(t_env));
    if (!new_node)
        return (head);
    new_node->var = strdup(var);
    new_node->value = strdup(value);
    new_node->next = head;
    return (new_node);
}

t_env   *init_env_list(char **envp)
{
    t_env   *env_list;
    int i;

    i = 0;
    env_list = NULL;
    while (envp[i])
    {
        char    *env_entry;
        env_entry = strdup(envp[i]);
        if (!env_entry)
        {
            perror("erro ao duplicar variavel de ambiente");
            exit(EXIT_FAILURE);
        }
        char    *var;
        char    *value;
        var = strtok(env_entry, "=");
        value = strtok(NULL, "\0");
        env_list = add_env(env_list, var, value ? value : "");
        i++;
    }
    return (env_list);
}

void    free_matrix(char **matrix)
{
    int i;

    i = 0;
    while (matrix && matrix[i])
    {
        free(matrix[i]);
        i++;
    }
    free(matrix);
}
