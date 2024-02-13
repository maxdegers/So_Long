/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 14:33:16 by mbrousse          #+#    #+#             */
/*   Updated: 2024/02/13 19:00:17 by mbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
 
void	ft_compo_chec(t_slg *slg, char c)
{
	if (c == 'P')
		slg->pcnt++;
	if (c == 'C')
		slg->ccnt++;
	if (c == 'E')
		slg->ecnt++;
}

int	ft_map_wal(char **tab)
{
	size_t		y;
	long int	x;

	x = -1;
	while (tab[0][++x])
		if (tab[0][x] != '1' && tab[0][x] != '\n')
			return (1);
	y = 0;
	while (tab[y])
	{
		if (tab[y][0] != '1' || tab[y][ft_strlen(tab[y]) - 2] != '1')
			return (1);
		y++;
	}
	y--;
	x = -1;
	while (tab[y][++x])
		if (tab[y][x] != '1' && tab[0][x] != '\n')
			return (1);
	return (0);
}

char **ft_clonemap(char **map)
{
	int		x;
	int		y;
	char	**tab;

	y = -1;
	while (map[++y]);
	tab = malloc(sizeof(char *) * (y + 1));
	if (!tab)
		return (NULL);
	y = -1;
	while (map[++y])
	{
		x = ft_strlen(map[y]);
		tab[y] = malloc(sizeof(char) * (x + 1));
		if (!tab[y])
		return (NULL);
		x = -1;
		while (map[y][++x])
			tab[y][x] = map[y][x];
		tab[y][x] = 0;
	}
	tab[y] = NULL;
	return (tab);
}

void	ft_val_rec(char **mclone, size_t *y, size_t *x)
{
	if (mclone[*y][*x] == '1' || mclone[*y][*x] == '2')
		return ;
	mclone[*y][*x] = '2';
	*y -= 1;
	ft_val_rec(mclone, y, x);
	*y += 2;
	ft_val_rec(mclone, y, x);
	*x -= 1;
	ft_val_rec(mclone, y, x);
	*x += 2;
	ft_val_rec(mclone, y, x);
}

int	ft_map_valid(t_slg *slg, char **mclone)
{
	size_t y;
	size_t x;

	y = 0;
	x = 0;
	while (slg->map[y])
	{
		x = 0;
		while (slg->map[y][x] != 0)
		{
			if (slg->map[y][x] == 'E')
				break;
			x += 1; 
		}
		if (slg->map[y][x] == 'E')
				break;
		y += 1;
	}
	ft_printf("%i %i", x , y);
	ft_val_rec(mclone, &y, &x);
	ft_printf("bobo");
	if (mclone[slg->py][slg->px] != '2')
		return (1);
	if (ft_chec_mapc(mclone) == 1)
		return (1);
	return (0);
}
