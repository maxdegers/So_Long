/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 14:35:41 by mbrousse          #+#    #+#             */
/*   Updated: 2024/02/06 18:13:52 by mbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	char	**tab;
	
	if (argc != 2)
		return (0);
	tab = ft_fill_tab(argv[1]);
	if (!tab)
		return (1);
	print_tab(tab);//
	ft_checker(tab);
	
	ft_freetab(tab);
	return (0);
}
