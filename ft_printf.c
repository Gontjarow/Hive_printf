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
			flag.precision = -1;
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
	// printf("uhh... %c\n", *format);
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
	else if (flag->type == 'f')
	{
		if (flag->specifier == SPECIFIER_L)
			flag->written = output_double(va_arg(flag->ap, long double), flag);
		else
			flag->written = output_double(va_arg(flag->ap, double), flag);
	}
	//printf("\tParsed: %d\n", parsed);
	return (parsed);
}

int			main(int argc, char **argv)
{
	// ! TODO: ft_printf("%s", ft_ftoa) prints a single random(?) digit.
	// (void)argc; (void)argv;

	// printf(" 7: |%7.7f|\n", 1234567890123456789.1234567890123456789);
	// printf("15: |%15.15f|\n", 1234567890123456789.1234567890123456789);
	// printf("\n");
	// printf(" 7: |%7.7f|\n", 123456789012345678.1234567890123456789);
	// printf("15: |%15.15f|\n", 123456789012345678.1234567890123456789);
	// printf("\n");
	// printf(" 7: |%7.7f|\n", 12345678901234567.1234567890123456789);
	// printf("15: |%15.15f|\n", 12345678901234567.1234567890123456789);
	// printf("\n");
	// printf(" 7: |%7.7f|\n", 1234567890123456.1234567890123456789);
	// printf("15: |%15.15f|\n", 1234567890123456.1234567890123456789);
	// printf("\n");
	// printf(" 7: |%7.7f|\n", 123456789012345.1234567890123456789);
	// printf("15: |%15.15f|\n", 123456789012345.1234567890123456789);
	// printf("\n");
	// printf(" 7: |%7.7f|\n", 12345678901234.1234567890123456789);
	// printf("15: |%15.15f|\n", 12345678901234.1234567890123456789);
	printf("====================\n");

	int prec = 18;
	printf("FTOA VS PRINTF TESTS:\n");
	printf("real: |%.*f|\n", prec, PI);
 ft_printf("mine: |%s|\n", ft_ftoa(PI, prec));
	printf("\n");
	printf("real: |%.*f|\n", prec, -PI);
 ft_printf("mine: |%s|\n", ft_ftoa(-PI, prec));
	printf("\n");
	printf("real: |%.*f|\n", prec, 1.0 / 3);
 ft_printf("mine: |%s|\n", ft_ftoa(1.0 / 3, prec));
	printf("\n");
	printf("real 0: |%.*f|\n", prec, (double)0);
 ft_printf("mine 0: |%s|\n", ft_ftoa((double)0, prec));
	printf("\n");
	printf("real 0: |%.*f|\n", prec, -0);
 ft_printf("mine 0: |%s|\n", ft_ftoa(-0, prec));
	printf("\n");
	printf("real -0: |%.*f|\n", prec, -0.0);
 ft_printf("mine -0: |%s|\n", ft_ftoa(0 / -INFINITY, prec));
	printf("\n");
	printf("real: |%.*f|\n", prec, (double)1);
 ft_printf("mine: |%s|\n", ft_ftoa((double)1, prec));
	printf("\n");
	printf("real: |%.*f|\n", prec, (double)-1);
 ft_printf("mine: |%s|\n", ft_ftoa((double)-1, prec));
	printf("\n");
	printf("real: |%.*f|\n", prec, 123.123);
 ft_printf("mine: |%s|\n", ft_ftoa(123.123, prec));
	printf("\n");
	printf("real inf: |%.*f|\n", prec, 3.0 / 0);
 ft_printf("mine inf: |%s|\n", ft_ftoa(3.0 / 0, prec));
	printf("\n");
	printf("real -inf: |%.*f|\n", prec, -3.0 / 0);
 ft_printf("mine -inf: |%s|\n", ft_ftoa(-3.0 / 0, prec));
	printf("\n");
	printf("real nan: |%.*f|\n", prec, sqrt(-1));
 ft_printf("mine nan: |%s|\n", ft_ftoa(sqrt(-1), prec));
	printf("\n");
	printf("real: |%.*f|\n", 0, 1.99);
 ft_printf("mine: |%s|\n", ft_ftoa(1.99, 0));
	printf("\n");
	printf("real: |%.*f|\n", 123.000000123, prec);
 ft_printf("mine: |%s|\n", ft_ftoa(123.000000123, prec));
	printf("\n====================\n\n");
	// printf("\n");
	// printf("12345678901234.1234567890123456789 (string)\n");
	// printf("%14.19f (printf %%14.19f)\n", 12345678901234.1234567890123456789);
	// printf("%14.19Lf (printf %%14.19Lf)\n", 12345678901234.1234567890123456789);
	// ft_putendl("mine:");
	// ft_ftoa(12345678901234.1234567890123456789, 19);

	printf("real: %.f\n", 123.000000123);
 ft_printf("mine: %.f\n", 123.000000123);

	printf("real: %.Lf\n", 123.000000123L);
 ft_printf("mine: %.Lf\n", 123.000000123L);

	printf("real: %.f\n", 123.000000123L);
 ft_printf("mine: %.f\n", 123.000000123L);

	// output_double(12345678901234.1234567890123456789, NULL); // TODO
	// float_to_binary(6.000000476837158203125E0);
	// double_to_binary(6.000000476837158203125E0L);

	// printf("\n1.2345679020032E13 (string)\n");
	// printf("%f (printf)\n", 1.2345679020032E13);
	// ft_putendl("mine:");
	// float_to_binary(1.2345679020032E13);
	// double_to_binary(1.2345679020032E13);

	// int a, b;

	// printf("int:%lu ll int:%lu\n", sizeof(int), sizeof(long long int));
	// a =    printf("real: |%u|\n", 123);
	// b = ft_printf("mine: |%u|\n", 123);
	// printf("%d == %d\n", a, b); //!

	// a =    printf("real: |%u|\n", -123);
	// b = ft_printf("mine: |%u|\n", -123);
	// printf("%d == %d\n", a, b); //!
	// ft_putendl("");

	// ft_putendl("-1 signed types");
	//    printf("test hhu |%10hhu|\n", (unsigned char)-1);
	// ft_printf("test hhu |%10hhu|\n", (unsigned char)-1);
	// ft_putendl("");
	//    printf("test hu  |%10hu|\n", (unsigned short)-1);
	// ft_printf("test hu  |%10hu|\n", (unsigned short)-1);
	// ft_putendl("");
	//    printf("test u   |%10u|\n", (unsigned int)-1);
	// ft_printf("test u   |%10u|\n", (unsigned int)-1);
	// ft_putendl("");
	//    printf("test lu  |%10lu|\n", (unsigned long)-1);
	// ft_printf("test lu  |%10lu|\n", (unsigned long)-1);
	// ft_putendl("");
	//    printf("test llu |%10llu|\n", (unsigned long long)-1);
	// ft_printf("test llu |%10llu|\n", (unsigned long long)-1);

	// ft_putendl("");
	//    printf("test h	%hd\n", -1);
	// ft_printf("test h	%hd\n", -1);
	//    printf("test h	%hd\n", (short)-1);
	// ft_printf("test h	%hd\n", (short)-1);
	// ft_putendl("");
	//    printf("test hh	%hhd\n", -1);
	// ft_printf("test hh	%hhd\n", -1);
	//    printf("test hh	%hhd\n", (char)-1);
	// ft_printf("test hh	%hhd\n", (char)-1);
	// ft_putendl("");
	//    printf("test l	%ld\n", -1);
	// ft_printf("test l	%ld\n", -1);
	//    printf("test l	%ld\n", (long)-1);
	// ft_printf("test l	%ld\n", (long)-1);
	// ft_putendl("");
	//    printf("test ll	%lld\n", -1);
	// ft_printf("test ll	%lld\n", -1);
	//    printf("test ll	%lld\n", (long long)-1);
	// ft_printf("test ll	%lld\n", (long long)-1);
	// ft_putendl("");
	// //    printf("undefined test L	%Ld\n", -1);
	// // ft_printf("undefined test L	%Ld\n", -1);
	// //    printf("undefined test L	%Ld\n", (long long)-1);
	// // ft_printf("undefined test L	%Ld\n", (long long)-1);
	// // ft_putendl("");
	// //    printf("undefined test LL	%LLd\n", -1);
	// // ft_printf("undefined test LL	%LLd\n", -1);
	// //    printf("undefined test LL	%LLd\n", (long long)-1);
	// // ft_printf("undefined test LL	%LLd\n", (long long)-1);
	// // ft_putendl("");
	// //    printf("undefined test Ll	%Lld\n", -1);
	// // ft_printf("undefined test Ll	%Lld\n", -1);
	// //    printf("undefined test Ll	%Lld\n", (long long)-1);
	// // ft_printf("undefined test Ll	%Lld\n", (long long)-1);
	// // ft_putendl("");

	// ft_putendl("");
	// ft_putendl("pointers");
	//    printf("real: |%p| (uint %llu)\n", &a, (unsigned long long)&a);
	// ft_printf("mine: |%p|\n", &a);
	// ft_putendl("");
	// //    printf("undefined real: |%0.0p|\n", &a);
	// // ft_printf("undefined mine: |%0.0p|\n", &a);
	// // ft_putendl("");
	// //    printf("undefined real: |%20.5p|\n", &a);
	// // ft_printf("undefined mine: |%20.5p|\n", &a);
	// // ft_putendl("");
	// //    printf("undefined real: |%5.20p|\n", &a);
	// // ft_printf("undefined mine: |%5.20p|\n", &a);
	// // ft_putendl("");

	// ft_putendl("width & precision, positive numbers");
	//    printf("real: |%20.5d|\n", -123);
	//    printf("real: |%*.*d|\n", 20, 5, -123);
	//    printf("real: |%20.*d|\n", 5, -123);
	//    printf("real: |%*.5d|\n", 20, -123);
	// ft_putendl("");
	// ft_printf("mine: |%20.5d|\n", -123);
	// ft_printf("mine: |%*.*d|\n", 20, 5, -123);
	// ft_printf("mine: |%20.*d|\n", 5, -123);
	// ft_printf("mine: |%*.5d|\n", 20, -123);
	// ft_putendl("");

	//    printf("real: |%20.20d|\n", -123);
	//    printf("real: |%*.*d|\n", 20, 20, -123);
	//    printf("real: |%20.*d|\n", 20, -123);
	//    printf("real: |%*.20d|\n", 20, -123);
	// ft_putendl("");
	// ft_printf("mine: |%20.20d|\n", -123);
	// ft_printf("mine: |%*.*d|\n", 20, 20, -123);
	// ft_printf("mine: |%20.*d|\n", 20, -123);
	// ft_printf("mine: |%*.20d|\n", 20, -123);
	// ft_putendl("");

	//    printf("real: |%20.25d|\n", -123);
	//    printf("real: |%*.*d|\n", 20, 25, -123);
	//    printf("real: |%20.*d|\n", 25, -123);
	//    printf("real: |%*.25d|\n", 20, -123);
	// ft_putendl("");
	// ft_printf("mine: |%20.25d|\n", -123);
	// ft_printf("mine: |%*.*d|\n", 20, 25, -123);
	// ft_printf("mine: |%20.*d|\n", 25, -123);
	// ft_printf("mine: |%*.25d|\n", 20, -123);
	// ft_putendl("");

	// ft_putendl("all decimal types");
	//    printf("real d: |%.13d|\n", -123);
	// ft_printf("mine d: |%.13d|\n", -123);
	// ft_putendl("");
	//    printf("real i: |%.13i|\n", -123);
	// ft_printf("mine i: |%.13i|\n", -123);
	// ft_putendl("");
	//    printf("real u: |%.13u|\n", -123);
	// ft_printf("mine u: |%.13u|\n", -123);
	// ft_putendl("");
	//    printf("real o: |%.13o|\n", -123);
	// ft_printf("mine o: |%.13o|\n", -123);
	// ft_putendl("");
	//    printf("real x: |%.13x|\n", -123);
	// ft_printf("mine x: |%.13x|\n", -123);
	// ft_putendl("");
	//    printf("real X: |%.13X|\n", -123);
	// ft_printf("mine X: |%.13X|\n", -123);
	// ft_putendl("");

	//    printf("real: |%d|\n", -123);
	// ft_printf("mine: |%d|\n", -123);
	// ft_putendl("");

	// ft_putendl("variables");
	//    printf("real: |%0.5d|\n", 123);
	//    printf("real: |%*.*d|\n", 0, 5, 123);
	//    printf("real: |%0.*d|\n", 5, 123);
	//    printf("real: |%*.5d|\n", 0, 123);
	// ft_printf("mine: |%0.5d|\n", 123);
	// ft_printf("mine: |%*.*d|\n", 0, 5, 123);
	// ft_printf("mine: |%0.*d|\n", 5, 123);
	// ft_printf("mine: |%*.5d|\n", 0, 123);
	// ft_putendl("");

	// ft_putendl("width & precision, negative numbers");
	//    printf("real: |%10.5d|\n", -123);
	//    printf("real: |%*.*d|\n", 10, 5, -123);
	//    printf("real: |%10.*d|\n", 5, -123);
	//    printf("real: |%*.5d|\n", 10, -123);
	// ft_printf("mine: |%10.5d|\n", -123);
	// ft_printf("mine: |%*.*d|\n", 10, 5, -123);
	// ft_printf("mine: |%10.*d|\n", 5, -123);
	// ft_printf("mine: |%*.5d|\n", 10, -123);
	// ft_putendl("");

	//    printf("real: |%10.0d|\n", -123);
	//    printf("real: |%*.*d|\n", 10, 0, -123);
	//    printf("real: |%10.*d|\n", 0, -123);
	//    printf("real: |%*.0d|\n", 10, -123);
	// ft_printf("mine: |%10.0d|\n", -123);
	// ft_printf("mine: |%*.*d|\n", 10, 0, -123);
	// ft_printf("mine: |%10.*d|\n", 0, -123);
	// ft_printf("mine: |%*.0d|\n", 10, -123);
	// ft_putendl("");

	// ft_putendl("width & precision, char");
	// ft_putendl("width > precision");
	//    printf("real: |%10.5c|\n", '?');
	//    printf("real: |%*.*c|\n", 10, 5, '?');
	//    printf("real: |%10.*c|\n", 5, '?');
	//    printf("real: |%*.5c|\n", 10, '?');
	// ft_printf("mine: |%10.5c|\n", '?');
	// ft_printf("mine: |%*.*c|\n", 10, 5, '?');
	// ft_printf("mine: |%10.*c|\n", 5, '?');
	// ft_printf("mine: |%*.5c|\n", 10, '?');
	// ft_putendl("");
	//    printf("real: |%010.5c|\n", '?');
	// ft_printf("mine: |%010.5c|\n", '?');
	// ft_putendl("");
	// ft_putendl("precision > width");
	//    printf("real: |%5.10c|\n", '?');
	//    printf("real: |%*.*c|\n", 5, 10, '?');
	//    printf("real: |%5.*c|\n", 10, '?');
	//    printf("real: |%*.10c|\n", 5, '?');
	// ft_printf("mine: |%5.10c|\n", '?');
	// ft_printf("mine: |%*.*c|\n", 5, 10, '?');
	// ft_printf("mine: |%5.*c|\n", 10, '?');
	// ft_printf("mine: |%*.10c|\n", 5, '?');
	// ft_putendl("");
	//    printf("real: |%05.10c|\n", '?');
	// ft_printf("mine: |%05.10c|\n", '?');
	// ft_putendl("");
	//    printf("real: |%0.0c|\n", '?');
	// ft_printf("mine: |%0.0c|\n", '?');
	//    printf("real: |%.0c|\n", '?');
	// ft_printf("mine: |%.0c|\n", '?');
	//    printf("real: |%0c|\n", '?');
	// ft_printf("mine: |%0c|\n", '?');
	//    printf("real: |%0.0c|\n", '?');
	// ft_printf("mine: |%0.0c|\n", '?');
	// ft_putendl("");


	// ft_putendl("asterisk");
	// printf("real> %%*s 15 	|%*s|\n", 15, "hello world");
	// ft_printf("mine> %%*s 15 	|%*s|\n", 15, "hello world");
	// ft_putendl("");

	// printf("real> %%-*s 15 	|%-*s|\n", 15, "hello world");
	// ft_printf("mine> %%-*s 15 	|%-*s|\n", 15, "hello world");
	// ft_putendl("");

	// printf("real> %%*s -15 	|%*s|\n", -15, "hello world");
	// ft_printf("mine> %%*s -15 	|%*s|\n", -15, "hello world");
	// ft_putendl("");

	// printf("real> %%-*s -15 	|%-*s|\n", -15, "hello world");
	// ft_printf("mine> %%-*s -15 	|%-*s|\n", -15, "hello world");
	// ft_putendl("");

	// printf("real> |%s %% %s|\n", "hello", "world");
	// ft_printf("mine> |%s %% %s|\n", "hello", "world");
	// ft_putendl("");


	// ft_putendl("percentage");
	// printf("real> |%%|\n");
	// ft_printf("mine> |%%|\n");
	// ft_putendl("");
	// printf("real> |%10.5%|\n");
	// ft_printf("mine> |%10.5%|\n");


	// ft_putendl("regular string");
	// printf("real> |%s, and good night|\n", "hello world");
	// ft_printf("mine> |%s, and good night|\n", "hello world");
	// ft_putendl("");


	// ft_putendl("null string");
	// printf("real> |%s, and good night|\n", NULL);
	// ft_printf("mine> |%s, and good night|\n", NULL);
	// ft_putendl("");


	// ft_putendl("width positive");
	// printf("real> |%15s, and good night|\n", "hello world");
	// ft_printf("mine> |%15s, and good night|\n", "hello world");
	// ft_putendl("");

	// printf("real> |%15s, and good night|\n", NULL);
	// ft_printf("mine> |%15s, and good night|\n", NULL);
	// ft_putendl("");

	// printf("real> |%1s, and good night|\n", "hello world");
	// ft_printf("mine> |%1s, and good night|\n", "hello world");
	// ft_putendl("");

	// printf("real> |%1s, and good night|\n", NULL);
	// ft_printf("mine> |%1s, and good night|\n", NULL);
	// ft_putendl("");


	// ft_putendl("width negative");
	// printf("real> |%-15s, and good night|\n", "hello world");
	// ft_printf("mine> |%-15s, and good night|\n", "hello world");
	// ft_putendl("");

	// printf("real> |%-15s, and good night|\n", NULL);
	// ft_printf("mine> |%-15s, and good night|\n", NULL);
	// ft_putendl("");

	// printf("real> |%-1s, and good night|\n", "hello world");
	// ft_printf("mine> |%-1s, and good night|\n", "hello world");
	// ft_putendl("");

	// printf("real> |%-1s, and good night|\n", NULL);
	// ft_printf("mine> |%-1s, and good night|\n", NULL);
	// ft_putendl("");

	// printf("precision tests\n");
	// printf("real> |%-.4s, and good night|\n", "hello world");
	// ft_printf("mine> |%-.4s, and good night|\n", "hello world");
	// ft_putendl("");
	// printf("real> |%.4s, and good night|\n", "hello world");
	// ft_printf("mine> |%.4s, and good night|\n", "hello world");
	// ft_putendl("");
	// printf("real> |%-10.4s, and good night|\n", "hello world");
	// ft_printf("mine> |%-10.4s, and good night|\n", "hello world");
	// ft_putendl("");
	// printf("real> |%10.4s, and good night|\n", "hello world");
	// ft_printf("mine> |%10.4s, and good night|\n", "hello world");
	// ft_putendl("");
	// printf("real> |%10.s, and good night|\n", "hello world");
	// ft_printf("mine> |%10.s, and good night|\n", "hello world");
	// ft_putendl("");
}

