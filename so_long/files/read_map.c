/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 13:10:02 by cramos            #+#    #+#             */
/*   Updated: 2024/09/05 02:33:55 by cramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*new_read(char *new_read, char *buffer)
{
	char	*new_new_read;
	char	*temp;

	temp = new_read;
	if (new_read == NULL)
		new_new_read = ft_strdup(buffer);
	else
		new_new_read = ft_strcat(new_read, buffer);
	if (temp)
		free(temp);
	return (new_new_read);
}

char	*read_files(char *file_name)
{
	char	buffer[1025];
	char	*all_read;
	char	*temp;
	int		quanty;
	int		fd;

	all_read = NULL;
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		rest_read();
	quanty = read(fd, buffer, sizeof(buffer) - 1);
	while (quanty > 0)
	{
		buffer[quanty] = '\0';
		all_read = new_read(all_read, buffer);
		quanty = read(fd, buffer, sizeof(buffer) - 1);
	}
	close(fd);
	if (quanty < 0 || all_read == NULL)
	{
		free(all_read);
		exit(1);
	}
	return (all_read);
}

char	**save_maps(char *file_name)
{
	char	*count;
	char	**map;

	count = read_files(file_name);
	if (!valid_file(count))
	{
		ft_printf("\nError\nINVALID MAP!!\n");
		free(count);
		exit(1);
	}
	map = ft_split(count);
	free(count);
	return (map);
}

void	screen_value(t_vars *vars, int fd)
{
	char	buffer;
	int		altura;
	int		largura;
	int		botton;

	altura = 0;
	largura = 0;
	botton = 0;
	vars->res_altura = 0;
	vars->res_largura = 0;
	while (read(fd, &buffer, 1) != 0)
	{
		if (buffer != '\n')
		{
			if (botton == 0)
				largura++;
		}
		if (buffer == '\n')
		{
			botton = 10;
			altura++;
		}
	}
	vars->res_altura = altura;
	vars->res_largura = largura;
}

void	dimen(t_vars *vars, char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		exit(1);
	screen_value(vars, fd);
	close(fd);
	return ;
}
