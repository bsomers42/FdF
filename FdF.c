/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   FdF.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: bsomers <bsomers@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/22 10:32:41 by bsomers       #+#    #+#                 */
/*   Updated: 2022/05/02 17:10:51 by bsomers       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

// mlx_init(); //sets up connection to graphical system. If it fails, it returns NULL.

// mlx_new_window(); //manage windows
// mlx_pixel_put(); //draw nside window
// mlx_new_image(); //maniulate images
// mlx_loop(); //handle keyboard our mouse events

int	main()
{
	void *mlxptr;
	void *window;

	mlxptr = mlx_init();
	if (mlxptr == NULL)
		if_error("could not connect to mlx");
	window = mlx_new_window(mlxptr, 300, 400, "FdF bsomers");
	mlx_loop(mlxptr);
}