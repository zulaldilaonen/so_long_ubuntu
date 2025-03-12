/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuonen <zuonen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 21:22:09 by zuonen            #+#    #+#             */
/*   Updated: 2025/03/11 17:41:21 by zuonen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_game(t_game *game)
{
	int i;

	i = 0;
	if (!game)
		return ;
	if(game->m)
	{
		while(game->m[i])
		{
			free(game->m[i]);
			i++;
		}
		free(game->m);
	}
	free_map_data(game);
	free_player_data(game);
	free_coins_data(game);
	free_exit_imgs_data(game);
	free_mlx_data(game);
	free(game);
	game = NULL;
	exit(EXIT_SUCCESS);
}
