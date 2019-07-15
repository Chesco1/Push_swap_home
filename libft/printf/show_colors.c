/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   show_colors.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-rei <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/22 13:56:59 by avan-rei       #+#    #+#                */
/*   Updated: 2019/05/24 15:34:32 by avan-rei      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	write_bold_color(const char *str)
{
	if (str[2] == 'B' && str[4] == 'A')
		write(1, "\033[1m\033[30m", 10);
	else if (str[2] == 'R' && str[4] == 'D')
		write(1, "\033[1m\033[31m", 10);
	else if (str[2] == 'G')
		write(1, "\033[1m\033[32m", 10);
	else if (str[2] == 'Y')
		write(1, "\033[1m\033[33m", 10);
	else if (str[2] == 'B' && str[4] == 'U')
		write(1, "\033[1m\033[34m", 10);
	else if (str[2] == 'M')
		write(1, "\033[1m\033[35m", 10);
	else if (str[2] == 'C')
		write(1, "\033[1m\033[36m", 10);
	else if (str[2] == 'W')
		write(1, "\033[1m\033[37m", 10);
}

static void	write_color(const char *str)
{
	if (str[1] == 'B' && str[3] == 'A')
		write(1, "\033[30m", 6);
	else if (str[1] == 'R')
		write(1, "\033[31m", 6);
	else if (str[1] == 'G')
		write(1, "\033[32m", 6);
	else if (str[1] == 'Y')
		write(1, "\033[33m", 6);
	else if (str[1] == 'B' && str[3] == 'U')
		write(1, "\033[34m", 6);
	else if (str[1] == 'M')
		write(1, "\033[35m", 6);
	else if (str[1] == 'C')
		write(1, "\033[36m", 6);
	else if (str[1] == 'W')
		write(1, "\033[37m", 6);
}

void		set_color(const char *str, int *i)
{
	if (str[0] == '{')
	{
		if (str[1] == '$')
			write_bold_color(str);
		else if (str[1] == 'R' && str[3] != 'D')
			write(1, "\033[0m", 5);
		else
			write_color(str);
		*i += ft_strchr_int(str, '}') + 1;
	}
}

void		show_colors(t_format *arg)
{
	write(1, "\n\033[1m\033[33mHeey visitor!", 24);
	write(1, " Nice to have you here!\033[1m\033[37m\n", 33);
	write(1, "Looks like you're interested ", 29);
	write(1, "in our \033[32mcolor\033[37m options:\n", 33);
	write(1, "\nSimply write {\033[31mcolor\033[37m} after using '%'\n", 47);
	write(1, "\nIf you prefer it bold, ", 25);
	write(1, "write a '$' before the \033[36mcolor\033[37m ", 39);
	write(1, "name\nTo reset, type {RESET}\n\nAll possible colors:\n", 50);
	write(1, "\033[0m\033[30mBLACK\033[1m\033[30mBOLD (black)\n", 42);
	write(1, "\033[0m\033[31mRED\033[1m\033[31mBOLD\n", 31);
	write(1, "\033[0m\033[32mGREEN\033[1m\033[32mBOLD\n", 33);
	write(1, "\033[0m\033[33mYELLOW\033[1m\033[33mBOLD\n", 34);
	write(1, "\033[0m\033[34mBLUE\033[1m\033[34mBOLD\n", 32);
	write(1, "\033[0m\033[35mMAGENTA\033[1m\033[35mBOLD\n", 35);
	write(1, "\033[0m\033[36mCYAN\033[1m\033[36mBOLD\n", 32);
	write(1, "\033[0m\033[37mWHITE\033[1m\033[37mBOLD", 31);
	write(1, "\n\033[35mCiao!\033[0m\n", 16);
	RESULT = ft_strdup("\0");
}
