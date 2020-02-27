/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 21:42:32 by ngontjar          #+#    #+#             */
/*   Updated: 2020/02/27 19:00:23 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// width, precision, signage, justification, fill
// https://www.cypress.com/file/54441/download

char	parse_format(const char *format, t_flag *flag)
{
	int		bytes;
	char	*temp;

	if (*format == '%')
	{
		write(1, format, 1);
		return (1);
	}
	bytes = 0;
	while (*format)
	{
		++bytes;
		while (*format == '-')
		{
			flag->pad |= PAD_RIGHT;
			++format;
			++bytes;
		}
		while (*format == '0')
		{
			flag->pad |= PAD_ZERO;
			++format;
			++bytes;
		}
		// ???
		if (*format == '*')
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
		else if (ft_isdigit(*format))
		{
			while (ft_isdigit(*format))
			{
				flag->width *= 10;
				flag->width += (*format - '0');
				++format;
				++bytes;
			}
		}
		if (*format == '.')
		{
			++format;
			++bytes;
			if (*format == '*')
			{
				flag->precision = va_arg(flag->ap, int);
				++format;
				++bytes;
			}
			else
				while (ft_isdigit(*format))
				{
					flag->precision *= 10;
					flag->precision += (*format - '0');
					++format;
					++bytes;
				}
		}
		// ???

		temp = ft_strchr("sdcinouxX", *format);
		flag->type = (temp ? *temp : 0);
		if (flag->type)
			break ;
		else
		{
			ft_putstr("{All we had to do was follow the damn flags, printf!}");
			return (0);
		}
		++format;
	}
	return (bytes);
}
