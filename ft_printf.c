/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <niko.gontjarow@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 18:54:29 by ngontjar          #+#    #+#             */
/*   Updated: 2020/07/31 16:12:08 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	try_parsing(const char *format, t_data *flag);

int			ft_printf(const char *format, ...)
{
	t_data	flag;
	char	bytes;

	flag = (t_data){{{0}}, 0, 0, 0, 0, 0, 0, 0, 0};
	va_start(flag.ap, format);
	while (*format)
	{
		// printf("\treading str: %c\n", *format);
		if (*format == '%')
		{
			// printf("\tTry parsing...\n");
			bytes = 1;
			flag.bit = 0;
			flag.padder = ' ';
			flag.width = 0;
			flag.precision = -1;
			flag.specifier = 0;
			flag.type = 0;
			flag.p = 0;
			// flag.written = 0;
			bytes += try_parsing(format, &flag);
			format += bytes;
			// flag.written += bytes;
			// printf("\tskipping to %c after parse.\n", *format);
			continue ;
		}
		write(1, format, 1);
		++format;
		++flag.written;
	}
	va_end(flag.ap);
	return (flag.written);
}

static char	try_parsing(const char *format, t_data *flag)
{
	char	parsed;
	// printf("uhh... %c\n", *format);
	if (0 == (parsed = parse_format(++format, flag)))
	{
		// printf("\tparse_format said NO!\n");
		return (0);
	}

	// printf("\tLet's see what it is...\n");
	if (flag->type == 's') // ? done
		output_str(va_arg(flag->ap, char *), flag);
	else if (flag->type == '%') // ? done
		output_str("%", flag);
	else if (ft_strchr("dci", flag->type)) // ? done
	{
		if (flag->specifier == SPECIFIER_L)
			output_int(va_arg(flag->ap, long), flag);
		else if (flag->specifier == SPECIFIER_LL)
			output_int(va_arg(flag->ap, long long), flag);
		else
			output_int(va_arg(flag->ap, int), flag);
	}
	else if (ft_strchr("Xxuo", flag->type)) // ? done
	{
		if (flag->specifier == SPECIFIER_L)
			output_uint(va_arg(flag->ap, unsigned long), flag);
		else if (flag->specifier == SPECIFIER_LL)
			output_uint(va_arg(flag->ap, unsigned long long), flag);
		else
			output_uint(va_arg(flag->ap, unsigned int), flag);
	}
	else if (flag->type == 'p') // ? done
		output_pointer(va_arg(flag->ap, void *), flag);
	else if (flag->type == 'f') // todo: f
	{
		if (flag->specifier == SPECIFIER_L)
			output_double(va_arg(flag->ap, long double), flag);
		else
			output_double(va_arg(flag->ap, double), flag);
	}
	//printf("\tParsed: %d\n", parsed);
	return (parsed);
}
