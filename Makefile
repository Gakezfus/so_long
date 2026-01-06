
SOURCES = $(wildcard *.c)

OBJECTS = $(SOURCES:%.c=%.o)

NAME = so_long

LIBFT = libft/libft.a

CFLAGS = -Wall -Wextra -Werror -Ilibft -I.mlx -g

all: $(NAME)

$(NAME): $(OBJECTS) $(LIBFT) so_long.h
	cc $(CFLAGS) $(OBJECTS) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C libft

%.o: %.c
	cc $(CFLAGS) -c $< -o $@

-include $(SRC:%.c=%.d)

clean:
	rm -f $(OBJECTS) $(OBJECTS:%.o=%.d)
	make clean -C libft

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)
	rm -f $(SOURCES:%.c=%.d)
	rm -f $(BONUS_SOURCES:%.c=%.d)
	make fclean -C libft

re: fclean all

.PHONY: all clean fclean re bonus
