/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 18:54:29 by ngontjar          #+#    #+#             */
/*   Updated: 2020/02/20 20:38:56 by ngontjar         ###   ########.fr       */
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
		//printf("\treading str: %c\n", *format);
		if (*format == '%')
		{
			////printf("\tTry parsing...\n");
			bytes = 1;
			bytes += try_parsing(format, ap);
			format += bytes;
			//printf("\tskipping to %c after parse.\n", *format);
			continue ;
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
	{
		//printf("\tparse_format said NO!\n");
		return (0);
	}

	//printf("\tLet's see what it is...\n");
	if (flag.type == 's')
		written = output_str(va_arg(ap, char *), flag);
	else if (strcany("dci", flag.type))
		written = output_int(va_arg(ap, int), flag);
	else if (strcany("Xxuo", flag.type))
		written = output_uint(va_arg(ap, unsigned int), flag);

	//printf("\tParsed: %d\n", parsed);
	return (parsed);
}

int			main(int argc, char **argv)
{
	(void)argc; (void)argv;
	// printf("argin %d\n", argument_index("2$"));
	// printf("|%-05d|\n", 5);
	printf("\treal> %s, and good night\n", "hello world");
	ft_printf("\tmine> %s, and good night\n", "hello world");
	ft_putendl("");
	printf("\treal> %15s, and good night\n", "hello world");
	ft_printf("\tmine> %15s, and good night\n", "hello world");
}
