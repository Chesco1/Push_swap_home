/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lst_remove_first.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccoers <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/07 16:21:52 by ccoers         #+#    #+#                */
/*   Updated: 2019/09/23 15:19:55 by avan-rei      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_remove_first(t_list **alst)
{
	t_list	*tmp;

	tmp = *alst;
	*alst = (*alst)->next;
	free(tmp->content);
	free(tmp);
}
