NAME = lib_matrix.a	
SRC = 	./srcs/matrix_put_and_get.c \
				./srcs/matrix_multiply.c \
				./srcs/matrix_free.c \
				./srcs/matrix_conversion.c \
				./srcs/matrix_for_each.c \
				./srcs/matrix_init.c \
				./srcs/matrix_subtract.c \
				./srcs/matrix_map.c \
				./srcs/matrix_add.c \
				./srcs/matrix_transpose.c\
				./srcs/f_random.c

ARRAY_LIST = ../arraylist/includes/
TRY_CATCH = ../try_catch/includes/
LIBFT = ../libft/includes
SB = ../stringbuilder/includes
INC = ./includes/ \
			-I $(ARRAY_LIST) \
			-I $(TRY_CATCH) \
			-I $(LIBFT) \
			-I $(SB)

OBJ= $(SRC:.c=.o)
CC = gcc	
FLAGS= -Wall -Werror -Wextra 	
PARA  = -c	

%.o: %.c
	$(CC) $(PARA) -I $(INC) -g -o  $@ $<

all: $(NAME)	test

$(NAME): $(OBJ) 		
	ar rc $(NAME) $(OBJ)	

clean:	
	rm -f $(OBJ)	

fclean: clean	
	rm -f $(NAME)	
	rm -f includes/*.*.gch	

re: fclean all

test:
	$(MAKE) -C ./tests/
	./tests/TEST