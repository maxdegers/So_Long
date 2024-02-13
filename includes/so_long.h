/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 14:32:16 by mbrousse          #+#    #+#             */
/*   Updated: 2024/02/13 17:49:43 by mbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../mlx_linux/mlx.h"
# include "../mlx_linux/mlx_int.h"

typedef struct  s_slg
{
    char        **map;
    size_t      px;
    size_t      py;
    size_t      cmoves;
    size_t      ccnt;
    size_t      ecnt;
    size_t      pcnt;
}               t_slg;


//to remouve
void	print_tab(char **tab);
//map utils
char	**ft_fill_tab(char *map);
//error
void	ft_freetab(char **tab);
void	ft_perror();
//checker
void	ft_checker(t_slg *slg);
void	ft_compo_chec(t_slg *slg, char c);
int		ft_map_wal(char **tab);
char	**ft_clonemap(char **map);
int     ft_map_valid(t_slg *slg, char **mclone);
void	ft_val_rec(char **mclone, size_t *y, size_t *x);
int     ft_chec_mapc(char **str);
#endif