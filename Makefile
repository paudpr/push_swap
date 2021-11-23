NAME = push_swap

SRCS = lasquesean.c\
		unaspocasmas.c

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g3

RM = rm -f

LIBFT_PATH = ../libft

LIBFT_NAME = libft.a





-L is used to include paths where the linker will look for libraries
-l is used to link a library, which must be passed without the lib prefix and the extension





.c.o:	%(cc) $(CFLAGS) -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
		mensaje_personalizado $(COMPILALIBFT) $(NAME) $(OBJS)

run: all
	gcc $(FLAGS) $(SRCS)

norminette:
	norminette $(SRCS) 

clean: 
	$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME) a.out

re: fclean all

PHONY.: all clean fclean re norminette