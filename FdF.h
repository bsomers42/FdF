/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   FdF.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: bsomers <bsomers@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/22 13:51:39 by bsomers       #+#    #+#                 */
/*   Updated: 2022/06/01 15:54:24 by bsomers       ########   odam.nl         */
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

typedef struct	s_draw
{
	int x;
	int	y;
	int x_prev;
	int y_prev;
	int **map_x;
	int **map_y;
}				t_draw;

void    if_error(char *str);
int	parse_map(char *argv[], t_map *map);
void    draw_tile(t_struct *info,/* t_map *map, */int x, int y, int color);
void    draw_horizontal(t_struct *info, t_map *map, int x, int y, int color);
void    draw_vertical(t_struct *info, t_map *map, int x, int y, int color);
void	calc_coord_horiz(t_draw *draw, int z, t_struct *info);//, int mapx, int i);
void	draw_between_coord_v(int x0, int y0, int x1, int y1, t_struct *info);
void	calc_coord_vert(t_draw *draw, int z, t_struct *info);
void	pixel_put(t_struct *info, int *x, int *y, int color);
void	bresenham_g(int x0, int y0, int x1, int y1, t_struct *info);
void	bresenham_r(int x0, int y0, int x1, int y1, t_struct *info);

#endif