// #include <limits.h>
// #include <float.h>
// int		main(void)
// {
// 	int myreturn = 0; int rlreturn = 0;

// 	// char			char1;
// 	// char			*string1;
// 	// char			*string2;
// 	// int				int1;
// 	// double			double1;

// 	// // // string1 = (char *)malloc(sizeof(*string1) * 6000);
// 	// char			*format;
// 	// char			*pointer1;

// 	// myreturn += ft_printf("\nMINE: D:%10.0d.", 0);
// 	// rlreturn += printf("\nREAL: D:%10.0d.", 0);
// 	// printf("\n");
// 	// double1 = 56;
// 	// myreturn += printf("REAL:%0 15f.\n", double1);
// 	// rlreturn += ft_printf("MINE:%0 15f.\n", double1);
// 	// double1 = 5656;
// 	// myreturn += printf("REAL:%015hhf.\n", double1);
// 	// rlreturn += ft_printf("MINE:%015hhf.\n", double1);
// 	// double1 = 56;
// 	// myreturn += printf("REAL:% 15f.\n", double1);
// 	// rlreturn += ft_printf("MINE:% 15f.\n", double1);
// 	// double1 = -56;
// 	// myreturn += printf("REAL:%0 15f.\n", double1);
// 	// rlreturn += ft_printf("MINE:%0 15f.\n", double1);
// 	// double1 = -5656;
// 	// myreturn += printf("REAL:%015hhf.\n", double1);
// 	// rlreturn += ft_printf("MINE:%015hhf.\n", double1);
// 	// double1 = -56;
// 	// myreturn += printf("REAL:% 15f.\n", double1);
// 	// rlreturn += ft_printf("MINE:% 15f.\n", double1);
// 	// myreturn += ft_printf("\nMINE: +f:% .d +fN:% f.", 0, (double)-1);
// 	// rlreturn += printf("\nREAL: +f:% .d +fN:% f.", 0, (double)-1);
// 	// printf("\n");
// 	// myreturn += ft_printf("\nMINE: +f:% d +fN:% .f.", 0, (double)10);
// 	// rlreturn += printf("\nREAL: +f:% d +fN:% .f.", 0, (double)10);
// 	// printf("\n");
// 	// myreturn += ft_printf("\nMINE: +f:% .1d +fN:% .3f.", 0, (double)0);
// 	// rlreturn += printf("\nREAL: +f:% .1d +fN:% .3f.", 0, (double)0);
// 	// printf("\n");
// 	// myreturn += ft_printf("\nMINE: +f:% .2d +fN:% .f.", 0, (double)0);
// 	// rlreturn += printf("\nREAL: +f:% .2d +fN:% .f.", 0, (double)0);
// 	// printf("\n");
// 	// rlreturn += printf("REAL:%s\n", (char *)NULL);
// 	// myreturn += ft_printf("MINE:%s\n", (char *)NULL);

// 	myreturn += ft_printf("\nMINE: D:%%, D:%3.3%, D:%- 10%, D:%#0.0%, D:%10.5%, D:%2.1%, D:%3.1%, D:%1.3%, D:%1.2%, D:%1.1%, D:% %, D:%10%, D:%.10%, D:%.%.");
// 	rlreturn += printf("\nREAL: D:%%, D:%3.3%, D:%- 10%, D:%#0.0%, D:%10.5%, D:%2.1%, D:%3.1%, D:%1.3%, D:%1.2%, D:%1.1%, D:% %, D:%10%, D:%.10%, D:%.%.");
// 	printf("\n");
// 	// myreturn += ft_printf("\nMINE: D:%2.0%.");
// 	// rlreturn += printf("\nREAL: D:%2.0%."); TESTAA KOULULLA!


// 	printf("\n");
// 	myreturn += ft_printf("\nMINE: +f:% .d +fN:% f.", 0, (double)10);
// 	rlreturn += printf("\nREAL: +f:% .d +fN:% f.", 0, (double)10);
// 	printf("\n");
// 	myreturn += ft_printf("\nMINE: +f:% d +fN:% .f.", 0, (double)0);
// 	rlreturn += printf("\nREAL: +f:% d +fN:% .f.", 0, (double)0);
// 	printf("\n");
// 	myreturn += ft_printf("\nMINE: +f:% .1d +fN:% .f.", 0, (double)0);
// 	rlreturn += printf("\nREAL: +f:% .1d +fN:% .f.", 0, (double)0);
// 	printf("\n");
// 	myreturn += ft_printf("\nMINE: +f:% .2d +fN:% .f.", 0, (double)0);
// 	rlreturn += printf("\nREAL: +f:% .2d +fN:% .f.", 0, (double)0);
// 	printf("\n");
// 	myreturn += ft_printf("\nMINE: +f:%+.10f +fN:%+f, +D:%+d, +DN%+d, +.5->Dpres:%+.5d.", (double)10, (double)-10, 10, -10, -10);
// 	rlreturn += printf("\nREAL: +f:%+.10f +fN:%+f, +D:%+d, +DN%+d, +.5->Dpres:%+.5d.", (double)10, (double)-10, 10, -10, -10);
// 	printf("\n");
// 	myreturn += ft_printf("\nMINE: +f:%+.10f +fN:%+f.", (double)10, (double)0);
// 	rlreturn += printf("\nREAL: +f:%+.10f +fN:%+f.", (double)10, (double)0);
// 	printf("\n");
// 	myreturn += ft_printf("\nMINE: D:%-1.0d, DN:%.0d, O:%.0o, NO:%.o, U:%u, UN:%.0u, x:%.x, X:%.X.", 0, -1, 10, 1, 9, -100, 9999, -999);
// 	rlreturn += printf("\nREAL: D:%-1.0d, DN:%.0d, O:%.0o, NO:%.o, U:%u, UN:%.0u, x:%.x, X:%.X.", 0, -1, 10, 1, 9, -100, 9999, -999);
// 	printf("\n");
// 	myreturn += ft_printf("\nMINE: D:%-10.0d, D:%.0d, D:%-1.1d,", 0, 0, 0);
// 	rlreturn += printf("\nREAL: D:%-10.0d, D:%.0d, D:%-1.1d,", 0, 0, 0);
// 	printf("\n");
// 	myreturn += ft_printf("\nMINE: S:%s, S:%10s, S:%.s, S:%10.10s, S:%14.10s, S:%6.7s, S:%10.s, S:%6.6s, S:%7.7s, S:%7.6s.", "Hello!", "Hello!", "Hello!", "Hello!", "Hello!", "Hello!", "Hello!", "Hello!", "Hello!", "Hello!");
// 	rlreturn += printf("\nREAL: S:%s, S:%10s, S:%.s, S:%10.10s, S:%14.10s, S:%6.7s, S:%10.s, S:%6.6s, S:%7.7s, S:%7.6s.", "Hello!", "Hello!", "Hello!", "Hello!", "Hello!", "Hello!", "Hello!", "Hello!", "Hello!", "Hello!");
// 	printf("\n(dot)\n");
// 	myreturn += ft_printf("\nMINE: S:%.s, S:%6.6s.","Hello!", "Hello!");
// 	rlreturn += printf("\nREAL: S:%.s, S:%6.6s.","Hello!", "Hello!");
// 	printf("\n(dot)\n");
// 	myreturn += ft_printf("\nMINE: S:%10s, S:%.s.","Hello!", "Hello!");
// 	rlreturn += printf("\nREAL: S:%10s, S:%.s.","Hello!", "Hello!");
// 	printf("\n(dot)\n");
// 	myreturn += ft_printf("\nMINE: S:%11s, S:%.s.","Hello!", "Hello!");
// 	rlreturn += printf("\nREAL: S:%11s, S:%.s.","Hello!", "Hello!");
// 	printf("\n(dot)\n");
// 	myreturn += ft_printf("\nMINE: D:%-++-d, D:%+0.0d, D:%+.0d, D:%-+.1d, D:%-+.2d, D:%-+.3d, D:%+-.4d, D:%+-1.1d, D:%+2.4d, D:%+3.3d, D:%3.3d, D:%2.3d.", 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10);
// 	rlreturn += printf("\nREAL: D:%-++-d, D:%+0.0d, D:%+.0d, D:%-+.1d, D:%-+.2d, D:%-+.3d, D:%+-.4d, D:%+-1.1d, D:%+2.4d, D:%+3.3d, D:%3.3d, D:%2.3d.", 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10);
// 	printf("\n(dot)\n");
// 	myreturn += ft_printf("\nMINE: D:%-+4.3d, D:%+-7.6d, D:%2d, D:%2.2d, D:%-1.1d, D:%-+7.6d, D:%+8.8d, D:%+16.d, D:%--++10.10d, D:%0002d, D:%++10d, D:%--10d.", 0, 0, 0, 0, 10, 10, 10, 10, 10, 10, 10, 10);
// 	rlreturn += printf("\nREAL: D:%-+4.3d, D:%+-7.6d, D:%2d, D:%2.2d, D:%-1.1d, D:%-+7.6d, D:%+8.8d, D:%+16.d, D:%--++10.10d, D:%0002d, D:%++10d, D:%--10d.", 0, 0, 0, 0, 10, 10, 10, 10, 10, 10, 10, 10);
// 	printf("\n(dot)\n");
// 	myreturn += ft_printf("\nMINE: D:%-++-d, D:%+0.0d, D:%+.0d, D:%-+.1d, D:%-+.2d, D:%-+.3d, D:%+-.4d, D:%+-1.1d, D:%+2.4d, D:%+3.3d, D:%3.3d, D:%2.3d.", -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10);
// 	rlreturn += printf("\nREAL: D:%-++-d, D:%+0.0d, D:%+.0d, D:%-+.1d, D:%-+.2d, D:%-+.3d, D:%+-.4d, D:%+-1.1d, D:%+2.4d, D:%+3.3d, D:%3.3d, D:%2.3d.", -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10);
// 	printf("\n(dot)\n");
// 	myreturn += ft_printf("\nMINE: D:%-+4.3d, D:%+-7.6d, D:%2d, D:%2.2d, D:%-1.1d, D:%-+7.6d, D:%+8.8d, D:%+16.d, D:%--++10.10d, D:%0002d, D:%++10d, D:%--10d.", -0, -0, -0, -0, -10, -10, -10, -10, -10, -10, -10, -10);
// 	rlreturn += printf("\nREAL: D:%-+4.3d, D:%+-7.6d, D:%2d, D:%2.2d, D:%-1.1d, D:%-+7.6d, D:%+8.8d, D:%+16.d, D:%--++10.10d, D:%0002d, D:%++10d, D:%--10d.", -0, -0, -0, -0, -10, -10, -10, -10, -10, -10, -10, -10);
// 	printf("\n(dot)\n");
// 	myreturn += ft_printf("\nMINE: D:%-+1.1d, D:%+-2.2d, D:%2d, D:%2.2d, D:%-1.0d, D:%-+7.10d, D:%+15.0d, D:%+16.d, D:%--++10.10d, D:%0002d, D:%++10d, D:%--10d.", -0, -100, -0, -999, -10, -10, -10, -10, -10, -10, -10, -10);
// 	rlreturn += printf("\nREAL: D:%-+1.1d, D:%+-2.2d, D:%2d, D:%2.2d, D:%-1.0d, D:%-+7.10d, D:%+15.0d, D:%+16.d, D:%--++10.10d, D:%0002d, D:%++10d, D:%--10d.", -0, -100, -0, -999, -10, -10, -10, -10, -10, -10, -10, -10);
// 	printf("\n(dot)\n");
// 	myreturn += ft_printf("\nMINE: %.x, %.10x, %.15x, %15.15x, %0100x, %-15x.", 100, 10, 1, 0, 999, -999);
// 	rlreturn += printf("\nREAL: %.x, %.10x, %.15x, %15.15x, %0100x, %-15x.", 100, 10, 1, 0, 999, -999);
// 	printf("\n(dot)\n");
// 	myreturn += ft_printf("\nMINE: %.X, %.10X, %.15X, %15.15X, %0100X, %-15X.", 100, 10, 1, 0, 999, -999);
// 	rlreturn += printf("\nREAL: %.X, %.10X, %.15X, %15.15X, %0100X, %-15X.", 100, 10, 1, 0, 999, -999);
// 	printf("\n(dot)\n");
// 	myreturn += ft_printf("\nMINE: %.o, %.10o, %.15o, %15.15o, %0100o, %-15o.", 100, 10, 1, 0, 999, -999);
// 	rlreturn += printf("\nREAL: %.o, %.10o, %.15o, %15.15o, %0100o, %-15o.", 100, 10, 1, 0, 999, -999);
// 	printf("\n(dot)\n");
// 	myreturn += ft_printf("\nMINE: %.u, %.10u, %.15u, %15.15u, %0100u, %-15u.", 100, 10, 1, 0, 999, -999);
// 	rlreturn += printf("\nREAL: %.u, %.10u, %.15u, %15.15u, %0100u, %-15u.", 100, 10, 1, 0, 999, -999);
// 	int *i = 0;
// 	printf("\n(dot)\n");
// 	myreturn += ft_printf("\nMINE: %10p, %12p, %13p, %15p, %100p, %-15p.", i, i, i, i, i, i);
// 	rlreturn += printf("\nREAL: %10p, %12p, %13p, %15p, %100p, %-15p.", i, i, i, i, i, i);
// 	printf("\n(dot)\n");
// 	myreturn += ft_printf("\nMINE: C:%c, C:%10c, C:%15c, C:%15c, C:%100c, C:%-15c.", 43, 'A', '\200', '\0', 'b', 'a'); // testaa koululla mitä vittua
// 	rlreturn += printf("\nREAL: C:%c, C:%10c, C:%15c, C:%15c, C:%100c, C:%-15c.", 43, 'A', '\200', '\0', 'b', 'a');
// 	printf("\n(dot)\n");
// 	myreturn += ft_printf("\nMINE: %c, %10c, %15c, %15c, %100c, %-15c.", '\0', '\0', '\0', '\0', '\0', '\0');
// 	rlreturn += printf("\nREAL: %c, %10c, %15c, %15c, %100c, %-15c.", '\0', '\0', '\0', '\0', '\0', '\0');
// 	printf("\n(dot)\n");
// 	myreturn += ft_printf("\nC:%2c.", '\0');
// 	rlreturn += printf("\nC:%2c.", '\0');
// 	printf("\n(dot)\n");
// 	myreturn += ft_printf("\nf:%.10f, f:%+020.f, f:%9.11f, f:%+-15.10f, f:%015.f, f:%015f, f:%3.3f, f:%2.2f.", (double)10, (double)10, (double)10, (double)10, (double)-10, (double)-10, (double)-10, (double)-10);
// 	rlreturn += printf("\nf:%.10f, f:%+020.f, f:%9.11f, f:%+-15.10f, f:%015.f, f:%015f, f:%3.3f, f:%2.2f.", (double)10, (double)10, (double)10, (double)10, (double)-10, (double)-10, (double)-10, (double)-10);
// 	printf("\n(dot)\n");
// 	myreturn += ft_printf("\nf:%#0.f, f:%#+020.f, f:%#++20.f, f:%#+-20.f, f:%#015.f, f:%#015.f, f:%#5.f, f:%#2.f.", (double)10, (double)10, (double)10, (double)10, (double)-10, (double)-10, (double)-10, (double)-10);
// 	rlreturn += printf("\nf:%#0.f, f:%#+020.f, f:%#++20.f, f:%#+-20.f, f:%#015.f, f:%#015.f, f:%#5.f, f:%#2.f.", (double)10, (double)10, (double)10, (double)10, (double)-10, (double)-10, (double)-10, (double)-10);
// 	printf("\n(dot)\n");
// 	myreturn += ft_printf("\nREAL: f:%#+-20.10f, f:%#+-20.10f.", (double)10, (double)-10);
// 	rlreturn += printf("\nMINE: f:%#+-20.10f, f:%#+-20.10f.", (double)10, (double)-10);
// 	printf("\n(dot)\n");
// 	myreturn += ft_printf("\nMINE: f:%#++20.11f, f:%#++20.10f.", (double)10, (double)-10);
// 	rlreturn += printf("\nREAL: f:%#++20.11f, f:%#++20.10f.", (double)10, (double)-10);
// 	printf("\n(dot)\n");
// 	myreturn += ft_printf("\nMINE: f:%#+020.15f, f:%#+020.15f.", (double)10, (double)-10);
// 	rlreturn += printf("\nREAL: f:%#+020.15f, f:%#+020.15f.", (double)10, (double)-10);
// 	printf("\n(dot)\n");
// 	myreturn += ft_printf("\nMINE: f:%#0.10f, f:%#0.10f.", (double)10, (double)-10);
// 	rlreturn += printf("\nREAL: f:%#0.10f, f:%#0.10f.", (double)10, (double)-10);
// 	printf("\n(dot)\n");
// 	myreturn += ft_printf("\nMINE: f:%#+-20.f, f:%#+-20.f.", (double)10, (double)-10);
// 	rlreturn += printf("\nREAL: f:%#+-20.f, f:%#+-20.f.", (double)10, (double)-10);
// 	printf("\n");
// 	myreturn += ft_printf("\nMINE: +f:%+.10f +fN:%+f, +D:%+d, +DN%+d, +.5->Dpres:%+.5d.", (double)10, (double)-10, 10, -10, -10);
// 	rlreturn += printf("\nREAL: +f:%+.10f +fN:%+f, +D:%+d, +DN%+d, +.5->Dpres:%+.5d.", (double)10, (double)-10, 10, -10, -10);
// 	printf("\n");
// 	myreturn += ft_printf("\nMINE: #o:%#o, #x:%#x, #X:%#X, N#o:%#o, N#x:%#x, N#X:%#X", 0, 10, 99, -1, -10, -99);
// 	rlreturn += printf("\nREAL: #o:%#o, #x:%#x, #X:%#X, N#o:%#o, N#x:%#x, N#X:%#X", 0, 10, 99, -1, -10, -99);
// 	printf("\n");
// 	myreturn += ft_printf("\nMINE: D:%.0d, DN:%.0d, O:%.0o, NO:%.o, U:%u, UN:%.0u, x:%.x, X:%.X.", 0, -1, 10, 1, 9, -100, 9999, -999);
// 	rlreturn += printf("\nREAL: D:%.0d, DN:%.0d, O:%.0o, NO:%.o, U:%u, UN:%.0u, x:%.x, X:%.X.", 0, -1, 10, 1, 9, -100, 9999, -999);
// 	printf("\n");
// 	long ni = 99999999999998; long long j = 99999999999999998; short k = 10; char l = 'A';
// 	long double aa = 0; long double aaa = 1.9999995;long double aaaa = -0.9999995; long double aaaaa = -1.9999994;
// 	myreturn += ft_printf("\nMINE: LLD:%lld, LD:%ld, HU:%hu, HHN:%hhu, xl:%lx, LLX:%llX, HHO:%hho HO:%ho", j, ni, k, l, ni, j, l, k);
// 	rlreturn += printf("\nREAL: LLD:%lld, LD:%ld, HU:%hu, HHN:%hhu, xl:%lx, LLX:%llX, HHO:%hho HO:%ho", j, ni, k, l, ni, j, l, k);
// 	printf("\n");
// 	myreturn += ft_printf("\nMINE:f:%.16Lf, f:%.16Lf, f:%.16Lf, f:%.16Lf.", aa, aaa, aaaa, aaaaa);
// 	rlreturn += printf("\nREAL:f:%.16Lf, f:%.16Lf, f:%.16Lf, f:%.16Lf.", aa, aaa, aaaa, aaaaa);
// 	printf("\n");
// 	myreturn += ft_printf("\nMINE: str:%s 0:%1.0s, 1:%2.1s, 2:%3.2s, 3:%4.3s, 4:%5.4s, 5:%6.5s, 6:%7.6s, 7:%8.7s, 8:%9.8s, 9:%10.9s.", "NUMS:", "000", "11111", "2222222", "33333333", "4444444444", "555555555", "66666666666", "77777777777", "88888888888", "9999999999");
// 	rlreturn += printf("\nREAL: str:%s 0:%1.0s, 1:%2.1s, 2:%3.2s, 3:%4.3s, 4:%5.4s, 5:%6.5s, 6:%7.6s, 7:%8.7s, 8:%9.8s, 9:%10.9s.", "NUMS:", "000", "11111", "2222222", "33333333", "4444444444", "555555555", "66666666666", "77777777777", "88888888888", "9999999999");

