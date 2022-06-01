/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   FdF_draw.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: bsomers <bsomers@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/09 12:15:05 by bsomers       #+#    #+#                 */
/*   Updated: 2022/06/01 15:54:55 by bsomers       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"
#include <stdio.h> //Weeeegggg!!!!

void	bresenham_r(int x1, int y1, int x2, int y2, t_struct *info)
{
	int x;
	int y;
	int dx;
	int dy;
	int dx1;
	int dy1;
	int px;
	int py;
	int xe;
	int ye;
	int i;

	dx = x2 - x1;;
	dy = y2 - y1;
	dx1 = abs(dx);
	dy1 = abs(dy);
	px = 2 * dy1 - dx1;
	py = 2* dx1 - dy1;
	if (dy1 <= dx1) {
        // Line is drawn left to right
        if (dx >= 0) {
            x = x1; y = y1; xe = x2;
        } else { // Line is drawn right to left (swap ends)
            x = x2; y = y2; xe = x1;
        }
        pixel_put(info, &x, &y, RED); // Draw first pixel
        // Rasterize the line
        for (i = 0; x < xe; i++) {
            x = x + 1;
            // Deal with octants...
            if (px < 0) {
                px = px + 2 * dy1;
            } else {
                if ((dx < 0 && dy < 0) || (dx > 0 && dy > 0)) {
                    y = y + 1;
                } else {
                    y = y - 1;
                }
                px = px + 2 * (dy1 - dx1);
            }
            // Draw pixel from line span at
            // currently rasterized position
            pixel_put(info, &x, &y, RED);
        }
    } else { // The line is Y-axis dominant
        // Line is drawn bottom to top
        if (dy >= 0) {
            x = x1; y = y1; ye = y2;
        } else { // Line is drawn top to bottom
            x = x2; y = y2; ye = y1;
        }
        pixel_put(info, &x, &y, RED); // Draw first pixel
        // Rasterize the line
        for (i = 0; y < ye; i++) {
            y = y + 1;
            // Deal with octants...
            if (py <= 0) {
                py = py + 2 * dx1;
            } else {
                if ((dx < 0 && dy<0) || (dx > 0 && dy > 0)) {
                    x = x + 1;
                } else {
                    x = x - 1;
                }
                py = py + 2 * (dx1 - dy1);
            }
            // Draw pixel from line span at
            // currently rasterized position
            pixel_put(info, &x, &y, RED);
        }
    }
 }

void	bresenham_g(int x1, int y1, int x2, int y2, t_struct *info)
{
	int x;
	int y;
	int dx;
	int dy;
	int dx1;
	int dy1;
	int px;
	int py;
	int xe;
	int ye;
	int i;

	dx = x2 - x1;;
	dy = y2 - y1;
	dx1 = abs(dx);
	dy1 = abs(dy);
	px = 2 * dy1 - dx1;
	py = 2* dx1 - dy1;
	if (dy1 <= dx1) {
        // Line is drawn left to right
        if (dx >= 0) {
            x = x1; y = y1; xe = x2;
        } else { // Line is drawn right to left (swap ends)
            x = x2; y = y2; xe = x1;
        }
        pixel_put(info, &x, &y, GREEN); // Draw first pixel
        // Rasterize the line
        for (i = 0; x < xe; i++) {
            x = x + 1;
            // Deal with octants...
            if (px < 0) {
                px = px + 2 * dy1;
            } else {
                if ((dx < 0 && dy < 0) || (dx > 0 && dy > 0)) {
                    y = y + 1;
                } else {
                    y = y - 1;
                }
                px = px + 2 * (dy1 - dx1);
            }
            // Draw pixel from line span at
            // currently rasterized position
            pixel_put(info, &x, &y, GREEN);
        }
    } else { // The line is Y-axis dominant
        // Line is drawn bottom to top
        if (dy >= 0) {
            x = x1; y = y1; ye = y2;
        } else { // Line is drawn top to bottom
            x = x2; y = y2; ye = y1;
        }
        pixel_put(info, &x, &y, GREEN); // Draw first pixel
        // Rasterize the line
        for (i = 0; y < ye; i++) {
            y = y + 1;
            // Deal with octants...
            if (py <= 0) {
                py = py + 2 * dx1;
            } else {
                if ((dx < 0 && dy<0) || (dx > 0 && dy > 0)) {
                    x = x + 1;
                } else {
                    x = x - 1;
                }
                py = py + 2 * (dx1 - dy1);
            }
            // Draw pixel from line span at
            // currently rasterized position
            pixel_put(info, &x, &y, GREEN);
        }
    }
 }

void	draw_between_coord_h(int x0, int y0, int x1, int y1, t_struct *info)
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
			pixel_put(info, &x, &y, WHITE);
			y = y +1;
			p = p+2*dy-2*dx;
		}
		else
		{
			pixel_put(info, &x, &y, WHITE);
			p = p + 2*dy;
		}
		//printf("x0: %d, x1: %d, y0: %d, y1: %d, p: %d\n", x, x1, y, y1, p);
		x++;
	}
}

void	draw_between_coord_v(int x0, int y0, int x1, int y1, t_struct *info)
{
	int dx;
	int dy;
	int p;
	int x;
	int y;

	y1 = -1 * y1;
	y0 = -1 * y0;
	dx=x1-x0;
	dy=y1-y0;
 
	x=x0;
	y=y0;
 
	p=2*dy-dx;
 
	while(x<x1)
	{
		if(p>=0)
		{
			y = y * -1;
			pixel_put(info, &x, &y, WHITE);
			y = y * -1;
			y=y+1;
			p=p+2*dy-2*dx;
		}
		else
		{
			y = y * -1;
			pixel_put(info, &x, &y, WHITE);
			y = y * -1;
			p=p+2*dy;
		}
	 	printf("x0: %d, x1: %d, y0: %d, y1: %d, p: %d\n", x, x1, y, y1, p);
		x=x+1;
	}
	// int dx;
	// int dy;
	// int p;
	// int x;
	// int y;
	// x = x1;
	// x1 = x0;
	// y = y1;
	// y1 = y0;
	// dx = x1 - x0;
	// dy = y1 - y0 ;//* -1);

	// p = 2*dy - dx;
	// while (x < x1)
	// {
	// 	if (p >= 0)
	// 	{
	// 		pixel_put(info, &x, &y, 0x23f90b);
	// 		y = y -1;
	// 		p = p+2*dy-2*dx;
	// 	}
	// 	else
	// 	{
	// 		pixel_put(info, &x, &y, 0x23f90b);
	// 		p = p + 2*dy;
	// 	}
	// 	printf("x0: %d, x1: %d, y0: %d, y1: %d, p: %d\n", x, x1, y, y1, p);
	// 	x++;
	// }
}


void	calc_coord_horiz(t_draw *draw, int z, t_struct *info)//, int mapx, int i)
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

	if (draw->y_prev > 0 && draw->x_prev < x1)
		bresenham_r(draw->x_prev, draw->y_prev, x1, y1, info);
	
	draw->x_prev = draw->x;
	draw->y_prev = draw->y;
}


void	calc_coord_vert(t_draw *draw, int z, t_struct *info)
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
		draw_between_coord_v(draw->x_prev, draw->y_prev, x1, y1, info);
	draw->x_prev = draw->x;
	draw->y_prev = draw->y;
}
