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

	flag = (t_data){{{0}}, 0, 0, 0, 0, 0, 0, 0};
	va_start(flag.ap, format);
	while (*format)
	{
		// printf("\treading str: %c\n", *format);
		if (*format == '%')
		{
			// printf("\tTry parsing...\n");
			bytes = 1;
			flag.bit = 0;
			flag.padder = ' ';
			flag.width = 0;
			flag.precision = 0;
			flag.specifier = 0;
			flag.type = 0;
			flag.written = 0;
			bytes += try_parsing(format, &flag);
			format += bytes;
			flag.written += bytes;
			// printf("\tskipping to %c after parse.\n", *format);
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
		// printf("\tparse_format said NO!\n");
		return (0);
	}

	// printf("\tLet's see what it is...\n");
	if (flag->type == 's')
		flag->written = output_str(va_arg(flag->ap, char *), flag);
	else if (flag->type == '%')
		flag->written = output_str("%", flag);
	else if (ft_strchr("dci", flag->type))
	{
		if (flag->specifier == SPECIFIER_L)
			flag->written = output_int(va_arg(flag->ap, long), flag);
		else if (flag->specifier == SPECIFIER_LL)
			flag->written = output_int(va_arg(flag->ap, long long), flag);
		else
			flag->written = output_int(va_arg(flag->ap, int), flag);
	}
	else if (ft_strchr("Xxuo", flag->type))
		flag->written = output_uint(va_arg(flag->ap, unsigned long long), flag);
	else if (flag->type == 'p')
		flag->written = output_pointer(va_arg(flag->ap, void *), flag);
	//printf("\tParsed: %d\n", parsed);
	return (parsed);
}