// 	long double x = 0;
// 	long double xx = -0;
// 	long double xxx = -0.1;
// 	long double xxxx = 0.1;
// 	long double xxxxx = -0.00005;
// 	long double xxxxxx = 0.00005;
// 	long double xxxxxxx = -0.999;
// 	long double xxxxxxxx = 0.999;
// 	long double xxxxxxxxx = -0.99999999;
// 	long double xxxxxxxxxx = 0.99999999;
// 	long double xxxxxxxxxxx = -9.999999;
// 	long double xxxxxxxxxxxx = 9.999999;
// 	long double xxxxxxxxxxxxx = -99.9999995;
// 	long double xxxxxxxxxxxxxx = 99.9999995;
// 	long double xxxxxxxxxxxxxxx = -999.9999995;
// 	long double xxxxxxxxxxxxxxxx = 999.9999995;
// 	long double xxxxxxxxxxxxxxxxx = -10.10101010;
// 	long double xxxxxxxxxxxxxxxxxx = 10.10101010;
// 	long double xxxxxxxxxxxxxxxxxxx = 5.3949956029740937512097409217509788210442804;
// 	printf("\n(dot)\n");
// 	myreturn += ft_printf("\nMINE: f:%.Lf, f:%.Lf, f:%.Lf, f:%.Lf, f:%.Lf, f:%.Lf, f:%.Lf, f:%.100Lf, f:%.Lf, f:%.Lf, f:%.Lf, f:%.Lf, f:%.Lf, f:%.Lf, f:%.Lf, f:%.Lf, f:%.Lf, f:%.Lf, f:%.Lf.", x, xx, xxx, xxxx, xxxxx, xxxxxx, xxxxxxx, xxxxxxxx, xxxxxxxxx, xxxxxxxxxx, xxxxxxxxxxx, xxxxxxxxxxxx, xxxxxxxxxxxxx, xxxxxxxxxxxxxx, xxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxxx);
// 	rlreturn += printf("\nREAL: f:%.Lf, f:%.Lf, f:%.Lf, f:%.Lf, f:%.Lf, f:%.Lf, f:%.Lf, f:%.100Lf, f:%.Lf, f:%.Lf, f:%.Lf, f:%.Lf, f:%.Lf, f:%.Lf, f:%.Lf, f:%.Lf, f:%.Lf, f:%.Lf, f:%.Lf.", x, xx, xxx, xxxx, xxxxx, xxxxxx, xxxxxxx, xxxxxxxx, xxxxxxxxx, xxxxxxxxxx, xxxxxxxxxxx, xxxxxxxxxxxx, xxxxxxxxxxxxx, xxxxxxxxxxxxxx, xxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxxx);
// 	printf("\n0\n");
// 	myreturn += ft_printf("\nMINE: f:%.0Lf, f:%.0Lf, f:%.0Lf, f:%.0Lf, f:%.0Lf, f:%.0Lf, f:%.0Lf, f:%.0Lf, f:%.0Lf, f:%.0Lf, f:%.0Lf, f:%.0Lf, f:%.0Lf, f:%.0Lf, f:%.0Lf, f:%.0Lf, f:%.0Lf, f:%.0Lf, f:%.0Lf.", x, xx, xxx, xxxx, xxxxx, xxxxxx, xxxxxxx, xxxxxxxx, xxxxxxxxx, xxxxxxxxxx, xxxxxxxxxxx, xxxxxxxxxxxx, xxxxxxxxxxxxx, xxxxxxxxxxxxxx, xxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxxx);
// 	rlreturn += printf("\nREAL: f:%.0Lf, f:%.0Lf, f:%.0Lf, f:%.0Lf, f:%.0Lf, f:%.0Lf, f:%.0Lf, f:%.0Lf, f:%.0Lf, f:%.0Lf, f:%.0Lf, f:%.0Lf, f:%.0Lf, f:%.0Lf, f:%.0Lf, f:%.0Lf, f:%.0Lf, f:%.0Lf, f:%.0Lf.", x, xx, xxx, xxxx, xxxxx, xxxxxx, xxxxxxx, xxxxxxxx, xxxxxxxxx, xxxxxxxxxx, xxxxxxxxxxx, xxxxxxxxxxxx, xxxxxxxxxxxxx, xxxxxxxxxxxxxx, xxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxxx);
// 	printf("\n#(dot)\n");
// 	myreturn += ft_printf("\nMINE: f:%#.Lf, f:%#.Lf, f:%#.Lf, f:%#.Lf, f:%#.Lf, f:%#.Lf, f:%#.Lf, f:%#.Lf, f:%#.Lf, f:%#.Lf, f:%#.Lf, f:%#.Lf, f:%#.Lf, f:%#.Lf, f:%#.Lf, f:%#.Lf, f:%#.Lf, f:%#.Lf, f:%#.Lf.", x, xx, xxx, xxxx, xxxxx, xxxxxx, xxxxxxx, xxxxxxxx, xxxxxxxxx, xxxxxxxxxx, xxxxxxxxxxx, xxxxxxxxxxxx, xxxxxxxxxxxxx, xxxxxxxxxxxxxx, xxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxxx);
// 	rlreturn += printf("\nREAL: f:%#.Lf, f:%#.Lf, f:%#.Lf, f:%#.Lf, f:%#.Lf, f:%#.Lf, f:%#.Lf, f:%#.Lf, f:%#.Lf, f:%#.Lf, f:%#.Lf, f:%#.Lf, f:%#.Lf, f:%#.Lf, f:%#.Lf, f:%#.Lf, f:%#.Lf, f:%#.Lf, f:%#.Lf.", x, xx, xxx, xxxx, xxxxx, xxxxxx, xxxxxxx, xxxxxxxx, xxxxxxxxx, xxxxxxxxxx, xxxxxxxxxxx, xxxxxxxxxxxx, xxxxxxxxxxxxx, xxxxxxxxxxxxxx, xxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxxx);
// 	printf("\n#0\n");
// 	myreturn += ft_printf("\nMINE: f:%#.0Lf, f:%#.0Lf, f:%#.0Lf, f:%#.0Lf, f:%#.0Lf, f:%#.0Lf, f:%#.0Lf, f:%#.0Lf, f:%#.0Lf, f:%#.0Lf, f:%#.0Lf, f:%#.0Lf, f:%#.0Lf, f:%#.0Lf, f:%#.0Lf, f:%#.0Lf, f:%#.0Lf, f:%#.0Lf, f:%#.0Lf.", x, xx, xxx, xxxx, xxxxx, xxxxxx, xxxxxxx, xxxxxxxx, xxxxxxxxx, xxxxxxxxxx, xxxxxxxxxxx, xxxxxxxxxxxx, xxxxxxxxxxxxx, xxxxxxxxxxxxxx, xxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxxx);
// 	rlreturn += printf("\nREAL: f:%#.0Lf, f:%#.0Lf, f:%#.0Lf, f:%#.0Lf, f:%#.0Lf, f:%#.0Lf, f:%#.0Lf, f:%#.0Lf, f:%#.0Lf, f:%#.0Lf, f:%#.0Lf, f:%#.0Lf, f:%#.0Lf, f:%#.0Lf, f:%#.0Lf, f:%#.0Lf, f:%#.0Lf, f:%#.0Lf, f:%#.0Lf.", x, xx, xxx, xxxx, xxxxx, xxxxxx, xxxxxxx, xxxxxxxx, xxxxxxxxx, xxxxxxxxxx, xxxxxxxxxxx, xxxxxxxxxxxx, xxxxxxxxxxxxx, xxxxxxxxxxxxxx, xxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxxx);
// 	printf("\n1\n");
// 	myreturn += ft_printf("\nMINE: f:%.1Lf, f:%.1Lf, f:%.1Lf, f:%.1Lf, f:%.1Lf, f:%.1Lf, f:%.1Lf, f:%.1Lf, f:%.1Lf, f:%.1Lf, f:%.1Lf, f:%.1Lf, f:%.1Lf, f:%.1Lf, f:%.1Lf, f:%.1Lf, f:%.1Lf, f:%.1Lf, f:%.1Lf.", x, xx, xxx, xxxx, xxxxx, xxxxxx, xxxxxxx, xxxxxxxx, xxxxxxxxx, xxxxxxxxxx, xxxxxxxxxxx, xxxxxxxxxxxx, xxxxxxxxxxxxx, xxxxxxxxxxxxxx, xxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxxx);
// 	rlreturn += printf("\nREAL: f:%.1Lf, f:%.1Lf, f:%.1Lf, f:%.1Lf, f:%.1Lf, f:%.1Lf, f:%.1Lf, f:%.1Lf, f:%.1Lf, f:%.1Lf, f:%.1Lf, f:%.1Lf, f:%.1Lf, f:%.1Lf, f:%.1Lf, f:%.1Lf, f:%.1Lf, f:%.1Lf, f:%.1Lf.", x, xx, xxx, xxxx, xxxxx, xxxxxx, xxxxxxx, xxxxxxxx, xxxxxxxxx, xxxxxxxxxx, xxxxxxxxxxx, xxxxxxxxxxxx, xxxxxxxxxxxxx, xxxxxxxxxxxxxx, xxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxxx);
// 	printf("\n#1\n");
// 	myreturn += ft_printf("\nMINE: f:%#.1Lf, f:%#.1Lf, f:%#.1Lf, f:%#.1Lf, f:%#.1Lf, f:%#.1Lf, f:%#.1Lf, f:%#.1Lf, f:%#.1Lf, f:%#.1Lf, f:%#.1Lf, f:%#.1Lf, f:%#.1Lf, f:%#.1Lf, f:%#.1Lf, f:%#.1Lf, f:%#.1Lf, f:%#.1Lf, f:%#.1Lf.", x, xx, xxx, xxxx, xxxxx, xxxxxx, xxxxxxx, xxxxxxxx, xxxxxxxxx, xxxxxxxxxx, xxxxxxxxxxx, xxxxxxxxxxxx, xxxxxxxxxxxxx, xxxxxxxxxxxxxx, xxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxxx);
// 	rlreturn += printf("\nREAL: f:%#.1Lf, f:%#.1Lf, f:%#.1Lf, f:%#.1Lf, f:%#.1Lf, f:%#.1Lf, f:%#.1Lf, f:%#.1Lf, f:%#.1Lf, f:%#.1Lf, f:%#.1Lf, f:%#.1Lf, f:%#.1Lf, f:%#.1Lf, f:%#.1Lf, f:%#.1Lf, f:%#.1Lf, f:%#.1Lf, f:%#.1Lf.", x, xx, xxx, xxxx, xxxxx, xxxxxx, xxxxxxx, xxxxxxxx, xxxxxxxxx, xxxxxxxxxx, xxxxxxxxxxx, xxxxxxxxxxxx, xxxxxxxxxxxxx, xxxxxxxxxxxxxx, xxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxxx);
// 	printf("\n2\n");
// 	myreturn += ft_printf("\nMINE: f:%.2Lf, f:%.2Lf, f:%.2Lf, f:%.2Lf, f:%.2Lf, f:%.2Lf, f:%.2Lf, f:%.2Lf, f:%.2Lf, f:%.2Lf, f:%.2Lf, f:%.2Lf, f:%.2Lf, f:%.2Lf, f:%.2Lf, f:%.2Lf, f:%.2Lf, f:%.2Lf, f:%.2Lf.", x, xx, xxx, xxxx, xxxxx, xxxxxx, xxxxxxx, xxxxxxxx, xxxxxxxxx, xxxxxxxxxx, xxxxxxxxxxx, xxxxxxxxxxxx, xxxxxxxxxxxxx, xxxxxxxxxxxxxx, xxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxxx);
// 	rlreturn += printf("\nREAL: f:%.2Lf, f:%.2Lf, f:%.2Lf, f:%.2Lf, f:%.2Lf, f:%.2Lf, f:%.2Lf, f:%.2Lf, f:%.2Lf, f:%.2Lf, f:%.2Lf, f:%.2Lf, f:%.2Lf, f:%.2Lf, f:%.2Lf, f:%.2Lf, f:%.2Lf, f:%.2Lf, f:%.2Lf.", x, xx, xxx, xxxx, xxxxx, xxxxxx, xxxxxxx, xxxxxxxx, xxxxxxxxx, xxxxxxxxxx, xxxxxxxxxxx, xxxxxxxxxxxx, xxxxxxxxxxxxx, xxxxxxxxxxxxxx, xxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxxx);
// 	printf("\n#2\n");
// 	myreturn += ft_printf("\nMINE: f:%#.2Lf, f:%#.2Lf, f:%#.2Lf, f:%#.2Lf, f:%#.2Lf, f:%#.2Lf, f:%#.2Lf, f:%#.2Lf, f:%#.2Lf, f:%#.2Lf, f:%#.2Lf, f:%#.2Lf, f:%#.2Lf, f:%#.2Lf, f:%#.2Lf, f:%#.2Lf, f:%#.2Lf, f:%#.2Lf, f:%#.2Lf.", x, xx, xxx, xxxx, xxxxx, xxxxxx, xxxxxxx, xxxxxxxx, xxxxxxxxx, xxxxxxxxxx, xxxxxxxxxxx, xxxxxxxxxxxx, xxxxxxxxxxxxx, xxxxxxxxxxxxxx, xxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxxx);
// 	rlreturn += printf("\nREAL: f:%#.2Lf, f:%#.2Lf, f:%#.2Lf, f:%#.2Lf, f:%#.2Lf, f:%#.2Lf, f:%#.2Lf, f:%#.2Lf, f:%#.2Lf, f:%#.2Lf, f:%#.2Lf, f:%#.2Lf, f:%#.2Lf, f:%#.2Lf, f:%#.2Lf, f:%#.2Lf, f:%#.2Lf, f:%#.2Lf, f:%#.2Lf.", x, xx, xxx, xxxx, xxxxx, xxxxxx, xxxxxxx, xxxxxxxx, xxxxxxxxx, xxxxxxxxxx, xxxxxxxxxxx, xxxxxxxxxxxx, xxxxxxxxxxxxx, xxxxxxxxxxxxxx, xxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxxx);
// 	printf("\n3\n");
// 	myreturn += ft_printf("\nMINE: f:%.3Lf, f:%.3Lf, f:%.3Lf, f:%.3Lf, f:%.3Lf, f:%.3Lf, f:%.3Lf, f:%.3Lf, f:%.3Lf, f:%.3Lf, f:%.3Lf, f:%.3Lf, f:%.3Lf, f:%.3Lf, f:%.3Lf, f:%.3Lf, f:%.3Lf, f:%.3Lf, f:%.3Lf.", x, xx, xxx, xxxx, xxxxx, xxxxxx, xxxxxxx, xxxxxxxx, xxxxxxxxx, xxxxxxxxxx, xxxxxxxxxxx, xxxxxxxxxxxx, xxxxxxxxxxxxx, xxxxxxxxxxxxxx, xxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxxx);
// 	rlreturn += printf("\nREAL: f:%.3Lf, f:%.3Lf, f:%.3Lf, f:%.3Lf, f:%.3Lf, f:%.3Lf, f:%.3Lf, f:%.3Lf, f:%.3Lf, f:%.3Lf, f:%.3Lf, f:%.3Lf, f:%.3Lf, f:%.3Lf, f:%.3Lf, f:%.3Lf, f:%.3Lf, f:%.3Lf, f:%.3Lf.", x, xx, xxx, xxxx, xxxxx, xxxxxx, xxxxxxx, xxxxxxxx, xxxxxxxxx, xxxxxxxxxx, xxxxxxxxxxx, xxxxxxxxxxxx, xxxxxxxxxxxxx, xxxxxxxxxxxxxx, xxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxxx);
// 	printf("\n#3\n");
// 	myreturn += ft_printf("\nMINE: f:%#.3Lf, f:%#.3Lf, f:%#.3Lf, f:%#.3Lf, f:%#.3Lf, f:%#.3Lf, f:%#.3Lf, f:%#.3Lf, f:%#.3Lf, f:%#.3Lf, f:%#.3Lf, f:%#.3Lf, f:%#.3Lf, f:%#.3Lf, f:%#.3Lf, f:%#.3Lf, f:%#.3Lf, f:%#.3Lf, f:%#.3Lf.", x, xx, xxx, xxxx, xxxxx, xxxxxx, xxxxxxx, xxxxxxxx, xxxxxxxxx, xxxxxxxxxx, xxxxxxxxxxx, xxxxxxxxxxxx, xxxxxxxxxxxxx, xxxxxxxxxxxxxx, xxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxxx);
// 	rlreturn += printf("\nREAL: f:%#.3Lf, f:%#.3Lf, f:%#.3Lf, f:%#.3Lf, f:%#.3Lf, f:%#.3Lf, f:%#.3Lf, f:%#.3Lf, f:%#.3Lf, f:%#.3Lf, f:%#.3Lf, f:%#.3Lf, f:%#.3Lf, f:%#.3Lf, f:%#.3Lf, f:%#.3Lf, f:%#.3Lf, f:%#.3Lf, f:%#.3Lf.", x, xx, xxx, xxxx, xxxxx, xxxxxx, xxxxxxx, xxxxxxxx, xxxxxxxxx, xxxxxxxxxx, xxxxxxxxxxx, xxxxxxxxxxxx, xxxxxxxxxxxxx, xxxxxxxxxxxxxx, xxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxxx);
// 	printf("\n4\n");
// 	myreturn += ft_printf("\nMINE: f:%.4Lf, f:%.4Lf, f:%.4Lf, f:%.4Lf, f:%.4Lf, f:%.4Lf, f:%.4Lf, f:%.4Lf, f:%.4Lf, f:%.4Lf, f:%.4Lf, f:%.4Lf, f:%.4Lf, f:%.4Lf, f:%.4Lf, f:%.4Lf, f:%.4Lf, f:%.4Lf, f:%.4Lf.", x, xx, xxx, xxxx, xxxxx, xxxxxx, xxxxxxx, xxxxxxxx, xxxxxxxxx, xxxxxxxxxx, xxxxxxxxxxx, xxxxxxxxxxxx, xxxxxxxxxxxxx, xxxxxxxxxxxxxx, xxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxxx);
// 	rlreturn += printf("\nREAL: f:%.4Lf, f:%.4Lf, f:%.4Lf, f:%.4Lf, f:%.4Lf, f:%.4Lf, f:%.4Lf, f:%.4Lf, f:%.4Lf, f:%.4Lf, f:%.4Lf, f:%.4Lf, f:%.4Lf, f:%.4Lf, f:%.4Lf, f:%.4Lf, f:%.4Lf, f:%.4Lf, f:%.4Lf.", x, xx, xxx, xxxx, xxxxx, xxxxxx, xxxxxxx, xxxxxxxx, xxxxxxxxx, xxxxxxxxxx, xxxxxxxxxxx, xxxxxxxxxxxx, xxxxxxxxxxxxx, xxxxxxxxxxxxxx, xxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxxx);
// 	printf("\n#4\n");
// 	myreturn += ft_printf("\nMINE: f:%#.4Lf, f:%#.4Lf, f:%#.4Lf, f:%#.4Lf, f:%#.4Lf, f:%#.4Lf, f:%#.4Lf, f:%#.4Lf, f:%#.4Lf, f:%#.4Lf, f:%#.4Lf, f:%#.4Lf, f:%#.4Lf, f:%#.4Lf, f:%#.4Lf, f:%#.4Lf, f:%#.4Lf, f:%#.4Lf, f:%#.4Lf.", x, xx, xxx, xxxx, xxxxx, xxxxxx, xxxxxxx, xxxxxxxx, xxxxxxxxx, xxxxxxxxxx, xxxxxxxxxxx, xxxxxxxxxxxx, xxxxxxxxxxxxx, xxxxxxxxxxxxxx, xxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxxx);
// 	rlreturn += printf("\nREAL: f:%#.4Lf, f:%#.4Lf, f:%#.4Lf, f:%#.4Lf, f:%#.4Lf, f:%#.4Lf, f:%#.4Lf, f:%#.4Lf, f:%#.4Lf, f:%#.4Lf, f:%#.4Lf, f:%#.4Lf, f:%#.4Lf, f:%#.4Lf, f:%#.4Lf, f:%#.4Lf, f:%#.4Lf, f:%#.4Lf, f:%#.4Lf.", x, xx, xxx, xxxx, xxxxx, xxxxxx, xxxxxxx, xxxxxxxx, xxxxxxxxx, xxxxxxxxxx, xxxxxxxxxxx, xxxxxxxxxxxx, xxxxxxxxxxxxx, xxxxxxxxxxxxxx, xxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxxx);
// 	printf("\n5\n");
// 	myreturn += ft_printf("\nMINE: f:%.5Lf, f:%.5Lf, f:%.5Lf, f:%.5Lf, f:%.5Lf, f:%.5Lf, f:%.5Lf, f:%.5Lf, f:%.5Lf, f:%.5Lf, f:%.5Lf, f:%.5Lf, f:%.5Lf, f:%.5Lf, f:%.5Lf, f:%.5Lf, f:%.5Lf, f:%.5Lf, f:%.5Lf.", x, xx, xxx, xxxx, xxxxx, xxxxxx, xxxxxxx, xxxxxxxx, xxxxxxxxx, xxxxxxxxxx, xxxxxxxxxxx, xxxxxxxxxxxx, xxxxxxxxxxxxx, xxxxxxxxxxxxxx, xxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxxx);
// 	rlreturn += printf("\nREAL: f:%.5Lf, f:%.5Lf, f:%.5Lf, f:%.5Lf, f:%.5Lf, f:%.5Lf, f:%.5Lf, f:%.5Lf, f:%.5Lf, f:%.5Lf, f:%.5Lf, f:%.5Lf, f:%.5Lf, f:%.5Lf, f:%.5Lf, f:%.5Lf, f:%.5Lf, f:%.5Lf, f:%.5Lf.", x, xx, xxx, xxxx, xxxxx, xxxxxx, xxxxxxx, xxxxxxxx, xxxxxxxxx, xxxxxxxxxx, xxxxxxxxxxx, xxxxxxxxxxxx, xxxxxxxxxxxxx, xxxxxxxxxxxxxx, xxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxxx);
// 	printf("\n#5\n");
// 	myreturn += ft_printf("\nMINE: f:%#.5Lf, f:%#.5Lf, f:%#.5Lf, f:%#.5Lf, f:%#.5Lf, f:%#.5Lf, f:%#.5Lf, f:%#.5Lf, f:%#.5Lf, f:%#.5Lf, f:%#.5Lf, f:%#.5Lf, f:%#.5Lf, f:%#.5Lf, f:%#.5Lf, f:%#.5Lf, f:%#.5Lf, f:%#.5Lf, f:%#.5Lf.", x, xx, xxx, xxxx, xxxxx, xxxxxx, xxxxxxx, xxxxxxxx, xxxxxxxxx, xxxxxxxxxx, xxxxxxxxxxx, xxxxxxxxxxxx, xxxxxxxxxxxxx, xxxxxxxxxxxxxx, xxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxxx);
// 	rlreturn += printf("\nREAL: f:%#.5Lf, f:%#.5Lf, f:%#.5Lf, f:%#.5Lf, f:%#.5Lf, f:%#.5Lf, f:%#.5Lf, f:%#.5Lf, f:%#.5Lf, f:%#.5Lf, f:%#.5Lf, f:%#.5Lf, f:%#.5Lf, f:%#.5Lf, f:%#.5Lf, f:%#.5Lf, f:%#.5Lf, f:%#.5Lf, f:%#.5Lf.", x, xx, xxx, xxxx, xxxxx, xxxxxx, xxxxxxx, xxxxxxxx, xxxxxxxxx, xxxxxxxxxx, xxxxxxxxxxx, xxxxxxxxxxxx, xxxxxxxxxxxxx, xxxxxxxxxxxxxx, xxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxxx);
// 	printf("\n6\n");
// 	myreturn += ft_printf("\nMINE: f:%.6Lf, f:%.6Lf, f:%.6Lf, f:%.6Lf, f:%.6Lf, f:%.6Lf, f:%.6Lf, f:%.6Lf, f:%.6Lf, f:%.6Lf, f:%.6Lf, f:%.6Lf, f:%.6Lf, f:%.6Lf, f:%.6Lf, f:%.6Lf, f:%.6Lf, f:%.6Lf, f:%.6Lf.", x, xx, xxx, xxxx, xxxxx, xxxxxx, xxxxxxx, xxxxxxxx, xxxxxxxxx, xxxxxxxxxx, xxxxxxxxxxx, xxxxxxxxxxxx, xxxxxxxxxxxxx, xxxxxxxxxxxxxx, xxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxxx);
// 	rlreturn += printf("\nREAL: f:%.6Lf, f:%.6Lf, f:%.6Lf, f:%.6Lf, f:%.6Lf, f:%.6Lf, f:%.6Lf, f:%.6Lf, f:%.6Lf, f:%.6Lf, f:%.6Lf, f:%.6Lf, f:%.6Lf, f:%.6Lf, f:%.6Lf, f:%.6Lf, f:%.6Lf, f:%.6Lf, f:%.6Lf.", x, xx, xxx, xxxx, xxxxx, xxxxxx, xxxxxxx, xxxxxxxx, xxxxxxxxx, xxxxxxxxxx, xxxxxxxxxxx, xxxxxxxxxxxx, xxxxxxxxxxxxx, xxxxxxxxxxxxxx, xxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxxx);
// 	printf("\n#6\n");
// 	myreturn += ft_printf("\nMINE: f:%#.6Lf, f:%#.6Lf, f:%#.6Lf, f:%#.6Lf, f:%#.6Lf, f:%#.6Lf, f:%#.6Lf, f:%#.6Lf, f:%#.6Lf, f:%#.6Lf, f:%#.6Lf, f:%#.6Lf, f:%#.6Lf, f:%#.6Lf, f:%#.6Lf, f:%#.6Lf, f:%#.6Lf, f:%#.6Lf, f:%#.6Lf.", x, xx, xxx, xxxx, xxxxx, xxxxxx, xxxxxxx, xxxxxxxx, xxxxxxxxx, xxxxxxxxxx, xxxxxxxxxxx, xxxxxxxxxxxx, xxxxxxxxxxxxx, xxxxxxxxxxxxxx, xxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxxx);
// 	rlreturn += printf("\nREAL: f:%#.6Lf, f:%#.6Lf, f:%#.6Lf, f:%#.6Lf, f:%#.6Lf, f:%#.6Lf, f:%#.6Lf, f:%#.6Lf, f:%#.6Lf, f:%#.6Lf, f:%#.6Lf, f:%#.6Lf, f:%#.6Lf, f:%#.6Lf, f:%#.6Lf, f:%#.6Lf, f:%#.6Lf, f:%#.6Lf, f:%#.6Lf.", x, xx, xxx, xxxx, xxxxx, xxxxxx, xxxxxxx, xxxxxxxx, xxxxxxxxx, xxxxxxxxxx, xxxxxxxxxxx, xxxxxxxxxxxx, xxxxxxxxxxxxx, xxxxxxxxxxxxxx, xxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxxx);
// 	printf("\n7\n");
// 	myreturn += ft_printf("\nMINE: f:%.7Lf, f:%.7Lf, f:%.7Lf, f:%.7Lf, f:%.7Lf, f:%.7Lf, f:%.7Lf, f:%.7Lf, f:%.7Lf, f:%.7Lf, f:%.7Lf, f:%.7Lf, f:%.7Lf, f:%.7Lf, f:%.7Lf, f:%.7Lf, f:%.7Lf, f:%.7Lf, f:%.7Lf.", x, xx, xxx, xxxx, xxxxx, xxxxxx, xxxxxxx, xxxxxxxx, xxxxxxxxx, xxxxxxxxxx, xxxxxxxxxxx, xxxxxxxxxxxx, xxxxxxxxxxxxx, xxxxxxxxxxxxxx, xxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxxx);
// 	rlreturn += printf("\nREAL: f:%.7Lf, f:%.7Lf, f:%.7Lf, f:%.7Lf, f:%.7Lf, f:%.7Lf, f:%.7Lf, f:%.7Lf, f:%.7Lf, f:%.7Lf, f:%.7Lf, f:%.7Lf, f:%.7Lf, f:%.7Lf, f:%.7Lf, f:%.7Lf, f:%.7Lf, f:%.7Lf, f:%.7Lf.", x, xx, xxx, xxxx, xxxxx, xxxxxx, xxxxxxx, xxxxxxxx, xxxxxxxxx, xxxxxxxxxx, xxxxxxxxxxx, xxxxxxxxxxxx, xxxxxxxxxxxxx, xxxxxxxxxxxxxx, xxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxxx);
// 	printf("\n#7\n");
// 	myreturn += ft_printf("\nMINE: f:%#.7Lf, f:%#.7Lf, f:%#.7Lf, f:%#.7Lf, f:%#.7Lf, f:%#.7Lf, f:%#.7Lf, f:%#.7Lf, f:%#.7Lf, f:%#.7Lf, f:%#.7Lf, f:%#.7Lf, f:%#.7Lf, f:%#.7Lf, f:%#.7Lf, f:%#.7Lf, f:%#.7Lf, f:%#.7Lf, f:%#.7Lf.", x, xx, xxx, xxxx, xxxxx, xxxxxx, xxxxxxx, xxxxxxxx, xxxxxxxxx, xxxxxxxxxx, xxxxxxxxxxx, xxxxxxxxxxxx, xxxxxxxxxxxxx, xxxxxxxxxxxxxx, xxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxxx);
// 	rlreturn += printf("\nREAL: f:%#.7Lf, f:%#.7Lf, f:%#.7Lf, f:%#.7Lf, f:%#.7Lf, f:%#.7Lf, f:%#.7Lf, f:%#.7Lf, f:%#.7Lf, f:%#.7Lf, f:%#.7Lf, f:%#.7Lf, f:%#.7Lf, f:%#.7Lf, f:%#.7Lf, f:%#.7Lf, f:%#.7Lf, f:%#.7Lf, f:%#.7Lf.", x, xx, xxx, xxxx, xxxxx, xxxxxx, xxxxxxx, xxxxxxxx, xxxxxxxxx, xxxxxxxxxx, xxxxxxxxxxx, xxxxxxxxxxxx, xxxxxxxxxxxxx, xxxxxxxxxxxxxx, xxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxxx);
// 	printf("\n8\n");
// 	myreturn += ft_printf("\nMINE: f:%.8Lf, f:%.8Lf, f:%.8Lf, f:%.8Lf, f:%.8Lf, f:%.8Lf, f:%.8Lf, f:%.8Lf, f:%.8Lf, f:%.8Lf, f:%.8Lf, f:%.8Lf, f:%.8Lf, f:%.8Lf, f:%.8Lf, f:%.8Lf, f:%.8Lf, f:%.8Lf, f:%.8Lf.", x, xx, xxx, xxxx, xxxxx, xxxxxx, xxxxxxx, xxxxxxxx, xxxxxxxxx, xxxxxxxxxx, xxxxxxxxxxx, xxxxxxxxxxxx, xxxxxxxxxxxxx, xxxxxxxxxxxxxx, xxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxxx);
// 	rlreturn += printf("\nREAL: f:%.8Lf, f:%.8Lf, f:%.8Lf, f:%.8Lf, f:%.8Lf, f:%.8Lf, f:%.8Lf, f:%.8Lf, f:%.8Lf, f:%.8Lf, f:%.8Lf, f:%.8Lf, f:%.8Lf, f:%.8Lf, f:%.8Lf, f:%.8Lf, f:%.8Lf, f:%.8Lf, f:%.8Lf.", x, xx, xxx, xxxx, xxxxx, xxxxxx, xxxxxxx, xxxxxxxx, xxxxxxxxx, xxxxxxxxxx, xxxxxxxxxxx, xxxxxxxxxxxx, xxxxxxxxxxxxx, xxxxxxxxxxxxxx, xxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxxx);
// 	printf("\n#8\n");
// 	myreturn += ft_printf("\nMINE: f:%#.8Lf, f:%#.8Lf, f:%#.8Lf, f:%#.8Lf, f:%#.8Lf, f:%#.8Lf, f:%#.8Lf, f:%#.8Lf, f:%#.8Lf, f:%#.8Lf, f:%#.8Lf, f:%#.8Lf, f:%#.8Lf, f:%#.8Lf, f:%#.8Lf, f:%#.8Lf, f:%#.8Lf, f:%#.8Lf, f:%#.8Lf.", x, xx, xxx, xxxx, xxxxx, xxxxxx, xxxxxxx, xxxxxxxx, xxxxxxxxx, xxxxxxxxxx, xxxxxxxxxxx, xxxxxxxxxxxx, xxxxxxxxxxxxx, xxxxxxxxxxxxxx, xxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxxx);
// 	rlreturn += printf("\nREAL: f:%#.8Lf, f:%#.8Lf, f:%#.8Lf, f:%#.8Lf, f:%#.8Lf, f:%#.8Lf, f:%#.8Lf, f:%#.8Lf, f:%#.8Lf, f:%#.8Lf, f:%#.8Lf, f:%#.8Lf, f:%#.8Lf, f:%#.8Lf, f:%#.8Lf, f:%#.8Lf, f:%#.8Lf, f:%#.8Lf, f:%#.8Lf.", x, xx, xxx, xxxx, xxxxx, xxxxxx, xxxxxxx, xxxxxxxx, xxxxxxxxx, xxxxxxxxxx, xxxxxxxxxxx, xxxxxxxxxxxx, xxxxxxxxxxxxx, xxxxxxxxxxxxxx, xxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxxx);
// 	printf("\n9\n");
// 	myreturn += ft_printf("\nMINE: f:%.9Lf, f:%.9Lf, f:%.9Lf, f:%.9Lf, f:%.9Lf, f:%.9Lf, f:%.9Lf, f:%.9Lf, f:%.9Lf, f:%.9Lf, f:%.9Lf, f:%.9Lf, f:%.9Lf, f:%.9Lf, f:%.9Lf, f:%.9Lf, f:%.9Lf, f:%.9Lf, f:%.9Lf.", x, xx, xxx, xxxx, xxxxx, xxxxxx, xxxxxxx, xxxxxxxx, xxxxxxxxx, xxxxxxxxxx, xxxxxxxxxxx, xxxxxxxxxxxx, xxxxxxxxxxxxx, xxxxxxxxxxxxxx, xxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxxx);
// 	rlreturn += printf("\nREAL: f:%.9Lf, f:%.9Lf, f:%.9Lf, f:%.9Lf, f:%.9Lf, f:%.9Lf, f:%.9Lf, f:%.9Lf, f:%.9Lf, f:%.9Lf, f:%.9Lf, f:%.9Lf, f:%.9Lf, f:%.9Lf, f:%.9Lf, f:%.9Lf, f:%.9Lf, f:%.9Lf, f:%.9Lf.", x, xx, xxx, xxxx, xxxxx, xxxxxx, xxxxxxx, xxxxxxxx, xxxxxxxxx, xxxxxxxxxx, xxxxxxxxxxx, xxxxxxxxxxxx, xxxxxxxxxxxxx, xxxxxxxxxxxxxx, xxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxxx);
// 	printf("\n#9\n");
// 	myreturn += ft_printf("\nMINE: f:%#.9Lf, f:%#.9Lf, f:%#.9Lf, f:%#.9Lf, f:%#.9Lf, f:%#.9Lf, f:%#.9Lf, f:%#.9Lf, f:%#.9Lf, f:%#.9Lf, f:%#.9Lf, f:%#.9Lf, f:%#.9Lf, f:%#.9Lf, f:%#.9Lf, f:%#.9Lf, f:%#.9Lf, f:%#.9Lf, f:%#.9Lf.", x, xx, xxx, xxxx, xxxxx, xxxxxx, xxxxxxx, xxxxxxxx, xxxxxxxxx, xxxxxxxxxx, xxxxxxxxxxx, xxxxxxxxxxxx, xxxxxxxxxxxxx, xxxxxxxxxxxxxx, xxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxxx);
// 	rlreturn += printf("\nREAL: f:%#.9Lf, f:%#.9Lf, f:%#.9Lf, f:%#.9Lf, f:%#.9Lf, f:%#.9Lf, f:%#.9Lf, f:%#.9Lf, f:%#.9Lf, f:%#.9Lf, f:%#.9Lf, f:%#.9Lf, f:%#.9Lf, f:%#.9Lf, f:%#.9Lf, f:%#.9Lf, f:%#.9Lf, f:%#.9Lf, f:%#.9Lf.", x, xx, xxx, xxxx, xxxxx, xxxxxx, xxxxxxx, xxxxxxxx, xxxxxxxxx, xxxxxxxxxx, xxxxxxxxxxx, xxxxxxxxxxxx, xxxxxxxxxxxxx, xxxxxxxxxxxxxx, xxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxxx);
// 	printf("\n10\n");
// 	myreturn += ft_printf("\nMINE: f:%.10Lf, f:%.10Lf, f:%.10Lf, f:%.10Lf, f:%.10Lf, f:%.10Lf, f:%.10Lf, f:%.10Lf, f:%.10Lf, f:%.10Lf, f:%.10Lf, f:%.10Lf, f:%.10Lf, f:%.10Lf, f:%.10Lf, f:%.10Lf, f:%.10Lf, f:%.10Lf, f:%.10Lf.", x, xx, xxx, xxxx, xxxxx, xxxxxx, xxxxxxx, xxxxxxxx, xxxxxxxxx, xxxxxxxxxx, xxxxxxxxxxx, xxxxxxxxxxxx, xxxxxxxxxxxxx, xxxxxxxxxxxxxx, xxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxxx);
// 	rlreturn += printf("\nREAL: f:%.10Lf, f:%.10Lf, f:%.10Lf, f:%.10Lf, f:%.10Lf, f:%.10Lf, f:%.10Lf, f:%.10Lf, f:%.10Lf, f:%.10Lf, f:%.10Lf, f:%.10Lf, f:%.10Lf, f:%.10Lf, f:%.10Lf, f:%.10Lf, f:%.10Lf, f:%.10Lf, f:%.10Lf.", x, xx, xxx, xxxx, xxxxx, xxxxxx, xxxxxxx, xxxxxxxx, xxxxxxxxx, xxxxxxxxxx, xxxxxxxxxxx, xxxxxxxxxxxx, xxxxxxxxxxxxx, xxxxxxxxxxxxxx, xxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxxx);
// 	printf("\n#10\n");
// 	myreturn += ft_printf("\nMINE: f:%#.10Lf, f:%#.10Lf, f:%#.10Lf, f:%#.10Lf, f:%#.10Lf, f:%#.10Lf, f:%#.10Lf, f:%#.10Lf, f:%#.10Lf, f:%#.10Lf, f:%#.10Lf, f:%#.10Lf, f:%#.10Lf, f:%#.10Lf, f:%#.10Lf, f:%#.10Lf, f:%#.10Lf, f:%#.10Lf, f:%#.10Lf.", x, xx, xxx, xxxx, xxxxx, xxxxxx, xxxxxxx, xxxxxxxx, xxxxxxxxx, xxxxxxxxxx, xxxxxxxxxxx, xxxxxxxxxxxx, xxxxxxxxxxxxx, xxxxxxxxxxxxxx, xxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxxx);
// 	rlreturn += printf("\nREAL: f:%#.10Lf, f:%#.10Lf, f:%#.10Lf, f:%#.10Lf, f:%#.10Lf, f:%#.10Lf, f:%#.10Lf, f:%#.10Lf, f:%#.10Lf, f:%#.10Lf, f:%#.10Lf, f:%#.10Lf, f:%#.10Lf, f:%#.10Lf, f:%#.10Lf, f:%#.10Lf, f:%#.10Lf, f:%#.10Lf, f:%#.10Lf.", x, xx, xxx, xxxx, xxxxx, xxxxxx, xxxxxxx, xxxxxxxx, xxxxxxxxx, xxxxxxxxxx, xxxxxxxxxxx, xxxxxxxxxxxx, xxxxxxxxxxxxx, xxxxxxxxxxxxxx, xxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxxx);
// 	printf("\n11\n");
// 	myreturn += ft_printf("\nMINE: f:%.11Lf, f:%.11Lf, f:%.11Lf, f:%.11Lf, f:%.11Lf, f:%.11Lf, f:%.11Lf, f:%.11Lf, f:%.11Lf, f:%.11Lf, f:%.11Lf, f:%.11Lf, f:%.11Lf, f:%.11Lf, f:%.11Lf, f:%.11Lf, f:%.11Lf, f:%.11Lf, f:%.11Lf.", x, xx, xxx, xxxx, xxxxx, xxxxxx, xxxxxxx, xxxxxxxx, xxxxxxxxx, xxxxxxxxxx, xxxxxxxxxxx, xxxxxxxxxxxx, xxxxxxxxxxxxx, xxxxxxxxxxxxxx, xxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxxx);
// 	rlreturn += printf("\nREAL: f:%.11Lf, f:%.11Lf, f:%.11Lf, f:%.11Lf, f:%.11Lf, f:%.11Lf, f:%.11Lf, f:%.11Lf, f:%.11Lf, f:%.11Lf, f:%.11Lf, f:%.11Lf, f:%.11Lf, f:%.11Lf, f:%.11Lf, f:%.11Lf, f:%.11Lf, f:%.11Lf, f:%.11Lf.", x, xx, xxx, xxxx, xxxxx, xxxxxx, xxxxxxx, xxxxxxxx, xxxxxxxxx, xxxxxxxxxx, xxxxxxxxxxx, xxxxxxxxxxxx, xxxxxxxxxxxxx, xxxxxxxxxxxxxx, xxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxxx);
// 	printf("\n#11\n");
// 	myreturn += ft_printf("\nMINE: f:%#.11Lf, f:%#.11Lf, f:%#.11Lf, f:%#.11Lf, f:%#.11Lf, f:%#.11Lf, f:%#.11Lf, f:%#.11Lf, f:%#.11Lf, f:%#.11Lf, f:%#.11Lf, f:%#.11Lf, f:%#.11Lf, f:%#.11Lf, f:%#.11Lf, f:%#.11Lf, f:%#.11Lf, f:%#.11Lf, f:%#.11Lf.", x, xx, xxx, xxxx, xxxxx, xxxxxx, xxxxxxx, xxxxxxxx, xxxxxxxxx, xxxxxxxxxx, xxxxxxxxxxx, xxxxxxxxxxxx, xxxxxxxxxxxxx, xxxxxxxxxxxxxx, xxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxxx);
// 	rlreturn += printf("\nREAL: f:%#.11Lf, f:%#.11Lf, f:%#.11Lf, f:%#.11Lf, f:%#.11Lf, f:%#.11Lf, f:%#.11Lf, f:%#.11Lf, f:%#.11Lf, f:%#.11Lf, f:%#.11Lf, f:%#.11Lf, f:%#.11Lf, f:%#.11Lf, f:%#.11Lf, f:%#.11Lf, f:%#.11Lf, f:%#.11Lf, f:%#.11Lf.", x, xx, xxx, xxxx, xxxxx, xxxxxx, xxxxxxx, xxxxxxxx, xxxxxxxxx, xxxxxxxxxx, xxxxxxxxxxx, xxxxxxxxxxxx, xxxxxxxxxxxxx, xxxxxxxxxxxxxx, xxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxxx);
// 	printf("\n12\n");
// 	myreturn += ft_printf("\nMINE: f:%.12Lf, f:%.12Lf, f:%.12Lf, f:%.12Lf, f:%.12Lf, f:%.12Lf, f:%.12Lf, f:%.12Lf, f:%.12Lf, f:%.12Lf, f:%.12Lf, f:%.12Lf, f:%.12Lf, f:%.12Lf, f:%.12Lf, f:%.12Lf, f:%.12Lf, f:%.12Lf, f:%.12Lf.", x, xx, xxx, xxxx, xxxxx, xxxxxx, xxxxxxx, xxxxxxxx, xxxxxxxxx, xxxxxxxxxx, xxxxxxxxxxx, xxxxxxxxxxxx, xxxxxxxxxxxxx, xxxxxxxxxxxxxx, xxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxxx);
// 	rlreturn += printf("\nREAL: f:%.12Lf, f:%.12Lf, f:%.12Lf, f:%.12Lf, f:%.12Lf, f:%.12Lf, f:%.12Lf, f:%.12Lf, f:%.12Lf, f:%.12Lf, f:%.12Lf, f:%.12Lf, f:%.12Lf, f:%.12Lf, f:%.12Lf, f:%.12Lf, f:%.12Lf, f:%.12Lf, f:%.12Lf.", x, xx, xxx, xxxx, xxxxx, xxxxxx, xxxxxxx, xxxxxxxx, xxxxxxxxx, xxxxxxxxxx, xxxxxxxxxxx, xxxxxxxxxxxx, xxxxxxxxxxxxx, xxxxxxxxxxxxxx, xxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxxx);
// 	printf("\n#12\n");
// 	myreturn += ft_printf("\nMINE: f:%#.12Lf, f:%#.12Lf, f:%#.12Lf, f:%#.12Lf, f:%#.12Lf, f:%#.12Lf, f:%#.12Lf, f:%#.12Lf, f:%#.12Lf, f:%#.12Lf, f:%#.12Lf, f:%#.12Lf, f:%#.12Lf, f:%#.12Lf, f:%#.12Lf, f:%#.12Lf, f:%#.12Lf, f:%#.12Lf, f:%#.12Lf.", x, xx, xxx, xxxx, xxxxx, xxxxxx, xxxxxxx, xxxxxxxx, xxxxxxxxx, xxxxxxxxxx, xxxxxxxxxxx, xxxxxxxxxxxx, xxxxxxxxxxxxx, xxxxxxxxxxxxxx, xxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxxx);
// 	rlreturn += printf("\nREAL: f:%#.12Lf, f:%#.12Lf, f:%#.12Lf, f:%#.12Lf, f:%#.12Lf, f:%#.12Lf, f:%#.12Lf, f:%#.12Lf, f:%#.12Lf, f:%#.12Lf, f:%#.12Lf, f:%#.12Lf, f:%#.12Lf, f:%#.12Lf, f:%#.12Lf, f:%#.12Lf, f:%#.12Lf, f:%#.12Lf, f:%#.12Lf.", x, xx, xxx, xxxx, xxxxx, xxxxxx, xxxxxxx, xxxxxxxx, xxxxxxxxx, xxxxxxxxxx, xxxxxxxxxxx, xxxxxxxxxxxx, xxxxxxxxxxxxx, xxxxxxxxxxxxxx, xxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxxx);
// 	printf("\n13\n");
// 	myreturn += ft_printf("\nMINE: f:%.13Lf, f:%.13Lf, f:%.13Lf, f:%.13Lf, f:%.13Lf, f:%.13Lf, f:%.13Lf, f:%.13Lf, f:%.13Lf, f:%.13Lf, f:%.13Lf, f:%.13Lf, f:%.13Lf, f:%.13Lf, f:%.13Lf, f:%.13Lf, f:%.13Lf, f:%.13Lf, f:%.13Lf.", x, xx, xxx, xxxx, xxxxx, xxxxxx, xxxxxxx, xxxxxxxx, xxxxxxxxx, xxxxxxxxxx, xxxxxxxxxxx, xxxxxxxxxxxx, xxxxxxxxxxxxx, xxxxxxxxxxxxxx, xxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxxx);
// 	rlreturn += printf("\nREAL: f:%.13Lf, f:%.13Lf, f:%.13Lf, f:%.13Lf, f:%.13Lf, f:%.13Lf, f:%.13Lf, f:%.13Lf, f:%.13Lf, f:%.13Lf, f:%.13Lf, f:%.13Lf, f:%.13Lf, f:%.13Lf, f:%.13Lf, f:%.13Lf, f:%.13Lf, f:%.13Lf, f:%.13Lf.", x, xx, xxx, xxxx, xxxxx, xxxxxx, xxxxxxx, xxxxxxxx, xxxxxxxxx, xxxxxxxxxx, xxxxxxxxxxx, xxxxxxxxxxxx, xxxxxxxxxxxxx, xxxxxxxxxxxxxx, xxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxxx);
// 	printf("\n#13\n");
// 	myreturn += ft_printf("\nMINE: f:%#.13Lf, f:%#.13Lf, f:%#.13Lf, f:%#.13Lf, f:%#.13Lf, f:%#.13Lf, f:%#.13Lf, f:%#.13Lf, f:%#.13Lf, f:%#.13Lf, f:%#.13Lf, f:%#.13Lf, f:%#.13Lf, f:%#.13Lf, f:%#.13Lf, f:%#.13Lf, f:%#.13Lf, f:%#.13Lf, f:%#.13Lf.", x, xx, xxx, xxxx, xxxxx, xxxxxx, xxxxxxx, xxxxxxxx, xxxxxxxxx, xxxxxxxxxx, xxxxxxxxxxx, xxxxxxxxxxxx, xxxxxxxxxxxxx, xxxxxxxxxxxxxx, xxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxxx);
// 	rlreturn += printf("\nREAL: f:%#.13Lf, f:%#.13Lf, f:%#.13Lf, f:%#.13Lf, f:%#.13Lf, f:%#.13Lf, f:%#.13Lf, f:%#.13Lf, f:%#.13Lf, f:%#.13Lf, f:%#.13Lf, f:%#.13Lf, f:%#.13Lf, f:%#.13Lf, f:%#.13Lf, f:%#.13Lf, f:%#.13Lf, f:%#.13Lf, f:%#.13Lf.", x, xx, xxx, xxxx, xxxxx, xxxxxx, xxxxxxx, xxxxxxxx, xxxxxxxxx, xxxxxxxxxx, xxxxxxxxxxx, xxxxxxxxxxxx, xxxxxxxxxxxxx, xxxxxxxxxxxxxx, xxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxxx);
// 	printf("\n14\n");
// 	myreturn += ft_printf("\nMINE: f:%.14Lf, f:%.14Lf, f:%.14Lf, f:%.14Lf, f:%.14Lf, f:%.14Lf, f:%.14Lf, f:%.14Lf, f:%.14Lf, f:%.14Lf, f:%.14Lf, f:%.14Lf, f:%.14Lf, f:%.14Lf, f:%.14Lf, f:%.14Lf, f:%.14Lf, f:%.14Lf, f:%.14Lf.", x, xx, xxx, xxxx, xxxxx, xxxxxx, xxxxxxx, xxxxxxxx, xxxxxxxxx, xxxxxxxxxx, xxxxxxxxxxx, xxxxxxxxxxxx, xxxxxxxxxxxxx, xxxxxxxxxxxxxx, xxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxxx);
// 	rlreturn += printf("\nREAL: f:%.14Lf, f:%.14Lf, f:%.14Lf, f:%.14Lf, f:%.14Lf, f:%.14Lf, f:%.14Lf, f:%.14Lf, f:%.14Lf, f:%.14Lf, f:%.14Lf, f:%.14Lf, f:%.14Lf, f:%.14Lf, f:%.14Lf, f:%.14Lf, f:%.14Lf, f:%.14Lf, f:%.14Lf.", x, xx, xxx, xxxx, xxxxx, xxxxxx, xxxxxxx, xxxxxxxx, xxxxxxxxx, xxxxxxxxxx, xxxxxxxxxxx, xxxxxxxxxxxx, xxxxxxxxxxxxx, xxxxxxxxxxxxxx, xxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxxx);
// 	printf("\n#14\n");
// 	myreturn += ft_printf("\nMINE: f:%#.14Lf, f:%#.14Lf, f:%#.14Lf, f:%#.14Lf, f:%#.14Lf, f:%#.14Lf, f:%#.14Lf, f:%#.14Lf, f:%#.14Lf, f:%#.14Lf, f:%#.14Lf, f:%#.14Lf, f:%#.14Lf, f:%#.14Lf, f:%#.14Lf, f:%#.14Lf, f:%#.14Lf, f:%#.14Lf, f:%#.14Lf.", x, xx, xxx, xxxx, xxxxx, xxxxxx, xxxxxxx, xxxxxxxx, xxxxxxxxx, xxxxxxxxxx, xxxxxxxxxxx, xxxxxxxxxxxx, xxxxxxxxxxxxx, xxxxxxxxxxxxxx, xxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxxx);
// 	rlreturn += printf("\nREAL: f:%#.14Lf, f:%#.14Lf, f:%#.14Lf, f:%#.14Lf, f:%#.14Lf, f:%#.14Lf, f:%#.14Lf, f:%#.14Lf, f:%#.14Lf, f:%#.14Lf, f:%#.14Lf, f:%#.14Lf, f:%#.14Lf, f:%#.14Lf, f:%#.14Lf, f:%#.14Lf, f:%#.14Lf, f:%#.14Lf, f:%#.14Lf.", x, xx, xxx, xxxx, xxxxx, xxxxxx, xxxxxxx, xxxxxxxx, xxxxxxxxx, xxxxxxxxxx, xxxxxxxxxxx, xxxxxxxxxxxx, xxxxxxxxxxxxx, xxxxxxxxxxxxxx, xxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxxx);
// 	printf("\n15\n");
// 	myreturn += ft_printf("\nMINE: f:%.15Lf, f:%.15Lf, f:%.15Lf, f:%.15Lf, f:%.15Lf, f:%.15Lf, f:%.15Lf, f:%.15Lf, f:%.15Lf, f:%.15Lf, f:%.15Lf, f:%.15Lf, f:%.15Lf, f:%.15Lf, f:%.15Lf, f:%.15Lf, f:%.15Lf, f:%.15Lf, f:%.15Lf.", x, xx, xxx, xxxx, xxxxx, xxxxxx, xxxxxxx, xxxxxxxx, xxxxxxxxx, xxxxxxxxxx, xxxxxxxxxxx, xxxxxxxxxxxx, xxxxxxxxxxxxx, xxxxxxxxxxxxxx, xxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxxx);
// 	rlreturn += printf("\nREAL: f:%.15Lf, f:%.15Lf, f:%.15Lf, f:%.15Lf, f:%.15Lf, f:%.15Lf, f:%.15Lf, f:%.15Lf, f:%.15Lf, f:%.15Lf, f:%.15Lf, f:%.15Lf, f:%.15Lf, f:%.15Lf, f:%.15Lf, f:%.15Lf, f:%.15Lf, f:%.15Lf, f:%.15Lf.", x, xx, xxx, xxxx, xxxxx, xxxxxx, xxxxxxx, xxxxxxxx, xxxxxxxxx, xxxxxxxxxx, xxxxxxxxxxx, xxxxxxxxxxxx, xxxxxxxxxxxxx, xxxxxxxxxxxxxx, xxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxxx);
// 	printf("\n#15\n");
// 	myreturn += ft_printf("\nMINE: f:%#.15Lf, f:%#.15Lf, f:%#.15Lf, f:%#.15Lf, f:%#.15Lf, f:%#.15Lf, f:%#.15Lf, f:%#.15Lf, f:%#.15Lf, f:%#.15Lf, f:%#.15Lf, f:%#.15Lf, f:%#.15Lf, f:%#.15Lf, f:%#.15Lf, f:%#.15Lf, f:%#.15Lf, f:%#.15Lf, f:%#.15Lf.", x, xx, xxx, xxxx, xxxxx, xxxxxx, xxxxxxx, xxxxxxxx, xxxxxxxxx, xxxxxxxxxx, xxxxxxxxxxx, xxxxxxxxxxxx, xxxxxxxxxxxxx, xxxxxxxxxxxxxx, xxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxxx);
// 	rlreturn += printf("\nREAL: f:%#.15Lf, f:%#.15Lf, f:%#.15Lf, f:%#.15Lf, f:%#.15Lf, f:%#.15Lf, f:%#.15Lf, f:%#.15Lf, f:%#.15Lf, f:%#.15Lf, f:%#.15Lf, f:%#.15Lf, f:%#.15Lf, f:%#.15Lf, f:%#.15Lf, f:%#.15Lf, f:%#.15Lf, f:%#.15Lf, f:%#.15Lf.", x, xx, xxx, xxxx, xxxxx, xxxxxx, xxxxxxx, xxxxxxxx, xxxxxxxxx, xxxxxxxxxx, xxxxxxxxxxx, xxxxxxxxxxxx, xxxxxxxxxxxxx, xxxxxxxxxxxxxx, xxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxxx);
// 	printf("\n16\n");
// 	myreturn += ft_printf("\nMINE: f:%.16Lf, f:%.16Lf, f:%.16Lf, f:%.16Lf, f:%.16Lf, f:%.16Lf, f:%.16Lf, f:%.16Lf, f:%.16Lf, f:%.16Lf, f:%.16Lf, f:%.16Lf, f:%.16Lf, f:%.16Lf, f:%.16Lf, f:%.16Lf, f:%.16Lf, f:%.16Lf, f:%.16Lf.", x, xx, xxx, xxxx, xxxxx, xxxxxx, xxxxxxx, xxxxxxxx, xxxxxxxxx, xxxxxxxxxx, xxxxxxxxxxx, xxxxxxxxxxxx, xxxxxxxxxxxxx, xxxxxxxxxxxxxx, xxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxxx);
// 	rlreturn += printf("\nREAL: f:%.16Lf, f:%.16Lf, f:%.16Lf, f:%.16Lf, f:%.16Lf, f:%.16Lf, f:%.16Lf, f:%.16Lf, f:%.16Lf, f:%.16Lf, f:%.16Lf, f:%.16Lf, f:%.16Lf, f:%.16Lf, f:%.16Lf, f:%.16Lf, f:%.16Lf, f:%.16Lf, f:%.16Lf.", x, xx, xxx, xxxx, xxxxx, xxxxxx, xxxxxxx, xxxxxxxx, xxxxxxxxx, xxxxxxxxxx, xxxxxxxxxxx, xxxxxxxxxxxx, xxxxxxxxxxxxx, xxxxxxxxxxxxxx, xxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxxx);
// 	printf("\n#16\n");
// 	myreturn += ft_printf("\nMINE: f:%#.16Lf, f:%#.16Lf, f:%#.16Lf, f:%#.16Lf, f:%#.16Lf, f:%#.16Lf, f:%#.16Lf, f:%#.16Lf, f:%#.16Lf, f:%#.16Lf, f:%#.16Lf, f:%#.16Lf, f:%#.16Lf, f:%#.16Lf, f:%#.16Lf, f:%#.16Lf, f:%#.16Lf, f:%#.16Lf, f:%#.16Lf.", x, xx, xxx, xxxx, xxxxx, xxxxxx, xxxxxxx, xxxxxxxx, xxxxxxxxx, xxxxxxxxxx, xxxxxxxxxxx, xxxxxxxxxxxx, xxxxxxxxxxxxx, xxxxxxxxxxxxxx, xxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxxx);
// 	rlreturn += printf("\nREAL: f:%#.16Lf, f:%#.16Lf, f:%#.16Lf, f:%#.16Lf, f:%#.16Lf, f:%#.16Lf, f:%#.16Lf, f:%#.16Lf, f:%#.16Lf, f:%#.16Lf, f:%#.16Lf, f:%#.16Lf, f:%#.16Lf, f:%#.16Lf, f:%#.16Lf, f:%#.16Lf, f:%#.16Lf, f:%#.16Lf, f:%#.16Lf.", x, xx, xxx, xxxx, xxxxx, xxxxxx, xxxxxxx, xxxxxxxx, xxxxxxxxx, xxxxxxxxxx, xxxxxxxxxxx, xxxxxxxxxxxx, xxxxxxxxxxxxx, xxxxxxxxxxxxxx, xxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxx, xxxxxxxxxxxxxxxxxxx);

