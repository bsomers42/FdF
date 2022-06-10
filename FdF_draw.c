/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   FdF_draw.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: bsomers <bsomers@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/09 12:15:05 by bsomers       #+#    #+#                 */
/*   Updated: 2022/06/10 14:09:05 by bsomers       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"
#include <stdio.h> //weggg

// int	pick_color(int z)
// {
// 	if (z < 0)
// 		return (BLUE);
// 	if (z >= 0 && z <= 5)
// 		return (BROWN);
// 	if (z > 5 && z < 30)
// 		return (GREEN);
// 	else
// 		return (WHITE);
// }



void	calc_coord(t_draw *draw, int z, /*t_str *info,*/ t_br *br, mlx_image_t *g_img)
{
	int	prev_x;
	int	prev_y;

	prev_x = draw->x;
	prev_y = draw->y;
	if (z < 0)
		z = z - draw->z_key;
	else if (z > 0)
		z = z + draw->z_key;
	draw->x = (prev_x - prev_y) * cos(0.523599);
	draw->y = -z + (prev_x + prev_y) * sin(0.523599);
	if (draw->x > 0 && draw->y > 0 && draw->y < HEIGHT && draw->x < WIDTH)
		mlx_put_pixel(g_img, draw->x, draw->y, draw->color);
	// else
	// 	if_error("Going outside window!\n");
	br->x1 = draw->x_prev;
	br->x2 = draw->x;
	br->y1 = draw->y_prev;
	br->y2 = draw->y;
	if (draw->y_prev > 0 && draw->x_prev < draw->x)
		bresenham(br, g_img, draw->color);
	draw->x_prev = draw->x;
	draw->y_prev = draw->y;
}

void	coord_and_horiz_lines(t_draw *draw, t_map *map, /*t_str *info,*/ t_br *br, mlx_image_t *g_img)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	draw->x = 700; //Starting positions of drawing, needs to be a calculation!
	draw->y = -200;
	draw->y_prev = -1;
	// ft_printf("Value of move x & y: %d, %d\n", br->move_x, br->move_y);

	while (i < map->y)
	{
		while (j < map->x)
		{
			draw->x = 700 + j * 14 * (0.1 * draw->zoom) + br->move_x;//draw->rib;//14; //Deze 14 bepaalt de grootte van de vakjes
			draw->y = -200 + i * 14 * (0.1 * draw->zoom) + br->move_y;//draw->rib;//14;
			calc_coord(draw, map->map[i][j], /*info,*/ br, g_img);
			draw->map_x[i][j] = draw->x;
			draw->map_y[i][j] = draw->y;
			j++;
		}
		j = 0;
		i++;
	}
}

void	vert_lines(t_draw *draw, t_map *map, /*t_str *info,*/ t_br *br, mlx_image_t *g_img)
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
			bresenham(br, /*info,*/ g_img, draw->color);
			j++;
		}
		j = 1;
		i++;
	}
}

void	make_raster(t_draw *draw, t_map *map, t_br *br, mlx_image_t *g_img)
{
	int		i;

	i = 0;
	draw->map_x = malloc(map->y * sizeof(int *));
	draw->map_y = malloc(map->y * sizeof(int *));
	while (i < map->y)
	{
		draw->map_x[i] = malloc(map->x * sizeof(int));
		draw->map_y[i] = malloc(map->x * sizeof(int));
		i++;
	}
	coord_and_horiz_lines(draw, map, br, g_img);
	vert_lines(draw, map, br, g_img);
	i = 0;
	while (i < map->y)
	{
		free(draw->map_x[i]);
		free(draw->map_y[i]);
		i++;
	}
	free(draw->map_y);
    free(draw->map_x);
}
