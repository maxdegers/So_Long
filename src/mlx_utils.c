/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 20:42:15 by mbrousse          #+#    #+#             */
/*   Updated: 2024/02/15 20:35:41 by mbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
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

static void	ft_get_image(t_vars	*slg, size_t x, size_t y)
{
	int		size_image;

	size_image = 32;
	if (slg->map_i->map[y][x] == '1')
		slg->img->img = mlx_xpm_file_to_image(slg->mlx,
			"texture/stone_bricks.xpm", &size_image, &size_image);
	if (slg->map_i->map[y][x] == 'E')
		slg->img->img = mlx_xpm_file_to_image(slg->mlx,
			"texture/barrel_top.xpm", &size_image, &size_image);
	if (slg->map_i->map[y][x] == 'P')
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
			mlx_put_image_to_window(slg->mlx, slg->win, slg->img->img, x * 32, y * 32);
			mlx_destroy_image(slg->mlx, slg->img->img);
			x++;
		}
		y++;
	}
	
}