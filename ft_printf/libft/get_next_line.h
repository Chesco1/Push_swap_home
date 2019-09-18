/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccoers <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/04 18:03:42 by ccoers        #+#    #+#                 */
/*   Updated: 2019/02/26 17:25:15 by ccoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef _GET_NEXT_LINE_H

# define _GET_NEXT_LINE_H
# define BUFF_SIZE 8300

int		get_next_line(const int fd, char **line);

#endif
