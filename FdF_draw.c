/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   FdF_draw.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: bsomers <bsomers@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/09 12:15:05 by bsomers       #+#    #+#                 */
/*   Updated: 2022/05/16 16:57:56 by bsomers       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"
#include <stdio.h> //Weeeegggg!!!!

void	draw_line_h(t_struct *info, t_map *map, int x, int y, int color, int l)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < map->x)
	{
		if (/*(map->map[l][i] == 0) || */map->map[l][i] == map->map[l][i-1])
		{
			while (j < 10)
			{
				pixel_put(info, x, y, color);
				x = x + 2;
				y = y + 1;
				j++;
			}
			j = 0;
		}
		if ((map->map[l][i] == 0) && (map->map[l][i-1] == 10))
		{
			while (j < 10)
			{
				pixel_put(info, x, y, color);
				x = x + 0.5;
				y = y + 2;
				j++;
			}
			j = 0;
		}
		else if ((map->map[l][i] > 0) && (map->map[l][i-1] == 0))
		{
			while (j < 15)
			{
				pixel_put(info, x, y, color);
				x = x + 1;
				y = y - 1;
				j++;
			}
			j = 0;
		}
//	printf("[%d], l = %d, i = %d \n", map->map[l][i], l, i);
		i++;
	}
}

void	draw_line_v(t_struct *info, t_map *map, int x, int y, int color, int l)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < (map->y - 1))
	{
		if (i == 0)
		{
			while (j < 10)
			{
				pixel_put(info, x, y, color);
				x = x - 2;
				y = y + 1;
				j++;
			}
		}
		else if (i > 0 && (map->map[i][l] == map->map[i+1][l]))
		{
			while (j < 10)
			{
				pixel_put(info, x, y, color);
				x = x - 2;
				y = y + 1;
				j++;
			}
		}
		else if ((map->map[i][l] == 0) && (map->map[i+1][l] == 10)) //stijgen
		{
			while (j < 10)
			{
				pixel_put(info, x, y, color);
				x = x - 0.5;
				y = y - 2;
				j++;
			}
		}
		else if ((map->map[i][l] > 0) && (map->map[i+1][l] == 0)) //dalen
		{
			while (j < 15)
			{
				pixel_put(info, x, y, color);
				x = x - 0.5;
				y = y + 2;
				j++;
			}
		}
	j = 0;
	i++;
	}
}

void    draw_horizontal(t_struct *info, t_map *map, int x, int y, int color)
{
	int i;

	i = 0;
	while (i < map->y)
	{
		draw_line_h(info, map, x, y, color, i);
		x = x - 20;
		y = y + 10;
		i++;
	}
}

void    draw_vertical(t_struct *info, t_map *map, int x, int y, int color)
{
	int i;

	i = 0;
	while (i < map->x)
	{
		draw_line_v(info, map, x, y, color, i);
		x = x + 20;
		y = y + 10;
		i++;
	}
}

void    draw_tile(t_struct *info, /*t_map *map,*/ int x, int y, int color)
{
    // int	width;
	// int height;
	// int	avg;
	int i;

	i = 0;
	// avg = (map->x + map->y) / 4;
	while (i < 10)
	{
		pixel_put(info, x, y, color);
		x = x + 2;
		y = y + 1;
		i++;
	}
	i = 0;
	while (i < 10)
	{
		pixel_put(info, x, y, color);
		x = x - 2;
		y = y + 1;
		i++;
	}
	i = 0;
	while (i < 10)
	{
		pixel_put(info, x, y, color);
		x = x - 2;
		y = y - 1;
		i++;
	}
	i = 0;
	while (i < 10)
	{
		pixel_put(info, x, y, color);
		x = x + 2;
		y = y - 1;
		i++;
	}
}