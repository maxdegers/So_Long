/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 14:35:35 by mbrousse          #+#    #+#             */
/*   Updated: 2024/01/31 17:19:06 by mbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_compo(char **tab)
{
	int	x;
	int	y;
	
	y = 0;
	while (tab[y])
	{
		x = 0;
		while (tab[y][x])
		{
			if ((tab[y][x] != '0') || (tab[y][x] != '1') || (tab[y][x] != 'P')
				|| (tab[y][x] != 'C') || (tab[y][x] != 'E') 
				|| (tab[y][x] != '\n'))
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

// static int	ft_valid(char **tab)
// {
// 	return (0);
// }

// static int	ft_map_isrec(char **tab)
// {
// 	return (0);
// }

void	ft_checker(char **tab)
{
	if (ft_compo(tab) != 0)
		perror("Error map compisition !!");
	// if (ft_valid(tab) != 0)
	// 	perror("Error map validity !!");
	// if (ft_map_isrec(tab) != 0)
	// 	perror("Error map is not rectangular !!");
}