/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccoers <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/15 11:54:02 by ccoers        #+#    #+#                 */
/*   Updated: 2019/02/26 17:42:41 by ccoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_lst_unlink(t_list **alst, int fd, int ret)
{
	t_list *current;
	t_list *temp;

	if (ret == -1)
		return (-1);
	current = *alst;
	if ((int)current->content_size == fd)
	{
		*alst = current->next;
		free(current->content);
		free(current);
		current = NULL;
		return (0);
	}
	while (current->next != NULL && (int)current->next->content_size != fd)
		current = current->next;
	temp = current->next;
	current->next = current->next->next;
	free(temp->content);
	free(temp);
	temp = NULL;
	return (0);
}

static t_list	*get_list(t_list **alst, int fd)
{
	t_list *current;
	t_list *new_node;

	current = *alst;
	while (current != NULL)
	{
		if ((int)current->content_size == fd)
			return (current);
		current = current->next;
	}
	new_node = ft_lstnew("\0", 1);
	if (new_node == NULL)
		return (NULL);
	new_node->content_size = fd;
	ft_lstadd(alst, new_node);
	return (new_node);
}

static int		fill_line(char **line, char **str)
{
	if (ft_strchr_int(*str, '\n') != -1)
		*line = ft_strndup(*str, ft_strchr_int(*str, '\n'));
	else
	{
		*line = ft_strdup(*str);
		ft_strclr(*str);
	}
	if (*line == NULL)
		return (-1);
	return (1);
}

static int		set_str(char **str, int fd, t_list **alst)
{
	char	*to_free;
	int		ret;
	int		i;
	char	buf[BUFF_SIZE + 1];

	i = 0;
	while (ft_strchr_int(*str, '\n') == -1)
	{
		ret = read(fd, buf, BUFF_SIZE);
		if (ret <= 0)
		{
			if ((i == 0 && *str[0] == '\0') || ret == -1)
				return (ft_lst_unlink(alst, fd, ret));
			break ;
		}
		buf[ret] = '\0';
		to_free = *str;
		*str = ft_strjoin(*str, buf);
		if (*str == NULL)
			return (-1);
		free(to_free);
		i = 1;
	}
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*alst;
	t_list			*current;
	char			*to_free;
	int				i;

	current = get_list(&alst, fd);
	if (current == NULL || current->content == NULL)
		return (-1);
	to_free = current->content;
	current->content = ft_strdup(&current->content[(ft_strchr_int(current->
	content, '\n') + 1)]);
	free(to_free);
	if (current->content == NULL)
		return (-1);
	i = set_str((char **)&current->content, fd, &alst);
	if (i <= 0)
		return (i);
	return (fill_line(line, (char **)&current->content));
}
