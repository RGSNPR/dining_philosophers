NAME = philo

CC = gcc

CFLAGS = -g -Wall -Wextra -Werror

RM = rm -f

INCL = philo_one.h

SRC = main.c utils.c inits.c actions.c upgrade_usleep.c checkers.c

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
		$(CC) $(CFLAGS) -o $(NAME) $(SRC)

all: $(NAME)

clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean all re bonus
