/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuonen <zuonen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:55:26 by zuonen            #+#    #+#             */
/*   Updated: 2025/03/11 11:43:14 by zuonen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize_game_data(t_game *game)
{
	game->mlx = NULL;
	game->window = NULL;
	game->wall_img = NULL;
	game->floor_img = NULL;
	game->exit_imgs = NULL;
	game->player_i = NULL;
	game->player_j = NULL;
	game->map = NULL;
	game->coins = NULL;
	game->player = NULL;
	game->move = 0;
	game->res = 0;
	game->coin = 0;
	game->exit_i = -1;
	game->exit_j = -1;
}

int	load_map_and_init_game(int ac, char **av, t_game *game)
{
	if (ac != 2)
	{
		error_code(-42, game);
		return (1);
	}
	game->map = initialize_map(av[1], game);
	if (!game->map)
	{
		error_code(-42, game);
		return (1);
	}
	init_structures(game);
	initialize_images(game);
	render_map(game);
	head_up_display_render(game);
	return (0);
}

int	setup_game(int ac, char **av, t_game **game_ptr)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
	{
		error_code(-42, NULL);
		return (1);
	}
	initialize_game_data(game);
	if (load_map_and_init_game(ac, av, game) != 0)
	{
		free(game);
		return (1);
	}
	*game_ptr = game;
	return (0);
}

void	run_game_loop(t_game *game)
{
	mlx_hook(game->window, 2, 1L << 0, key_hook, game);
	mlx_hook(game->window, 17, 0, close_hook, game);
	mlx_loop(game->mlx);
}

int	main(int ac, char **av)
{
	t_game	*game;

	if (setup_game(ac, av, &game) != 0)
		return (1);
	run_game_loop(game);
	return (0);
}
