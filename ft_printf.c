/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 18:54:29 by ngontjar          #+#    #+#             */
/*   Updated: 2020/02/19 19:19:17 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	try_parsing(const char *format, va_list ap);

int			ft_printf(const char *format, ...)
{
	va_list	ap;
	char	bytes;

	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			bytes = 1;
			bytes += try_parsing(format, ap);
			format += bytes;
		}
		write(1, format, 1);
		++format;
	}
	va_end(ap);
	return (0);
}

static char	try_parsing(const char *format, va_list ap)
{
	t_flag	flag;
	char	parsed;
	int		written;

	if (0 == (parsed = parse_format(++format, &flag)))
		return (0);

	else if (flag.type == 's')
		written = output_str(va_arg(ap, char *), flag);
	else if (strcany("dci", flag.type))
		written = output_int(va_arg(ap, int), flag);
	else if (strcany("Xxuo", flag.type))
		written = output_uint(va_arg(ap, unsigned int), flag);

	return (parsed);
}

int			main(int argc, char **argv)
{
	// printf("argin %d\n", argument_index("2$"));
	// printf("|%-05d|\n", 5);
	printf("%s\n", "hello world");
	ft_printf("%s\n", "hello world");
}