/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   FdF.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: bsomers <bsomers@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/22 10:32:41 by bsomers       #+#    #+#                 */
/*   Updated: 2022/06/09 17:25:25 by bsomers       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"
#include <stdio.h> //wegggg

void	get_color(t_press *press)
{
	if (press->ptr->c_key == 0)
		press->ptr->color = WHITE;
	else if (press->ptr->c_key == 1)
		press->ptr->color = YELLOW;
	else if (press->ptr->c_key == 2)
		press->ptr->color = GREEN;
	else if (press->ptr->c_key == 3)
		press->ptr->color = BLUE;
	else if (press->ptr->c_key == 4)
		press->ptr->color = RED;
	else if (press->ptr->c_key == 5)
		press->ptr->color = BLACK;
}

void	fdf_keyhook(mlx_key_data_t keydata, void* param)
{
	t_press *press; 

	press = (t_press *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		exit(EXIT_SUCCESS);
	else if (keydata.key == MLX_KEY_PAGE_UP && keydata.action == MLX_PRESS)
	{
		press->ptr->z_key = press->ptr->z_key + 5;
		printf("z_key: %d\n", press->ptr->z_key);
	}
	else if (keydata.key == MLX_KEY_PAGE_DOWN && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
	{
		press->ptr->z_key = press->ptr->z_key - 5;
		printf("z_key: %d\n", press->ptr->z_key);
	}
	else if (keydata.key == MLX_KEY_EQUAL && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
	{
		press->ptr->zoom = press->ptr->zoom + 1;
		printf("zoom: %d\n", press->ptr->zoom);
	}
	else if (keydata.key == MLX_KEY_MINUS && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
	{
		press->ptr->zoom = press->ptr->zoom - 1;
		printf("zoom: %d\n", press->ptr->zoom);
	}
	else if (keydata.key == MLX_KEY_D && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
	{
		press->ptrbr->move_x = press->ptrbr->move_x + 10;
		printf("move right: %d\n", press->ptrbr->move_x);
	}
	else if (keydata.key == MLX_KEY_A && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
	{
		press->ptrbr->move_x = press->ptrbr->move_x - 10;
		printf("move left: %d\n", press->ptrbr->move_x);
	}
	else if (keydata.key == MLX_KEY_S && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
	{
		press->ptrbr->move_y = press->ptrbr->move_y + 10;
		printf("move down: %d\n", press->ptrbr->move_y);
	}
	else if (keydata.key == MLX_KEY_W && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
	{
		press->ptrbr->move_y = press->ptrbr->move_y - 10;
		printf("move up: %d\n", press->ptrbr->move_y);
	}
	else if (keydata.key == MLX_KEY_C && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
	{
		if (press->ptr->c_key < 5)
		{
			press->ptr->c_key++;
			get_color(press);
		}
		else
		{
			press->ptr->c_key = 0;
			get_color(press);
		}
	}
	mlx_delete_image(press->mlx, press->ptr->g_img); // Once the application request an exit, cleanup.
	press->ptr->g_img = mlx_new_image(press->mlx, WIDTH, HEIGHT);
	make_raster(press->ptr, press->ptrm, press->ptrbr, press->ptr->g_img);
	mlx_image_to_window(press->mlx, press->ptr->g_img, 0, 0);  // Adds an image to the render queue.
	return ;
}

void	write_instructions(t_press *press)
{
	mlx_put_string(press->mlx, "______________", 24, 26);
	mlx_put_string(press->mlx, "| KEY USE FdF |", 20, 23);
	mlx_put_string(press->mlx, "______________", 24, 7);
	mlx_put_string(press->mlx, "Zoom in: [-]", 24, 50);
	mlx_put_string(press->mlx, "Zoom out: [+]", 24, 70);
	mlx_put_string(press->mlx, "Higher: [Page Up]", 24, 90);
	mlx_put_string(press->mlx, "Lower: [Page Down]", 24, 110);
	mlx_put_string(press->mlx, "Move: [W][A][S][D]", 24, 130);
	mlx_put_string(press->mlx, "Change color: [C]", 24, 150);
}

int	main(int argc, char *argv[])
{
	t_map	map;

	parse_map(argv, &map);
	argc = 1; //weghalen
	t_draw	draw;
	t_br br;
	t_press press;

	press.ptr = &draw;
	press.ptrm = &map;
	press.ptrbr = &br;
	draw.color = WHITE;
	draw.c_key = 0;
	draw.z_key = 0;
	draw.zoom = 10;
	br.move_x = 0;
	br.move_y = 0;
	press.mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!press.mlx)
		if_error("Could not init MLX");
	draw.g_img = mlx_new_image(press.mlx, WIDTH, HEIGHT);
	make_raster(&draw, &map, &br, draw.g_img);
	write_instructions(&press);
	mlx_key_hook(press.mlx, &fdf_keyhook, &press);
	mlx_image_to_window(press.mlx, draw.g_img, 0, 0);  // Adds an image to the render queue.
	mlx_loop(press.mlx);
	mlx_delete_image(press.mlx, draw.g_img); // Once the application request an exit, cleanup.
	mlx_terminate(press.mlx);
}
