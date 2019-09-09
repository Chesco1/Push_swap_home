/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstunlink.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/13 20:41:10 by fmiceli       #+#    #+#                 */
/*   Updated: 2019/02/13 20:41:14 by fmiceli       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lst_unlink(t_list **alst)
{
	t_list *current;
	t_list *temp;

	current = *alst;
	if ((int)current->content_size == 1337)
	{
		*alst = current->next;
		free(current->content);
		free(current);
		current = NULL;
	}
	while (current->next != NULL && (int)current->next->content_size != 1337)
		current = current->next;
	temp = current->next;
	current->next = current->next->next;
	free(temp->content);
	free(temp);
	temp = NULL;
}