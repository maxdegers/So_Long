/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 14:35:35 by mbrousse          #+#    #+#             */
/*   Updated: 2024/02/13 15:29:53 by mbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h" 
 
static int	ft_compo(char **tab)
{
	int	x;
	int	y;
	int	num[3];

	y = 0;
	num[0] = 0;
	num[1] = 0;
	num[2] = 0;
	while (tab[y])
	{
		x = 0;
		while (tab[y][x])
		{
			if ((tab[y][x] != '0') && (tab[y][x] != '1') && (tab[y][x] != 'P')
				&& (tab[y][x] != 'C') && (tab[y][x] != 'E')
				&& (tab[y][x] != '\n'))
				return (1);
			ft_compo_chec(num, tab[y][x]);
			x++;
		}
		y++;
	}
	if (num[0] != 1 || num[1] < 1 || num[2] != 1)
		return (1);
	return (ft_map_wal(tab));
}

static int	ft_valid(char **map)
{
	char	**tab;

	tab = ft_clonemap(map);
	if (!tab)
		return (1);
	print_tab(tab);
	// if ((ft_map_valid(map, tab)) != 0);
	// 	return (1);
	ft_freetab(tab);
	return (0);
}

static int	ft_map_isrec(char **tab)
{
	size_t	i;
	size_t	size_l;
	size_t	size_c;

	i = -1;
	size_l = ft_strlen(tab[0]);
	size_c = 0;
	while (tab[++i])
	{
		if ((ft_strlen(tab[i])) != size_l)
			return (1);
		size_c++;
	}
	return (0);
}

void	ft_checker(char **tab)
{
	if (ft_compo(tab) != 0)
		return (perror("Error map compisition !!\n"));
	else if (ft_map_isrec(tab) != 0)
		return (perror("Error map is not rectangular !!\n"));
	else if (ft_valid(tab) != 0)
		return (perror("Error map validity !!\n"));
	else
		ft_printf("MAP IS OK\n");
}