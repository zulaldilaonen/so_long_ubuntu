/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuonen <zuonen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 20:35:53 by zuonen            #+#    #+#             */
/*   Updated: 2025/03/11 17:36:35 by zuonen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	**occurmatris(int i, int j, t_game *game)
{
	int	**rt;
	int	a;

	rt = (int **)malloc(sizeof(int *) * i);
	if (!rt)
		error_code(-500, game);
	a = 0;
	while (a < i)
	{
		rt[a] = (int *)malloc(sizeof(int) * j);
		if (!rt[a])
			error_code(-500, game);
		a++;
	}
	return (rt);
}

int	**initalize_positions(t_map *map, char c, t_game *game)
{
	int	i;
	int	j;
	int	**rt;
	int	count;

	count = 0;
	rt = occurmatris(count_character(map, c), 2, game);
	i = -1;
	while (map->map[++i])
	{
		j = -1;
		while (map->map[i][++j])
		{
			if (map->map[i][j] == c)
			{
				rt[count][0] = i;
				rt[count][1] = j;
				count++;
			}
		}
	}
	return (rt);
}

void	initalize_player_positions(t_map *map, t_player *player)
{
	int	i;
	int	j;

	i = -1;
	while (map->map[++i])
	{
		j = -1;
		while (map->map[i][++j])
		{
			if (map->map[i][j] == 'P')
			{
				player->player_i = i;
				player->player_j = j;
			}
		}
	}
}

void	initalize_exit_positions(t_map *map, t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (map->map[++i])
	{
		j = -1;
		while (map->map[i][++j])
		{
			if (map->map[i][j] == 'E')
			{
				game->exit_i = i;
				game->exit_j = j;
			}
		}
	}
}

void	init_structures(t_game *game)
{
	t_coins		*coins;
	t_player	*player;

	coins = (t_coins *)malloc(sizeof(t_coins));
	player = (t_player *)malloc(sizeof(t_player));
	if (!coins || !player)
		error_code(-500, game);
	coins->coins_c = &game->map->coins;
	coins->coin_pos = initalize_positions(game->map, 'C', game);
	initalize_player_positions(game->map, player);
	game->m = game->map->map;
	game->coins = coins;
	game->player = player;
	game->move = 0;
	game->coin = game->map->coins;
	game->player_i = &game->player->player_i;
	game->player_j = &game->player->player_j;
	initalize_exit_positions(game->map, game);
}
