/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   FdF.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: bsomers <bsomers@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/22 10:32:41 by bsomers       #+#    #+#                 */
/*   Updated: 2022/05/11 14:13:11 by bsomers       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

// mlx_init(); //sets up connection to graphical system. If it fails, it returns NULL.

// mlx_new_window(); //manage windows
// mlx_pixel_put(); //draw nside window
// mlx_new_image(); //maniulate images
// mlx_loop(); //handle keyboard our mouse events

void	pixel_put(t_struct *info, int x, int y, int color)
{
	char *dst;

	dst = info->addr + (y * info->len_line + x * (info->bpp / 8));
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
	void *mlxptr;
	void *window;
	int i;
	int j = 0;
	int color;
	int x;
	// int a;
	// int b;


	color = 0x0fffffe;
	calc_size_window(map);
	if ((map->win_h * 1.5) == map->win_w)
		x = (map->win_w / 2) + 25;
	else
		x = (map->win_w / 3) + 25;
	// if (map->y > map->x)
	// {
	// 	a = (map->x + map->y);
	// 	b = map->y / a;
	// 	x = (b) * map->win_w;
	// }
	// else
	// {
	// 	a = (map->x + map->y);
	// 	b = map->x / a;
	// 	x = (b) * map->win_w;
	// }
	//int x = map->win_w * 0.35;
	int y = map->y * 2;

	ft_printf("x: %d, y: %d\n", map->x, map->y);
	i = 0;
	mlxptr = mlx_init();
	if (mlxptr == NULL)
		if_error("Could not connect to mlx");
	window = mlx_new_window(mlxptr, map->win_w, map->win_h, "FdF bsomers");
	info.img = mlx_new_image(mlxptr, map->win_w, map->win_h);
	info.addr = mlx_get_data_addr(info.img, &info.bpp, &info.len_line, &info.endian);
	while (j < map->y)
	{
		while (i < map->x)
		{
			draw_tile(&info, /*map,*/ x, y, color);
			x = x + 20;
			y = y + 10;
			i++;
		}
		x = x - ((i + 1) * 20);
		y = y - ((i - 1) * 10);
		i = 0;
		j++;
	}
	mlx_put_image_to_window(mlxptr, window, info.img, 0, 0);
	mlx_loop(mlxptr);
}

int	main(int argc, char *argv[])
{
	t_map map;

	map.map = parse_map(argv, &map);
	fdf(&map);
	argc = 1; //weghalen
}