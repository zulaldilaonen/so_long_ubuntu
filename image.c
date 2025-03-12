/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuonen <zuonen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 20:35:01 by zuonen            #+#    #+#             */
/*   Updated: 2025/03/11 17:41:48 by zuonen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	prepare_images(t_game *g, int *r, void *mlx)
{
	g->player->player_img = mlx_xpm_file_to_image(mlx, PLAYER_SRC, r, r);
	g->coins->coin_img = mlx_xpm_file_to_image(mlx, COIN_SRC, r, r);
	g->exit_imgs[0] = mlx_xpm_file_to_image(mlx, EXITA_SRC, r, r);
	g->wall_img = mlx_xpm_file_to_image(mlx, WALL_SRC, r, r);
	g->exit_imgs[1] = mlx_xpm_file_to_image(mlx, EXITDA_SRC, r, r);
	g->floor_img = mlx_xpm_file_to_image(mlx, FLOOR_SRC, r, r);
}

void	initialize_images(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		error_code(-500, game);
	}
	game->window = mlx_new_window(game->mlx, (RES * game->map->row_len),
			(RES * game->map->row_num), "So_long");
	if (!game->window)
	{
		error_code(-500, game);
	}
	game->exit_imgs = (void **)malloc(sizeof(void *) * 2);
	if (!game->exit_imgs)
	{
		error_code(-500, game);
	}
	game->res = RES;
	prepare_images(game, &game->res, game->mlx);
}
