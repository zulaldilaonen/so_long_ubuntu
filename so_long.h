/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuonen <zuonen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 20:28:57 by zuonen            #+#    #+#             */
/*   Updated: 2025/03/11 13:26:31 by zuonen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define RES 64

# include "minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

enum			e_events
{
	ON_KEYDOWN = 2,
	ON_DESTROY = 17
};

# define WALL_SRC "img/wall.xpm"
# define FLOOR_SRC "img/floor.xpm"
# define EXITA_SRC "img/exit.xpm"
# define PLAYER_SRC "img/player.xpm"
# define EXITDA_SRC "img/EDA.xpm"
# define COIN_SRC "img/coin.xpm"

typedef struct s_coins
{
	int			*coins_c;
	int			**coin_pos;
	int			frame;
	void		*coin_img;
}				t_coins;

typedef struct s_player
{
	int			player_i;
	int			player_j;
	int			frame;
	void		*player_img;
}				t_player;

typedef struct s_map
{
	int			row_len;
	int			row_num;
	int			coins;
	char		**map;
}				t_map;

typedef struct s_game
{
	void		*mlx;
	void		*window;
	void		*wall_img;
	void		*floor_img;
	void		**exit_imgs;
	int			move;
	int			res;
	int			coin;
	int			*player_i;
	int			*player_j;
	int			exit_i;
	int			exit_j;
	char		**m;
	t_map		*map;
	t_coins		*coins;
	t_player	*player;
}				t_game;

int				**occurmatris(int i, int j, t_game *game);
int				**initalize_positions(t_map *map, char c, t_game *game);
void			initalize_player_positions(t_map *map, t_player *player);
void			initalize_exit_positions(t_map *map, t_game *game);
void			init_structures(t_game *game);
int				can_move(t_map *map, int i, int j);
void			mark_to_reach(t_map *map, int i, int j);
void			can_access_all(t_map *rt_map, t_game *game);
void			can_accesable(t_map *rt_map, t_game *game);
void			to_left(t_game *game);
void			to_down(t_game *game);
void			to_right(t_game *game);
void			to_up(t_game *game);
char			*ft_itoa(int n);
char			**ft_split(char const *s, char c);
char			*ft_read(int fd);
char			*ft_strdup(const char *s1);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			display_exit(t_game *g, int i, int j);
void			display_floor(t_game *g, int i, int j);
void			display_wall(t_game *g, int i, int j);
void			display_coin(t_game *g, int i, int j);
void			display_player(t_game *g, int i, int j);
void			prepare_images(t_game *g, int *r, void *mlx);
void			initialize_images(t_game *game);
int				count_character(t_map *map, char c);
void			count_map(t_map *map, t_game *game);
int				count_line(char *str);
void			validate_walls(t_map *rt_map, t_game *game);
void			read_map(t_map *rt_map, char *src, int flag, t_game *game);
void			validate_mapsize(t_map *rt_map, t_game *game);
t_map			*initialize_map(char *src, t_game *game);
void			ft_putnbr(int nb);
void			move_count(int num);
void			display_move_count(t_game *game);
void			display_coin_count(t_game *game);
void			head_up_display_render(t_game *game);
int				ft_strcmp(char *s1, char *s2);
int				ft_strlen(const char *str);
int				ft_strrchr(char *str, int c);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char *s1, char *s2);
void			free_map(t_map *map);
void			check_exit(t_game *game);
void			collectible_items(t_coins *c, int i, int j);
void			move_action(t_game *game, int i, int j, int key);
void			free_map_data(t_game *game);
void			free_player_data(t_game *game);
void			free_coins_data(t_game *game);
void			free_exit_imgs_data(t_game *game);
void			free_mlx_data(t_game *game);
void			exit_game(t_game *game);
void			display_coordinate(t_game *game, int i, int j);
void			render_move(t_game *game, int code);
void			render_map(t_game *game);
void			error_code(int code, t_game *game);
int				key_hook(int keycode, t_game *game);
int				close_hook(t_game *game);

#endif
