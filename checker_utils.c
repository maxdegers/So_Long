/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 14:33:16 by mbrousse          #+#    #+#             */
/*   Updated: 2024/02/07 15:39:30 by mbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_compo_chec(int *num, char c)
{
	if (c == 'P')
		num[0]++;
	if (c == 'C')
		num[1]++;
	if (c == 'E')
		num[2]++;
}

int	ft_map_wal(char **tab)
{
	size_t		y;
	long int	x;

	x = -1;
	while (tab[0][++x])
		if (tab[0][x] != '1' && tab[0][x] != '\n')
			return (1);
	y = 0;
	while (tab[y])
	{
		if (tab[y][0] != '1' || tab[y][ft_strlen(tab[y])- 2] != '1')
			return (1);
		y++;
	}
	y--;
	x = -1;
	while (tab[y][++x])
		if (tab[y][x] != '1' && tab[0][x] != '\n')
			return (1);
	return (0);
}

char **ft_clonemap(char **map)
{
	
}

int	ft_map_valid(char **map, char **mclone)
{
	
}
