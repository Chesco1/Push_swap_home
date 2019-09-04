/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccoers <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/04 13:44:33 by ccoers         #+#    #+#                */
/*   Updated: 2019/09/02 17:00:27 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"

typedef struct  s_stacks
{
    int         *stack_a;
    int         *stack_b;
    int         len_stack_a;
    int         len_stack_b;
    char        last_op;
    char        print;
    char        show_color;
    int         left_in_partition_a;
    t_list      *b_partitions;
}               t_stacks;              



//    11   |  10  |   9   |  8   | 7   |  6  | 5  |  4  | 3  | 2  | 1  
//    rrr  |  rrb |  rra  |  rr  | rb  | ra  | pb |  pa | ss | sb | sa

# define A info->stack_a
# define B info->stack_b
# define LEN_A info->len_stack_a
# define LEN_B info->len_stack_b
# define LAST_OP info->last_op
# define PRINT info->print
# define SHOW_COLOR info->show_color
# define LEFT_IN_PARTITION_A info->left_in_partition_a
# define B_PARTITIONS info->b_partitions
# define LEFT_IN_PARTITION_B info->b_partitions->content_size

void	swap_a(t_stacks *info);
void	swap_b(t_stacks *info);
void	swap_both(t_stacks *info);

void	push_a(t_stacks *info);
void	push_b(t_stacks *info);

void	rotate_a(t_stacks *info);
void	rotate_b(t_stacks *info);
void	rotate_both(t_stacks *info);

void	reverse_rotate_a(t_stacks *info);
void	reverse_rotate_b(t_stacks *info);
void	reverse_rotate_both(t_stacks *info);

void	print_stacks(t_stacks *info);
int		is_sorted(t_stacks *info, char stack);
int     is_done(t_stacks *info);
void	execute_command(t_stacks *info, char *command);

void	initial_push(t_stacks *info);
int		find_closest_A(t_stacks *info, int pivot, char *op_to_closest);
int		find_closest_B(t_stacks *info, int pivot, char *op_to_closest);
void	push_closest_b(t_stacks *info, int to_find, char *op_to_closest);
void    push_closest_a(t_stacks *info, int to_find, char *op_to_closest);

void	push_back_to_a(t_stacks *info);
void	push_back_to_b(t_stacks *info);
void    correct_stack_a(t_stacks *info);
void    correct_stack_b(t_stacks *info);

void	free_all(t_stacks *info);

#endif