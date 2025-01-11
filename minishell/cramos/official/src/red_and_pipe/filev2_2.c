#include "../../header/header.h"

void	process_operator(t_process_context *ctx,
	char *prev, char *token)
{
	if (prev)
	{
		*(ctx->result) = realloc(*(ctx->result),
				(*(ctx->count) + 1) * sizeof(char *));
		(*(ctx->result))[(*(ctx->count))++] = ft_strdup(ctx->buffer);
	}
	if (prev)
		snprintf(ctx->buffer, 256, "%s", prev);
	else
		snprintf(ctx->buffer, 256, "%s", "");
	strncat(ctx->buffer, " ", 256 - ft_strlen(ctx->buffer) - 1);
	strncat(ctx->buffer, token, 256 - ft_strlen(ctx->buffer) - 1);
}

void	process_non_operator(t_process_context *ctx,
	char *token, int *buffer_filled)
{
	if (*buffer_filled)
	{
		strncat(ctx->buffer, " ", 256 - ft_strlen(ctx->buffer) - 1);
		strncat(ctx->buffer, token, 256 - ft_strlen(ctx->buffer) - 1);
	}
	else
	{
		snprintf(ctx->buffer, 256, "%s", token);
		*buffer_filled = 1;
	}
}

void	init_context(t_process_context *ctx, char ***result, int *count)
{
	ctx->result = result;
	ctx->count = count;
	ctx->buffer = malloc(256);
	ft_memset(ctx->buffer, 0, 256);
}

void	process_token(t_process_context *ctx,
	char *token, char **prev, int *buffer_filled)
{
	int	is_operator;

	is_operator = (ft_strcmp(token, ">") == 0 || ft_strcmp(token, "<") == 0
			|| ft_strcmp(token, ">>") == 0 || ft_strcmp(token, "<<") == 0);
	if (is_operator)
	{
		process_operator(ctx, *prev, token);
		*buffer_filled = 1;
	}
	else
		process_non_operator(ctx, token, buffer_filled);
	*prev = token;
}

void	finalize_buffer(t_process_context *ctx, int buffer_filled)
{
	if (buffer_filled)
	{
		*(ctx->result) = realloc(*(ctx->result),
				(*(ctx->count) + 1) * sizeof(char *));
		(*(ctx->result))[(*(ctx->count))++] = ft_strdup(ctx->buffer);
	}
}
