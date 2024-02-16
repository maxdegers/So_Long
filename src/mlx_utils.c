/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 20:42:15 by mbrousse          #+#    #+#             */
/*   Updated: 2024/02/16 18:04:58 by mbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	mlx_destroyer(t_vars *slg)
{
	mlx_destroy_window(slg->mlx, slg->win);
	mlx_destroy_display(slg->mlx);
	free(slg->mlx);
}

int	close_window(t_vars *slg)
{
	mlx_loop_end(slg->mlx);
	return (0);
}

int	key_p(int key, t_vars *slg)
{
	if (key == 65307)
		close_window(slg);
	else if (key == 'w')
		ft_move_u(slg);
	else if (key == 's')
		ft_move_d(slg);
	else if (key == 'a')
		ft_move_l(slg);
	else if (key == 'd')
		ft_move_r(slg);
	if (slg->map_i->ecnt == 1)
		ft_map_g(slg);
	else
		close_window(slg);
	return (0);
}

static void	ft_get_image(t_vars	*slg, size_t x, size_t y)
{
	int		size_image;

	size_image = 32;
	if (slg->map_i->map[y][x] == '1')
		slg->img->img = mlx_xpm_file_to_image(slg->mlx,
				"texture/stone_bricks.xpm", &size_image, &size_image);
	if (slg->map_i->map[y][x] == 'E' && slg->map_i->ccnt == 0)
		slg->img->img = mlx_xpm_file_to_image(slg->mlx,
				"texture/barrel_top_open.xpm", &size_image, &size_image);
	else if (slg->map_i->map[y][x] == 'E')
		slg->img->img = mlx_xpm_file_to_image(slg->mlx,
				"texture/barrel_top.xpm", &size_image, &size_image);
	if (slg->map_i->map[y][x] == 'P' && y == slg->map_i->ey
		&& x == slg->map_i->ex)
		slg->img->img = mlx_xpm_file_to_image(slg->mlx,
				"texture/dolphin_on_exit.xpm", &size_image, &size_image);
	else if (slg->map_i->map[y][x] == 'P')
		slg->img->img = mlx_xpm_file_to_image(slg->mlx,
				"texture/dolphin.xpm", &size_image, &size_image);
	if (slg->map_i->map[y][x] == 'C')
		slg->img->img = mlx_xpm_file_to_image(slg->mlx,
				"texture/pufferfish.xpm", &size_image, &size_image);
	if (slg->map_i->map[y][x] == '0')
		slg->img->img = mlx_xpm_file_to_image(slg->mlx,
				"texture/water.xpm", &size_image, &size_image);
}

void	ft_map_g(t_vars	*slg)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < slg->map_i->ch)
	{
		x = 0;
		while (x < slg->map_i->cw)
		{
			ft_get_image(slg, x, y);
			mlx_put_image_to_window(slg->mlx, slg->win,
				slg->img->img, x * 32, y * 32);
			mlx_destroy_image(slg->mlx, slg->img->img);
			x++;
		}
		y++;
	}
}
