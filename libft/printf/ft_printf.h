/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-rei <avan-rei@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/17 17:59:02 by avan-rei       #+#    #+#                */
/*   Updated: 2019/06/03 19:07:34 by avan-rei      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft.h"

# define TRUE 1
# define FALSE 0
# define FT_MAX_INT 2147483647
# define FT_INT_MAX 2147483647

# define RESET		"\033[0m"
# define BLACK		"\033[30m"
# define RED		"\033[31m"
# define GREEN		"\033[32m"
# define YELLOW		"\033[33m"
# define BLUE		"\033[34m"
# define MAGENTA	"\033[35m"
# define CYAN		"\033[36m"
# define WHITE		"\033[37m"
# define $BLACK		"\033[1m\033[30m"
# define $RED		"\033[1m\033[31m"
# define $GREEN		"\033[1m\033[32m"
# define $YELLOW	"\033[1m\033[33m"
# define $BLUE		"\033[1m\033[34m"
# define $MAGENTA	"\033[1m\033[35m"
# define $CYAN		"\033[1m\033[36m"
# define $WHITE		"\033[1m\033[37m"

typedef struct		s_format
{
	unsigned char	flags;
	int				width;
	int				precision;
	unsigned char	length;
	char			specifier;
	char			*result;
	int				index_specifier;
	char			precision_was_set;
}					t_format;

/*
**	flags:
**	64|32|16|8|4|2|1|
**	 ^| _|sp|0|#|+|-|
**
**	length:
**	|   0  |1|2|3 |4|5 |
**	| nada |L|l|ll|h|hh|
*/

# define FLAGS arg->flags
# define WIDTH arg->width
# define PRECISION arg->precision
# define LENGTH arg->length
# define SPECIFIER arg->specifier
# define RESULT arg->result
# define INDEX_SPECIFIER arg->index_specifier
# define PRECISION_WAS_SET arg->precision_was_set

typedef struct		s_print_info
{
	char			padding_char;
	int				len_output;
	char			justification;
	char			*to_print;
}					t_print_info;

# define PADDING_CHAR print_info->padding_char
# define LEN_OUTPUT print_info->len_output
# define JUSTIFICATION print_info->justification
# define TO_PRINT print_info->to_print

int					ft_printf(const char *format, ...);

void				set_arg(t_format *arg, const char *format_arg, va_list *ap);

void				set_result(va_list *ap, t_format *arg);

char				set_justification(t_format *arg);
char				set_padding_char(t_format *arg);
void				set_to_print(t_format *arg, t_print_info *print_info);

void				handle_precision(char *temp_result, t_format *arg);
void				default_precision(t_format *arg);

void				pointer_address(va_list *ap, t_format *arg);

char				*ftoa(long double n, int precision);

char				*ftoa_sig(long double n, int precision);

char				*sciftoa(long double n, int precision, char c);

char				*sciftoa_sig(long double n, int precision, char c);

void				set_color(const char *str, int *i);
void				show_colors(t_format *arg);

void				handle_str(va_list *ap, t_format *arg);

int					check_edge_float(long double n, t_format *arg);

void				handle_hash(t_format *arg);

void				check_sign_width(t_format *arg, t_print_info *print_info,
					int *i, int *len);

int					handle_width_center(t_format *arg,
					t_print_info *print_info, int len);

#endif
