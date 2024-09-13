/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 08:43:38 by amdos-sa          #+#    #+#             */
/*   Updated: 2024/09/13 10:19:37 by amdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*alocate_space(char *save, char *buffer)
{
	char	*dest;

	if (save == NULL)
		dest = ft_strdup(buffer);
	else
		dest = ft_strcat(save, buffer);
	return (dest);
}

char	*get_next_line(char *filename)
{
	char	buffer[1025];
	char	*save;
	int	fd;
	int	bytes;


	save = NULL;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror("Error\n");
		exit(1);
	}
	bytes = read(fd, buffer, 1024);
	while (bytes > 0)
	{
		buffer[bytes] = '\0';
		save = alocate_space(save, buffer);
		bytes = read(fd, buffer, 1024);
	}
	close(fd);
	if (bytes < 0 || save == NULL)
	{
		free(save);
		exit(1);
	}
	printf("%s", save);
	return (save);
}

char	**print_map(char *str)
{
	char	*read_get;
	char	**matrix;

	read_get = get_next_line(str);
	matrix = NULL;
	//matrix = ft_split(read_get);
	free(read_get);
	return (matrix);
}
