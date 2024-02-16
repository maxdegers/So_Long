/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 14:35:35 by mbrousse          #+#    #+#             */
/*   Updated: 2024/02/16 18:06:35 by mbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_chec_mapc(char **tab)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (tab[y])
	{
		x = 0;
		while (tab[y][x])
		{
			if ((tab[y][x] == '0') || (tab[y][x] == 'P')
				|| (tab[y][x] == 'C') || (tab[y][x] == 'E'))
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

static int	ft_compo(t_map_i *slg)
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
				&& (tab[y][x] != 'C') && (tab[y][x] != 'E'))
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

static int	ft_valid(t_map_i *slg)
{
	char	**tab;

	tab = ft_clonemap(slg->map);
	if (!tab)
		return (1);
	if ((ft_map_valid(slg, tab)) != 0)
		return (ft_freetab(tab), 1);
	return (ft_freetab(tab), 0);
}

static int	ft_map_isrec(char **tab, t_vars *slg)
{
	size_t	size_l;
	size_t	size_c;

	size_l = ft_strlen(tab[0]);
	size_c = 0;
	while (tab[size_c])
	{
		if ((ft_strlen(tab[size_c])) != size_l)
			return (1);
		size_c++;
	}
	slg->map_i->ch = size_c;
	slg->map_i->cw = size_l;
	slg->map_i->exit = -1;
	slg->map_i->cmoves = 0;
	return (0);
}

void	ft_checker(t_map_i *map_i, t_vars *slg)
{
	map_i->ccnt = 0;
	map_i->ecnt = 0;
	map_i->pcnt = 0;
	map_i->py = 0;
	while (map_i->map[map_i->py] != NULL)
	{
		map_i->px = 0;
		while (map_i->map[map_i->py][map_i->px] != 0)
		{
			if (map_i->map[map_i->py][map_i->px] == 'P')
				break ;
			map_i->px += 1;
		}
		if (map_i->map[map_i->py][map_i->px] == 'P')
			break ;
		map_i->py += 1;
	}
	if (ft_compo(map_i) != 0)
		return (ft_putstr_fd("Error map compisition  1!!\n", 2));
	else if (ft_map_isrec(map_i->map, slg) != 0)
		return (ft_putstr_fd("Error map is not rectangular 2!!\n", 2));
	else if (ft_valid(map_i) != 0)
		return (ft_putstr_fd("Error map validity 3!!\n", 2));
	else
		ft_printf("MAP IS OK\n");
}
