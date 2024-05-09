NAME = libft.a

CFLAGS = -Werror -Wall -Wextra

OBJECTS = $(SRC:.c=.o)

SRC = ft_atoi.c \
     ft_bzero.c \
     ft_calloc.c \
     ft_isalnum.c \
     ft_isalpha.c \
     ft_isascii.c \
     ft_isdigit.c \
     ft_isprint.c \
     ft_memchr.c \
     ft_memcmp.c \
     ft_memcpy.c \
     ft_memmove.c \
     ft_memset.c \
     ft_strdup.c \
     ft_strchr.c \
     ft_strlcat.c \
     ft_strlcpy.c \
     ft_strlen.c \
     ft_strncmp.c \
     ft_strnstr.c \
     ft_strrchr.c \
     ft_tolower.c \
     ft_toupper.c \
     ft_itoa.c \
     ft_putchar_fd.c \
     ft_putendl_fd.c \
     ft_putnbr_fd.c \
     ft_putstr_fd.c \
     ft_split.c \
     ft_striteri.c \
     ft_strjoin.c \
     ft_strjoin_f.c \
     ft_strmapi.c \
     ft_strtrim.c \
     ft_substr.c \
     ft_lstnew.c \
     ft_lstadd_front.c \
     ft_lstsize.c \
     ft_lstlast.c \
     ft_lstadd_back.c \
     ft_lstdelone.c \
     ft_lstclear.c \
     ft_lstiter.c \
     ft_printf.c \
     ft_printf_extra.c \
     get_next_line.c \
     get_next_line_bonus.c \
     ft_split_a.c \
     alloc_list.c \
     alloc_list_utils.c \
     alloc_list_extra.c \
     ft_tablen.c \
     ft_strjoin_a.c \
     ft_strdup_a.c \
     ft_substr_a.c

AR = ar

RM = rm -f

$(NAME): $(OBJECTS)
	@ar -csr $(NAME) $(OBJECTS)
%.o: %.c
	@$(CC) $(CFLAGS) $< -c

$(OBJECTS): $(SRC) libft.h

all: $(NAME)
	
so:
	@$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRC)
	@gcc -nostartfiles -shared -o libft.so $(OBJECTS)

clean:
	@$(RM) $(OBJECTS) 


fclean: clean
	@$(RM) $(OBJECTS) $(NAME)
re:
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY:	all clean fclean re 
