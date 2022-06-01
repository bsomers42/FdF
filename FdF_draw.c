/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   FdF_draw.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: bsomers <bsomers@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/09 12:15:05 by bsomers       #+#    #+#                 */
/*   Updated: 2022/06/01 12:30:03 by bsomers       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"
#include <stdio.h> //Weeeegggg!!!!

void	draw_between_coord(int x0, int y0, int x1, int y1, t_struct *info)
{
	int dx;
	int dy;
	int p;
	int x;
	int y;

	dx = x1 - x0;
	dy = y1 - y0;// * -1);
	x = x0;
	y = y0;// * -1;
	p = 2*dy - dx;
	while (x < x1)
	{
		if (p >= 0)
		{
			pixel_put(info, &x, &y, 0xeb4034);
			y = y +1;
			p = p+2*dy-2*dx;
		}
		else
		{
			pixel_put(info, &x, &y, 0xeb4034);
			p = p + 2*dy;
		}
		printf("x0: %d, x1: %d, y0: %d, y1: %d, p: %d\n", x, x1, y, y1, p);
		x++;
	}
}


void	calc_coord(t_draw *draw, int z, t_struct *info)
{
	int	prev_x;
	int	prev_y;

	prev_x = draw->x;
	prev_y = draw->y;
	draw->x = (prev_x - prev_y) * cos(0.523599);
    draw->y = -z + (prev_x + prev_y) * sin(0.523599);
	pixel_put(info, &draw->x, &draw->y, 0x0fffffe);

	int x1 = draw->x;
	int y1 = draw->y;
	printf("xprev: %d, yprev: %d, x1: %d, y1: %d\n", draw->x_prev, draw->y_prev, draw->x, draw->y);

	if (draw->y_prev > 0)
		draw_between_coord(draw->x_prev, draw->y_prev, x1, y1, info);
	draw->x_prev = draw->x;
	draw->y_prev = draw->y;

	// int x = prev_x;
	// int y = prev_y;
	// int dx = draw->x - prev_x;
	// int dy = draw->y - prev_y;
	// int p = 2*dy-dx;


	// while (x > draw->x)
	// {
	// 	printf("x0: %d, x1: %d, y0: %d, y1: %d, p: %d\n", x, draw->x, y, draw->y, p);

	// 	if (p>=0)
	// 	{
	// 		pixel_put(info, &x, &y, 0xeb4034);
	// 		y = y + 1;
	// 		p = p + 2*dy-2*dx;
	// 	}
	// 	else
	// 	{
	// 		pixel_put(info, &x, &y, 0xeb4034);
	// 		p = p + 2*dy;
	// 	}
	// 	x = x - 1;
	// }


}

// void	draw_line_h(t_struct *info, t_map *map, int x, int y, int color, int l)
// {
// 	int i;
// 	int j;

// 	i = 0;
// 	j = 0;
// 	while (i < map->x)
// 	{
// 		if (/*(map->map[l][i] == 0) || */map->map[l][i] == map->map[l][i-1])
// 		{
// 			while (j < 10)
// 			{
// 				pixel_put(info, x, y, color);
// 				x = x + 2;
// 				y = y + 1;
// 				j++;
// 			}
// 			j = 0;
// 		}
// 		if ((map->map[l][i] == 0) && (map->map[l][i-1] == 10))
// 		{
// 			while (j < 10)
// 			{
// 				pixel_put(info, x, y, color);
// 				x = x + 0.5;
// 				y = y + 2;
// 				j++;
// 			}
// 			j = 0;
// 		}
// 		else if ((map->map[l][i] > 0) && (map->map[l][i-1] == 0))
// 		{
// 			while (j < 15)
// 			{
// 				pixel_put(info, x, y, color);
// 				x = x + 1;
// 				y = y - 1;
// 				j++;
// 			}
// 			j = 0;
// 		}
// //	printf("[%d], l = %d, i = %d \n", map->map[l][i], l, i);
// 		i++;
// 	}
// }

// void	draw_line_v(t_struct *info, t_map *map, int x, int y, int color, int l)
// {
// 	int i;
// 	int j;

// 	i = 0;
// 	j = 0;
// 	while (i < (map->y - 1))
// 	{
// 		if (i == 0)
// 		{
// 			while (j < 10)
// 			{
// 				pixel_put(info, x, y, color);
// 				x = x - 2;
// 				y = y + 1;
// 				j++;
// 			}
// 		}
// 		else if (i > 0 && (map->map[i][l] == map->map[i+1][l]))
// 		{
// 			while (j < 10)
// 			{
// 				pixel_put(info, x, y, color);
// 				x = x - 2;
// 				y = y + 1;
// 				j++;
// 			}
// 		}
// 		else if ((map->map[i][l] == 0) && (map->map[i+1][l] == 10)) //stijgen
// 		{
// 			while (j < 10)
// 			{
// 				pixel_put(info, x, y, color);
// 				x = x - 0.5;
// 				y = y - 2;
// 				j++;
// 			}
// 		}
// 		else if ((map->map[i][l] > 0) && (map->map[i+1][l] == 0)) //dalen
// 		{
// 			while (j < 15)
// 			{
// 				pixel_put(info, x, y, color);
// 				x = x - 0.5;
// 				y = y + 2;
// 				j++;
// 			}
// 		}
// 	j = 0;
// 	i++;
// 	}
// }

// void    draw_horizontal(t_struct *info, t_map *map, int x, int y, int color)
// {
// 	int i;

// 	i = 0;
// 	while (i < map->y)
// 	{
// 		draw_line_h(info, map, x, y, color, i);
// 		x = x - 20;
// 		y = y + 10;
// 		i++;
// 	}
// }
