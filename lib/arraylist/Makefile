NAME = arraylist.a	
SRC = ./srcs/array_list.c ./srcs/array_list_crud.c ./srcs/array_list_delete_if.c ./srcs/array_list_operation.c ./srcs/array_list_sort.c
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