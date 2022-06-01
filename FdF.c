/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   FdF.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: bsomers <bsomers@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/22 10:32:41 by bsomers       #+#    #+#                 */
/*   Updated: 2022/06/01 17:53:21 by bsomers       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void	pixel_put(t_str *info, int *x, int *y, int color)
{
	char	*dst;

	dst = info->addr + (*y * info->len + *x * (info->bpp / 8));
	*(unsigned int *)dst = color;
}

void	calc_size_window(t_map *map)
{
	map->win_h = ((map->y + map->x) * 10) + 50;
	map->win_w = ((map->x + map->y) * 20) + 50;
}

void	fdf(t_map *map)
{
	t_str	info;
	t_draw	draw;
	void	*mlxptr;
	void	*window;
	int		x;

	calc_size_window(map);
	if ((map->win_h * 1.5) == map->win_w)
		x = (map->win_w / 2) + 25;
	else
		x = (map->win_w / 3) + 25;
	ft_printf("x: %d, y: %d\n", map->x, map->y);
	mlxptr = mlx_init();
	if (mlxptr == NULL)
		if_error("Could not connect to mlx");
	window = mlx_new_window(mlxptr, map->win_w, map->win_h, "FdF bsomers");
	info.img = mlx_new_image(mlxptr, map->win_w, map->win_h);
	info.addr = mlx_get_data_addr(info.img, &info.bpp, &info.len, &info.endian);
	make_raster(&draw, map, &info);
	mlx_put_image_to_window(mlxptr, window, info.img, 0, 0);
	mlx_loop(mlxptr);
}

int	main(int argc, char *argv[])
{
	t_map	map;

	parse_map(argv, &map);
	fdf(&map);
	argc = 1; //weghalen
}
