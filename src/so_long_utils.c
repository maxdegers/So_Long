/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 14:35:43 by mbrousse          #+#    #+#             */
/*   Updated: 2024/02/16 18:05:21 by mbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_compo_chec(t_map_i *slg, char c)
{
	if (c == 'P')
		slg->pcnt++;
	if (c == 'C')
		slg->ccnt++;
	if (c == 'E')
		slg->ecnt++;
}

void	ft_set_exit(size_t y, size_t x, t_map_i *map_i)
{
	map_i->ey = y;
	map_i->ex = x;
}
