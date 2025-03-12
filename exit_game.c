/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuonen <zuonen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 21:20:30 by zuonen            #+#    #+#             */
/*   Updated: 2025/03/11 17:54:20 by zuonen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map_data(t_game *game)
{
	if (game->map)
		free(game->map);
}

void	free_player_data(t_game *game)
{
	if (game->player)
	{
		if (game->player->player_img && game->mlx)
			mlx_destroy_image(game->mlx, game->player->player_img);
		free(game->player);
	}
}

void	free_coins_data(t_game *game)
{
	int	i;

	i = 0;
	if (!game || !game->coins)
		return;

	if (game->coins->coin_img && game->mlx)
	{
		mlx_destroy_image(game->mlx, game->coins->coin_img);
		game->coins->coin_img = NULL;
	}
	if (game->coins->coin_pos )
	{
		while (i < game->coin)
		{
			free(game->coins->coin_pos[i]);
			i++;
		}
	}
	free(game->coins->coin_pos);
	free(game->coins);
}

void	free_exit_imgs_data(t_game *game)
{
	int	i;

	if (game->exit_imgs && game->mlx)
	{
		i = 0;
		while (i < 2)
		{
			if (game->exit_imgs[i] && game->mlx)
				mlx_destroy_image(game->mlx, game->exit_imgs[i]);
			i++;
		}
		free(game->exit_imgs);
	}
}

void	free_mlx_data(t_game *game)
{
	if (game->wall_img && game->mlx)
		mlx_destroy_image(game->mlx, game->wall_img);
	if (game->floor_img && game->mlx)
		mlx_destroy_image(game->mlx, game->floor_img);
	if (game->mlx)
	{
		if (game->window)
			mlx_destroy_window(game->mlx, game->window);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
}