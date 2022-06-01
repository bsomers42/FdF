/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   FdF.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: bsomers <bsomers@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/22 10:32:41 by bsomers       #+#    #+#                 */
/*   Updated: 2022/06/01 15:54:33 by bsomers       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"
#include <stdio.h> //eeesegkjfbnkjtn!!

// mlx_init(); //sets up connection to graphical system. If it fails, it returns NULL.

// mlx_new_window(); //manage windows
// mlx_pixel_put(); //draw nside window
// mlx_new_image(); //maniulate images
// mlx_loop(); //handle keyboard our mouse events

void	pixel_put(t_struct *info, int *x, int *y, int color)
{
	char *dst;

	dst = info->addr + (*y * info->len_line + *x * (info->bpp / 8));
	*(unsigned int*)dst = color;
}

void	calc_size_window(t_map *map)
{
	map->win_h = ((map->y + map->x) * 10) + 50;
	map->win_w = ((map->x + map->y) * 20) + 50;
}

void	fdf(t_map *map)
{
	t_struct info;
	t_draw draw;
	void *mlxptr;
	void *window;
	int i;
	int j = 0;
	int color_h;
	int color_v;
	int x;
	// int a;
	// int b;


	color_v = 0x0fffffe;
	color_h = 0xeb4034;
	calc_size_window(map);
	if ((map->win_h * 1.5) == map->win_w)
		x = (map->win_w / 2) + 25;
	else
		x = (map->win_w / 3) + 25;
	//int y = map->y * 2;

	ft_printf("x: %d, y: %d\n", map->x, map->y);
	i = 0;
	mlxptr = mlx_init();
	if (mlxptr == NULL)
		if_error("Could not connect to mlx");
	window = mlx_new_window(mlxptr, map->win_w, map->win_h, "FdF bsomers");
	info.img = mlx_new_image(mlxptr, map->win_w, map->win_h);
	info.addr = mlx_get_data_addr(info.img, &info.bpp, &info.len_line, &info.endian);
	// while (j < map->y)////////////////Per tile///////
	// {
	// 	while (i < map->x)
	// 	{
	// 		draw_tile(&info, /*map,*/ x, y, color);
	// 		x = x + 20;
	// 		y = y + 10;
	// 		i++;
	// 	}
	// 	x = x - ((i + 1) * 20);
	// 	y = y - ((i - 1) * 10);
	// 	i = 0;
	// 	j++;
	// }/////////////////////////////////Per tile///////

	// draw_horizontal(&info, map, x, y, color_h);
	// draw_vertical(&info, map, x, y, color_v);
	i = 0;
	j = 0;
	draw.map_x = malloc(map->y * sizeof(int *));
	draw.map_y = malloc(map->y * sizeof(int *));
	while (i < map->y)
	{
		while (j < map->x)
		{
			draw.map_x[i] = malloc(map->x * sizeof(int));
			draw.map_y[i] = malloc(map->x * sizeof(int));
			j++;
		}
		j = 0;
		i++;
	}
	i = 0;
	j = 0;
	draw.x = 150;
	draw.y = 10;
	draw.y_prev = -1;
	while (i < map->y)
	{
		while (j < map->x)
		{
			draw.x = 150 + j*14;
			draw.y = 10 + i*14;
			calc_coord_horiz(&draw, map->map[i][j], &info);//, map->x, j);
			//if (draw.y_prev > 0)// && (j + 1) < map->x)
				// bresenham_r(draw.x_prev, draw.y_prev, draw.x, draw.y, &info);

			draw.map_x[i][j] = draw.x;
			draw.map_y[i][j] = draw.y;
			printf("draw.map_y: %d, draw.map_x: %d\n", draw.map_x[i][j], draw.map_y[i][j]);

			j++;
		}
		j = 0;
		i++;
	}
	draw.y_prev = -1;
	j = 1;
	i = 0;
	while (i < map->x)
	{
		while (j < map->y)
		{
			printf("--prev x: %d, prev y: %d, x1: %d, y1: %d\n", draw.map_x[j - 1][i], draw.map_y[j - 1][i], draw.map_x[j][i], draw.map_y[j][i]);

			//THIS ONE WORKSdraw_between_coord_v(draw.map_x[j][i], draw.map_y[j][i], draw.map_x[j - 1][i], draw.map_y[j - 1][i], &info);
			//draw_between_coord_v(draw.map_x[j - 1][i], draw.map_y[j - 1][i], draw.map_x[j][i], draw.map_y[j][i],  &info);
			bresenham_g(draw.map_x[j - 1][i], draw.map_y[j - 1][i], draw.map_x[j][i], draw.map_y[j][i],  &info);
			//Bresenham works here!
			j++;
		}
		j = 1;
		i++;
	}

	mlx_put_image_to_window(mlxptr, window, info.img, 0, 0);
	mlx_loop(mlxptr);
}

int	main(int argc, char *argv[])
{
	t_map map;

	/*map.map = */parse_map(argv, &map);
	fdf(&map);
	argc = 1; //weghalen
}