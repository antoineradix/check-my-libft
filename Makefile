# define your libft path here
LIBFT_PATH	=	../libft

NAME		=	check-my-libft

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
LDFLAGS		=	-L$(LIBFT_PATH) -lft
LBSDFLAGS	=	-lbsd

SRCS_PART1	=	part1/test_ft_is.c		\
				part1/test_ft_strlen.c	\
				part1/test_ft_memset.c	\
				part1/test_ft_bzero.c	\
				part1/test_ft_memcpy.c	\
				part1/test_ft_memmove.c	\
				part1/test_ft_strlcpy.c
SRCS		=	$(SRCS_PART1)

OBJS_FOLDER	=	objects
OBJS_PART1	=	$(addprefix $(OBJS_FOLDER)/,$(SRCS_PART1:.c=.o))
OBJS		=	$(addprefix $(OBJS_FOLDER)/,$(SRCS:.c=.o))

HEADERS		=	headers

.PHONY: all clean fclean re libft

all: $(NAME)

libft:
	$(MAKE) -C $(LIBFT_PATH) re

$(NAME): libft $(OBJS)
	$(CC) $(CFLAGS) -I $(HEADERS) -I $(LIBFT_PATH) main.c $(OBJS) $(LDFLAGS) -o $(NAME) $(LBSDFLAGS)
	./$(NAME)

part1: libft $(OBJS_PART1)
	$(CC) $(CFLAGS) -I $(HEADERS) -I $(LIBFT_PATH) main.c $(OBJS_PART1) $(LDFLAGS) -o $(NAME) $(LBSDFLAGS)
	./$(NAME)

$(OBJS_FOLDER)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -I $(HEADERS) -I $(LIBFT_PATH) -c $< -o $@

clean:
	rm -rf $(OBJS_FOLDER)

fclean: clean
	rm -f $(NAME)

re: fclean all
