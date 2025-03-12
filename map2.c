/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuonen <zuonen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 20:37:26 by zuonen            #+#    #+#             */
/*   Updated: 2025/03/11 14:03:06 by zuonen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	validate_walls(t_map *rt_map, t_game *game)
{
	int	i;

	i = 0;
	while (rt_map->map[0][i])
	{
		if (rt_map->map[0][i++] != '1')
			error_code(-5, game);
	}
	i = 0;
	while (rt_map->map[rt_map->row_num - 1][i])
	{
		if (rt_map->map[rt_map->row_num - 1][i++] != '1')
			error_code(-5, game);
	}
	i = rt_map->row_num - 2;
	while (i > 0)
	{
		if (rt_map->map[i][0] != '1')
			error_code(-5, game);
		if (rt_map->map[i][rt_map->row_len - 1] != '1')
			error_code(-5, game);
		i--;
	}
}

void	read_map_helper(t_map *rt_map, char *rd, t_game *game)
{
	int	i;

	rt_map->map = ft_split(rd, '\n');
	if (!rt_map->map)
	{
		write(1, "Error: ft_split failed!\n", 25);
		exit(1);
	}
	i = 0;
	while (rt_map->map[i])
		i++;
	if (i != count_line(rd))
		error_code(-2, game);
	free(rd);
}

void	read_map(t_map *rt_map, char *src, int flag, t_game *game)
{
	char	*rd;
	int		i;
	int		fd;

	fd = open(src, O_RDONLY);
	if (fd < 0)
		error_code(-404, game);
	rd = ft_read(fd);
	close(fd);
	if (flag == 1)
	{
		i = 0;
		while (rt_map->map[i])
			free(rt_map->map[i++]);
		free(rt_map->map);
	}
	read_map_helper(rt_map, rd, game);
}

void	validate_mapsize(t_map *rt_map, t_game *game)
{
	int	i;

	i = 0;
	rt_map->row_len = ft_strlen(rt_map->map[0]);
	while (rt_map->map[i])
	{
		if (ft_strlen(rt_map->map[i]) != rt_map->row_len)
			error_code(-2, game);
		i++;
	}
	rt_map->row_num = i;
	if (i > 128 || rt_map->row_len > 128)
	{
		write(2, "Error map size is bigger than 128\n", 34);
		exit(1);
	}
}

t_map	*initialize_map(char *src, t_game *game)
{
	t_map	*rt_map;

	rt_map = (t_map *)malloc(sizeof(t_map));
	if (!rt_map)
		error_code(-500, game);
	if (ft_strcmp(src + ft_strrchr(src, '.') + 1, "ber") == 0)
		error_code(-1, game);
	read_map(rt_map, src, 0, game);
	validate_mapsize(rt_map, game);
	count_map(rt_map, game);
	validate_walls(rt_map, game);
	can_accesable(rt_map, game);
	read_map(rt_map, src, 1, game);
	return (rt_map);
}
