/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   FdF.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: bsomers <bsomers@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/22 13:51:39 by bsomers       #+#    #+#                 */
/*   Updated: 2022/06/10 12:17:24 by bsomers       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H

# include "./libft/libft.h"
# include "./MLX42/include/MLX42/MLX42.h"
# include <stdlib.h>
# include <math.h>

# define GREEN 0x39BD00FF
# define RED 0xFF0000FF
# define WHITE 0xFFFFFFFF
# define BLACK 0x000000FF
# define BLUE 0x0000FFFF
# define YELLOW 0xFFFF00FF
# define HEIGHT 1080
# define WIDTH 1920

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
	int rib;
	int **map_x;
	int **map_y;
	int z_key;
	int zoom;
	int color;
	int c_key;
	void *g_img;

}				t_draw;

typedef struct	s_press
{
	struct s_draw *ptr;
	struct s_map *ptrm;
	struct s_br *ptrbr;
	void *mlx;
}				t_press;

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
	int move_start;
	int move_x;
	int move_y;
}				t_br;

void    if_error(char *str);
int		parse_map(char *argv[], t_map *map);
void	make_raster(t_draw *draw, t_map *map, t_br *br,/*t_str *info, */mlx_image_t *g_img);
void	bresenham(t_br *br, /*t_str *info,*/ mlx_image_t *g_img, int color);
void    free_structs(/*t_draw *draw,*/ t_map *map);


#endif