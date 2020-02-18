/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 18:54:29 by ngontjar          #+#    #+#             */
/*   Updated: 2020/02/18 21:43:19 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char * format, ...)
{
	va_list	ap;
	t_flag	flag;
	char	bytes;
	char	parsed;

	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			bytes = 1;
			if (0 == (parsed = parse_format(format + 1, &flag)))
			{
				++format;
				continue ;
			}
			if (flag.type == 's')
				output(va_arg(ap, char *), flag);
			else if (strcany("dci", flag.type))
				output(va_arg(ap, int), flag);
			else if (strcany("Xxuo", flag.type))
				output(va_arg(ap, unsigned int));
			format += bytes;
		}
		write(1, format, 1);
		++format;
	}
	va_end(ap);
	return (0);
}

int		main(int argc, char **argv)
{
	printf("argin %d\n", argument_index("2$"));
	printf("|%-05d|\n", 5);
}