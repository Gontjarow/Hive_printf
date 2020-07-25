/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 21:42:32 by ngontjar          #+#    #+#             */
/*   Updated: 2020/07/25 04:26:45 by ngontjar         ###   ########.fr       */
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
			flag->precision = va_arg(flag->ap, int); // ? negative = none
			flag->precision = (flag->precision < 0 ? 0 : flag->precision);
			++(*format);
			++bytes;
		}
		else if (**format == 'f' || **format == 'L') // todo: needed?
		{
			flag->precision = 0;
		}
		else //if (**format != 'f' || **format != 'L') // todo: test
		{
			if (!ft_isdigit(**format))
				flag->precision = 0;
			while (ft_isdigit(**format))
			{
				if (flag->precision == -1)
					flag->precision = (**format - '0');
				else
				{
					flag->precision = (flag->precision * 10) + (**format - '0');
				}
				++(*format);
				++bytes;
			}
		}
		if (flag->precision < -1)
			flag->precision = -flag->precision;
	}
	// printf("parse precision {%d}\n", flag->precision);
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
	while (**format == '-'
		|| **format == '+'
		|| **format == ' '
		|| **format == '#'
		|| **format == '0')
	{
		// printf("read: '%c'\n", **format);
		if (**format == '-')
		{
			flag->bit |= FLAG_JUSTIFY_LEFT;
			// printf("FLAG_JUSTIFY_LEFT set\n");
		}
		if (**format == '+')
		{
			flag->bit |= FLAG_FORCE_SIGN;
			// printf("FLAG_FORCE_SIGN set\n");
		}
		if (**format == ' ')
		{
			flag->bit |= FLAG_HIDE_SIGN;
			// printf("FLAG_HIDE_SIGN set\n");
		}
		if (**format == '#')
		{
			flag->bit |= FLAG_PREFIX;
			// printf("FLAG_PREFIX set\n");
		}
		if (**format == '0')
		{
			flag->bit |= FLAG_PAD_ZERO;
			// printf("FLAG_PAD_ZERO set\n");
		}
		++(*format) && ++bytes; // ? Norminette is okay with this. I'm not, but it's better than potentially having to split this function in two.
	}
	return (bytes);
}

char		parse_format(const char *format, t_data *flag)
{
	int		bytes;
	char	*type;

	bytes = 1; // ? percentage-sign
	// printf("format first char: %c\n\n", *format);

	bytes += parse_flags(&format, flag);
	// printf("\nbytes: %d (flags), next: %c\n", bytes, *format);
	// printf("Flags set: {%d}\n", flag->bit);

	bytes += parse_width(&format, flag);
	// printf("\nbytes: %d (width), next: %c\n", bytes, *format);

	bytes += parse_precision(&format, flag);
	// printf("\nbytes: %d (precision), next: %c\n", bytes, *format);

	bytes += parse_specifier(&format, flag);
	// printf("\nbytes: %d (specifier), next: %c\n\n", bytes, *format);

	type = ft_strchr("sdfciXxu%op", *format);
	flag->type = (type ? *type : 0);
	if (!flag->type)
	{
		// ft_putstr("{Unrecognized type}");
		printf("{Unrecognized type:%s}\n", type);
		return (0);
	}
	return (bytes);
}
