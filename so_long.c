/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 14:35:41 by mbrousse          #+#    #+#             */
/*   Updated: 2024/01/29 18:15:37 by mbrousse         ###   ########.fr       */
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
	i = 0;
	while (tab[i])
	{
		ft_printf("%s", tab[i]);
		i++;
	}
	// ft_freetab(tab);
	return (0);
}
