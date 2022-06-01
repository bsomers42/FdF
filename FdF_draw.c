/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   FdF_draw.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: bsomers <bsomers@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/09 12:15:05 by bsomers       #+#    #+#                 */
/*   Updated: 2022/06/01 17:54:07 by bsomers       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void	calc_coord(t_draw *draw, int z, t_str *info, t_br *br)
{
	int	prev_x;
	int	prev_y;

	prev_x = draw->x;
	prev_y = draw->y;
	draw->x = (prev_x - prev_y) * cos(0.523599);
	draw->y = -z + (prev_x + prev_y) * sin(0.523599);
	pixel_put(info, &draw->x, &draw->y, 0x0fffffe);
	br->x1 = draw->x_prev;
	br->x2 = draw->x;
	br->y1 = draw->y_prev;
	br->y2 = draw->y;
	if (draw->y_prev > 0 && draw->x_prev < draw->x)
		bresenham(br, info);
	draw->x_prev = draw->x;
	draw->y_prev = draw->y;
}

void	coord_and_horiz_lines(t_draw *draw, t_map *map, t_str *info, t_br *br)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	draw->x = 150; //Starting positions of drawing, needs to be a calculation!
	draw->y = 10;
	draw->y_prev = -1;
	while (i < map->y)
	{
		while (j < map->x)
		{
			draw->x = 150 + j * 14; //Deze 14 bepaalt de grootte van de vakjes
			draw->y = 10 + i * 14;
			calc_coord(draw, map->map[i][j], info, br);
			draw->map_x[i][j] = draw->x;
			draw->map_y[i][j] = draw->y;
			j++;
		}
		j = 0;
		i++;
	}
}

void	vert_lines(t_draw *draw, t_map *map, t_str *info, t_br *br)
{
	int	i;
	int	j;

	j = 1;
	i = 0;
	draw->y_prev = -1;
	while (i < map->x)
	{
		while (j < map->y)
		{
			br->x1 = draw->map_x[j - 1][i];
			br->x2 = draw->map_x[j][i];
			br->y1 = draw->map_y[j - 1][i];
			br->y2 = draw->map_y[j][i];
			bresenham(br, info);
			j++;
		}
		j = 1;
		i++;
	}
}

void	make_raster(t_draw *draw, t_map *map, t_str *info)
{
	t_br	br;
	int		i;
	int		j;

	i = 0;
	j = 0;
	draw->map_x = malloc(map->y * sizeof(int *));
	draw->map_y = malloc(map->y * sizeof(int *));
	while (i < map->y)
	{
		while (j < map->x)
		{
			draw->map_x[i] = malloc(map->x * sizeof(int));
			draw->map_y[i] = malloc(map->x * sizeof(int));
			j++;
		}
		j = 0;
		i++;
	}
	coord_and_horiz_lines(draw, map, info, &br);
	vert_lines(draw, map, info, &br);
}
