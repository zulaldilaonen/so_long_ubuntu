/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuonen <zuonen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 20:36:22 by zuonen            #+#    #+#             */
/*   Updated: 2025/03/09 13:49:28 by zuonen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	can_move(t_map *map, int i, int j)
{
	int	coin;

	coin = count_character(map, 'C');
	if (map->map[i][j] == '0' || map->map[i][j] == 'C' || map->map[i][j] == 'X')
		return (1);
	if (map->map[i][j] == 'E' && coin == 0)
		return (1);
	return (0);
}

void	mark_to_reach(t_map *map, int i, int j)
{
	if (can_move(map, i - 1, j))
		map->map[i - 1][j] = 'P';
	if (can_move(map, i + 1, j))
		map->map[i + 1][j] = 'P';
	if (can_move(map, i, j - 1))
		map->map[i][j - 1] = 'P';
	if (can_move(map, i, j + 1))
		map->map[i][j + 1] = 'P';
}

void	can_access_all(t_map *rt_map, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (rt_map->map[i])
	{
		j = 0;
		while (rt_map->map[i][j])
		{
			if (rt_map->map[i][j] == 'E' || rt_map->map[i][j] == 'C')
			{
				error_code(-6, game);
			}
			j++;
		}
		i++;
	}
}

void	can_accesable(t_map *rt_map, t_game *game)
{
	int	i;
	int	j;
	int	tmp;

	while (1)
	{
		tmp = count_character(rt_map, 'P');
		i = -1;
		while (rt_map->map[++i])
		{
			j = -1;
			while (rt_map->map[i][++j])
			{
				if (rt_map->map[i][j] == 'P')
					mark_to_reach(rt_map, i, j);
			}
		}
		if (tmp == count_character(rt_map, 'P'))
			break ;
	}
	can_access_all(rt_map, game);
}
