/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 14:35:41 by mbrousse          #+#    #+#             */
/*   Updated: 2024/01/29 15:00:20 by mbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    ft_getmap(char *map)
{
	int		fd;
	char	*line;

	fd = open(map, 0);
	if (fd < 0)
	{
		perror("Error opening file");
		return ;
	}
	line = get_next_line(fd);
	ft_printf("%s", line);
	free(line);
	line = get_next_line(fd);
	ft_printf("%s", line);
	free(line);
	close(fd);
}

int main(int argc, char **argv)
{
	if (argc != 2)
		return (0);
	ft_getmap(argv[1]);
	return (0);
}
