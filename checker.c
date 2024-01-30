/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 14:35:35 by mbrousse          #+#    #+#             */
/*   Updated: 2024/01/30 20:09:51 by mbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_compo(char **tab)
{
	
}

static int	ft_valid(char **tab)
{
	
}

static int	ft_map_isrec(char **tab)
{
	
}

void	ft_checker(char **tab)
{
	if (ft_compo(tab) != 0)
		perror("Error map compisition !!");
	if (ft_valid(tab) != 0)
		perror("Error map validity !!");
	if (ft_map_isrec(tab) != 0)
		perror("Error map is not rectangular !!");
}