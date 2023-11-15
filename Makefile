NAME		=	check-my-libft

CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror

SRCS_PART1	=	part1/test_ft_isalpha.c	\

SRCS		=	$(SRCS_PART1)	\

OBJS_FOLDER	=	objects
OBJS		=	$(addprefix $(OBJS_FOLDER)/,$(SRCS:.c=.o))

HEADERS		=	headers

LIBFT_PATH	=	../libft

all: $(NAME)

libft:
	cd $(LIBFT_PATH) && make re

$(NAME): libft
	$(CC) $(FLAGS) -I $(HEADERS) -I $(LIBFT_PATH) main.c $(SRCS) -L $(LIBFT_PATH) -lft -o $(NAME)
	./$(NAME)

part1: libft 
	$(CC) $(FLAGS) -I $(HEADERS) -I $(LIBFT_PATH) main.c $(SRCS_PART1) -L $(LIBFT_PATH) -lft -o $(NAME)
	./$(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
