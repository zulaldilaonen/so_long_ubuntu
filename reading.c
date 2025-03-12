/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuonen <zuonen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 20:38:25 by zuonen            #+#    #+#             */
/*   Updated: 2025/03/10 20:28:24 by zuonen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_left(t_game *game, int i, int j)
{
	game->map->map[i][j] = '0';
	game->map->map[i][j - 1] = 'P';
	*game->player_j -= 1;
}

void	move_down(t_game *game, int i, int j)
{
	game->map->map[i][j] = '0';
	game->map->map[i + 1][j] = 'P';
	*game->player_i += 1;
}

void	move_right(t_game *game, int i, int j)
{
	game->map->map[i][j] = '0';
	game->map->map[i][j + 1] = 'P';
	*game->player_j += 1;
}

void	move_up(t_game *game, int i, int j)
{
	game->map->map[i][j] = '0';
	game->map->map[i - 1][j] = 'P';
	*game->player_i -= 1;
}

void	move_action(t_game *game, int i, int j, int key)
{
	if (key == 0)
		move_left(game, i, j);
	if (key == 1)
		move_down(game, i, j);
	if (key == 2)
		move_right(game, i, j);
	if (key == 13)
		move_up(game, i, j);
	render_move(game, key);
	move_count(game->move);
}
