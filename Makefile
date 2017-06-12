##
## Makefile for Makefile in /home/benjamin.g/save/nouveau_projet
##
## Made by Benjamin GAYMAY
## Login   <benjamin.g@epitech.net>
##
## Started on  Sun Nov 20 13:42:20 2016 Benjamin GAYMAY
## Last update Fri Jan 20 12:05:16 2017 Benjamin GAYMAY
##

CC	=	gcc -g

RM	=	rm -f

NAME	=	mysh

CFLAGS	+=	-I./include

SRCS	=	main.c \
		my_printf/flag.c \
		my_printf/hexa.c \
		my_printf/my_printf.c \
		my_printf/my_putchar_printf.c \
		my_printf/my_put_nbr_printf.c \
		my_printf/my_put_nbr_unsigned.c \
		my_printf/my_putstr_printf.c \
		my_printf/my_strlen_printf.c \
		my_printf/octal_bin.c \
		my_putchar.c \
		my_put_nbr.c \
		my_putstr.c \
		my_revstr.c \
		my_strlen.c \
		my_strcmp.c \
		get_next_line.c \
		count.c \
		my_strcat.c \
		use_array.c \
		path.c \
		parent.c \
		child.c \
		setenv.c \
		cd.c \
		my_str_isnum.c \
		my_getnbr.c \
		my_exit.c

OBJS	=	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY:	all clean fclean re
