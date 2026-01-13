NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = main.c \
      push_swap.c \
      push_swap2.c \
      ft_utils.c \
      ft_utils2.c \
      ft_utils3.c \
      node_operations.c \
      node_operations2.c \
      operations.c \
      operations2.c \
      operations3.c \
      utils.c \
      sorting.c \
      sort_large.c \
      sort_large_utils.c \
      sort_large_utils2.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re