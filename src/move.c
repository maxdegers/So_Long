/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 17:39:17 by mbrousse          #+#    #+#             */
/*   Updated: 2024/02/16 18:08:48 by mbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_move_u(t_vars *slg)
{
	char	tmp;

	tmp = slg->map_i->map[slg->map_i->py - 1][slg->map_i->px];
	if (tmp == '1')
		return ;
	else
	{
		slg->map_i->map[slg->map_i->py - 1][slg->map_i->px] = 'P';
		if (slg->map_i->exit == 1)
		{
			slg->map_i->map[slg->map_i->py][slg->map_i->px] = 'E';
			slg->map_i->exit = 0;
		}
		else
			slg->map_i->map[slg->map_i->py][slg->map_i->px] = '0';
		slg->map_i->py -= 1;
		if (tmp == 'C')
			slg->map_i->ccnt -= 1;
		if (tmp == 'E' && slg->map_i->ccnt != 0)
			slg->map_i->exit = 1;
		if (tmp == 'E' && slg->map_i->ccnt == 0)
			slg->map_i->ecnt -= 1;
	}
	ft_printf("Number of Movements : %i\n", ++slg->map_i->cmoves);
}

void	ft_move_d(t_vars *slg)
{
	char	tmp;

	tmp = slg->map_i->map[slg->map_i->py + 1][slg->map_i->px];
	if (tmp == '1')
		return ;
	else
	{
		slg->map_i->map[slg->map_i->py + 1][slg->map_i->px] = 'P';
		if (slg->map_i->exit == 1)
		{
			slg->map_i->map[slg->map_i->py][slg->map_i->px] = 'E';
			slg->map_i->exit = 0;
		}
		else
			slg->map_i->map[slg->map_i->py][slg->map_i->px] = '0';
		slg->map_i->py += 1;
		if (tmp == 'C')
			slg->map_i->ccnt -= 1;
		if (tmp == 'E' && slg->map_i->ccnt != 0)
			slg->map_i->exit = 1;
		if (tmp == 'E' && slg->map_i->ccnt == 0)
			slg->map_i->exit -= 1;
	}
	ft_printf("Number of Movements : %i\n", ++slg->map_i->cmoves);
}

void	ft_move_l(t_vars *slg)
{
	char	tmp;

	tmp = slg->map_i->map[slg->map_i->py][slg->map_i->px - 1];
	if (tmp == '1')
		return ;
	else
	{
		slg->map_i->map[slg->map_i->py][slg->map_i->px - 1] = 'P';
		if (slg->map_i->exit == 1)
		{
			slg->map_i->map[slg->map_i->py][slg->map_i->px] = 'E';
			slg->map_i->exit = 0;
		}
		else
			slg->map_i->map[slg->map_i->py][slg->map_i->px] = '0';
		slg->map_i->px -= 1;
		if (tmp == 'C')
			slg->map_i->ccnt -= 1;
		if (tmp == 'E' && slg->map_i->ccnt != 0)
			slg->map_i->exit = 1;
		if (tmp == 'E' && slg->map_i->ccnt == 0)
			slg->map_i->exit -= 1;
	}
	ft_printf("Number of Movements : %i\n", ++slg->map_i->cmoves);
}

void	ft_move_r(t_vars *slg)
{
	char	tmp;

	tmp = slg->map_i->map[slg->map_i->py][slg->map_i->px + 1];
	if (tmp == '1')
		return ;
	else
	{
		slg->map_i->map[slg->map_i->py][slg->map_i->px + 1] = 'P';
		if (slg->map_i->exit == 1)
		{
			slg->map_i->map[slg->map_i->py][slg->map_i->px] = 'E';
			slg->map_i->exit = 0;
		}
		else
			slg->map_i->map[slg->map_i->py][slg->map_i->px] = '0';
		slg->map_i->px += 1;
		if (tmp == 'C')
			slg->map_i->ccnt -= 1;
		if (tmp == 'E' && slg->map_i->ccnt != 0)
			slg->map_i->exit = 1;
		if (tmp == 'E' && slg->map_i->ccnt == 0)
			slg->map_i->exit -= 1;
	}
	ft_printf("Number of Movements : %i\n", ++slg->map_i->cmoves);
}
