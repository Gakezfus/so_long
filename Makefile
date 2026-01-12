
SOURCES = $(wildcard *.c)

OBJECTS = $(SOURCES:%.c=%.o)

NAME = so_long

LIBFT = libft/libft.a

MLX = minilibx-linux/libmlx.a

CFLAGS = -Wall -Wextra -Werror -Ilibft -Iminilibx-linux -g

BONUS:= 0

all: $(NAME)

$(NAME): $(MLX) $(OBJECTS) $(LIBFT) so_long.h
	cc $(OBJECTS) $(CFLAGS) $(LIBFT) $(MLX) -lXext -lX11 -o $(NAME)

bonus: BONUS:= 1 $(NAME)

$(LIBFT):
	make -C libft

$(MLX):
	wget https://cdn.intra.42.fr/document/document/39937/minilibx-linux.tgz
	tar -xzf minilibx-linux.tgz
	rm -f minilibx-linux.tgz
	make -C minilibx-linux

%.o: %.c
	cc $(CFLAGS) -D BONUS=$(BONUS) -c $< -o $@

-include $(SRC:%.c=%.d)

clean:
	rm -f $(OBJECTS) $(OBJECTS:%.o=%.d)
	make clean -C libft

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)
	rm -f $(SOURCES:%.c=%.d)
	make fclean -C libft
	make clean -C minilibx-linux

re: fclean all

.PHONY: all clean fclean re bonus
