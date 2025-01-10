#include "../../header/header.h"

void	process_tokens(char ***result, int *count, char *input_copy)
{
	t_process_context	ctx;
	char				*token;
	char				*prev;
	int					buffer_filled;

	init_context(&ctx, result, count);
	buffer_filled = 0;
	token = ft_strtok(input_copy, " ");
	prev = NULL;
	while (token)
	{
		process_token(&ctx, token, &prev, &buffer_filled);
		token = ft_strtok(NULL, " ");
	}
	finalize_buffer(&ctx, buffer_filled);
	free(ctx.buffer);
}

char	**org_red(char *input)
{
	char	**result;
	char	*normalized_input;
	char	*input_copy;
	int		count;

	result = NULL;
	normalized_input = add_spaces_around_operators(input);
	input_copy = ft_strdup(normalized_input);
	count = 0;
	process_tokens(&result, &count, input_copy);
	result = realloc(result, (count + 1) * sizeof(char *));
	result[count] = NULL;
	free(input_copy);
	free(normalized_input);
	return (result);
}

int	more_than_two(char *news)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_space(news);
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

int	cheack_in_tree(char *news)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_space(news);
	while (str[i])
	{
		if (str[i] == '<' && str[i + 1] == '<' && str[i + 2] == '<')
		{
			free(str);
			return (1);
		}
		else if (str[i] == '<' && str[i + 1] == '<' && str[i + 2] != '<')
		{
			free(str);
			return (2);
		}
		i++;
	}
	free(str);
	return (0);
}

int	handle_syntax_error(void)
{
	printf("minishell: syntax error near unexpected token `>'\n");
	return (1);
}
