# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: ccoers <marvin@codam.nl>                     +#+                      #
#                                                    +#+                       #
#    Created: 2019/09/17 14:01:00 by ccoers         #+#    #+#                 #
#    Updated: 2019/09/23 15:14:40 by avan-rei      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME_PS = push_swap
NAME_CH = checker
SRCS_PS = main.c fill_struct.c sort_small_amount.c is_done.c correct_stacks.c \
		execute_command.c ft_lstnew_b.c new_push_swap.c print_stacks.c \
		push_closest.c push.c rotate.c reverse_rotate.c swap.c\
		ps_atoi.c ft_error.c check_duplicate.c update_partitions.c\

SRCS_CH = checker.c	execute_command.c fill_struct.c is_done.c push.c \
			rotate.c reverse_rotate.c swap.c ft_lstnew_b.c print_stacks.c \
			ft_printf/libft/get_next_line.c ft_error.c check_duplicate.c\
			ps_atoi.c\
			
MKPRINT = make -C ft_printf/ re

OBJS_PS = $(SRCS_PS:.c=.o)
OBJS_CH = $(SRCS_CH:.c=.o)

INCL = push_swap.h
FLAGS = -Wall -Werror -Wextra

all: $(NAME_PS) $(NAME_CH)

$(NAME_PS): $(SRCS_PS)
	@$(MKPRINT)
	@gcc $(SRCS_PS) -I $(INCL) $(FLAGS) -o $(NAME_PS) ft_printf/libftprintf.a

$(NAME_CH): $(SRCS_CH)
	@gcc $(SRCS_CH) -I $(INCL) $(FLAGS) -o $(NAME_CH) ft_printf/libftprintf.a

clean:
	@make -C ft_printf/ clean
	@rm -f $(OBJS)
	@rm -f *~
	@rm -f .DS_Store
	@rm -f \#*.c\#

fclean: clean
	@make -C ft_printf/ fclean
	@rm -f $(NAME_PS)
	@rm -f $(NAME_CH)

re: fclean all
