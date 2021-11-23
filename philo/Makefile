SRC_PATH = ./src
OBJ_PATH = ./obj
LIB_PATH = ./lib

CC = clang
FLAGS = -Wall -Wextra -Werror -g -fsanitize=address
LIB_NAME = philo.a
NAME = philo

MAIN = main.c

LIB = $(LIB_PATH)/$(LIB_NAME)
SRC = $(notdir $(wildcard ./src/*.c))
OBJ=$(addprefix $(OBJ_PATH)/, $(SRC:.c=.o))

all: config $(NAME)

clean:
	rm -f $(OBJ_PATH)/*.o

fclean:	clean
	rm -f $(LIB_PATH)/*.a
	rm -f $(NAME)
	rm -f *.o
	rm -fR *.dSYM
	rm -fR obj
	rm -fR lib

re: fclean all

config:
	mkdir -p obj
	mkdir -p lib

$(NAME): $(LIB)
	$(CC) $(FLAGS) $(MAIN) -g -L. -pthread $(LIB) -o $@

$(LIB): $(OBJ)
	ar rcs $@ $(OBJ)

$(OBJ_PATH)/%.o:	$(SRC_PATH)/%.c
	$(CC) -g $(FLAGS) -c $< -o $@

