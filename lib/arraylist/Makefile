NAME = arraylist.a	
SRC = ./srcs/array_list.c\
	 ./srcs/array_list_crud.c \
	  ./srcs/array_list_delete_if.c\
		 ./srcs/array_list_operation.c ./srcs/array_list_sort.c ./srcs/array_list.c ./srcs/array_list_clone.c
INC = ./includes/
LIBFT = ../libft/includes/
TRY_CATCH = ../try_catch/includes/
OBJ= $(SRC:.c=.o)
CC = gcc	
FLAGS= -Wall -Werror -Wextra 	
PARA  = -c	

%.o: %.c
	$(CC) $(PARA) -I $(INC) -I $(LIBFT) -I $(TRY_CATCH) $(FLAGS) -o $@  $<

all: $(NAME)	

$(NAME): $(OBJ)		
	ar rc $(NAME) $(OBJ)

clean:	
	rm -f  $(OBJ)

fclean: clean	
	rm -f $(NAME)	
	rm -f includes/*.*.gch	

re: fclean all

test:
	$(CC)  -I $(INC) -I $(LIBFT) -I $(TRY_CATCH) $(FLAGS) -o test
	echo "testing arrayList"
	./test 