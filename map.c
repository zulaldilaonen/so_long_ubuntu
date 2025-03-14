/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuonen <zuonen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 20:31:57 by zuonen            #+#    #+#             */
/*   Updated: 2025/03/14 08:43:45 by zuonen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_character(t_map *map, char c)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = -1;
	while (map->map[++i])
	{
		j = -1;
		while (map->map[i][++j])
		{
			if (map->map[i][j] == c)
				count++;
		}
	}
	return (count);
}

void	count_map_free(int err_code, t_map *map, t_game *game)
{
	free_map(map);
	error_code(err_code, game);
}

void	count_map(t_map *map, t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (map->map[++i])
	{
		j = -1;
		while (map->map[i][++j])
		{
			if (!(map->map[i][j] == '1' || map->map[i][j] == '0'
					|| map->map[i][j] == 'P' || map->map[i][j] == 'E'
					|| map->map[i][j] == 'C'))
			{
				free_argv(map->map);
				free(map);
				error_code(-3, game);
			}
		}
	}
	map->coins = count_character(map, 'C');
	if (count_character(map, 'P') != 1
		|| count_character(map, 'E') != 1
		|| map->coins == 0)
		count_map_free(-4, map, game);
}

int	count_line(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			count++;
		i++;
	}
	count++;
	return (count);
}
