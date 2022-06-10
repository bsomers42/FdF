/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   FdF_utils.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bsomers <bsomers@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/22 10:42:37 by bsomers       #+#    #+#                 */
/*   Updated: 2022/06/10 13:49:30 by bsomers       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void    if_error(char *str)
{
    ft_putstr_fd("\033[0;\e[1mFdF Error: \e[0m", 2);
    ft_putstr_fd(str, 2);
    exit(EXIT_FAILURE);
}

void    free_structs(/*t_draw *draw, */t_map *map)
{
   	int i;
    int j;
    j = 0;
	i = 0;

   	// while (draw->map_x[i])
	// {
	// 	free(draw->map_x[i]);
    //     free(draw->map_y[i]);
	// 	i++;
    //     j = 0;
	// }
	// free(draw->map_y);
    // free(draw->map_x);
    // i = 0;
    // j = 0;
	while (map->map[i])
	{
		free(map->map[i]);
		i++;
    }
    free(map->map);
}