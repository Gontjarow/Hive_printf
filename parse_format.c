/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <niko.gontjarow@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 21:42:32 by ngontjar          #+#    #+#             */
/*   Updated: 2020/08/13 18:55:29 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	parse_width(const char **format, t_data *flag)
{
	char bytes;

	bytes = 0;
	if (**format == '*')
	{
		flag->width = va_arg(flag->ap, int);
		if (flag->width < 0)
		{
			flag->bit |= FLAG_JUSTIFY_LEFT;
			flag->width = -flag->width;
		}
		++(*format) && ++bytes;
	}
	else
	{
		while (ft_isdigit(**format))
		{
			flag->width *= 10;
			flag->width += (**format - '0');
			++(*format) && ++bytes;
		}
	}
	return (bytes);
}

static char	parse_precision(const char **format, t_data *flag)
{
	char bytes;

	if (**format != '.')
		return (0);
	++(*format) && (bytes = 1);
	if (**format == '*' && ++(*format) && ++bytes)
	{
		flag->precision = va_arg(flag->ap, int);
		flag->precision = (flag->precision < 0 ? -1 : flag->precision);
	}
	else if (**format != 'f' || **format != 'L')
	{
		flag->precision = (!ft_isdigit(**format)) ? 0 : flag->precision;
		while (ft_isdigit(**format))
		{
			if (flag->precision == -1)
				flag->precision = (**format - '0');
			else
				flag->precision = (flag->precision * 10) + (**format - '0');
			++(*format) && ++bytes;
		}
	}
	if (flag->precision < -1)
		flag->precision = -flag->precision;
	return (bytes);
}

static char	parse_specifier(const char **format, t_data *flag)
{
	char			bytes;
	size_t			skip;

	bytes = 0;
	if (**format == 'h')
	{
		++(*format) && ++bytes;
		if (**format == 'h' && ++(*format) && ++bytes)
			flag->specifier = SPECIFIER_HH;
		else
			flag->specifier = SPECIFIER_H;
	}
	else if (**format == 'l' || **format == 'L')
	{
		++(*format) && ++bytes;
		if (**format == 'l' && ++(*format) && ++bytes)
			flag->specifier = SPECIFIER_LL;
		else
			flag->specifier = *(*format - 1) == 'L' ? SPECIFIER_L : 0;
	}
	if ((skip = (size_t)strany_skip(*format, "hlL")))
		skip -= (size_t)(*format);
	(bytes += skip) && ((*format) += skip);
	return (bytes);
}

static char	parse_flags(const char **format, t_data *flag)
{
	int bytes;

	bytes = 0;
	while (**format == '-'
		|| **format == '+'
		|| **format == ' '
		|| **format == '#'
		|| **format == '0')
	{
		if (**format == '-')
			flag->bit |= FLAG_JUSTIFY_LEFT;
		if (**format == '+')
			flag->bit |= FLAG_FORCE_SIGN;
		if (**format == ' ')
			flag->bit |= FLAG_PAD_SIGN;
		if (**format == '#')
			flag->bit |= FLAG_PREFIX;
		if (**format == '0')
			flag->bit |= FLAG_LEADING_ZERO;
		++(*format) && ++bytes;
	}
	return (bytes);
}

char		parse_format(const char *format, t_data *flag)
{
	int		bytes;
	char	*type;

	bytes = 1;
	bytes += parse_flags(&format, flag);
	bytes += parse_width(&format, flag);
	bytes += parse_precision(&format, flag);
	bytes += parse_specifier(&format, flag);
	type = ft_strchr("sdfciXxu%op", *format);
	flag->type = (type ? *type : 0);
	if (!flag->type)
		return (0);
	return (bytes);
}
