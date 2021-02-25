NAME = TEST
MATRIX =  ../lib_matrix.a

ARRAY_LIST = ../../arraylist/includes/
TRY_CATCH = ../../try_catch/includes/
LIBFT = ../../libft/includes
SB = ../../stringbuilder/includes
TEST_TOOLS = ../../test_tools/includes
INC = ../includes/ \
			-I $(ARRAY_LIST) \
			-I $(TRY_CATCH) \
			-I $(LIBFT) \
			-I $(SB) \
			-I $(TEST_TOOLS)
all:
	gcc -fsanitize=address ./test.c  -g  $(MATRIX) ../../test_tools/srcs/test_tools.c  ../../stringbuilder/lib_string_builder.a ../../arraylist/arraylist.a ../../libft/srcs/*.c  ../../try_catch/try_catch.a   -I $(INC) -o $(NAME)