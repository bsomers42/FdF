/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   FdF.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: bsomers <bsomers@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/22 10:32:41 by bsomers       #+#    #+#                 */
/*   Updated: 2022/06/10 15:41:47 by bsomers       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

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

void	init_values(t_draw *draw, t_map *map, t_br *br, t_press *press)
{
	press->ptr = draw;
	press->ptrm = map;
	press->ptrbr = br;
	draw->color = WHITE;
	draw->c_key = 0;
	draw->z_key = 0;
	draw->zoom = 10;
	br->move_x = 0;
	br->move_y = 0;
}

void	fdf_close(void *param)
{
	(void)param;
	exit(EXIT_SUCCESS);
}

int	main(int argc, char *argv[])
{
	t_map	map;
	t_draw	draw;
	t_br	br;
	t_press	press;

	if (argc != 2)
		if_error("wrong input. Usage: ./FdF <mapname>.fdf\n");
	init_values(&draw, &map, &br, &press);
	parse_map(argv, &map);
	press.mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!press.mlx)
		if_error("Could not init MLX\n");
	draw.g_img = mlx_new_image(press.mlx, WIDTH, HEIGHT);
	make_raster(&draw, &map, &br, draw.g_img);
	write_instructions(&press);
	mlx_key_hook(press.mlx, &fdf_keyhook, &press);
	mlx_close_hook(press.mlx, &fdf_close, NULL);
	mlx_image_to_window(press.mlx, draw.g_img, 0, 0);
	mlx_loop(press.mlx);
	mlx_delete_image(press.mlx, draw.g_img);
	mlx_terminate(press.mlx);
	free_struct(&map);
}
