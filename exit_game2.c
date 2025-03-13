/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuonen <zuonen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 21:22:09 by zuonen            #+#    #+#             */
/*   Updated: 2025/03/13 22:11:56 by zuonen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_game(t_game *game)
{
	if (!game)
		return ;
	if (game->m)
		free_argv(game->m);
	free_map_data(game);
	free_player_data(game);
	if (game->coins)
		free_coins_data(game);
	if (game->exit_imgs)
		free_exit_imgs_data(game);
	free_mlx_data(game);
	free(game);
	game = NULL;
	exit(EXIT_SUCCESS);
}

void	exit_game2(t_game *game)
{
	if (!game)
		return ;
	free_map_data(game);
	free_player_data(game);
	free_coins_data(game);
	free_exit_imgs_data(game);
	free_mlx_data(game);
	free(game);
	game = NULL;
	exit(EXIT_SUCCESS);
}
