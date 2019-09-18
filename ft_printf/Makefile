# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: avan-rei <avan-rei@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/04/17 11:12:31 by avan-rei       #+#    #+#                 #
#    Updated: 2019/05/28 18:20:09 by avan-rei      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRCS = ft_printf.c ftoa_sig.c ftoa.c handle_precision.c pointer_adress.c\
		sciftoa_sig.c sciftoa.c set_arg.c set_result.c set_to_print.c\
		show_colors.c check_edge_float.c handle_str.c\
		handle_width_center.c
MKLIB = make -C libft/ re

OBJS = $(SRCS:.c=.o)

INCL = ft_printf.h
FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	$(MKLIB)
	mv libft/libft.a $(NAME)
	gcc $(FLAGS) -I ./ -c $(SRCS)
	ar -rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	make -C libft/ clean
	rm -f $(OBJS)
	rm -f *~
	rm -f .DS_Store
	rm -f \#*.c\#

fclean: clean
	make -C libft/ fclean
	rm -f $(NAME)
	rm -f libft.a

re: fclean all