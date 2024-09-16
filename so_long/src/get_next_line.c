/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 04:06:00 by amdos-sa          #+#    #+#             */
/*   Updated: 2024/09/16 05:30:05 by amdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	handle_error(int fd, char *content)
{
	if (fd < 0)
	{
		perror("Error\n");
		exit(1);
	}
	if (content == NULL)
	{
		free(content);
		exit(1);
	}
}

static void	read_file_content(int fd, char **content)
{
	char	buffer[1025];
	int		bytes;

	bytes = read(fd, buffer, 1024);
	while (bytes > 0)
	{
		buffer[bytes] = '\0';
		*content = alocate_space(*content, buffer);
		bytes = read(fd, buffer, 1024);
	}
	if (bytes < 0)
		handle_error(fd, *content);
}

char	*get_nextline(char *str)
{
	char	*content;
	int		fd;

	content = 0;
	fd = open(str, O_RDONLY);
	read_file_content(fd, &content);
	handle_error(fd, content);
	close(fd);
	return (content);
}
