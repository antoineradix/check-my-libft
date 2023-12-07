# define your libft path here
LIBFT_PATH	=	../school-projects/libft

# compiler and flags
CC			=	gcc
CFLAGS		=	-g3 -Wall -Wextra -Werror
LDFLAGS		=	-L$(LIBFT_PATH) -lft
LBSDFLAGS	=	-lbsd

# libft 
LIBFT		=	$(LIBFT_PATH)/libft.a
LIBFT_MAKE	=	make -C $(LIBFT_PATH)

# directories
HEADERS		=	headers
TESTS		=	tests

# targets for part1
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
				ft_memchr		\
				ft_memcmp		\
				ft_strnstr		\
				ft_atoi			\
				ft_calloc		\
				ft_strdup		\

# targets for part2
PART2		=	ft_substr		\
				ft_strjoin		\
				ft_strtrim		\
				ft_split		\
				ft_itoa			\
				ft_strmapi		\
				ft_striteri		\
				ft_putchar_fd	\
				ft_putstr_fd	\
				ft_putendl_fd	\
				ft_putnbr_fd	\

# targets for bonuvoid ft_putnbr_fd(int n, int fd);s
BONUS		=	ft_lstnew		\
				ft_lstadd_front	\
				ft_lstsize		\
				ft_lstlast		\
				ft_lstadd_back	\

# function to dynamically test specified functions from the libft
define test_func
	@for func in $(1); do \
		if nm -g -o $(LIBFT) | grep -q $$func; then \
			$(CC) $(CFLAGS) -I$(LIBFT_PATH) -I$(HEADERS) -o test_$$func \
			$(TESTS)/$$func.c signal_handler.c $(LDFLAGS) $(LBSDFLAGS); \
			./test_$$func; \
			rm -f test_$$func; \
		fi \
	done
endef

.PHONY: all part1 part2 bonus libft libft_re re

all: part1 part2 bonus

part1: libft
	@$(call test_func, $(PART1))

part2: libft
	@$(call test_func, $(PART2))

bonus: libft_bonus
	@$(call test_func, $(BONUS))

%: libft
	@$(call test_func, $(@))

libft:
	@$(LIBFT_MAKE) > /dev/null

libft_bonus:
	@$(LIBFT_MAKE) bonus > /dev/null

libft_clean:
	@$(LIBFT_MAKE) clean > /dev/null

libft_fclean:
	@$(LIBFT_MAKE) fclean > /dev/null

libft_re:
	@$(LIBFT_MAKE) re > /dev/null

re: libft_re all