// 	char			*format;
// 	char			char1;
// 	char			char2;
// 	char			*string1;
// 	char			*string2;
// 	char			*pointer1;
// 	int				int1;
// 	//	long long		long1;
// 	unsigned int	unsigned_int1;
// 	double			double1;
// 	double			double2;
// 	double			double3;

// 	printf("%p\\n", &ft_printf);
// 	ft_printf("%p\\n", &ft_printf);

// 	format = "%#.3Lf\n";
// 	double1 = 123456789123456789.1269;
// 	printf("%s\n", "double1");
// 	printf(format, double1);
// 	ft_printf(format, double1);

// 	format = "%.5Lf\n";
// 	double1 = -0.0;
// 	printf("%s\n", "Octal U");
// 	printf(format, double1);
// 	ft_printf(format, double1);

// 	format = "%.5Lf\n";
// 	double1 = -0.0;
// 	printf("%s\n", "Octal U");
// 	printf(format, double1);
// 	ft_printf(format, double1);

// 	format = "%s\n";
// 	string1 = "42";
// 	printf("%s\n", "Percentage A");
// 	printf(format, string1);
// 	ft_printf(format, string1);

// 	format = "%.3o\n";
// 	int1 = 42;
// 	printf("%s\n", "Octal U");
// 	printf(format, int1);
// 	ft_printf(format, int1);

