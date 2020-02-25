/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 21:42:32 by ngontjar          #+#    #+#             */
/*   Updated: 2020/02/25 20:31:00 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// width, precision, signage, justification, fill
// https://www.cypress.com/file/54441/download

// char	argument_index(const char * format)
// {
// 	char	bytes;
// 	char	*c;

// 	bytes = 0;
// 	if (ft_isdigit(*format) && (c = ft_strchr(format, '$')))
// 	{
// 		bytes = c - format;
// 	}
// 	return (bytes + 1);
// }

char	parse_format(const char *format, t_flag *flag)
{
	int		bytes;
	char	*temp;

	// printf("\tEntering parse_format...\n");
	if (*format == '%')
	{
		// printf("\tT'was just a %%\n");
		write(1, format, 1);
		return (1);
	}
	bytes = 0;
	while (*format)
	{
		++bytes;
		// printf("\tparsing flag specifier: %c\n", *format);
		if (*format == '-')
		{
			// printf("\tIt's a sign!\n");
			flag->pad |= PAD_RIGHT;
			++format;
			++bytes;
		}
		while (*format == '0')
		{
			// printf("\tAin't no hero.\n");
			flag->pad |= PAD_ZERO;
			++format;
			++bytes;
		}
		if (format[0] == '.' && format[1] == '*')
		{
			flag->precision = va_arg(flag->ap, int);
			format += 2;
			bytes += 2;
		}
		else if (format[0] == '*')
		{
			flag->width = va_arg(flag->ap, int);
			if (flag->width < 0)
			{
				flag->pad |= PAD_RIGHT;
				flag->width = -flag->width;
			}
			++format;
			++bytes;
		}
		if (*format == '.')
		{
			++format;
			++bytes;
		}
		while (ft_isdigit(*format))
		{
			// printf("\tWide boi\n");
			flag->width *= 10;
			flag->width += (*format - '0');
			++format;
			++bytes;
		}
		if (*format == '.')
		{
			++format;
			++bytes;
		}
		temp = strcany("sdcinouxX", *format);
		flag->type = (temp ? *temp : 0);
		// printf("\tflag->type = %c\n", flag->type);
		if (flag->type)
			break ;
		else
		{
			ft_putstr("{All we had to do was follow the damn flags, printf!}");
			return (0);
		}
		++format;
	}

	// printf("\tparse_format finished after %d bytes.\n", bytes);
	return (bytes);
}
