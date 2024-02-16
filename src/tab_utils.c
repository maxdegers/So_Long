/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:14:00 by mbrousse          #+#    #+#             */
/*   Updated: 2024/02/16 18:05:33 by mbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static size_t	ft_get_map_size(char *map)
{
	int		fd;
	char	line[1024];
	size_t	size;
	ssize_t	sz;

	fd = open(map, 0);
	if (fd < 0)
	{
		perror("Error opening file");
		exit (1);
	}
	size = 0;
	sz = 1;
	while (sz > 0)
	{
		sz = read(fd, line, 1024);
		if (sz == -1)
			ft_perror();
		size += sz;
	}
	close(fd);
	return (size);
}

void	ft_nl_chec(char *line)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (line[i] == '\n' && line[i + 1] == '\n')
		{
			free(line);
			ft_putstr_fd("Error : MAP COMPO !!\n", 2);
			exit(1);
		}
	}
}

char	**ft_fill_tab(char *map)
{
	int		fd;
	char	**tab;
	char	*line;
	size_t	size;
	int		i;

	size = ft_get_map_size(map);
	line = ft_calloc(size + 1, sizeof(char));
	fd = open(map, 0);
	i = read(fd, line, size);
	close(fd);
	if (i == -1)
	{
		free(line);
		ft_perror();
	}
	ft_nl_chec(line);
	tab = ft_split(line, '\n');
	if (!tab)
	{
		ft_freetab(tab);
		ft_perror();
	}
	return (free(line), tab);
}
