NAME = push_swap

LIBFT_NAME = libft.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g3

CFLAGS += -I ./$(INC_PATH) -I ./$(LIBFT_PATH)

LIBFT_PATH	= libft
INC_PATH	= includes
SRC_PATH	= sources
OBJ_PATH	= objects

SRC =	push_swap_utils.c \
		main.c \
		main_utils.c\
		process_arguments.c\
		create_list.c\
		swap.c\
		push.c\
		rotate.c \
		sort_3.c

##CFLAGS += -I $(INC_PATH) -I $(LIBFT_PATH)
##referencia al libft.a cuando se haya compilado, o algo
##LIBFT_FLAGS = -L $(LIBFT_PATH)

all: $(NAME)

##-L is used to include paths where the linker will look for libraries
##-l is used to link a library, which must be passed without the lib prefix and the extension
## -p para creaar directorios uno dentro del otro

OBJS_NAME = $(SRC:%.c=%.o)

##addprefix "coge" el segundo argumento y el path del primer argumento. funciona como un while añadiendo paths a cada source
SRCS = $(addprefix $(SRC_PATH)/, $(SRC))

OBJS =  $(addprefix $(OBJ_PATH)/, $(OBJS_NAME))

$(OBJ_PATH):
			mkdir -p $(OBJ_PATH) 2> /dev/null

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c | $(OBJ_PATH)
			$(CC) $(CFLAGS) -c $< -o $@
			
##s es para silenciar y C para que vaya al directorio
##	make -sC $(LIBFT_PATH)

##el | está para evitar que haga relink
##otra solución sería copiar la orden de $(LIBFT_NAME) para ejecutar antes de la compilación (dentro de $(NAME))
$(NAME): $(OBJS) | $(LIBFT_NAME)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(addprefix $(LIBFT_PATH)/, $(LIBFT_NAME))

$(LIBFT_NAME):
			$(MAKE) -sC $(LIBFT_PATH)

##RULES

#hace make a un "sub-makefile"
$(MAKE): make

##debug: CFLAGS += -fsanitize=address
##debug: $(NAME)

norminette:
	norminette $(SRCS) 

clean: 
	rm $(OBJS)

fclean: clean
		rm $(NAME) 
		rm -rf $(OBJ_PATH)
		make fclean -sC $(LIBFT_PATH)

re: fclean all

PHONY.: all clean fclean re norminette
