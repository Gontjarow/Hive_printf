/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 18:54:29 by ngontjar          #+#    #+#             */
/*   Updated: 2020/03/06 13:55:32 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	try_parsing(const char *format, t_data *flag);

int			ft_printf(const char *format, ...)
{
	t_data	flag;
	char	bytes;

	flag = (t_data){{{0}}, 0, 0, 0, 0, 0, 0};
	va_start(flag.ap, format);
	while (*format)
	{
		//printf("\treading str: %c\n", *format);
		if (*format == '%')
		{
			//printf("\tTry parsing...\n");
			bytes = 1;
			flag.pad = 0;
			flag.padder = ' ';
			flag.width = 0;
			flag.precision = 0;
			flag.type = 0;
			flag.written = 0;
			bytes += try_parsing(format, &flag);
			format += bytes;
			flag.written += bytes;
			//printf("\tskipping to %c after parse.\n", *format);
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

	if (0 == (parsed = parse_format(++format, flag)))
	{
		//printf("\tparse_format said NO!\n");
		return (0);
	}

	// printf("\tLet's see what it is...\n");
	if (flag->type == 's')
		flag->written = output_str(va_arg(flag->ap, char *), flag);
	else if (flag->type == '%')
		flag->written = output_str("%", flag);
	else if (ft_strchr("dci", flag->type))
		flag->written = output_int(va_arg(flag->ap, int), flag);
	else if (ft_strchr("Xxuo", flag->type))
		flag->written = output_uint(va_arg(flag->ap, unsigned int), flag);

	//printf("\tParsed: %d\n", parsed);
	return (parsed);
}

int			main(int argc, char **argv)
{
	(void)argc; (void)argv;

	int a, b;

	a =    printf("real: |%u|\n", 123);
	b = ft_printf("mine: |%u|\n", 123);
	printf("%d == %d\n", a, b); //!

	a =    printf("real: |%u|\n", -123);
	b = ft_printf("mine: |%u|\n", -123);
	printf("%d == %d\n", a, b); //!
	ft_putendl("");

	ft_putendl("width & precision, positive numbers");
	   printf("real: |%20.5d|\n", -123);
	   printf("real: |%*.*d|\n", 20, 5, -123);
	   printf("real: |%20.*d|\n", 5, -123);
	   printf("real: |%*.5d|\n", 20, -123);
	ft_putendl("");
	ft_printf("mine: |%20.5d|\n", -123);
	ft_printf("mine: |%*.*d|\n", 20, 5, -123);
	ft_printf("mine: |%20.*d|\n", 5, -123);
	ft_printf("mine: |%*.5d|\n", 20, -123);
	ft_putendl("");

	   printf("real: |%20.20d|\n", -123);
	   printf("real: |%*.*d|\n", 20, 20, -123);
	   printf("real: |%20.*d|\n", 20, -123);
	   printf("real: |%*.20d|\n", 20, -123);
	ft_putendl("");
	ft_printf("mine: |%20.20d|\n", -123);
	ft_printf("mine: |%*.*d|\n", 20, 20, -123);
	ft_printf("mine: |%20.*d|\n", 20, -123);
	ft_printf("mine: |%*.20d|\n", 20, -123);
	ft_putendl("");

	   printf("real: |%20.25d|\n", -123);
	   printf("real: |%*.*d|\n", 20, 25, -123);
	   printf("real: |%20.*d|\n", 25, -123);
	   printf("real: |%*.25d|\n", 20, -123);
	ft_putendl("");
	ft_printf("mine: |%20.25d|\n", -123);
	ft_printf("mine: |%*.*d|\n", 20, 25, -123);
	ft_printf("mine: |%20.*d|\n", 25, -123);
	ft_printf("mine: |%*.25d|\n", 20, -123);
	ft_putendl("");

	   printf("real: |%.13d|\n", -123);
	   printf("real: |%.13i|\n", -123);
	   printf("real: |%.13u|\n", -123);
	   printf("real: |%.13o|\n", -123);
	   printf("real: |%.13x|\n", -123);
	   printf("real: |%.13X|\n", -123);
	ft_putendl("");
	ft_printf("mine: |%.13d|\n", -123);
	ft_printf("mine: |%.13i|\n", -123);
	ft_printf("mine: |%.13u|\n", -123);
	ft_printf("mine: |%.13o|\n", -123);
	ft_printf("mine: |%.13x|\n", -123);
	ft_printf("mine: |%.13X|\n", -123);
	ft_putendl("");

	   printf("real: |%d|\n", -123);
	ft_printf("mine: |%d|\n", -123);
	ft_putendl("");

	   printf("real: |%0.5d|\n", 123);
	   printf("real: |%*.*d|\n", 0, 5, 123);
	   printf("real: |%0.*d|\n", 5, 123);
	   printf("real: |%*.5d|\n", 0, 123);
	ft_printf("mine: |%0.5d|\n", 123);
	ft_printf("mine: |%*.*d|\n", 0, 5, 123);
	ft_printf("mine: |%0.*d|\n", 5, 123);
	ft_printf("mine: |%*.5d|\n", 0, 123);
	ft_putendl("");

	ft_putendl("width & precision, negative numbers");
	   printf("real: |%10.5d|\n", -123);
	   printf("real: |%*.*d|\n", 10, 5, -123);
	   printf("real: |%10.*d|\n", 5, -123);
	   printf("real: |%*.5d|\n", 10, -123);
	ft_printf("mine: |%10.5d|\n", -123);
	ft_printf("mine: |%*.*d|\n", 10, 5, -123);
	ft_printf("mine: |%10.*d|\n", 5, -123);
	ft_printf("mine: |%*.5d|\n", 10, -123);
	ft_putendl("");

	   printf("real: |%10.0d|\n", -123);
	   printf("real: |%*.*d|\n", 10, 0, -123);
	   printf("real: |%10.*d|\n", 0, -123);
	   printf("real: |%*.0d|\n", 10, -123);
	ft_printf("mine: |%10.0d|\n", -123);
	ft_printf("mine: |%*.*d|\n", 10, 0, -123);
	ft_printf("mine: |%10.*d|\n", 0, -123);
	ft_printf("mine: |%*.0d|\n", 10, -123);
	ft_putendl("");

	ft_putendl("width & precision, char");
	   printf("real: |%10.5c|\n", '?'); //!
	   printf("real: |%*.*c|\n", 10, 5, '?'); //!
	   printf("real: |%10.*c|\n", 5, '?'); //!
	   printf("real: |%*.5c|\n", 10, '?'); //!
	ft_printf("mine: |%10.5c|\n", '?'); //!
	ft_printf("mine: |%*.*c|\n", 10, 5, '?'); //!
	ft_printf("mine: |%10.*c|\n", 5, '?'); //!
	ft_printf("mine: |%*.5c|\n", 10, '?'); //!
	ft_putendl("");


	ft_putendl("asterisk");
	printf("real> %%*s 15 	|%*s|\n", 15, "hello world");
	ft_printf("mine> %%*s 15 	|%*s|\n", 15, "hello world");
	ft_putendl("");

	printf("real> %%-*s 15 	|%-*s|\n", 15, "hello world");
	ft_printf("mine> %%-*s 15 	|%-*s|\n", 15, "hello world");
	ft_putendl("");

	printf("real> %%*s -15 	|%*s|\n", -15, "hello world");
	ft_printf("mine> %%*s -15 	|%*s|\n", -15, "hello world");
	ft_putendl("");

	printf("real> %%-*s -15 	|%-*s|\n", -15, "hello world");
	ft_printf("mine> %%-*s -15 	|%-*s|\n", -15, "hello world");
	ft_putendl("");

	printf("real> |%s %% %s|\n", "hello", "world");
	ft_printf("mine> |%s %% %s|\n", "hello", "world");
	ft_putendl("");


	ft_putendl("percentage");
	printf("real> |%%|\n");
	ft_printf("mine> |%%|\n");
	ft_putendl("");
	printf("real> |%10.5%|\n");
	ft_printf("mine> |%10.5%|\n");


	ft_putendl("regular string");
	printf("real> |%s, and good night|\n", "hello world");
	ft_printf("mine> |%s, and good night|\n", "hello world");
	ft_putendl("");


	ft_putendl("null string");
	printf("real> |%s, and good night|\n", NULL);
	ft_printf("mine> |%s, and good night|\n", NULL);
	ft_putendl("");


	ft_putendl("width positive");
	printf("real> |%15s, and good night|\n", "hello world");
	ft_printf("mine> |%15s, and good night|\n", "hello world");
	ft_putendl("");

	printf("real> |%15s, and good night|\n", NULL);
	ft_printf("mine> |%15s, and good night|\n", NULL);
	ft_putendl("");

	printf("real> |%1s, and good night|\n", "hello world");
	ft_printf("mine> |%1s, and good night|\n", "hello world");
	ft_putendl("");

	printf("real> |%1s, and good night|\n", NULL);
	ft_printf("mine> |%1s, and good night|\n", NULL);
	ft_putendl("");


	ft_putendl("width negative");
	printf("real> |%-15s, and good night|\n", "hello world");
	ft_printf("mine> |%-15s, and good night|\n", "hello world");
	ft_putendl("");

	printf("real> |%-15s, and good night|\n", NULL);
	ft_printf("mine> |%-15s, and good night|\n", NULL);
	ft_putendl("");

	printf("real> |%-1s, and good night|\n", "hello world");
	ft_printf("mine> |%-1s, and good night|\n", "hello world");
	ft_putendl("");

	printf("real> |%-1s, and good night|\n", NULL);
	ft_printf("mine> |%-1s, and good night|\n", NULL);
	ft_putendl("");
}
