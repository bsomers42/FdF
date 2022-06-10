/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   FdF_utils.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bsomers <bsomers@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/22 10:42:37 by bsomers       #+#    #+#                 */
/*   Updated: 2022/06/10 15:07:59 by bsomers       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void	malloc_map(t_map *map, int x, int y)
{
	int	i;

	i = 0;
	map->map = malloc(y * sizeof(int *));
	while (i < y)
	{
		map->map[i] = malloc(x * sizeof(int));
		i++;
	}
}

void	if_error(char *str)
{
	ft_putstr_fd("\033[0;\e[1mfdf Error: \e[0m", 2);
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}

void	free_struct(t_map *map)
{
	int	i;

	i = 0;
	while (map->map[i])
	{
		free(map->map[i]);
		i++;
	}
	free(map->map);
}
