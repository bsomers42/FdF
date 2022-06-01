/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   FdF_bresenham.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: bsomers <bsomers@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/01 16:12:07 by bsomers       #+#    #+#                 */
/*   Updated: 2022/06/01 17:46:38 by bsomers       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void	loop_x_oct(t_str *info, t_br *br)
{
	while (br->x < br->xe)
	{
		br->x = br->x + 1;
		if (br->px < 0)
			br->px = br->px + 2 * br->dy1;
		else
		{
			if ((br->dx < 0 && br->dy < 0) || (br->dx > 0 && br->dy > 0))
				br->y = br->y + 1;
			else
				br->y = br->y - 1;
			br->px = br->px + 2 * (br->dy1 - br->dx1);
		}
		pixel_put(info, &br->x, &br->y, WHITE);
		br->i++;
	}
}

void	loop_y_oct(t_str *info, t_br *br)
{
	while (br->y < br->ye)
	{
		br->y = br->y + 1;
		if (br->py <= 0)
			br->py = br->py + 2 * br->dx1;
		else
		{
			if ((br->dx < 0 && br->dy < 0) || (br->dx > 0 && br->dy > 0))
				br->x = br->x + 1;
			else
				br->x = br->x - 1;
			br->py = br->py + 2 * (br->dx1 - br->dy1);
		}
		pixel_put(info, &br->x, &br->y, WHITE);
		br->i++;
	}
}

void	br_x_axis_dominant(t_str *info, t_br *br)
{
	if (br->dx >= 0)
	{
		br->x = br->x1;
		br->y = br->y1;
		br->xe = br->x2;
	}
	else
	{
		br->x = br->x2;
		br->y = br->y2;
		br->xe = br->x1;
	}
	pixel_put(info, &br->x, &br->y, WHITE);
	loop_x_oct(info, br);
}

void	br_y_axis_dominant(t_str *info, t_br *br)
{
	if (br->dy >= 0)
	{
		br->x = br->x1;
		br->y = br->y1;
		br->ye = br->y2;
	}
	else
	{
		br->x = br->x2;
		br->y = br->y2;
		br->ye = br->y1;
	}
	pixel_put(info, &br->x, &br->y, WHITE);
	loop_y_oct(info, br);
}

void	bresenham(t_br *br, t_str *info)
{
	br->dx = br->x2 - br->x1;
	br->dy = br->y2 - br->y1;
	if (br->dx < 0)
		br->dx1 = br->dx * -1;
	else
		br->dx1 = br->dx;
	if (br->dy < 0)
		br->dy1 = br->dy * -1;
	else
		br->dy1 = br->dy;
	br->px = 2 * br->dy1 - br->dx1;
	br->py = 2 * br->dx1 - br->dy1;
	br->i = 0;
	if (br->dy1 <= br->dx1)
		br_x_axis_dominant(info, br);
	else
		br_y_axis_dominant(info, br);
}
