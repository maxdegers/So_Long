/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 14:35:41 by mbrousse          #+#    #+#             */
/*   Updated: 2024/02/14 21:01:06 by mbrousse         ###   ########.fr       */
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

static int	ft_mlx()
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	
	mlx = mlx_init();
	if (!mlx)
		return (1);
	mlx_win = mlx_new_window(mlx, 800, 800, "Hello world!");
	img.img = mlx_new_image(mlx, 800, 800);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}

int main(int argc,char **argv)
{
	t_slg	slg;

	if (argc != 2)
		return (1);
	slg.map = ft_fill_tab(argv[1]);
	ft_checker(&slg);
	if (ft_mlx() != 0)
		return(ft_freetab(slg.map), ft_perror(), 1);
	return (ft_freetab(slg.map), 0);
}
