/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   FdF.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: bsomers <bsomers@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/22 13:51:39 by bsomers       #+#    #+#                 */
/*   Updated: 2022/05/16 16:39:27 by bsomers       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H

# include "./libft/libft.h"
# include "./mlx/mlx.h"
#include <stdlib.h>
#include <math.h>

typedef struct	s_struct
{
    void *img;
	char *addr;
	int bpp;
	int len_line;
	int endian;
}				t_struct;

typedef struct	s_map
{
    int	win_h;
	int win_w;
	int x;
	int	y;
	int	**map;
}				t_map;


void    if_error(char *str);
int	parse_map(char *argv[], t_map *map);
void    draw_tile(t_struct *info,/* t_map *map, */int x, int y, int color);
void    draw_horizontal(t_struct *info, t_map *map, int x, int y, int color);
void    draw_vertical(t_struct *info, t_map *map, int x, int y, int color);

void	pixel_put(t_struct *info, int x, int y, int color);


#endif