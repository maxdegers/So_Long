/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 14:35:35 by mbrousse          #+#    #+#             */
/*   Updated: 2024/02/13 16:58:53 by mbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
 
static int	ft_compo(t_slg *slg)
{
	int		x;
	int		y;
	char	**tab;

	tab = slg->map;
	y = 0;
	while (tab[y])
	{
		x = 0;
		while (tab[y][x])
		{
			if ((tab[y][x] != '0') && (tab[y][x] != '1') && (tab[y][x] != 'P')
				&& (tab[y][x] != 'C') && (tab[y][x] != 'E')
				&& (tab[y][x] != '\n'))
				return (1);
			ft_compo_chec(slg, tab[y][x]);
			x++;
		}
		y++;
	}
	if (slg->ecnt != 1 || slg->ccnt < 1 || slg->pcnt != 1)
		return (1);
	return (ft_map_wal(slg->map));
}

static int	ft_valid(t_slg *slg)
{
	char	**tab;

	tab = ft_clonemap(slg->map);
	if (!tab)
		return (1);
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

void	ft_checker(t_slg *slg)
{
	slg->ccnt = 0;
	slg->ecnt = 0;
	slg->pcnt = 0;
	if (ft_compo(slg) != 0)
		return (ft_putstr_fd("Error map compisition !!\n", 2));
	else if (ft_map_isrec(slg->map) != 0)
		return (ft_putstr_fd("Error map is not rectangular !!\n", 2));
	else if (ft_valid(slg) != 0)
		return (ft_putstr_fd("Error map validity !!\n", 2));
	else
		ft_printf("MAP IS OK\n");
}