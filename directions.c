/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuonen <zuonen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 20:39:52 by zuonen            #+#    #+#             */
/*   Updated: 2025/03/10 20:28:04 by zuonen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	to_left(t_game *game)
{
	int	i;
	int	j;

	i = *game->player_i;
	j = *game->player_j;
	if (j > 0)
	{
		if (game->map->map[i][j - 1] == 'E')
			check_exit(game);
		else if (game->map->map[i][j - 1] != '1')
			game->move++;
		if (game->map->map[i][j - 1] == '0')
			move_action(game, i, j, 0);
		if (game->map->map[i][j - 1] == 'C')
		{
			collectible_items(game->coins, i, j - 1);
			move_action(game, i, j, 0);
			display_coordinate(game, game->exit_i, game->exit_j);
		}
	}
}

void	to_down(t_game *game)
{
	int	i;
	int	j;

	i = *game->player_i;
	j = *game->player_j;
	if (i < game->map->row_num)
	{
		if (game->map->map[i + 1][j] == 'E')
			check_exit(game);
		else if (game->map->map[i + 1][j] != '1')
			game->move++;
		if (game->map->map[i + 1][j] == '0')
			move_action(game, i, j, 1);
		if (game->map->map[i + 1][j] == 'C')
		{
			collectible_items(game->coins, i + 1, j);
			move_action(game, i, j, 1);
			display_coordinate(game, game->exit_i, game->exit_j);
		}
	}
}

void	to_right(t_game *game)
{
	int	i;
	int	j;

	i = *game->player_i;
	j = *game->player_j;
	if (j < game->map->row_len)
	{
		if (game->map->map[i][j + 1] == 'E')
			check_exit(game);
		else if (game->map->map[i][j + 1] != '1')
			game->move++;
		if (game->map->map[i][j + 1] == '0')
			move_action(game, i, j, 2);
		if (game->map->map[i][j + 1] == 'C')
		{
			collectible_items(game->coins, i, j + 1);
			move_action(game, i, j, 2);
			display_coordinate(game, game->exit_i, game->exit_j);
		}
	}
}

void	to_up(t_game *game)
{
	int	i;
	int	j;

	i = *game->player_i;
	j = *game->player_j;
	if (i > 0)
	{
		if (game->map->map[i - 1][j] == 'E')
			check_exit(game);
		else if (game->map->map[i - 1][j] != '1')
			game->move++;
		if (game->map->map[i - 1][j] == '0')
			move_action(game, i, j, 13);
		if (game->map->map[i - 1][j] == 'C')
		{
			collectible_items(game->coins, i - 1, j);
			move_action(game, i, j, 13);
			display_coordinate(game, game->exit_i, game->exit_j);
		}
	}
}
