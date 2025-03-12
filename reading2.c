/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuonen <zuonen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 21:15:14 by zuonen            #+#    #+#             */
/*   Updated: 2025/03/11 14:14:00 by zuonen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_map *map)
{
	int	i;

	if (!map || !map->map)
		return ;
	i = 0;
	while (i < map->row_num)
	{
		free(map->map[i]);
		i++;
	}
	free(map->map);
	free(map);
}

void	check_exit(t_game *game)
{
	if (*game->coins->coins_c == 0)
	{
		game->move++;
		move_count(game->move);
		write(1, "THAT'S GREAT GIRL/BOY!\n", 24);
		exit_game(game);
	}
}

void	collectible_items(t_coins *c, int i, int j)
{
	int	num;
	int	*tmp;

	num = 0;
	while (num < *c->coins_c)
	{
		if (c->coin_pos[num][0] == i && c->coin_pos[num][1] == j)
		{
			tmp = c->coin_pos[num];
			c->coin_pos[num] = c->coin_pos[*c->coins_c - 1];
			c->coin_pos[*c->coins_c - 1] = tmp;
		}
		num++;
	}
	*c->coins_c -= 1;
}
