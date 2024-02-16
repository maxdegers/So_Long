/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 14:32:16 by mbrousse          #+#    #+#             */
/*   Updated: 2024/02/16 18:22:25 by mbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../mlx_linux/mlx.h"
# include "../mlx_linux/mlx_int.h"

typedef struct s_map_i
{
	char		**map;
	size_t		px;
	size_t		py;
	size_t		cmoves;
	size_t		ccnt;
	size_t		ecnt;
	size_t		pcnt;
	size_t		cw;
	size_t		ch;
	size_t		exit;
	size_t		ex;
	size_t		ey;
}				t_map_i;

typedef struct s_data {
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

typedef struct s_vars {
	void	*mlx;
	void	*win;
	t_map_i	*map_i;
	t_data	*img;
}				t_vars;

void	ft_compo_chec(t_map_i *slg, char c);
char	**ft_fill_tab(char *map);
void	ft_freetab(char **tab);
void	ft_perror(void);
int		ft_checker(t_map_i *map_i, t_vars *slg);
void	ft_compo_chec(t_map_i *slg, char c);
int		ft_map_wal(char **tab);
char	**ft_clonemap(char **map);
int		ft_map_valid(t_map_i *slg, char **mclone);
void	ft_val_rec(char **mclone, size_t y, size_t x);
int		ft_chec_mapc(char **str);
void	ft_init_image(void *mlx, t_data	img);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	mlx_destroyer(t_vars *slg);
int		close_window(t_vars *slg);
void	ft_map_g(t_vars	*slg);
int		key_p(int key, t_vars *slg);
void	ft_set_exit(size_t y, size_t x, t_map_i *map_i);
void	ft_move_u(t_vars *slg);
void	ft_move_d(t_vars *slg);
void	ft_move_l(t_vars *slg);
void	ft_move_r(t_vars *slg);

#endif