NAME=libft.a
SRC= 	ft_atoi.c         ft_isdigit.c      ft_memccpy.c      ft_putchar_fd.c   ft_strdup.c       ft_strncmp.c      ft_toupper.c \
		ft_bzero.c        ft_isprint.c      ft_memchr.c       ft_putendl_fd.c   ft_strjoin.c      ft_strnstr.c \
		ft_calloc.c       ft_itoa.c         ft_memcmp.c       ft_putnbr_fd.c    ft_strlcat.c      ft_strrchr.c \
		ft_isalnum.c      ft_memcpy.c       ft_putstr_fd.c    ft_strlcpy.c      ft_strtrim.c \
		ft_isalpha.c      ft_memmove.c      ft_split.c        ft_strlen.c       ft_substr.c \
		ft_isascii.c      ft_memset.c       ft_strchr.c       ft_strmapi.c      ft_tolower.c 	get_next_line.c
SRCB = ft_lstadd_back.c  ft_lstadd_front.c ft_lstclear.c     ft_lstdelone.c    ft_lstiter.c      ft_lstlast.c      ft_lstmap.c       ft_lstnew.c       ft_lstsize.c
FLAGS=-Wall -Wextra -Werror
OBJS = $(SRC:.c=.o)
OBJSB = $(SRCB:.c=.o)
HEADER = libft.h
OBJDIR = ./

all: $(NAME)


$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

bonus: $(OBJSB) $(OBJS)
	ar -rcs $(NAME) $(OBJSB) $(OBJS)

$(OBJDIR)%.o : %.c
	gcc $(FLAGS) -I./ -o $@ -c $<

clean:
	rm -rf $(OBJS) $(OBJSB)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re all
