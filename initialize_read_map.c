/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_read_map.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuonen <zuonen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 02:35:19 by zuonen            #+#    #+#             */
/*   Updated: 2025/03/14 02:39:48 by zuonen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_map_helper(t_map *rt_map, char *rd, t_game *game)
{
	int	i;

	rt_map->map = ft_split(rd, '\n');
	if (!rt_map->map)
	{
		write(1, "Error: ft_split failed!\n", 25);
		free_argv(rt_map->map);
	}
	i = 0;
	while (rt_map->map[i])
		i++;
	if (i != count_line(rd))
	{
		free_argv(rt_map->map);
		free(rt_map);
		free(rd);
		error_code(-2, game);
	}
	free(rd);
}

void	read_map(t_map *rt_map, char *src, int flag, t_game *game)
{
	char	*rd;
	int		i;
	int		fd;

	fd = open(src, O_RDONLY);
	if (fd < 0)
	{
		free(rt_map);
		error_code(-404, game);
	}
	rd = ft_read(fd, game, rt_map);
	close(fd);
	if (flag == 1)
	{
		i = 0;
		while (rt_map->map[i])
			free(rt_map->map[i++]);
		free(rt_map->map);
	}
	read_map_helper(rt_map, rd, game);
}
