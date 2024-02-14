/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 14:35:35 by mbrousse          #+#    #+#             */
/*   Updated: 2024/02/14 15:59:56 by mbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_chec_mapc(char **tab)
{
	size_t y;
	size_t x;
	
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
	if ((ft_map_valid(slg, tab)) != 0)
		return (ft_freetab(tab), 1);
	return (ft_freetab(tab), 0);
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
	slg->py = 0;
	while (slg->map[slg->py] != NULL)
	{
		slg->px = 0;
		while (slg->map[slg->py][slg->px] != 0)
		{
			if (slg->map[slg->py][slg->px] == 'P')
				break;
			slg->px += 1; 
		}
		if (slg->map[slg->py][slg->px] == 'P')
				break;
		slg->py += 1;
	}
	if (ft_compo(slg) != 0)
		return (ft_putstr_fd("Error map compisition !!\n", 2));
	else if (ft_map_isrec(slg->map) != 0)
		return (ft_putstr_fd("Error map is not rectangular !!\n", 2));
	else if (ft_valid(slg) != 0)
		return (ft_putstr_fd("Error map validity !!\n", 2));
	else
		ft_printf("MAP IS OK\n");
}
