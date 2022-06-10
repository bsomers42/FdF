/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   FdF_parse.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bsomers <bsomers@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/04 14:59:42 by bsomers       #+#    #+#                 */
/*   Updated: 2022/06/10 15:04:35 by bsomers       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

int	check_and_convert_map(t_map *map, char ***sep_lines, int x, int y)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	j = 0;
	temp = 0;
	malloc_map(map, x, y);
	while (i < y)
	{
		while (j < x)
		{
			temp = ft_atoi(sep_lines[i][j]);
			map->map[i][j] = temp;
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
	int	i;
	int	j;

	x = 0;
	i = 0;
	j = 0;
	while (i < y)
	{
		while (sep_lines[i][j])
			j++;
		if (i > 0 && j != x)
			if_error("Invalid map\n");
		x = j;
		j = 0;
		i++;
	}
	return (x);
}

int	get_y(char *map)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (map[i] != '\0')
	{
		if (map[i] == '\n')
			y++;
		i++;
	}
	return (y);
}

char	*get_map(char *argv[])
{
	char	*str;
	char	*strdef;
	int		fd;
	int		i;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		if_error("Map does not exist\n");
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
		free (str);
		i++;
	}
	return (strdef);
}

int	parse_map(char *argv[], t_map *map)
{
	char	*map_c;
	char	**lines;
	char	***sep_lines;
	int		i;

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
	check_and_convert_map(map, sep_lines, map->x, map->y);
	free(sep_lines);
	return (0);
}
