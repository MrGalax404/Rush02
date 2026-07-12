NAME = rush02

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
INC = includes

SRC = srcs/main.c \
	srcs/parse_dict.c \
	srcs/ft_read_file.c \
	srcs/ft_utlis.c \
	srcs/digit_calc.c \
	srcs/dict.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

srcs/%.o: srcs/%.c includes/rush02.h
	$(CC) $(CFLAGS) -I $(INC) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
