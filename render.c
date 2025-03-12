/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuonen <zuonen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 20:40:13 by zuonen            #+#    #+#             */
/*   Updated: 2025/03/09 14:46:38 by zuonen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_coordinate(t_game *game, int i, int j)
{
	if (!game || !game->map || !game->map->map || !game->player_i
		|| !game->player_j)
	{
		write(1, "Error: Invalid pointer\n", 24);
		exit(1);
	}
	display_floor(game, i, j);
	if (game->map->map[i][j] == '1')
		display_wall(game, i, j);
	if (game->map->map[i][j] == 'E')
		display_exit(game, i, j);
	if (game->map->map[i][j] == 'P')
		display_player(game, i, j);
	if (game->map->map[i][j] == 'C')
		display_coin(game, i, j);
}

void	render_move(t_game *game, int code)
{
	display_coordinate(game, *game->player_i, *game->player_j);
	if (code == 0)
		display_coordinate(game, *game->player_i, *game->player_j + 1);
	if (code == 1)
		display_coordinate(game, *game->player_i - 1, *game->player_j);
	if (code == 2)
		display_coordinate(game, *game->player_i, *game->player_j - 1);
	if (code == 13)
		display_coordinate(game, *game->player_i + 1, *game->player_j);
}

void	render_map(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map->map[++i])
	{
		j = -1;
		while (game->map->map[i][++j])
			display_coordinate(game, i, j);
	}
}
