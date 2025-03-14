/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuonen <zuonen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 02:38:23 by zuonen            #+#    #+#             */
/*   Updated: 2025/03/14 02:38:28 by zuonen           ###   ########.fr       */
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

void	exit_game_error(t_game *game)
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

void	free_argv(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

void	ft_close_and_free(char *rd, char *rt, t_map *rt_map, t_game *game)
{
	ft_free_rr(rd, rt);
	free(rt_map);
	error_code(-10, game);
}

void	ft_free_rr(char *rd, char *rt)
{
	free(rd);
	free(rt);
}
