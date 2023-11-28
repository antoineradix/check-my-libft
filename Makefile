# define your libft path here
LIBFT_PATH	=	../school-projects/libft
LIBFT		=	$(LIBFT_PATH)/libft.a

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
LDFLAGS		=	-L$(LIBFT_PATH) -lft
LBSDFLAGS	=

HEADERS		=	headers

PART1		=	ft_isalpha		\
				ft_isdigit		\
				ft_isalnum		\
				ft_isascii		\
				ft_isprint		\
				ft_strlen		\
				ft_memset		\
				ft_bzero		\
				ft_memcpy		\
				ft_memmove		\
				ft_strlcpy		\
				ft_strlcat		\
				ft_toupper		\
				ft_tolower		\
				ft_strchr		\
				ft_strrchr		\
				ft_strncmp		\

PART2		=	ft_ss ft_mdr
BONUS		=	bonuss

TESTS		=	tests

all part1 part2 bonus %: | libft
	@for item in $(SRCS); do \
		if nm -g -o $(LIBFT) | grep -q $$item; then \
			$(CC) $(CFLAGS) -I$(LIBFT_PATH) -I$(HEADERS) -o test_$$item $(TESTS)/$$item.c segfault_handler.c $(LDFLAGS) $(LBSDFLAGS); \
			./test_$$item; \
			rm -f test_$$item; \
		fi \
	done

all: SRCS=$(PART1) $(PART2) $(BONUS)
part1: SRCS=$(PART1)
part2: SRCS=$(PART2)
bonus: SRCS=$(BONUS)
%: SRCS=$@

libft:
	@$(MAKE) -C $(LIBFT_PATH) > /dev/null;

libft_re:
	@$(MAKE) -C $(LIBFT_PATH) re > /dev/null;

re: libft_re all

.PHONY: all part1 part2 bonus libft libft_re re
