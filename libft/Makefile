NAME = libft.a
CC = gcc
HEADER = libft.h
CFLAGS = -g -Wall -Werror -Wextra -c 
SRC = ft_atoi.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c \
ft_memmove.c ft_memchr.c ft_strlen.c ft_strlcpy.c  \
ft_strchr.c ft_strrchr.c ft_strjoin.c ft_isalpha.c ft_isspace.c \
ft_isascii.c ft_isalnum.c ft_isdigit.c ft_isprint.c ft_toupper.c \
ft_tolower.c ft_calloc.c ft_strdup.c

OBJ = $(SRC:%.c=%.o)
.PHONY  : all clean fclean
all : $(NAME)
$(NAME) : $(OBJ)
	ar rcs $(NAME) $?
%.o: %.c
	$(CC) $(CFLAGS) $(SRC)
clean :
	rm -rf $(OBJ)
fclean :
	rm -rf $(OBJ) $(NAME)
re: fclean all


