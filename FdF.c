/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   FdF.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: bsomers <bsomers@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/22 10:32:41 by bsomers       #+#    #+#                 */
/*   Updated: 2022/06/08 20:18:49 by bsomers       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"
#include <stdio.h> //wegggg

// void	pixel_put(t_str *info, int *x, int *y, int color)
// {
// 	char	*dst;

// 	dst = info->addr + (*y * info->len + *x * (info->bpp / 8));
// 	*(unsigned int *)dst = color;
// }

void	calc_size_window(t_map *map)
{
	// if ((((map->x + map->y) * 20) + 20) > NUM????)
	// {
	// 	map->win_h = NUMMM;
	// 	map->win_v = NUMMM;
	// }
	// else
	// int dia;

	// dia = (map->y^2) + (map->x^2);
	// dia = dia^2;
	// // if (map->x > map->y)
	// // {

	// // }
	// if (map->x == map->y)
	// {
	// 	map->win_h = (dia * 10) + 20;
	// 	map->win_w = map->win_h * 2;
	// }
	// // else


	// ft_printf("Dia: %d", dia);
	// // {
		map->win_h = ((map->y + map->x) * 10) + 20;
		map->win_w = ((map->x + map->y) * 20) + 20;
	// }
}

// void	fdf_move(mlx_key_data_t keydata, t_press *press)
// {
// 	if (keydata.key == MLX_KEY_UP)
// 		press->draw->
// 	if (keydata.key == MLX_KEY_DOWN)

// 	if (keydata.key == MLX_KEY_LEFT)
	
// 	if (keydata.key == MLX_KEY_RIGHT)

// }



void	fdf_keyhook(mlx_key_data_t keydata, void* param)
{

	//press = (t_press *)param;
	//param = 0;
	 
	//press.z_key = 0;
	//press.col = 0;
	t_press *press; 

	press = (t_press *)param;
	press->ptr->col = 0;

	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		exit(EXIT_SUCCESS);
	// if (keydata.key == MLX_KEY_UP) || keydata.key == MLX_KEY_DOWN || \
	// 	keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_RIGHT && \
	// 	keydata.action == MLX_PRESS)
	// 	fdf_move(keydata, press);
	else if (keydata.key == MLX_KEY_PAGE_UP && keydata.action == MLX_PRESS)
	{
		press->ptr->z_key = press->ptr->z_key + 5;
		printf("z_key: %d\n", press->ptr->z_key);
		// press->ptr->col = -1;
		
	}
	else if (keydata.key == MLX_KEY_PAGE_DOWN && keydata.action == MLX_PRESS)
	{
		press->ptr->z_key = press->ptr->z_key - 5;
		printf("z_key: %d\n", press->ptr->z_key);
		// press->ptr->col = -1;
	}
	else if (keydata.key == MLX_KEY_EQUAL && keydata.action == MLX_PRESS)
	{
		press->ptr->zoom = press->ptr->zoom + 1;
		printf("zoom: %d\n", press->ptr->zoom);
		// press->ptr->col = -1;
	}
	else if (keydata.key == MLX_KEY_MINUS && keydata.action == MLX_PRESS)
	{
		press->ptr->zoom = press->ptr->zoom - 1;
		printf("zoom: %d\n", press->ptr->zoom);
		// press->ptr->col = -1;
	}
	else if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
	{
		press->ptrbr->move_x = press->ptrbr->move_x + 10;
		printf("move right: %d\n", press->ptrbr->move_x);
		// press->ptr->col = -1;
	}
	else if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
	{
		press->ptrbr->move_x = press->ptrbr->move_x - 10;
		printf("move left: %d\n", press->ptrbr->move_x);
		// press->ptr->col = -1;
	}
	else if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
	{
		press->ptrbr->move_y = press->ptrbr->move_y + 10;
		printf("move down: %d\n", press->ptrbr->move_y);
		// press->ptr->col = -1;
	}
	else if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
	{
		press->ptrbr->move_y = press->ptrbr->move_y - 10;
		printf("move up: %d\n", press->ptrbr->move_y);
		// press->ptr->col = -1;
	}
	mlx_delete_image(press->mlx, press->ptr->g_img); // Once the application request an exit, cleanup.
	press->ptr->g_img = mlx_new_image(press->mlx, WIDTH, HEIGHT);
	make_raster(press->ptr, press->ptrm, press->ptrbr, press->ptr->g_img);
	mlx_image_to_window(press->mlx, press->ptr->g_img, 0, 0);  // Adds an image to the render queue.
	return ;
}


// void	fdf(t_map *map)
// {
// 	//t_str	info;
// 	t_draw	draw;
// 	void	*mlx;
// 	//void	*window;
// 	static	mlx_image_t *g_img;
// 	t_press press;

// 	calc_size_window(map);
// 	press.ptr = &draw;
// 	draw.z_key = 0;
// 	// mlxptr = mlx_init();
// 	// if (mlxptr == NULL)
// 	// 	if_error("Could not connect to mlx");
// 	// window = mlx_new_window(mlxptr, map->win_w, map->win_h, "FdF bsomers");
// 	// info.img = mlx_new_image(mlxptr, map->win_w, map->win_h);
// 	// info.addr = mlx_get_data_addr(info.img, &info.bpp, &info.len, &info.endian);
// 	// make_raster(&draw, map, &info);
// 	// mlx_put_image_to_window(mlxptr, window, info.img, 0, 0);
// 	// mlx_loop(mlxptr);
	
// 	mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
// 	if (!mlx)
// 		if_error("Could not init MLX");
// 	g_img = mlx_new_image(mlx, WIDTH, HEIGHT);
// 	make_raster(&draw, map, /*&info, */g_img);
// 	mlx_key_hook(mlx, &fdf_keyhook, &draw);

