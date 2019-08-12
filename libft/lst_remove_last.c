/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lst_remove_first.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccoers <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/07 16:21:52 by ccoers        #+#    #+#                 */
/*   Updated: 2019/08/07 16:21:55 by ccoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list     *ft_lst_remove_first(t_list **alst)
{
    t_list  *first;
    t_list  *second;

    first = *alst;
    second = first->next;
    free(first->content);
    free(first);
    return (second);
}