// 	format = "%+14.3i\n";
// 	int1 = 56;
// 	printf("%s\n", "Integer K");
// 	printf(format, int1);
// 	ft_printf(format, int1);

// 	format = "%0 42li\n";
// 	int1 = 5656;
// 	printf("%s\n", "Integer P");
// 	printf(format, int1);
// 	ft_printf(format, int1);

// 	format = "%s %s\n";
// 	string1 = "String K";
// 	printf("%s\n", string1);
// 	double1 = 30.35;
// 	printf(format, double1, string1);
// 	ft_printf(format, double1, string1);

// 	// format = "%s\n";
// 	// string1 = "String K";
// 	// printf("%s\n", string1);
// 	// double1 = 30.35;
// 	// printf(format, double1);
// 	//	ft_printf(format, double1);

// 	format = "% 05.6f\n";
// 	double1 = 7.3;
// 	printf("%s\n", "Float x");
// 	printf(format, double1);
// 	ft_printf(format, double1);

// 	format = "%#041o\n";
// 	int1 = 20;
// 	printf("%s\n", "Octal D");
// 	printf(format, int1);
// 	ft_printf(format, int1);

// 	format = "%\n";
// 	//	printf(format);
// 	ft_printf(format);

// 	format = "%05.0f\n";
// 	double1 = -7.3;
// 	printf("%s\n", "Float U");
// 	printf(format, double1);
// 	ft_printf(format, double1);

