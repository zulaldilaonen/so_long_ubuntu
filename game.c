/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuonen <zuonen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 20:31:21 by zuonen            #+#    #+#             */
/*   Updated: 2025/03/09 14:11:48 by zuonen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_exit(t_game *g, int i, int j)
{
	if (g->coins == NULL || g->coins->coins_c == NULL || g->exit_imgs == NULL)
	{
		error_code(-500, g);
	}
	if (*g->coins->coins_c != 0)
	{
		mlx_put_image_to_window(g->mlx, g->window, g->exit_imgs[1], j * RES,
			i * RES);
	}
	else
	{
		mlx_put_image_to_window(g->mlx, g->window, g->exit_imgs[0], j * RES,
			i * RES);
	}
}

void	display_floor(t_game *g, int i, int j)
{
	if (g->mlx == NULL || g->window == NULL || g->floor_img == NULL)
	{
		error_code(-500, g);
	}
	mlx_put_image_to_window(g->mlx, g->window, g->floor_img, j * RES, i * RES);
}

void	display_wall(t_game *g, int i, int j)
{
	if (g->mlx == NULL || g->window == NULL || g->wall_img == NULL)
	{
		error_code(-500, g);
	}
	mlx_put_image_to_window(g->mlx, g->window, g->wall_img, j * RES, i * RES);
}

void	display_coin(t_game *g, int i, int j)
{
	if (g->mlx == NULL || g->window == NULL || g->coins == NULL
		|| g->coins->coin_img == NULL)
	{
		error_code(-500, g);
	}
	mlx_put_image_to_window(g->mlx, g->window, g->coins->coin_img, j * RES,
		i * RES);
}

void	display_player(t_game *g, int i, int j)
{
	if (g->mlx == NULL || g->window == NULL || g->player == NULL
		|| g->player->player_img == NULL)
	{
		error_code(-500, g);
	}
	mlx_put_image_to_window(g->mlx, g->window, g->player->player_img, j * RES,
		i * RES);
}
