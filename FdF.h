/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   FdF.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: bsomers <bsomers@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/22 13:51:39 by bsomers       #+#    #+#                 */
/*   Updated: 2022/06/01 17:52:05 by bsomers       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H

# include "./libft/libft.h"
# include "./mlx/mlx.h"
#include <stdlib.h>
#include <math.h>

#define GREEN 0x23f90b
#define RED 0xeb4034
#define WHITE 0x0fffffe

typedef struct	s_str
{
    void *img;
	char *addr;
	int bpp;
	int len;
	int endian;
}				t_str;

typedef struct	s_map
{
    int	win_h;
	int win_w;
	int x;
	int	y;
	int	**map;
}				t_map;

typedef struct	s_draw
{
	int x;
	int	y;
	int x_prev;
	int y_prev;
	int **map_x;
	int **map_y;
}				t_draw;

typedef struct	s_br
{
	int x;
	int	y;
	int dx;
	int dy;
	int dx1;
	int dy1;
	int px;
	int py;
	int xe;
	int ye;
	int i;
	int x1;
	int x2;
	int y1;
	int y2;
}				t_br;

void    if_error(char *str);
int	parse_map(char *argv[], t_map *map);
void	pixel_put(t_str *info, int *x, int *y, int color);
void	make_raster(t_draw *draw, t_map *map, t_str *info);
void	bresenham(t_br *br, t_str *info);

#endif