// 	format = "%f\n";
// 	double1 = -3.85;
// 	printf("%s\n", "Float U");
// 	printf(format, double1);
// 	ft_printf(format, double1);

// 	format = "%f\n";
// 	double1 = 573.924;
// 	printf("%s\n", "Float U");
// 	printf(format, double1);
// 	ft_printf(format, double1);

// 	format = "%.1f\n";
// 	double1 = -3.85;
// 	printf("%s\n", "Float U");
// 	printf(format, double1);
// 	ft_printf(format, double1);

// 	format = "%.1f\n";
// 	double1 = -3.65;
// 	printf("%s\n", "Float U");
// 	printf(format, double1);
// 	ft_printf(format, double1);

// 	format = "%lo, %lo\n";
// 	printf(format, 0ul, ULONG_MAX);
// 	ft_printf(format, 0ul, ULONG_MAX);

// 	format = "111%s333%s555%saaa%sccc",
// 	printf(format, "222", "444", "666", "bbb");
// 	printf("\n");
// 	ft_printf(format, "222", "444", "666", "bbb");
// 	printf("\n");

// 	format = "%.u, %.0uXXXX\n";
// 	printf("%s\n", "Unsigned int NULL");
// 	printf(format, NULL);
// 	ft_printf(format, NULL);

