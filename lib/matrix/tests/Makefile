NAME = TEST
MATRIX =  ../lib_matrix.a
ARRAY_LIST = ../../arraylist/includes/
TRY_CATCH = ../../try_catch/includes/
LIBFT = ../../libft/includes
INC = ../includes/ \
			-I $(ARRAY_LIST) \
			-I $(TRY_CATCH) \
			-I $(LIBFT)
all:
	gcc ./test.c $(MATRIX) -I $(INC) -o $(NAME)