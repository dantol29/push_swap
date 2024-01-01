CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
BONUS_NAME = checker
LIBFT = libft
SRCS = src/push_swap.c src/utils.c src/memory.c src/errors.c src/algorithm.c src/assign_index.c \
		src/rotate_and_push.c src/operations_a.c src/operations_b.c
BONUS_SRCS = checker/checker.c checker/checker_memory.c checker/checker_errors.c \
		checker/checker_operations_a.c checker/checker_operations_b.c checker/get_next_line.c
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -L./$(LIBFT) -lft -o $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS)
	@make -C $(LIBFT)
	$(CC) $(CFLAGS) $(BONUS_OBJS) -L./$(LIBFT) -lft -o $(BONUS_NAME)

clean:
	rm -rf $(LIBFT)/*.o
	rm -rf $(OBJS)
	rm -rf $(BONUS_OBJS)

fclean: clean
	rm -f $(LIBFT)/libft.a
	rm -f $(NAME).exe
	rm -f $(BONUS_NAME).exe

re: fclean all

.PHONY: all bonus clean fclean re