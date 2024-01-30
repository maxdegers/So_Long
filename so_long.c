/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 14:35:41 by mbrousse          #+#    #+#             */
/*   Updated: 2024/01/30 19:57:29 by mbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc,char **argv)
{
	char	**tab;
	int		i;
	
	if (argc != 2)
		return (0);
	tab = ft_fill_tab(argv[1]);
	// to remouve
	i = 0;
	while (tab[i])
	{
		ft_printf("%s", tab[i]);
		i++;
	}
	//
	ft_checker(tab);
	ft_freetab(tab);
	return (0);
}
