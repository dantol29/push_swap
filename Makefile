CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
LIBFT = libft
SRCS = src/push_swap.c src/utils.c src/operations.c src/memory.c src/errors.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -L./$(LIBFT) -lft -o $(NAME)

clean:
	rm -rf $(LIBFT)/*.o
	rm -rf $(OBJS)

fclean: clean
	rm -f $(LIBFT)/libft.a
	rm -Rf $(NAME).exe

re: fclean all

.PHONY: all clean fclean re