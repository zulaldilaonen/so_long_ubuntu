/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuonen <zuonen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 20:34:30 by zuonen            #+#    #+#             */
/*   Updated: 2025/03/09 14:41:09 by zuonen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putnbr(int nb)
{
	char	c;

	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		nb = nb % 10;
	}
	if (nb < 10)
	{
		c = (nb + 48);
		write(1, &c, 1);
	}
}

void	move_count(int num)
{
	write(1, "move = ", 7);
	ft_putnbr(num);
	write(1, "\n", 1);
}

void	display_move_count(t_game *game)
{
	char	*move;

	move = ft_itoa(game->move);
	mlx_string_put(game->mlx, game->window, 0, 16, 0x003090, "Move = ");
	mlx_string_put(game->mlx, game->window, 50, 16, 0x003090, move);
	free(move);
}

void	display_coin_count(t_game *game)
{
	char	*co;

	co = ft_itoa(game->coin - *game->coins->coins_c);
	mlx_string_put(game->mlx, game->window, 0, 30, 0x003090, "Score = ");
	mlx_string_put(game->mlx, game->window, 50, 30, 0x003090, co);
	free(co);
}

void	head_up_display_render(t_game *game)
{
	display_coordinate(game, 0, 0);
	display_coordinate(game, 0, 1);
	display_move_count(game);
	display_coin_count(game);
}
