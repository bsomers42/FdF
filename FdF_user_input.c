/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   FdF_user_input.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: bsomers <bsomers@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/10 14:19:38 by bsomers       #+#    #+#                 */
/*   Updated: 2022/06/10 14:26:45 by bsomers       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

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

void	move_keys(mlx_key_data_t keydata, t_press *press)
{
	if (keydata.key == MLX_KEY_PAGE_UP && (keydata.action == MLX_PRESS || \
	keydata.action == MLX_REPEAT))
		press->ptr->z_key = press->ptr->z_key + 5;
	else if (keydata.key == MLX_KEY_PAGE_DOWN && \
	(keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		press->ptr->z_key = press->ptr->z_key - 5;
	else if (keydata.key == MLX_KEY_EQUAL && (keydata.action == MLX_PRESS || \
	keydata.action == MLX_REPEAT))
		press->ptr->zoom = press->ptr->zoom + 1;
	else if (keydata.key == MLX_KEY_MINUS && (keydata.action == MLX_PRESS || \
	keydata.action == MLX_REPEAT))
		press->ptr->zoom = press->ptr->zoom - 1;
	else if (keydata.key == MLX_KEY_D && (keydata.action == MLX_PRESS || \
	keydata.action == MLX_REPEAT))
		press->ptrbr->move_x = press->ptrbr->move_x + 10;
	else if (keydata.key == MLX_KEY_A && (keydata.action == MLX_PRESS || \
	keydata.action == MLX_REPEAT))
		press->ptrbr->move_x = press->ptrbr->move_x - 10;
	else if (keydata.key == MLX_KEY_S && (keydata.action == MLX_PRESS || \
	keydata.action == MLX_REPEAT))
		press->ptrbr->move_y = press->ptrbr->move_y + 10;
	else if (keydata.key == MLX_KEY_W && (keydata.action == MLX_PRESS || \
	keydata.action == MLX_REPEAT))
		press->ptrbr->move_y = press->ptrbr->move_y - 10;
}

void	fdf_keyhook(mlx_key_data_t keydata, void *param)
{
	t_press	*press;

	press = (t_press *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		exit(EXIT_SUCCESS);
	move_keys(keydata, press);
	if (keydata.key == MLX_KEY_C && (keydata.action == MLX_PRESS || \
	keydata.action == MLX_REPEAT))
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
	mlx_delete_image(press->mlx, press->ptr->g_img);
	press->ptr->g_img = mlx_new_image(press->mlx, WIDTH, HEIGHT);
	make_raster(press->ptr, press->ptrm, press->ptrbr, press->ptr->g_img);
	mlx_image_to_window(press->mlx, press->ptr->g_img, 0, 0);
	return ;
}
