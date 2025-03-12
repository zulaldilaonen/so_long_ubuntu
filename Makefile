CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
LDFLAGS = -Lminilibx-linux
MLX = minilibx-linux/libmlx.a
NAME = so_long

SRC = ft_itoa.c control1.c control2.c directions.c  exit_game.c \
	exit_game2.c ft_split.c game.c image.c main.c move.c\
    map.c map2.c others.c reading.c reading2.c render.c\
    ft_memcpy.c main2.c

OBJ = $(SRC:.c=.o)

LDLIBS = -lmlx -lX11 -lXext
MINILIB_LINUX = minilibx-linux/libmlx.a

all: $(NAME)

$(NAME): $(OBJ) $(MINILIB_LINUX)
	$(CC) $(OBJ) -o $(NAME) $(LDFLAGS) $(LDLIBS)

$(MINILIB_LINUX):
	$(MAKE) -C minilibx-linux

clean:
	rm -f $(OBJ)
#$(MAKE) -C minilibx-linux clean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