// 	mlx_image_to_window(mlx, g_img, 0, 0);  // Adds an image to the render queue.
// 	// mlx_key_hook(mlx, &fdf_keyhook, &draw);
// 	mlx_loop(mlx);
// 	printf("Value: %d", draw.col);

// 	//mlx_delete_image(mlx, g_img); // Once the application request an exit, cleanup.
// 	//mlx_terminate(mlx);
// 	printf("Value: %d", draw.col);
// }

// int	main(int argc, char *argv[])
// {
// 	t_map	map;

// 	parse_map(argv, &map);
// 	fdf(&map);
// 	argc = 1; //weghalen
// }


// void	fdf(t_map *map)
// {
// 	//t_str	info;
// 	t_draw	draw;
// 	void	*mlx;
// 	//void	*window;
// 	static	mlx_image_t *g_img;
// 	t_press press;

// 	calc_size_window(map);
// 	press.ptr = &draw;
// 	draw.z_key = 0;
// 	// mlxptr = mlx_init();
// 	// if (mlxptr == NULL)
// 	// 	if_error("Could not connect to mlx");
// 	// window = mlx_new_window(mlxptr, map->win_w, map->win_h, "FdF bsomers");
// 	// info.img = mlx_new_image(mlxptr, map->win_w, map->win_h);
// 	// info.addr = mlx_get_data_addr(info.img, &info.bpp, &info.len, &info.endian);
// 	// make_raster(&draw, map, &info);
// 	// mlx_put_image_to_window(mlxptr, window, info.img, 0, 0);
// 	// mlx_loop(mlxptr);
	
// 	mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
// 	if (!mlx)
// 		if_error("Could not init MLX");
// 	g_img = mlx_new_image(mlx, WIDTH, HEIGHT);
// 	make_raster(&draw, map, /*&info, */g_img);
// 	mlx_key_hook(mlx, &fdf_keyhook, &draw);

// 	mlx_image_to_window(mlx, g_img, 0, 0);  // Adds an image to the render queue.
// 	// mlx_key_hook(mlx, &fdf_keyhook, &draw);
// 	mlx_loop(mlx);
// 	printf("Value: %d", draw.col);

// 	//mlx_delete_image(mlx, g_img); // Once the application request an exit, cleanup.
// 	//mlx_terminate(mlx);
// 	printf("Value: %d", draw.col);
// }

// void	loop_hook(void)
// {
// 	make_raster();
// }

// int	loop(t_draw *draw, t_map *map, /*t_str *info, */mlx_image_t *g_img)
// {
// 	make_raster(draw, map, g_img);
// 	return (0);
// }

int	main(int argc, char *argv[])
{
	t_map	map;

	parse_map(argv, &map);
	//fdf(&map);
	argc = 1; //weghalen
	t_draw	draw;
	t_br br;
	// void	*mlx;
	//void	*window;
	//static	mlx_image_t *g_img;
	//void *g_img;
	t_press press;

	calc_size_window(&map);
	press.ptr = &draw;
	press.ptrm = &map;
	press.ptrbr = &br;
	draw.z_key = 0;
	draw.zoom = 10;
	br.move_x = 0;
	br.move_y = 0;
	// while (1)
	// {
	press.mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!press.mlx)
		if_error("Could not init MLX");
	draw.g_img = mlx_new_image(press.mlx, WIDTH, HEIGHT);
	ft_printf("firt Value of move x & y: %d, %d\n", br.move_x, br.move_y);

	make_raster(&draw, &map, &br, draw.g_img);
	// mlx_key_hook(mlx, &fdf_keyhook, &draw);
	// if (draw.col != 0)
	// {
	// 	mlx_loop_hook(mlx, (void*)loop, &draw);
	// 	printf("test: %d\n", draw.col);
	// }
	mlx_key_hook(press.mlx, &fdf_keyhook, &press);
	mlx_image_to_window(press.mlx, draw.g_img, 0, 0);  // Adds an image to the render queue.
	mlx_loop(press.mlx);
	// }
	mlx_delete_image(press.mlx, draw.g_img); // Once the application request an exit, cleanup.
	mlx_terminate(press.mlx);
}
