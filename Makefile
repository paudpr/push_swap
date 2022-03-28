NAME = push_swap

LIBFT_NAME = libft.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra
CFLAGS += -I $(INC_PATH) -I $(LIBFT_PATH)

LDFLAGS = -L $(LIBFT_PATH)
LDLIBS = -lft

LIBFT_PATH	= libft
INC_PATH	= includes
SRC_PATH	= sources
OBJ_PATH	= objects

SRC =	push_swap_utils.c \
		main.c \
		main_utils.c \
		process_arguments.c \
		process_arguments_utils.c \
		create_list.c\
		swap.c\
		push.c\
		rotate.c \
		mapping.c \
		sort_small.c \
		radix.c \
		push_swap.c



all: $(NAME)

OBJS_NAME = $(SRC:%.c=%.o)

SRCS_NAME = $(addprefix $(SRC_PATH)/, $(SRC))

OBJS =  $(addprefix $(OBJ_PATH)/, $(OBJS_NAME))

$(OBJ_PATH):
			mkdir -p $(OBJ_PATH) 2> /dev/null

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c | $(OBJ_PATH)
			$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
		make -C $(LIBFT_PATH)
		$(CC) $^ -o $@ $(CFLAGS) $(LDFLAGS) $(LDLIBS)

$(LIBFT_NAME):
			$(MAKE) all -sC $(LIBFT_PATH)

##RULES

$(MAKE): make

debug: CFLAGS += -fsanitize=address -g3
debug: $(NAME)

norminette:
	norminette $(SRCS) 

clean: 
	rm $(NAME) 
	rm -rf $(OBJ_PATH)
	make clean -sC $(LIBFT_PATH)

fclean: clean
		rm -rf $(NAME) 
		rm -rf $(OBJ_PATH)
		make fclean -sC $(LIBFT_PATH)

re: fclean all

PHONY.: all clean fclean re norminette
