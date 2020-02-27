/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 21:42:32 by ngontjar          #+#    #+#             */
/*   Updated: 2020/02/27 21:33:09 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// width, precision, signage, justification, fill
// https://www.cypress.com/file/54441/download

static char	parse_width(const char **format, t_flag *flag)
{
	char bytes;

	bytes = 0;
	if (**format == '*')
	{
		flag->width = va_arg(flag->ap, int);
		if (flag->width < 0)
		{
			flag->pad |= PAD_RIGHT;
			flag->width = -flag->width;
		}
		++(*format);
		++bytes;
	}
	else if (ft_isdigit(**format))
	{
		while (ft_isdigit(**format))
		{
			flag->width *= 10;
			flag->width += (**format - '0');
			++(*format);
			++bytes;
		}
	}
	return (bytes);
}

static char	parse_precision(const char **format, t_flag *flag)
{
	char bytes;

	bytes = 0;
	if (**format == '.')
	{
		++(*format);
		++bytes;
		if (**format == '*')
		{
			flag->precision = va_arg(flag->ap, int);
			++(*format);
			++bytes;
		}
		else
			while (ft_isdigit(**format))
			{
				flag->precision *= 10;
				flag->precision += (**format - '0');
				++(*format);
				++bytes;
			}
	}
	return (bytes);
}

char		parse_format(const char *format, t_flag *flag)
{
	int		bytes;
	char	*type;

	bytes = 0;
	while (*format)
	{
		++bytes;
		while (*format == '-')
		{
			flag->pad = PAD_RIGHT;
			++format;
			++bytes;
		}
		while (*format == '0')
		{
			flag->padder = '0';
			++format;
			++bytes;
		}
		bytes += parse_width(&format, flag);
		bytes += parse_precision(&format, flag);

		type = ft_strchr("sdciXxu%o", *format);
		flag->type = (type ? *type : 0);
		if (flag->type)
			break ;
		else
		{
			ft_putstr("{Unrecognized type}");
			return (0);
		}
	}
	return (bytes);
}
