/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 14:59:19 by amdos-sa          #+#    #+#             */
/*   Updated: 2024/09/18 15:40:04 by amdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

char	*ft_strdup(char *src)
{
	char	*dest;
	int	len;

	len = 0;
	while (src[len])
		len++;
	dest = malloc(sizeof(char) * (len + 1));
	if (dest)
	{
		len = -1;
		while (src[++len])
			dest[len] = src[len];
		dest[len] = '\0';
		return (dest);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	char		line[70000];
	static int	buffer_size;
	static int	buffer_pos;
	int		i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		if (buffer_pos >= buffer_size)
		{
			buffer_size = read(fd, buffer, BUFFER_SIZE);
			buffer_pos = 0;
			if (buffer_size <= 0)
				break ;
		}
		line[i++] = buffer[buffer_pos++];
		if (line[i - 1] == '\n')
			break ;
	}
	line[i] = '\0';
	if (i == 0)
		return (NULL);
	return (ft_strdup(line));

}
