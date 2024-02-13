/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 14:32:16 by mbrousse          #+#    #+#             */
/*   Updated: 2024/02/07 17:15:05 by mbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "mlx_linux/mlx.h"
# include "mlx_linux/mlx_int.h"
//to remouve
void	print_tab(char **tab);
//map utils
char	**ft_fill_tab(char *map);
//error
void	ft_freetab(char **tab);
//checker
void	ft_checker(char **tab);
void	ft_compo_chec(int *num, char c);
int		ft_map_wal(char **tab);
char	**ft_clonemap(char **map);
int		ft_map_valid(char **map, char **mclone);
#endif