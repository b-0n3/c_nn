NAME = try_catch.a	
SRC = ./srcs/try_catch.c
INC = ./includes/	
OBJ= $(SRC:.c=.o)
CC = gcc	
FLAGS= -Wall -Werror -Wextra 	
PARA  = -c	

%.o: %.c
	$(CC) $(PARA) -I $(INC) $(FLAGS)  $<

all: $(NAME)	

$(NAME): $(OBJ)		
	ar rc $(NAME) *.o	

clean:	
	rm -f *.o	

fclean: clean	
	rm -f $(NAME)	
	rm -f includes/*.*.gch	

re: fclean all