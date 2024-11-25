#include "../header/header.h"

char	*get_path(t_vars *vars)
{
    t_env *current;

    if (!vars->env_ref)
    {
        init_env(vars);
    }
    current = vars->env_ref;
    while (current)
    {
        if (strcmp(current->var, "PATH") == 0)
            return current->value;
        current = current->next;
    }
    return "nothing";
}

/*1: Verificar a presença da variável TERM
Adicionamos a função ensure_term_variable, que percorre a lista de variáveis de ambiente (t_env) e verifica se a variável TERM já está configurada:*/
void ensure_term_variable(t_vars *vars)
{
	t_env *current = vars->env_ref;

	while (current)
	{
		if (ft_strncmp(current->var, "TERM", 4) == 0)
			return; // TERM já está configurada
		current = current->next;
	}

	// Se não encontrar, adiciona TERM manualmente
	add_and_update(&vars->env_ref, "TERM", "xterm-256color");
}

/*2: Converter a lista de variáveis para o formato do sistema
A lista de variáveis de ambiente, que é gerenciada como uma lista encadeada (t_env), precisa ser convertida para um array de strings no formato esperado pelo sistema (ex.: "VAR=valor"). A função convert_env_list faz isso:*/
char **convert_env_list(t_env *env_list)
{
	int count = 0;
	t_env *current = env_list;
	char **env;
	char *temp;

	// Contar número de variáveis no ambiente
	while (current)
	{
		count++;
		current = current->next;
	}

	// Alocar espaço para o array de strings
	env = malloc(sizeof(char *) * (count + 1));
	if (!env)
		return (NULL);

	// Preencher o array de strings
	current = env_list;
	count = 0;
	while (current)
	{
		temp = ft_strjoin(current->var, "=");
		env[count] = ft_strjoin(temp, current->value);
		free(temp);
		current = current->next;
		count++;
	}
	env[count] = NULL;

	return (env);
}