int			main(int argc, char **argv)
{
	// (void)argc; (void)argv;

	int a, b;

	printf("int:%lu ll int:%lu\n", sizeof(int), sizeof(long long int));
	a =    printf("real: |%u|\n", 123);
	b = ft_printf("mine: |%u|\n", 123);
	printf("%d == %d\n", a, b); //!

	a =    printf("real: |%u|\n", -123);
	b = ft_printf("mine: |%u|\n", -123);
	printf("%d == %d\n", a, b); //!
	ft_putendl("");

	ft_putendl("-1 signed types");
	   printf("test hhu |%10hhu|\n", (unsigned char)-1);
	ft_printf("test hhu |%10hhu|\n", (unsigned char)-1);
	ft_putendl("");
	   printf("test hu  |%10hu|\n", (unsigned short)-1);
	ft_printf("test hu  |%10hu|\n", (unsigned short)-1);
	ft_putendl("");
	   printf("test u   |%10u|\n", (unsigned int)-1);
	ft_printf("test u   |%10u|\n", (unsigned int)-1);
	ft_putendl("");
	   printf("test lu  |%10lu|\n", (unsigned long)-1);
	ft_printf("test lu  |%10lu|\n", (unsigned long)-1);
	ft_putendl("");
	   printf("test llu |%10llu|\n", (unsigned long long)-1);
	ft_printf("test llu |%10llu|\n", (unsigned long long)-1);

	ft_putendl("");
	   printf("test h	%hd\n", -1);
	ft_printf("test h	%hd\n", -1);
	   printf("test h	%hd\n", (short)-1);
	ft_printf("test h	%hd\n", (short)-1);
	ft_putendl("");
	   printf("test hh	%hhd\n", -1);
	ft_printf("test hh	%hhd\n", -1);
	   printf("test hh	%hhd\n", (char)-1);
	ft_printf("test hh	%hhd\n", (char)-1);
	ft_putendl("");
	   printf("test l	%ld\n", -1);
	ft_printf("test l	%ld\n", -1);
	   printf("test l	%ld\n", (long)-1);
	ft_printf("test l	%ld\n", (long)-1);
	ft_putendl("");
	   printf("test ll	%lld\n", -1);
	ft_printf("test ll	%lld\n", -1);
	   printf("test ll	%lld\n", (long long)-1);
	ft_printf("test ll	%lld\n", (long long)-1);
	ft_putendl("");
	//    printf("undefined test L	%Ld\n", -1);
	// ft_printf("undefined test L	%Ld\n", -1);
	//    printf("undefined test L	%Ld\n", (long long)-1);
	// ft_printf("undefined test L	%Ld\n", (long long)-1);
	// ft_putendl("");
	//    printf("undefined test LL	%LLd\n", -1);
	// ft_printf("undefined test LL	%LLd\n", -1);
	//    printf("undefined test LL	%LLd\n", (long long)-1);
	// ft_printf("undefined test LL	%LLd\n", (long long)-1);
	// ft_putendl("");
	//    printf("undefined test Ll	%Lld\n", -1);
	// ft_printf("undefined test Ll	%Lld\n", -1);
	//    printf("undefined test Ll	%Lld\n", (long long)-1);
	// ft_printf("undefined test Ll	%Lld\n", (long long)-1);
	// ft_putendl("");

	ft_putendl("");
	ft_putendl("pointers");
	   printf("real: |%p| (uint %llu)\n", &a, (unsigned long long)&a);
	ft_printf("mine: |%p|\n", &a);
	ft_putendl("");
	//    printf("undefined real: |%0.0p|\n", &a);
	// ft_printf("undefined mine: |%0.0p|\n", &a);
	// ft_putendl("");
	//    printf("undefined real: |%20.5p|\n", &a);
	// ft_printf("undefined mine: |%20.5p|\n", &a);
	// ft_putendl("");
	//    printf("undefined real: |%5.20p|\n", &a);
	// ft_printf("undefined mine: |%5.20p|\n", &a);
	// ft_putendl("");

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

	ft_putendl("all decimal types");
	   printf("real d: |%.13d|\n", -123);
	ft_printf("mine d: |%.13d|\n", -123);
	ft_putendl("");
	   printf("real i: |%.13i|\n", -123);
	ft_printf("mine i: |%.13i|\n", -123);
	ft_putendl("");
	   printf("real u: |%.13u|\n", -123);
	ft_printf("mine u: |%.13u|\n", -123);
	ft_putendl("");
	   printf("real o: |%.13o|\n", -123);
	ft_printf("mine o: |%.13o|\n", -123);
	ft_putendl("");
	   printf("real x: |%.13x|\n", -123);
	ft_printf("mine x: |%.13x|\n", -123);
	ft_putendl("");
	   printf("real X: |%.13X|\n", -123);
	ft_printf("mine X: |%.13X|\n", -123);
	ft_putendl("");

	   printf("real: |%d|\n", -123);
	ft_printf("mine: |%d|\n", -123);
	ft_putendl("");

	ft_putendl("variables");
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
	ft_putendl("width > precision");
	   printf("real: |%10.5c|\n", '?');
	   printf("real: |%*.*c|\n", 10, 5, '?');
	   printf("real: |%10.*c|\n", 5, '?');
	   printf("real: |%*.5c|\n", 10, '?');
	ft_printf("mine: |%10.5c|\n", '?');
	ft_printf("mine: |%*.*c|\n", 10, 5, '?');
	ft_printf("mine: |%10.*c|\n", 5, '?');
	ft_printf("mine: |%*.5c|\n", 10, '?');
	ft_putendl("");
	   printf("real: |%010.5c|\n", '?');
	ft_printf("mine: |%010.5c|\n", '?');
	ft_putendl("");
	ft_putendl("precision > width");
	   printf("real: |%5.10c|\n", '?');
	   printf("real: |%*.*c|\n", 5, 10, '?');
	   printf("real: |%5.*c|\n", 10, '?');
	   printf("real: |%*.10c|\n", 5, '?');
	ft_printf("mine: |%5.10c|\n", '?');
	ft_printf("mine: |%*.*c|\n", 5, 10, '?');
	ft_printf("mine: |%5.*c|\n", 10, '?');
	ft_printf("mine: |%*.10c|\n", 5, '?');
	ft_putendl("");
	   printf("real: |%05.10c|\n", '?');
	ft_printf("mine: |%05.10c|\n", '?');
	ft_putendl("");
	   printf("real: |%0.0c|\n", '?');
	ft_printf("mine: |%0.0c|\n", '?');
	   printf("real: |%.0c|\n", '?');
	ft_printf("mine: |%.0c|\n", '?');
	   printf("real: |%0c|\n", '?');
	ft_printf("mine: |%0c|\n", '?');
	   printf("real: |%0.0c|\n", '?');
	ft_printf("mine: |%0.0c|\n", '?');
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
