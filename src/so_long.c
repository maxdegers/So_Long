/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 14:35:41 by mbrousse          #+#    #+#             */
/*   Updated: 2024/02/13 16:48:55 by mbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	print_tab(char **tab)//to remouve
{
	int		i;

	i = 0;
	while (tab[i])
	{
		ft_printf("%s", tab[i]);
		i++;
	}
	ft_printf("\n");
}

int main(int argc,char **argv)
{
	t_slg	slg;
	
	if (argc != 2)
		return (0);
	slg.map = ft_fill_tab(argv[1]);
	print_tab(slg.map);//
	ft_checker(&slg);
	
	ft_freetab(slg.map);
	return (0);
}
