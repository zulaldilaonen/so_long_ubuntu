/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuonen <zuonen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 20:37:26 by zuonen            #+#    #+#             */
/*   Updated: 2025/03/14 02:55:07 by zuonen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	validate_walls_free(int err_code, t_map *rt_map, t_game *game)
{
	free_argv(rt_map->map);
	free(rt_map);
	error_code(err_code, game);
}

void	validate_walls(t_map *rt_map, t_game *game)
{
	int	i;

	i = 0;
	while (rt_map->map[0][i])
	{
		if (rt_map->map[0][i++] != '1')
			validate_walls_free(-5, rt_map, game);
	}
	i = 0;
	while (rt_map->map[rt_map->row_num - 1][i])
	{
		if (rt_map->map[rt_map->row_num - 1][i++] != '1')
			validate_walls_free(-5, rt_map, game);
	}
	i = rt_map->row_num - 2;
	while (i > 0)
	{
		if (rt_map->map[i][0] != '1')
			validate_walls_free(-5, rt_map, game);
		if (rt_map->map[i][rt_map->row_len - 1] != '1')
			validate_walls_free(-5, rt_map, game);
		i--;
	}
}

void	validate_mapsize(t_map *rt_map, t_game *game)
{
	int	i;

	i = 0;
	rt_map->row_len = ft_strlen(rt_map->map[0]);
	while (rt_map->map[i])
	{
		if (ft_strlen(rt_map->map[i]) != rt_map->row_len)
		{
			free_argv(rt_map->map);
			free(rt_map);
			error_code(-2, game);
		}
		i++;
	}
	rt_map->row_num = i;
	if (i > 128 || rt_map->row_len > 128)
	{
		write(2, "Error map size is bigger than 128\n", 34);
		free_argv(rt_map->map);
		free(rt_map);
		exit_game_error(game);
	}
}

t_map	*initialize_map(char *src, t_game *game)
{
	t_map	*rt_map;

	rt_map = (t_map *)malloc(sizeof(t_map));
	if (!rt_map)
	{
		free(rt_map);
		error_code(-500, game);
	}
	if (ft_strcmp(src + ft_strrchr(src, '.') + 1, "ber") == 0)
	{
		free(rt_map);
		error_code(-1, game);
	}
	read_map(rt_map, src, 0, game);
	validate_mapsize(rt_map, game);
	count_map(rt_map, game);
	validate_walls(rt_map, game);
	can_accesable(rt_map, game);
	read_map(rt_map, src, 1, game);
	return (rt_map);
}
