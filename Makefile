CFLAGS = -Wall -Wextra -Werror
CC = gcc
LIB = libft/libft.a
SRCS = ft_printf.c
NAME = libftprintf.a
OBJS = $(SRCS:.c=.o)
all: $(NAME)

$(NAME): $(OBJS)
	make -C libft
	cp libft/libft.a $@
	ar -rc $@ $^

%.o: %.c
	cc $(CFLAGS) -c $< -o $@ 

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean re