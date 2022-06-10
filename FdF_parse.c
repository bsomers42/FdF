/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   FdF_parse.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bsomers <bsomers@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/04 14:59:42 by bsomers       #+#    #+#                 */
/*   Updated: 2022/06/10 13:24:40 by bsomers       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"
#include <stdio.h> //Weeggegegeg

int	check_and_convert_map(t_map *map, char ***sep_lines, int x, int y)
{
	int	i;
	int	j;
	// int **map_int;
	int temp;

	i = 0;
	j = 0;
	temp = 0;
	//map_int = malloc(y * sizeof(int *));
	map->map = malloc(y * sizeof(int *));
	while (i < y)
	{
		// map_int[i] = malloc(x * sizeof(int));
		map->map[i] = malloc(x * sizeof(int));
		i++;

	}
	i = 0;
	while (i < y)
	{
		while (j < x)
		{
				// if (isnumber(sep_lines[i][j][0] == 0)) DOES NOT WORK??
				// 	if_error("Invalid map");
			temp = ft_atoi(sep_lines[i][j]);
			//map_int[i][j] = temp;
			map->map[i][j] = temp;
			//ft_printf("%d ", map->map[i][j]);
			j++;
		}
		free_array(sep_lines[i]);
		j = 0;
		i++;
	}
	return (0);
}

int	get_x(char ***sep_lines, int y)
{
	int	x;
	int i;
	int j;

	x = 0;
	i = 0;
	j = 0;
	while (i < y)
	{
		while (sep_lines[i][j])
			j++;
		if (i > 0 && j != x)
			if_error("Invalid map");
		x = j;
		j = 0;
		i++;
	}
	return (x);
}

int	get_y(char *map)
{
	int i;
	int y;

	i = 0;
	y = 0;
	while (map[i] != '\0')
	{
		if (map[i] == '\n')
			y++;
		i++;
	}
	ft_printf("Lines(y): %d\n", y);
	return (y);
}

char	*get_map(char *argv[])
{
	char *str;
	char *strdef;
	int	fd;
	int i;

	fd = open(argv[1], O_RDONLY);
	str = "x";
	i = 0;
	while (str)
	{
		str = get_next_line(fd);
		if (str == NULL)
			break ;
		if (i == 0)
			strdef = ft_strdup(str);
		else
			strdef = ft_strjoin_fr(strdef, str);
		// ft_printf("strdef:\n %s\n", strdef);
		free (str);
		i++;
	}
	return (strdef);
}

int	parse_map(char *argv[], t_map *map)
{
	char *map_c;
	char **lines;
	char ***sep_lines;
	// int	**map_int;
	// int	y;
	//int	x;
	int	i;

	map_c = get_map(argv);
	i = 0;
	map->y = get_y(map_c);
	lines = ft_split(map_c, '\n');
	free(map_c);
	sep_lines = malloc(map->y * sizeof(int *));
	while (i < map->y)
	{
		sep_lines[i] = ft_split(lines[i], ' ');
		i++;
	}
	free_array(lines);
	map->x = get_x(sep_lines, map->y);
	ft_printf("X: %d\n", map->x);
	/*map_int =*/check_and_convert_map(map, sep_lines, map->x, map->y);
	ft_printf("==[%d]================================== ", map->map[2][3]);
	free(sep_lines);
	return (0);
}