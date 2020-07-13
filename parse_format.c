/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 21:42:32 by ngontjar          #+#    #+#             */
/*   Updated: 2020/02/28 23:30:36 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// width, precision, signage, justification, fill
// https://www.cypress.com/file/54441/download

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
		++(*format);
		++bytes;
	}
	else
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

static char	parse_precision(const char **format, t_data *flag)
{
	char bytes;

	bytes = 0;
	// printf("piss %c\n", **format);
	if (**format == '.')
	{
		++(*format);
		++bytes;
		// printf("parse next: %c\n", **format);
		if (**format == '*')
		{
			// ft_putendl("?????????\n");
			flag->precision = va_arg(flag->ap, int);
			++(*format);
			++bytes;
		}
		else if (**format == 'f' || **format == 'L')
		{
			// ft_putendl("!!!!!!!!!!\n");
			flag->precision = 0;
		}
		else
		{
			// ft_putendl("BRAAAAAANCH\n");
			while (ft_isdigit(**format))
			{
				flag->precision *= 10;
				flag->precision += (**format - '0');
				++(*format);
				++bytes;
			}
		}
		if (flag->precision < -1)
			flag->precision = -flag->precision;
	}
	// ft_putendl("BAIIIII");
	return (bytes);
}

static char parse_specifier(const char **format, t_data *flag)
{
	char bytes;

	bytes = 0;
	if (**format == 'h')
	{
		++(*format);
		++bytes;
		if ((*format)[1] == 'h')
		{
			++(*format);
			++bytes;
			flag->specifier = SPECIFIER_HH;
		}
		else
			flag->specifier = SPECIFIER_H;
	}
	else if (**format == 'l' || **format == 'L')
	{
		++(*format);
		++bytes;
		if ((*format)[1] == 'l' && **format == 'l') //? Don't accept Ll format
		{
			++(*format);
			++bytes;
			flag->specifier = SPECIFIER_LL;
		}
		else
			flag->specifier = SPECIFIER_L;
	}
	unsigned long skip = strany_skip(*format, "hlL") - (*format);
	bytes += skip;
	(*format) += skip;
	return (bytes);
}

static char	parse_flags(const char **format, t_data *flag)
{
	int bytes;

	bytes = 0;
	while (**format == '-' && ++(*format) && ++bytes)
	{
		flag->bit |= FLAG_JUSTIFY_LEFT;
	}
	while (**format == '+' && ++(*format) && ++bytes)
	{
		flag->bit |= FLAG_FORCE_SIGN;
	}
	while (**format == ' ' && ++(*format) && ++bytes)
	{
		flag->bit |= FLAG_HIDE_SIGN;
	}
	while (**format == '#' && ++(*format) && ++bytes)
	{
		flag->bit |= FLAG_PREFIX;
	}
	while (**format == '0' && ++(*format) && ++bytes)
	{
		flag->bit |= FLAG_PAD_ZERO;
	}
	return (bytes);
}


char		parse_format(const char *format, t_data *flag)
{
	int		bytes;
	char	*type;

	bytes = 0;
	// while (*format)
	// {
	// printf("SURELY\n");
	// printf("format first char: %c\n", *format);
	++bytes;
	// printf("\nbytes: %d (first)\n", bytes);
	bytes += parse_flags(&format, flag);
	// printf("bytes: %d (flags)\n", bytes);
	bytes += parse_width(&format, flag);
	// printf("bytes: %d (width)\n", bytes);
	bytes += parse_precision(&format, flag);
	// printf("bytes: %d (precision)\n", bytes);
	bytes += parse_specifier(&format, flag);
	// printf("bytes: %d (specifier)\n\n", bytes);
	type = ft_strchr("sdfciXxu%op", *format);
	flag->type = (type ? *type : 0);
	if (!flag->type)
	{
		ft_putstr("{Unrecognized type}");
		return (0);
	}
	// }
	return (bytes);
}
