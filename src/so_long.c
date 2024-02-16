/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 14:35:41 by mbrousse          #+#    #+#             */
/*   Updated: 2024/02/16 18:08:04 by mbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	ft_mlx(t_vars	*slg)
{
	t_data	img;

	slg->mlx = mlx_init();
	if (!slg->mlx)
		return (1);
	slg->win = mlx_new_window(slg->mlx, (slg->map_i->cw) * 32,
			(slg->map_i->ch) * 32, "THE GAME");
	slg->img = &img;
	ft_map_g(slg);
	mlx_hook(slg->win, 17, 1L << 0, close_window, slg);
	mlx_hook(slg->win, 2, 1L << 0, key_p, slg);
	mlx_loop(slg->mlx);
	mlx_destroyer(slg);
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars	slg;
	t_map_i	map_inf;

	if (argc != 2)
		return (1);
	slg.map_i = &map_inf;
	slg.map_i->map = ft_fill_tab(argv[1]);
	ft_checker(slg.map_i, &slg);
	if (ft_mlx(&slg) != 0)
		return (ft_freetab(slg.map_i->map), ft_perror(), 1);
	return (ft_freetab(slg.map_i->map), 0);
}
