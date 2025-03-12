/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuonen <zuonen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 20:59:33 by zuonen            #+#    #+#             */
/*   Updated: 2025/03/09 21:00:42 by zuonen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_code(int code, t_game *game)
{
	if (code == -1)
		write(2, "Error invalid extension\n", 25);
	else if (code == -2)
		write(2, "Error map is not rectangular\n", 29);
	else if (code == -3)
		write(2, "Error invalid component\n", 25);
	else if (code == -4)
		write(2, "Error invalid component count\n", 31);
	else if (code == -5)
		write(2, "Error invalid wall design\n", 27);
	else if (code == -6)
		write(2, "Error unreachable component exist\n", 35);
	else if (code == -42)
		write(2, "Error invalid argument count\n", 29);
	else if (code == -404)
		write(2, "Error file not found\n", 22);
	else if (code == -500)
		write(2, "Error Malloc\n", 14);
	else
		write(1, "Exit Game\n", 10);
	exit_game(game);
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == 65307)
		exit_game(game);
	if (keycode == 0 || keycode == 97 || keycode == 65361)
		to_left(game);
	if (keycode == 1 || keycode == 115 || keycode == 65364)
		to_down(game);
	if (keycode == 2 || keycode == 100 || keycode == 65363)
		to_right(game);
	if (keycode == 13 || keycode == 119 || keycode == 65362)
		to_up(game);
	head_up_display_render(game);
	render_move(game, keycode);
	return (0);
}

int	close_hook(t_game *game)
{
	exit_game(game);
	return (0);
}
