/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:01:45 by mbrousse          #+#    #+#             */
/*   Updated: 2024/01/29 15:07:05 by mbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*read_file(int fd, char *line, char *buffer)
{
	ssize_t	r;

	r = 1;
	while (r && ft_strchr_gnl(line, '\n') == 0)
	{
		r = read(fd, buffer, BUFFER_SIZE);
		if (r == -1)
			return (buffer[0] = 0, free(line), NULL);
		buffer[r] = '\0';
		line = ft_strjoin_f(line, buffer);
		if (!line)
			return (NULL);
	}
	return (line);
}

static void	ft_buffer_next(char *buffer)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (buffer[i] != '\n' && buffer[i])
		i++;
	if (buffer[i] == '\n')
		i++;
	j = 0;
	while (buffer[i + j])
	{
		buffer[j] = buffer[i + j];
		j++;
	}
	buffer[j] = '\0';
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1] = "\0";
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (buffer[0] = 0, NULL);
	line = ft_strdup_gnl(buffer);
	if (!line)
		return (NULL);
	line = read_file(fd, line, buffer);
	if (!line)
		return (NULL);
	ft_buffer_next(buffer);
	if (line[0] == '\0')
		return (free(line), NULL);
	return (line);
}
