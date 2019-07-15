/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   str_is_int.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccoers <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/06 17:00:15 by ccoers        #+#    #+#                 */
/*   Updated: 2019/06/06 17:00:16 by ccoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// #include "libft.h"

// static int  check_positive(char *str)
// {
//     if (str[0] < 2)
//         return (1);
//     if (str[0] == 2 && str[1] < 1)
//         return (1);
//     if (str[1] == 1 && str[2] < 4)
//         return (1);
//     if (str[2] == 4 && str[3] < 7)
//         return (1);
//     if (str[3] == 7 && str[4] < 4)
//         return (1); 
// }

int     str_is_int(char *str)
{
    // int i;
    // int len;

    // i = 0;
    // while (str[i] == '\n' && str[i] == '\v' && str[i] == '\r'
    //         && str[i] == '\f' && str[i] == '\t' && str[i] == ' ')
    //     i++;
    // len = ft_strlen(&str[i]);
    // if (len < 10 || (str[i] == '-' && len < 11))
    //     return (1);
    // else if (len == 10 && str[i] != '-')
    //     return (check_positive(&str[i]));
    // else if (len == 11 && str[i] == '-')
    //     return (check_negative(&str[i + 1]));
    return (0);
}