// 	format = "%2c\n";
// 	//	char1 = NULL;
// 	printf("%s\n", "Character NULL");
// 	printf(format, NULL);
// 	ft_printf(format, NULL);

// 	printf("/* Print unsigned int */\n");
// 	format = "%+u\n";
// 	int1 = 56;
// 	printf("%s\n", "Unsigned Integer A");
// 	printf(format, int1);
// 	ft_printf(format, int1);

// 	format = "%+042u\n";
// 	int1 = 56;
// 	printf("%s\n", "Unsigned Integer B");
// 	printf(format, int1);
// 	ft_printf(format, int1);

// 	format = "%+052.42u\n";
// 	int1 = -56;
// 	printf("%s\n", "Unsigned Integer C");
// 	printf(format, int1);
// 	ft_printf(format, int1);

// 	format = "%4u\n";
// 	int1 = 56;
// 	printf("%s\n", "Unsigned Integer D");
// 	printf(format, int1);
// 	ft_printf(format, int1);

// 	format = "%4.u\n";
// 	int1 = 56;
// 	printf("%s\n", "Unsigned Integer E");
// 	printf(format, int1);
// 	ft_printf(format, int1);

// 	format = "%4.4u\n";
// 	int1 = 56;
// 	printf("%s\n", "Unsigned Integer F");
// 	printf(format, int1);
// 	ft_printf(format, int1);

// 	format = "%14.9u\n";
// 	int1 = 56;
// 	printf("%s\n", "Unsigned Integer G");
// 	printf(format, int1);
// 	ft_printf(format, int1);

// 	format = "%14.2u\n";
// 	int1 = 56;
// 	printf("%s\n", "Unsigned Integer H");
// 	printf(format, int1);
// 	ft_printf(format, int1);

// 	format = "%14.3u\n";
// 	int1 = 56;
// 	printf("%s\n", "Unsigned Integer I");
// 	printf(format, int1);
// 	ft_printf(format, int1);

// 	format = "%+14.2u\n";
// 	int1 = 56;
// 	printf("%s\n", "Unsigned Integer J");
// 	printf(format, int1);
// 	ft_printf(format, int1);

// 	format = "%+14.3u\n";
// 	int1 = 56;
// 	printf("%s\n", "Unsigned Integer K");
// 	printf(format, int1);
// 	ft_printf(format, int1);

// 	format = "%+42u\n";
// 	int1 = 56;
// 	printf("%s\n", "Unsigned Integer L");
// 	printf(format, int1);
// 	ft_printf(format, int1);

// 	format = "%+ 42u\n";
// 	int1 = 56;
// 	printf("%s\n", "Unsigned Integer M");
// 	printf(format, int1);
// 	ft_printf(format, int1);

// 	format = "% 42u\n";
// 	int1 = 56;
// 	printf("%s\n", "Unsigned Integer N");
// 	printf(format, int1);
// 	ft_printf(format, int1);

// 	format = "%0 42u\n";
// 	int1 = 56;
// 	printf("%s\n", "Unsigned Integer O");
// 	printf(format, int1);
// 	ft_printf(format, int1);

// 	format = "%0 42hhu\n";
// 	int1 = 5656;
// 	printf("%s\n", "Unsigned Integer P");
// 	printf(format, int1);
// 	ft_printf(format, int1);

// 	format = "%-0 42u %u\n";
// 	int1 = 56;
// 	printf("%s\n", "Unsigned Integer Q");
// 	printf(format, int1, int1);
// 	ft_printf(format, int1, int1);

// 	format = "%-042u %u\n";
// 	int1 = 56;
// 	printf("%s\n", "Unsigned Integer R");
// 	printf(format, int1, int1);
// 	ft_printf(format, int1, int1);

// 	format = "% +u %u\n";
// 	int1 = 56;
// 	printf("%s\n", "Unsigned Integer S");
// 	printf(format, int1, int1);
// 	ft_printf(format, int1, int1);

// 	format = "% u %u\n";
// 	int1 = -56;
// 	printf("%s\n", "Unsigned Integer T");
// 	printf(format, int1, int1);
// 	ft_printf(format, int1, int1);

// /*
// 	format = "%llu\n";
// 	long1 = 9223372036854775807;
// 	printf("%s\n", "Unsigned Integer U");
// 	printf(format, -9223372036854775808);
// 	ft_printf(format, -9223372036854775808);
// */
// 	format = "%u\n";
// 	unsigned_int1 = 3040506070;
// 	printf("%s\n", "Unsigned Integer V");
// 	printf(format, unsigned_int1);
// 	ft_printf(format, unsigned_int1);
// /*
// 	format = "%tu\n";
// 	long1 = 9223372036854775807;
// 	printf("%s\n", "Unsigned Integer W");
// 	printf(format, -9223372036854775808);
// 	ft_printf(format, -9223372036854775808);

// 	format = "%zu\n";
// 	long1 = 9223372036854775807;
// 	printf("%s\n", "Unsigned Integer X");
// 	printf(format, -9223372036854775808);
// 	ft_printf(format, -9223372036854775808);
// */


// 	printf("/* Print octal */\n");
// 	format = "%o\n";
// 	int1 = 20;
// 	printf("%s\n", "Octal A");
// 	printf(format, int1);
// 	ft_printf(format, int1);

// 	format = "%#o\n";
// 	int1 = 20;
// 	printf("%s\n", "Octal B");
// 	printf(format, int1);
// 	ft_printf(format, int1);

// 	format = "%#41o\n";
// 	int1 = 20;
// 	printf("%s\n", "Octal C");
// 	printf(format, int1);
// 	ft_printf(format, int1);

// 	format = "%#041o\n";
// 	int1 = 20;
// 	printf("%s\n", "Octal D");
// 	printf(format, int1);
// 	ft_printf(format, int1);

// 	format = "%#41.o\n";
// 	int1 = 20;
// 	printf("%s\n", "Octal E");
// 	printf(format, int1);
// 	ft_printf(format, int1);

// 	format = "%#41.1o\n";
// 	int1 = 20;
// 	printf("%s\n", "Octal F");
// 	printf(format, int1);
// 	ft_printf(format, int1);

// 	format = "%41.1o\n";
// 	int1 = 20;
// 	printf("%s\n", "Octal G");
// 	printf(format, int1);
// 	ft_printf(format, int1);

// 	format = "%-41.1o %o\n";
// 	int1 = 20;
// 	printf("%s\n", "Octal H");
// 	printf(format, int1, int1);
// 	ft_printf(format, int1, int1);

// 	format = "%-41.1o %o\n";
// 	int1 = 0;
// 	printf("%s\n", "Octal I");
// 	printf(format, int1, int1);
// 	ft_printf(format, int1, int1);

// 	format = "%-41.o %#.o\n";
// 	int1 = 0;
// 	printf("%s\n", "Octal J");
// 	printf(format, int1, int1);
// 	ft_printf(format, int1, int1);

// 	format = "%-.o %#.o\n";
// 	int1 = 0;
// 	printf("%s\n", "Octal K");
// 	printf(format, int1, int1);
// 	ft_printf(format, int1, int1);

// 	format = "%-41.1o %o\n";
// 	int1 = 1;
// 	printf("%s\n", "Octal L");
// 	printf(format, int1, int1);
// 	ft_printf(format, int1, int1);

// 	format = "%#.3o\n";
// 	int1 = 1;
// 	printf("%s\n", "Octal M");
// 	printf(format, int1);
// 	ft_printf(format, int1);

// 	printf("/* Print int with + */\n");
// 	format = "%+d\n";
// 	int1 = 56;
// 	printf("%s\n", "Integer A");
// 	printf(format, int1);
// 	ft_printf(format, int1);

// 	format = "%+042i\n";
// 	int1 = 56;
// 	printf("%s\n", "Integer B");
// 	printf(format, int1);
// 	ft_printf(format, int1);

// 	format = "%+052.42i\n";
// 	int1 = -56;
// 	printf("%s\n", "Integer C");
// 	printf(format, int1);
// 	ft_printf(format, int1);

// 	format = "%4i\n";
// 	int1 = 56;
// 	printf("%s\n", "Integer D");
// 	printf(format, int1);
// 	ft_printf(format, int1);

// 	format = "%4.i\n";
// 	int1 = 56;
// 	printf("%s\n", "Integer E");
// 	printf(format, int1);
// 	ft_printf(format, int1);

// 	format = "%4.4i\n";
// 	int1 = 56;
// 	printf("%s\n", "Integer F");
// 	printf(format, int1);
// 	ft_printf(format, int1);

// 	format = "%14.9i\n";
// 	int1 = 56;
// 	printf("%s\n", "Integer G");
// 	printf(format, int1);
// 	ft_printf(format, int1);

// 	format = "%14.2i\n";
// 	int1 = 56;
// 	printf("%s\n", "Integer H");
// 	printf(format, int1);
// 	ft_printf(format, int1);

// 	format = "%14.3i\n";
// 	int1 = 56;
// 	printf("%s\n", "Integer I");
// 	printf(format, int1);
// 	ft_printf(format, int1);

// 	format = "%+14.2i\n";
// 	int1 = 56;
// 	printf("%s\n", "Integer J");
// 	printf(format, int1);
// 	ft_printf(format, int1);

// 	format = "%+14.3i\n";
// 	int1 = 56;
// 	printf("%s\n", "Integer K");
// 	printf(format, int1);
// 	ft_printf(format, int1);

// 	format = "%+42i\n";
// 	int1 = 56;
// 	printf("%s\n", "Integer L");
// 	printf(format, int1);
// 	ft_printf(format, int1);

// 	format = "%+ 42i\n";
// 	int1 = 56;
// 	printf("%s\n", "Integer M");
// 	printf(format, int1);
// 	ft_printf(format, int1);

// 	format = "% 15i\n";
// 	int1 = 56;
// 	printf("%s\n", "Integer N");
// 	printf(format, int1);
// 	ft_printf(format, int1);

// 	format = "%0 42i\n";
// 	int1 = 56;
// 	printf("%s\n", "Integer O");
// 	printf(format, int1);
// 	ft_printf(format, int1);

// 	format = "%0 42hhi\n";
// 	int1 = 5656;
// 	printf("%s\n", "Integer P");
// 	printf(format, int1);
// 	ft_printf(format, int1);

// 	format = "%-0 42i %i\n";
// 	int1 = 56;
// 	printf("%s\n", "Integer Q");
// 	printf(format, int1, int1);
// 	ft_printf(format, int1, int1);

// 	format = "%-042i %i\n";
// 	int1 = 56;
// 	printf("%s\n", "Integer R");
// 	printf(format, int1, int1);
// 	ft_printf(format, int1, int1);

// 	format = "% +i %i\n";
// 	int1 = 56;
// 	printf("%s\n", "Integer S");
// 	printf(format, int1, int1);
// 	ft_printf(format, int1, int1);

// 	format = "% i %i\n";
// 	int1 = -56;
// 	printf("%s\n", "Integer T");
// 	printf(format, int1, int1);
// 	ft_printf(format, int1, int1);

// 	format = "%0 42hhi\n";
// 	int1 = -5656;
// 	printf("%s\n", "Integer U");
// 	printf(format, int1);
// 	ft_printf(format, int1);

// 	format = "%i\n";
// 	int1 = 0;
// 	printf("%s\n", "Integer V");
// 	printf(format, int1);
// 	ft_printf(format, int1);

// 	format = "%.i\n";
// 	int1 = 0;
// 	printf("%s\n", "Integer W");
// 	printf(format, int1);
// 	ft_printf(format, int1);

// /*
// 	format = "%lld\n";
// 	long1 = 9223372036854775807;
// 	printf("%s\n", "Integer W");
// 	printf(format, -9223372036854775808);
// 	ft_printf(format, -9223372036854775808);
// */
// 	printf("/* Print Pointer */\n");
// 	format = "%p  %p\n";
// 	pointer1 = "Pointer A";
// 	printf("%s\n", pointer1);
// 	printf(format, pointer1, &pointer1);
// 	ft_printf(format, pointer1, &pointer1);

// 	format = "%11p  %22p\n";
// 	pointer1 = "Pointer B";
// 	printf("%s\n", pointer1);
// 	printf(format, pointer1, &pointer1);
// 	ft_printf(format, pointer1, &pointer1);

// 	format = "%11.6p  %22.11p\n";
// 	pointer1 = "Pointer C";
// 	printf("%s\n", pointer1);
// 	printf(format, pointer1, &pointer1);
// 	ft_printf(format, pointer1, &pointer1);

// 	format = "%11.p  %22.p\n";
// 	pointer1 = "Pointer D";
// 	printf("%s\n", pointer1);
// 	printf(format, pointer1, &pointer1);
// 	ft_printf(format, pointer1, &pointer1);

// 	format = "%15p  %022p\n";
// 	pointer1 = "Pointer E";
// 	printf("%s\n", pointer1);
// 	printf(format, pointer1, &pointer1);
// 	ft_printf(format, pointer1, &pointer1);

// 	format = "%15.p  %022.p\n";
// 	pointer1 = "Pointer F";
// 	printf("%s\n", pointer1);
// 	printf(format, pointer1, &pointer1);
// 	ft_printf(format, pointer1, &pointer1);

