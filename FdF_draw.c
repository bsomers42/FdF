/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   FdF_draw.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: bsomers <bsomers@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/09 12:15:05 by bsomers       #+#    #+#                 */
/*   Updated: 2022/05/09 15:05:17 by bsomers       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

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