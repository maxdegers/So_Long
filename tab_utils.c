/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:14:00 by mbrousse          #+#    #+#             */
/*   Updated: 2024/02/05 11:37:17 by mbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static size_t	ft_get_map_size(char *map)
{
	int		fd;
	char	*line;
	size_t	size;

	fd = open(map, 0);
	if (fd < 0)
	{
		perror("Error opening file");
		exit (1);
	}
	size = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
		size++;
	}
	close(fd);
	return (size);
}

char	**ft_fill_tab(char *map)
{
	int		fd;
	char	**tab;
	size_t	size;
	size_t	i;

	i = 0;
	size = ft_get_map_size(map);
	fd = open(map, 0);
	tab = malloc(sizeof(char *) * (size + 1));
	if (!tab)
		return (NULL);
	while (1)
	{
		tab[i] = get_next_line(fd);
		if (!tab[i])
			break ;
		i++;
	}
	close(fd);
	if (i != size)
		return (NULL);
	return (tab);
}
