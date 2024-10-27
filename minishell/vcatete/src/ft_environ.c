/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_environ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcatete <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 07:56:15 by vcatete           #+#    #+#             */
/*   Updated: 2024/10/19 07:56:16 by vcatete          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

void	handle_env(char	*entrada)
{
	char		**env;
	extern char	**environ;

	(void)entrada;
	env = environ;
	while (*env)
	{
		printf("%s\n", *env);
		env++;
	}
}

void	add_env_var(const char *name, const char *value, char **environ)
{
	char		*new_var;
	size_t		len;
	int			i;

	len = ft_strlen(name);
	new_var = malloc(len + ft_strlen(value) + 2);
	ft_strcpy(new_var, (char *)name);
	ft_strcat(new_var, "=");
	ft_strcat(new_var, (char *)value);
	i = 0;
	while (environ[i] != NULL)
	{
		if (ft_strncmp(environ[i], name, len) == 0
			&& environ[i][len] == '=')
		{
			free(environ[i]);
			environ[i] = new_var;
			return ;
		}
		i++;
	}
	while (environ[i] != NULL)
		i++;
	environ[i] = new_var;
	environ[i + 1] = NULL;
}

void	handle_setenv(char *entrada)
{
	char		*str;
	extern char	**environ;
	int			i;
	int			j;

	i = 6;
	j = 0;
	while (entrada[i] == 32)
		i++;
	while (entrada[i] != 61 && entrada[i++])
		j++;
	str = (char *)malloc(sizeof(char) * (j + 1));
	i = i - j;
	j = 0;
	while (entrada[i] != 61 && entrada[i])
		str[j++] = entrada[i++];
	str[j] = '\0';
	add_env_var(str, &entrada[i + 1], environ);
	free(str);
}

void	remove_env_var(char *name)
{
	extern char	**environ;
	size_t		len;
	int			i;
	int			j;

	len = ft_strlen(name);
	i = 0;
	while (environ[i] != NULL)
	{
		if (ft_strncmp(environ[i], name, len) == 0
			&& environ[i][len] == '=')
		{
			j = i;
			while (environ[j] != NULL)
			{
				environ[j] = environ[j + 1];
				j++;
			}
			return ;
		}
		i++;
	}
}

void	handle_unsetenv(char *entrada)
{
	int	i;

	i = 8;
	while (entrada[i] == 32)
		i++;
	remove_env_var(&entrada[i]);
}
