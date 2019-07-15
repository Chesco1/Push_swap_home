/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccoers <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/04 13:44:33 by ccoers        #+#    #+#                 */
/*   Updated: 2019/06/04 13:44:40 by ccoers        ########   odam.nl         */
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
    int         amt_to_sort;
    // int         *smallest_nbs;
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
# define AMT_TO_SORT info->amt_to_sort
// # define SMALLEST_NBS info->smallest_nbs
# define PIVOT info->pivot
# define CLOSEST info->closest
# define OP_TO_CLOSEST info->op_to_closest

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
void	execute_command(t_stacks *info, char *command);

void	initial_push(t_stacks *info);
int		find_closest_A(t_stacks *info, int pivot, char *op_to_closest);
int		find_closest_B(t_stacks *info, int pivot, char *op_to_closest);
void	push_closest_b(t_stacks *info, int to_find, char *op_to_closest);
void    push_closest_a(t_stacks *info, int to_find, char *op_to_closest);


#endif