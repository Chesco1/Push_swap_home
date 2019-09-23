/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstunlink.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/13 20:41:10 by fmiceli        #+#    #+#                */
/*   Updated: 2019/09/23 14:51:05 by avan-rei      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstunlink(t_list **head, t_list *to_unlink)
{
	t_list *current;
	t_list *temp;

	current = *head;
	if (to_unlink == *head)
	{
		*head = current->next;
		free(current->content);
		free(current);
		current = NULL;
		return (*head);
	}
	while (current->next != NULL && current->next != to_unlink)
		current = current->next;
	temp = current->next;
	current->next = current->next->next;
	free(temp->content);
	free(temp);
	temp = NULL;
	return (*head);
}
