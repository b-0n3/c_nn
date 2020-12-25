NAME = try_catch.a	
SRC = ./srcs/try_catch.c
INC = ./includes/	
LIBFT = ../libft/includes/
OBJ= $(SRC:.c=.o)
CC = gcc	
FLAGS= -Wall -Werror -Wextra 	
PARA  = -c	

%.o: %.c
	$(CC) $(PARA) -I $(INC) $(FLAGS)  -o $@  $<

all: $(NAME)	

$(NAME): $(OBJ)		
	ar rc $(NAME) $(OBJ)	

clean:	
	rm -f $(OBJ)

fclean: clean	
	rm -f $(NAME)	
	rm -f includes/*.*.gch	

re: fclean all

test:
	$(CC)  -I $(INC) -o test ./tests/test.c
	echo "testing try/catch"
	./test