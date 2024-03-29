/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccoers <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/04 13:44:33 by ccoers         #+#    #+#                */
/*   Updated: 2019/09/23 15:05:09 by avan-rei      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "ft_printf/libft/libft.h"
# include "ft_printf/ft_printf.h"

typedef struct					s_stacks
{
	int							*stack_a;
	int							*stack_b;
	int							len_stack_a;
	int							len_stack_b;
	char						last_op;
	char						print;
	char						show_color;
	int							left_in_partition_a;
	int							last_to_a;
	t_list						*b_partitions;
	t_list						*instructions;
}								t_stacks;

# define A						info->stack_a
# define B						info->stack_b
# define LEN_A					info->len_stack_a
# define LEN_B					info->len_stack_b
# define LAST_OP				info->last_op
# define PRINT					info->print
# define SHOW_COLOR				info->show_color
# define LEFT_IN_PARTITION_A	info->left_in_partition_a
# define LAST_TO_A				info->last_to_a
# define B_PARTITIONS			info->b_partitions
# define LEFT_IN_PARTITION_B	info->b_partitions->content_size
# define INSTRUCTIONS			info->instructions

void							swap_a(t_stacks *info);
void							swap_b(t_stacks *info);
void							swap_both(t_stacks *info);

void							push_a(t_stacks *info);
void							push_b(t_stacks *info);

void							rotate_a(t_stacks *info);
void							rotate_b(t_stacks *info);
void							rotate_both(t_stacks *info);

void							reverse_rotate_a(t_stacks *info);
void							reverse_rotate_b(t_stacks *info);
void							reverse_rotate_both(t_stacks *info);

void							print_stacks(t_stacks *info);
int								is_sorted(t_stacks *info, char stack);
int								is_done(t_stacks *info);
void							execute_command(t_stacks *info, char *command);
void							fill_struct(int argc,
								char **argv, t_stacks *info);

void							initial_push(t_stacks *info);
int								find_closest_a(t_stacks *info,
								int pivot, char *op_to_closest);
int								find_closest_b(t_stacks *info,
								int pivot, char *op_to_closest);
void							push_closest_b(t_stacks *info,
								int to_find, char *op_to_closest);
void							push_closest_a(t_stacks *info,
								int to_find, char *op_to_closest);

void							push_back_to_a(t_stacks *info);
void							push_back_to_b(t_stacks *info);
void							correct_stack_a(t_stacks *info);
void							correct_stack_b(t_stacks *info, int bottom_nb);

void							sort_three_a(t_stacks *info);

t_list							*ft_lstnew_b(void *content,
								size_t content_size);
void							ft_error(void);
void							check_duplicate(t_stacks *info);
void							update_partitions(t_stacks *info,
								char stack_last_pushed,
								int amount_last_pushed);
int								ps_atoi(const char *str);

#endif