// 	format = "%015.22p  %022.44p\n";
// 	pointer1 = "Pointer G";
// 	printf("%s\n", pointer1);
// 	printf(format, pointer1, &pointer1);
// 	ft_printf(format, pointer1, &pointer1);

// 	format = "%0.5p  %0.22p\n";
// 	pointer1 = "Pointer H";
// 	printf("%s\n", pointer1);
// 	printf(format, pointer1, &pointer1);
// 	ft_printf(format, pointer1, &pointer1);

// 	format = "%p  %.9p\n";
// 	pointer1 = "Pointer I";
// 	printf("%s\n", pointer1);
// 	pointer1 = NULL;
// 	printf(format, pointer1, pointer1);
// 	ft_printf(format, pointer1, pointer1);

// 	format = "%p  %.1p\n";
// 	pointer1 = "Pointer J";
// 	printf("%s\n", pointer1);
// 	pointer1 = NULL;
// 	printf(format, pointer1, pointer1);
// 	ft_printf(format, pointer1, pointer1);

// 	format = "%p  %.p\n";
// 	pointer1 = "Pointer K";
// 	printf("%s\n", pointer1);
// 	pointer1 = NULL;
// 	printf(format, pointer1, pointer1);
// 	ft_printf(format, pointer1, pointer1);

// 	format = "%p  %44.p\n";
// 	pointer1 = "Pointer L";
// 	printf("%s\n", pointer1);
// 	pointer1 = NULL;
// 	printf(format, pointer1, pointer1);
// 	ft_printf(format, pointer1, pointer1);

// 	format = "%15.4p  %022.2p\n";
// 	pointer1 = "Pointer M";
// 	printf("%s\n", pointer1);
// 	printf(format, pointer1, &pointer1);
// 	ft_printf(format, pointer1, &pointer1);

// 	format = "%15.4p  %022.42p\n";
// 	pointer1 = "Pointer N";
// 	printf("%s\n", pointer1);
// 	printf(format, pointer1, &pointer1);
// 	ft_printf(format, pointer1, &pointer1);

// 	format = "%.0p, %.p\n";
// 	pointer1 = "Pointer O";
// 	printf("%s\n", pointer1);
// 	pointer1 = NULL;
// 	printf(format, pointer1, pointer1);
// 	ft_printf(format, pointer1, pointer1);

// 	format = "%-15p, %p\n";
// 	pointer1 = "Pointer P";
// 	printf("%s\n", pointer1);
// 	pointer1 = NULL;
// 	printf(format, pointer1, pointer1);
// 	ft_printf(format, pointer1, pointer1);

// 	printf("/* Print String */\n");
// 	format = "%s\n";
// 	string1 = "String A";
// 	printf(format, string1);
// 	ft_printf(format, string1);

// 	format = "%22s\n";
// 	string1 = "String B";
// 	printf(format, string1);
// 	ft_printf(format, string1);

// 	format = "%22.11s\n";
// 	string1 = "String C";
// 	printf(format, string1);
// 	ft_printf(format, string1);

// 	format = "%11.s\n";
// 	string1 = "String D";
// 	printf(format, string1);
// 	ft_printf(format, string1);

// 	format = "%011.s\n";
// 	string1 = "String E";
// 	printf(format, string1);
// 	ft_printf(format, string1);

// 	format = "%0.5s\n";
// 	string1 = "String F";
// 	printf(format, string1);
// 	ft_printf(format, string1);

// 	format = "%0.25s\n";
// 	string1 = "String F";
// 	printf(format, string1);
// 	ft_printf(format, string1);

// 	format = "%-011s\n";
// 	string1 = "String G";
// 	printf(format, string1);
// 	ft_printf(format, string1);

// 	format = "%+s\n";
// 	string1 = "String H";
// 	printf(format, string1);
// 	ft_printf(format, string1);

// 	format = "% s\n";
// 	string1 = "String I";
// 	printf(format, string1);
// 	ft_printf(format, string1);

// 	format = "%33s %s\n";
// 	string1 = "String J";
// 	printf("%s\n", string1);
// 	string1 = NULL;
// 	string2 = "1234567890";
// 	printf(format, string1, string2);
// 	ft_printf(format, string1, string2);

// 	format = "%%\n";
// 	string1 = "String K";
// 	printf("%s\n", string1);
// 	printf(format, string1);
// 	ft_printf(format, string1);

// 	format = "%.0%\n";
// 	string1 = "String L";
// 	printf("%s\n", string1);
// 	printf(format, string1);
// 	ft_printf(format, string1);

// 	format = "%.1%\n";
// 	string1 = "String M";
// 	printf("%s\n", string1);
// 	printf(format, string1);
// 	ft_printf(format, string1);

// /*
// 	format = "%s\n";
// 	string1 = "String K";
// 	printf("%s\n", string1);
// 	double1 = 30.35;
// 	printf(format, double1);
// 	ft_printf(format, double1);
// */
// 	printf("/* Print Character */\n");
// 	format = "%c\n";
// 	char1 = 'A';
// 	printf(format, char1);
// 	ft_printf(format, char1);

// 	format = "%11c\n";
// 	char1 = 'B';
// 	printf(format, char1);
// 	ft_printf(format, char1);

// 	format = "%11.8c\n";
// 	char1 = 'C';
// 	printf(format, char1);
// 	ft_printf(format, char1);

// 	format = "%11.c\n";
// 	char1 = 'D';
// 	printf(format, char1);
// 	ft_printf(format, char1);

// 	format = "%011.c\n";
// 	char1 = 'E';
// 	printf(format, char1);
// 	ft_printf(format, char1);

// 	format = "%011.c\n";
// 	char1 = ' ';
// 	printf(format, char1);
// 	ft_printf(format, char1);

// 	format = "%0.11c\n";
// 	char1 = 'F';
// 	printf(format, char1);
// 	ft_printf(format, char1);

// 	format = "%-011c %c\n";
// 	char1 = 'G';
// 	printf(format, char1, char1);
// 	ft_printf(format, char1, char1);

// 	format = "%+c\n";
// 	char1 = 'H';
// 	printf(format, char1);
// 	ft_printf(format, char1);

// 	format = "% c\n";
// 	char1 = 'I';
// 	printf(format, char1);
// 	ft_printf(format, char1);

// 	format = "%011.5c\n";
// 	char1 = 'J';
// 	printf(format, char1);
// 	ft_printf(format, char1);

// 	format = "%011.c\n";
// 	char1 = 'K';
// 	printf(format, char1);
// 	ft_printf(format, char1);

// 	format = "%c\n";
// 	char1 = 0;
// 	printf(format, char1);
// 	ft_printf(format, char1);

// 	format = "%.2c\n";
// 	char1 = 0;
// 	printf(format, char1);
// 	ft_printf(format, char1);

// 	format = "%2.2c\n";
// 	char1 = 0;
// 	printf(format, char1);
// 	ft_printf(format, char1);

// 	format = "%-011c %c\n";
// 	char1 = 0;
// 	char2 = 'O';
// 	printf(format, char1, char2);
// 	ft_printf(format, char1, char2);

// 	/* Print unsigned int */
// 	format = "%u\n";
// 	unsigned_int1 = 3040506070;
// 	printf(format, unsigned_int1);
// 	ft_printf(format, unsigned_int1);

// 	/* Print hex */
// 	format = "%#x  %x\n";
// 	pointer1 = "Hex A";
// 	printf("%s\n", pointer1);
// 	pointer1 = NULL;
// 	printf(format, pointer1, &pointer1);
// 	ft_printf(format, pointer1, &pointer1);

// 	format = "%.0x, %.x\n";
// 	pointer1 = "Hex B";
// 	printf("%s\n", pointer1);
// 	pointer1 = NULL;
// 	printf(format, pointer1, &pointer1);
// 	ft_printf(format, pointer1, &pointer1);

// 	format = "%x\n";
// 	pointer1 = "Hex C";
// 	printf("%s\n", pointer1);
// 	pointer1 = 0;
// 	printf(format, pointer1, &pointer1);
// 	ft_printf(format, pointer1, &pointer1);

// 	format = "%#x\n";
// 	pointer1 = "Hex D";
// 	printf("%s\n", pointer1);
// 	int1 = 0;
// 	printf(format, int1);
// 	ft_printf(format, int1);

// 	format = "%#.0x\n";
// 	pointer1 = "Hex E";
// 	printf("%s\n", pointer1);
// 	int1 = 0;
// 	printf(format, int1);
// 	ft_printf(format, int1);

// 	format = "%#.0x\n";
// 	pointer1 = "Hex F";
// 	printf("%s\n", pointer1);
// 	int1 = 10;
// 	printf(format, int1);
// 	ft_printf(format, int1);

// 	/* Print HEX (upper case) */
// 	format = "MOI %#X  %X MOI\n";
// 	pointer1 = "Pointer 1";
// 	printf(format, pointer1, &pointer1);
// 	ft_printf(format, pointer1, &pointer1);

// 	/* Print string */
// 	format = "test";
// 	double1 = 20.2;
// 	printf(format, double1);
// 	printf("\n");
// 	ft_printf(format, double1);
// 	printf("\n");

// 	format = "111%s333%s555%saaa%sccc",
// 	printf(format, "222", "444", "666", "bbb");
// 	printf("\n");
// 	ft_printf(format, "222", "444", "666", "bbb");
// 	printf("\n");

// 	int1 = printf("JJ" "KK") + printf("YY\n");
// 	int1 = ft_printf("JJ" "KK") + ft_printf("YY\n");

// 	printf("Double:%2i\n", (int)sizeof(double));
// 	printf("Float: %2i\n", (int)sizeof(float));



// 	printf("/* Print float/\n");
// 	format = "%f %i\n";
// 	double1 = 55.95;
// 	int1 = 56;
// 	printf("%s\n", "Float A");
// 	printf(format, double1, int1);
// 	ft_printf(format, double1, int1);

// 	format = "%+f %i\n";
// 	string1 = "J";
// 	double1 = -0.012345;
// 	int1 = 56;
// 	printf("%s\n", "Float B");
// 	printf(format, double1, int1);
// 	ft_printf(format, double1, int1);

// 	format = "%+042f\n";
// 	double1 = 55.9999995;
// 	printf("%s\n", "Float C");
// 	printf(format, double1);
// 	ft_printf(format, double1);

// 	format = "%+052.42f\n";
// 	double1 = 55.0999995;
// 	printf("%s\n", "Float D");
// 	printf(format, double1);
// 	ft_printf(format, double1);

// 	format = "%#42.52f\n";
// 	double1 = 55.0999995;
// 	printf("%s\n", "Float E");
// 	printf(format, double1);
// 	ft_printf(format, double1);

// 	format = "%4.4f\n";
// 	double1 = 56;
// 	printf("%s\n", "Float F");
// 	printf(format, double1);
// 	ft_printf(format, double1);

// 	format = "%14.9f\n";
// 	double1 = 56;
// 	printf("%s\n", "Float G");
// 	printf(format, double1);
// 	ft_printf(format, double1);

// 	format = "%14.2f\n";
// 	double1 = 56;
// 	printf("%s\n", "Float H");
// 	printf(format, double1);
// 	ft_printf(format, double1);

// 	format = "%14.3f\n";
// 	double1 = 56;
// 	printf("%s\n", "Float I");
// 	printf(format, double1);
// 	ft_printf(format, double1);

// 	format = "%+14.2f\n";
// 	double1 = 56;
// 	printf("%s\n", "Float J");
// 	printf(format, double1);
// 	ft_printf(format, double1);

// 	format = "%+14.3f\n";
// 	double1 = 56;
// 	printf("%s\n", "Float K");
// 	printf(format, double1);
// 	ft_printf(format, double1);

// 	format = "%-42fMOI\n";
// 	double1 = 56;
// 	printf("%s\n", "Float L");
// 	printf(format, double1);
// 	ft_printf(format, double1);

// 	format = "%+ 42f\n";
// 	double1 = 56;
// 	printf("%s\n", "Float M");
// 	printf(format, double1);
// 	ft_printf(format, double1);

// 	format = "% 42f\n";
// 	double1 = 56;
// 	printf("%s\n", "Float N");
// 	printf(format, double1);
// 	ft_printf(format, double1);

// 	format = "%0 42f\n";
// 	double1 = 56;
// 	printf("%s\n", "Float O");
// 	printf(format, double1);
// 	ft_printf(format, double1);

// 	format = "%0 42hhf\n";
// 	double1 = 5656;
// 	printf("%s\n", "Float P");
// 	printf(format, double1);
// 	ft_printf(format, double1);

// 	format = "%-0 42i %f\n";
// 	double1 = 56;
// 	printf("%s\n", "Float Q");
// 	printf(format, double1, double1);
// 	ft_printf(format, double1, double1);

// 	format = "%-042i %f\n";
// 	double1 = 56;
// 	printf("%s\n", "Float R");
// 	printf(format, double1, double1);
// 	ft_printf(format, double1, double1);

// 	format = "% +i %f\n";
// 	double1 = 56;
// 	printf("%s\n", "Float S");
// 	printf(format, double1, double1);
// 	ft_printf(format, double1, double1);

// 	format = "% i %f\n";
// 	double1 = -56;
// 	printf("%s\n", "Float T");
// 	printf(format, double1, double1);
// 	ft_printf(format, double1, double1);

// 	format = "{%f}{%lf}{%Lf}\n";
// 	double1 = 1444565444646.6465424242242;
// 	double2 = 1444565444646.6465424242242;
// 	double3 = 1444565444646.6465424242242l;
// 	printf("%s\n", "Float V");
// 	printf(format, double1, double2, double3);
// 	ft_printf(format, double1, double2, double3);

// 	format = "%.1f\n";
// 	double1 = -3.65;
// 	printf("%s\n", "Float U");
// 	printf(format, double1);
// 	ft_printf(format, double1);

// 	format = "%010o\n";
// 	int1 = 42;
// 	printf("%s\n", "Octal R");
// 	printf(format, int1);
// 	ft_printf(format, int1);

// 	format = "%010.o\n";
// 	int1 = 42;
// 	printf("%s\n", "Octal S");
// 	printf(format, int1);
// 	ft_printf(format, int1);

// 	format = "%010.3o\n";
// 	int1 = 42;
// //	printf("%s\n", "Octal T");
// 	printf(format, int1);
// 	ft_printf(format, int1);

// 	format = "%.3o\n";
// 	int1 = 42;
// 	printf("%s\n", "Octal U");
// 	printf(format, int1);
// 	ft_printf(format, int1);

// 	format = "%.19Lf\n";
// 	double1 = 0.0;
// 	printf("%s\n", "Octal U");
// 	printf(format, -LDBL_MIN);
// 	ft_printf(format, -LDBL_MIN);

// 	format = "%.19Lf\n";
// 	double1 = -LDBL_MIN;
// 	printf("%s\n", "Octal U");
// 	printf(format, double1);
// 	ft_printf(format, double1);

// 	format = "%.5Lf\n";
// 	double1 = -10.1;
// 	printf("%s\n", "Octal U");
// 	printf(format, double1);
// 	ft_printf(format, double1);

// 	format = "%.5Lf\n";
// 	double1 = -0.0;
// 	printf("%s\n", "Octal U");
// 	printf(format, double1);
// 	ft_printf(format, double1);

// 	format = "%-5c\n";
// 	char1 = 0;
// 	printf("%s\n", "Char");
// 	printf(format, char1);
// 	ft_printf(format, char1);

// 	format = "%s\n";
// 	string1 = "Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoir";
// 	printf("%s\n", "String");
// 	printf(format, string1);
// 	ft_printf(format, string1);

// 	format = "%#.17f\n";
// 	double1 = 123.00000128;
// 	printf("%s\n", "double1");
// 	printf(format, double1);
// 	ft_printf(format, double1);

// 	format = "%#.17f\n";
// 	double1 = 1123.456;
// 	printf("%s\n", "double1");
// 	printf(format, double1);
// 	ft_printf(format, double1);

// 	format = "%#.3f\n";
// 	double1 = 123.1269;
// 	printf("%s\n", "double1");
// 	printf(format, double1);
// 	ft_printf(format, double1);

// 	format = "%#.3f\n";
// 	double1 = 123456789123456789.1269;
// 	printf("%s\n", "double1");
// 	printf(format, double1);
// 	ft_printf(format, double1);

// 	format = "%#.11f\n";
// 	double1 = 1234567891234567.1269;
// 	printf("%s\n", "double1");
// 	printf(format, double1);
// 	ft_printf(format, double1);

// 	printf("\n\n");
// 	printf("MY:return: %d\n", myreturn);
// 	printf("RL:return: %d\n", rlreturn);
// 	return (0);
// }