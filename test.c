#include "ft_printf.h"

int			main(int argc, char **argv)
{
	(void)argc; (void)argv;

	// printf("Just random tests:\n");
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

// 	printf("====================\n");
// 	printf("FTOA VS PRINTF TESTS:\n");
// 	int prec = 18;
// 	printf("real: |%.*f|\n", prec, PI);
//  ft_printf("mine: |%s|\n", ft_ftoa(PI, prec));
// 	printf("\n");
// 	printf("real: |%.*f|\n", prec, -PI);
//  ft_printf("mine: |%s|\n", ft_ftoa(-PI, prec));
// 	printf("\n");
// 	printf("real: |%.*f|\n", prec, 1.0 / 3);
//  ft_printf("mine: |%s|\n", ft_ftoa(1.0 / 3, prec));
// 	printf("\n");
// 	printf("real 0: |%.*f|\n", prec, (double)0);
//  ft_printf("mine 0: |%s|\n", ft_ftoa((double)0, prec));
// 	printf("\n");
// 	printf("real 0: |%.*f|\n", prec, -0);
//  ft_printf("mine 0: |%s|\n", ft_ftoa(-0, prec));
// 	printf("\n");
// 	printf("real -0: |%.*f|\n", prec, -0.0);
//  ft_printf("mine -0: |%s|\n", ft_ftoa(0 / -INFINITY, prec));
// 	printf("\n");
// 	printf("real: |%.*f|\n", prec, (double)1);
//  ft_printf("mine: |%s|\n", ft_ftoa((double)1, prec));
// 	printf("\n");
// 	printf("real: |%.*f|\n", prec, (double)-1);
//  ft_printf("mine: |%s|\n", ft_ftoa((double)-1, prec));
// 	printf("\n");
// 	printf("real: |%.*f|\n", prec, 123.123);
//  ft_printf("mine: |%s|\n", ft_ftoa(123.123, prec));
// 	printf("\n");
// 	printf("real inf: |%.*f|\n", prec, 3.0 / 0);
//  ft_printf("mine inf: |%s|\n", ft_ftoa(3.0 / 0, prec));
// 	printf("\n");
// 	printf("real -inf: |%.*f|\n", prec, -3.0 / 0);
//  ft_printf("mine -inf: |%s|\n", ft_ftoa(-3.0 / 0, prec));
// 	printf("\n");
// 	printf("real nan: |%.*f|\n", prec, sqrt(-1));
//  ft_printf("mine nan: |%s|\n", ft_ftoa(sqrt(-1), prec));
// 	printf("\n");
// 	printf("real: |%.*f|\n", 0, 1.99);
//  ft_printf("mine: |%s|\n", ft_ftoa(1.99, 0));
// 	printf("\n");
// 	printf("real: |%.*f|\n", 123.000000123, prec);
//  ft_printf("mine: |%s|\n", ft_ftoa(123.000000123, prec));
// 	printf("\n====================\n\n");

// 	printf("12345678901234.1234567890123456789 (string)\n");
// 	printf("%14.19f (   printf %%14.19f)\n", 12345678901234.1234567890123456789);
//  ft_printf("%14.19f (ft_printf %%14.19f)\n", 12345678901234.1234567890123456789);
// 	printf("%14.19Lf (   printf %%14.19Lf)\n", 12345678901234.1234567890123456789);
//  ft_printf("%14.19Lf (ft_printf %%14.19Lf)\n", 12345678901234.1234567890123456789);

// 	printf("\n====================\n");
// 	printf("test: 123.000000123 (%%.f)\n");
// 	printf("real: %.f\n", 123.000000123);
//  ft_printf("mine: %.f\n", 123.000000123);

// 	printf("test: 123.000000123L (%%.Lf)\n");
// 	printf("real: %.Lf\n", 123.000000123L);
//  ft_printf("mine: %.Lf\n", 123.000000123L);

// 	printf("test: 123.000000123L (%%.f)\n");
// 	printf("real: %.f (undefined)\n", 123.000000123L);
//  ft_printf("mine: %.f (undefined)\n", 123.000000123L);

		// // output_double(12345678901234.1234567890123456789, NULL);
		// // float_to_binary(6.000000476837158203125E0);
		// // double_to_binary(6.000000476837158203125E0L);
		// // printf("\n1.2345679020032E13 (string)\n");
		// // printf("%f (printf)\n", 1.2345679020032E13);
		// // ft_putendl("mine:");
		// // float_to_binary(1.2345679020032E13);
		// // double_to_binary(1.2345679020032E13);
	// printf("\n====================\n\n");
	// printf("int:%lu ll int:%lu\n", sizeof(int), sizeof(long long int));

	int a, b;

	printf("write count:\n"); // TODO: Return write count
	a =    printf("");
	b = ft_printf("");
	printf("%d == %d\n\n", a, b);

	a =    printf("real literal: write length\n");
	b = ft_printf("mine literal: write length\n");
	printf("%d == %d\n\n", a, b);

	a =    printf("real percent: %%\n");
	b = ft_printf("mine percent: %%\n");
	printf("%d == %d\n\n", a, b);

	a =    printf("real string: |%s|\n", "Hello world!");
	b = ft_printf("mine string: |%s|\n", "Hello world!");
	printf("%d == %d\n\n", a, b);

	a =    printf("real string %%5.15: |%15.5s|\n", "Test phrase!");
	b = ft_printf("mine string %%5.15: |%15.5s|\n", "Test phrase!");
	printf("%d == %d\n\n", a, b);

	a =    printf("real %%5.10d: |%5.10d|\n", -1337);
	b = ft_printf("mine %%5.10d: |%5.10d|\n", -1337);
	printf("%d == %d\n\n", a, b);

	a =    printf("real %%.10i: |%.10i|\n", 7799);
	b = ft_printf("mine %%.10i: |%.10i|\n", 7799);
	printf("%d == %d\n\n", a, b);

	a =    printf("real %%10.3i: |%10.3i|\n", -7799);
	b = ft_printf("mine %%10.3i: |%10.3i|\n", -7799);
	printf("%d == %d\n\n", a, b);

	a =    printf("real %%7.8i: |%7.8i|\n", -7799);
	b = ft_printf("mine %%7.8i: |%7.8i|\n", -7799);
	printf("%d == %d\n\n", a, b);

	a =    printf("real %%7.5c: |%.c|\n", '@');
	b = ft_printf("mine %%7.5c: |%.c|\n", '@');
	printf("%d == %d\n\n", a, b);

	a =    printf("real c: |%c|\n", '?');
	b = ft_printf("mine c: |%c|\n", '?');
	printf("%d == %d\n\n", a, b);

	a =    printf("real %%u: |%5u|\n", 8888);
	b = ft_printf("mine %%u: |%5u|\n", 8888);
	printf("%d == %d\n\n", a, b);

	a =    printf("real u: |%u|\n", 123);
	b = ft_printf("mine u: |%u|\n", 123);
	printf("%d == %d\n\n", a, b);

	a =    printf("real negative u: |%u|\n", -123);
	b = ft_printf("mine negative u: |%u|\n", -123);
	printf("%d == %d\n\n", a, b);
	ft_putendl("");

	a =    printf("real %%p: |%p|\n", &a);
	b = ft_printf("mine %%p: |%p|\n", &a);
	printf("%d == %d\n\n", a, b);

	printf("---\n");
	a =    printf("real %%20.18p: |%20.18p|\n", &a);
	b = ft_printf("mine %%20.18p: |%20.18p|\n", &a);
	printf("%d == %d\n\n", a, b);

	a =    printf("real %%20.10p: |%20.10p|\n", &a);
	b = ft_printf("mine %%20.10p: |%20.10p|\n", &a);
	printf("%d == %d\n\n", a, b);

	a =    printf("real %%.10p: |%.10p|\n", &a);
	b = ft_printf("mine %%.10p: |%.10p|\n", &a);
	printf("%d == %d\n\n", a, b);

	printf("\n====================\n\n");
	ft_putendl("-1 signed types");
	a =    printf("real: test hhu |%10hhu|\n", (unsigned char)-1);
	b = ft_printf("mine: test hhu |%10hhu|\n", (unsigned char)-1);
	printf("%d == %d\n\n", a, b);
	ft_putendl("");
	a =    printf("real: test hu  |%10hu|\n", (unsigned short)-1);
	b = ft_printf("mine: test hu  |%10hu|\n", (unsigned short)-1);
	printf("%d == %d\n\n", a, b);
	ft_putendl("");
	a =    printf("real: test u   |%10u|\n", (unsigned int)-1);
	b = ft_printf("mine: test u   |%10u|\n", (unsigned int)-1);
	printf("%d == %d\n\n", a, b);
	ft_putendl("");
	   printf("test:           18446744073709551615\n");
	a =    printf("real: test lu  |%10lu|\n", (unsigned long)-1);
	b = ft_printf("mine: test lu  |%10lu|\n", (unsigned long)-1);
	printf("%d == %d\n\n", a, b);
	ft_putendl("");
	   printf("test:           18446744073709551615\n");
	a =    printf("real: test llu |%10llu|\n", (unsigned long long)-1);
	b = ft_printf("mine: test llu |%10llu|\n", (unsigned long long)-1);
	printf("%d == %d\n\n", a, b);

	ft_putendl("");
	a =    printf("real: test h	%hd\n", -1);
	b = ft_printf("mine: test h	%hd\n", -1);
	printf("%d == %d\n\n", a, b);
	a =    printf("real: test h	%hd\n", (short)-1);
	b = ft_printf("mine: test h	%hd\n", (short)-1);
	printf("%d == %d\n\n", a, b);
	ft_putendl("");
	a =    printf("real: test hh	%hhd\n", -1);
	b = ft_printf("mine: test hh	%hhd\n", -1);
	printf("%d == %d\n\n", a, b);
	a =    printf("real: test hh	%hhd\n", (char)-1);
	b = ft_printf("mine: test hh	%hhd\n", (char)-1);
	printf("%d == %d\n\n", a, b);
	ft_putendl("");
	a =    printf("real: test l	%ld\n", -1);
	b = ft_printf("mine: test l	%ld\n", -1);
	printf("%d == %d\n\n", a, b);
	a =    printf("real: test l	%ld\n", (long)-1);
	b = ft_printf("mine: test l	%ld\n", (long)-1);
	printf("%d == %d\n\n", a, b);
	ft_putendl("");
	a =    printf("real: test ll	%lld\n", -1);
	b = ft_printf("mine: test ll	%lld\n", -1);
	printf("%d == %d\n\n", a, b);
	a =    printf("real: test ll	%lld\n", (long long)-1);
	b = ft_printf("mine: test ll	%lld\n", (long long)-1);
	printf("%d == %d\n\n", a, b);
	ft_putendl("");
	a =    printf("real: undefined test L	%Ld\n", -1);
	b = ft_printf("mine: undefined test L	%Ld\n", -1);
	printf("%d == %d\n\n", a, b);
	a =    printf("real: undefined test L	%Ld\n", (long long)-1);
	b = ft_printf("mine: undefined test L	%Ld\n", (long long)-1);
	printf("%d == %d\n\n", a, b);
	ft_putendl("");
	a =    printf("real: undefined test LL	%LLd\n", -1);
	b = ft_printf("mine: undefined test LL	%LLd\n", -1);
	printf("%d == %d\n\n", a, b);
	a =    printf("real: undefined test LL	%LLd\n", (long long)-1);
	b = ft_printf("mine: undefined test LL	%LLd\n", (long long)-1);
	printf("%d == %d\n\n", a, b);
	ft_putendl("");
	a =    printf("real: undefined test Ll	%Lld\n", -1);
	b = ft_printf("mine: undefined test Ll	%Lld\n", -1);
	printf("%d == %d\n\n", a, b);
	a =    printf("real: undefined test Ll	%Lld\n", (long long)-1);
	b = ft_printf("mine: undefined test Ll	%Lld\n", (long long)-1);
	printf("%d == %d\n\n", a, b);
	ft_putendl("");

	printf("\n====================\n\n");
	ft_putendl("pointers");
	a =    printf("real: |%p| (uint %llu)\n", &a, (unsigned long long)&a);
	b = ft_printf("mine: |%p| (uint %llu)\n", &a, (unsigned long long)&a);
	printf("%d == %d\n\n", a, b);
	ft_putendl("");
	a =    printf("real: |%p| (uint %llu)\n", NULL, NULL);
	b = ft_printf("mine: |%p| (uint %llu)\n", NULL, NULL);
	printf("%d == %d\n\n", a, b);
	ft_putendl("");
	a =    printf("real: |%0.0p| (undefined)\n", &a);
	b = ft_printf("mine: |%0.0p| (undefined)\n", &a);
	printf("%d == %d\n\n", a, b);
	ft_putendl("");
	a =    printf("real: |%20.5p| (undefined)\n", &a);
	b = ft_printf("mine: |%20.5p| (undefined)\n", &a);
	printf("%d == %d\n\n", a, b);
	ft_putendl("");
	a =    printf("real: |%5.20p| (undefined)\n", &a);
	b = ft_printf("mine: |%5.20p| (undefined)\n", &a);
	printf("%d == %d\n\n", a, b);
	ft_putendl("");

	printf("\n====================\n\n");
	ft_putendl("width & precision, positive numbers");
	a =    printf("real: |%20.5d|\n", -123);
	b = ft_printf("mine: |%20.5d|\n", -123);
	printf("%d == %d\n\n", a, b);
	ft_putendl("");

	a =    printf("real: |%*.*d|\n", 20, 5, -123);
	b = ft_printf("mine: |%*.*d|\n", 20, 5, -123);
	printf("%d == %d\n\n", a, b);
	ft_putendl("");

	a =    printf("real: |%20.*d|\n", 5, -123);
	b = ft_printf("mine: |%20.*d|\n", 5, -123);
	printf("%d == %d\n\n", a, b);
	ft_putendl("");

	a =    printf("real: |%*.5d|\n", 20, -123);
	b = ft_printf("mine: |%*.5d|\n", 20, -123);
	printf("%d == %d\n\n", a, b);
	ft_putendl("");

	a =    printf("real: |%20.20d|\n", -123);
	b = ft_printf("mine: |%20.20d|\n", -123);
	printf("%d == %d\n\n", a, b);
	ft_putendl("");

	a =    printf("real: |%*.*d|\n", 20, 20, -123);
	b = ft_printf("mine: |%*.*d|\n", 20, 20, -123);
	printf("%d == %d\n\n", a, b);
	ft_putendl("");

	a =    printf("real: |%20.*d|\n", 20, -123);
	b = ft_printf("mine: |%20.*d|\n", 20, -123);
	printf("%d == %d\n\n", a, b);
	ft_putendl("");

	a =    printf("real: |%*.20d|\n", 20, -123);
	b = ft_printf("mine: |%*.20d|\n", 20, -123);
	printf("%d == %d\n\n", a, b);
	ft_putendl("");


	a =    printf("real: |%20.25d|\n", -123);
	b = ft_printf("mine: |%20.25d|\n", -123);
	printf("%d == %d\n\n", a, b);
	ft_putendl("");

	a =    printf("real: |%*.*d|\n", 20, 25, -123);
	b = ft_printf("mine: |%*.*d|\n", 20, 25, -123);
	printf("%d == %d\n\n", a, b);
	ft_putendl("");

	a =    printf("real: |%20.*d|\n", 25, -123);
	b = ft_printf("mine: |%20.*d|\n", 25, -123);
	printf("%d == %d\n\n", a, b);
	ft_putendl("");

	a =    printf("real: |%*.25d|\n", 20, -123);
	b = ft_printf("mine: |%*.25d|\n", 20, -123);
	printf("%d == %d\n\n", a, b);
	ft_putendl("");

	printf("\n====================\n\n");
	ft_putendl("all decimal types");
	a =    printf("real d: |%.13d|\n", -123);
	b = ft_printf("mine d: |%.13d|\n", -123);
	printf("%d == %d\n\n", a, b);
	ft_putendl("");

	a =    printf("real i: |%.13i|\n", -123);
	b = ft_printf("mine i: |%.13i|\n", -123);
	printf("%d == %d\n\n", a, b);
	ft_putendl("");

	a =    printf("real u: |%.13u|\n", -123);
	b = ft_printf("mine u: |%.13u|\n", -123);
	printf("%d == %d\n\n", a, b);
	ft_putendl("");

	a =    printf("real o: |%.13o|\n", -123);
	b = ft_printf("mine o: |%.13o|\n", -123);
	printf("%d == %d\n\n", a, b);
	ft_putendl("");

	a =    printf("real x: |%.13x|\n", -123);
	b = ft_printf("mine x: |%.13x|\n", -123);
	printf("%d == %d\n\n", a, b);
	ft_putendl("");

	a =    printf("real X: |%.13X|\n", -123);
	b = ft_printf("mine X: |%.13X|\n", -123);
	printf("%d == %d\n\n", a, b);
	ft_putendl("");


	a =    printf("real: |%d|\n", -123);
	b = ft_printf("mine: |%d|\n", -123);
	printf("%d == %d\n\n", a, b);
	ft_putendl("");

// 	printf("\n====================\n\n"); // ? ok
// 	printf("char: '%c'\n", '\0');
// 	printf("digit: '%+ 11.11d'\n", 123);
// 	printf("float1: '%.f'\n", .99);
// 	printf("float2: '%3.0f'\n", 1.0000001);
// 	printf("Hex 0: %0.0X\n", 0);
// 	printf("Oct 0: %0.0o\n", 0);
// 	printf("Hex 15: %2x\n", 15);
// 	ft_putendl("");
//  ft_printf("char: '%c'\n", '\0');
//  ft_printf("digit: '%+ 11.11d'\n", 123);
//  ft_printf("float1: '%.f'\n", .99);
//  ft_printf("float2: '%3.0f'\n", 1.0000001);
//  ft_printf("Hex 0: %0.0X\n", 0);
//  ft_printf("Oct 0: %0.0o\n", 0);
//  ft_printf("Hex 15: %2x\n", 15);

	// printf("'%.0i'\n", 0);
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

	// printf("\n====================\n\n");
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

	// printf("\n====================\n\n");
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

	// printf("\n====================\n\n");
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

	//    printf("\n====================\n\n"); // ? ok
	// ft_putendl("asterisk");
	//    printf("real> %%*s 15 	|%*s|\n", 15, "hello world");
	// ft_printf("mine> %%*s 15 	|%*s|\n", 15, "hello world");
	// ft_putendl("");

	//    printf("real> %%-*s 15 	|%-*s|\n", 15, "hello world");
	// ft_printf("mine> %%-*s 15 	|%-*s|\n", 15, "hello world");
	// ft_putendl("");

	//    printf("real> %%*s -15 	|%*s|\n", -15, "hello world");
	// ft_printf("mine> %%*s -15 	|%*s|\n", -15, "hello world");
	// ft_putendl("");

	//    printf("real> %%-*s -15 	|%-*s|\n", -15, "hello world");
	// ft_printf("mine> %%-*s -15 	|%-*s|\n", -15, "hello world");
	// ft_putendl("");

	//    printf("real> |%s %% %s|\n", "hello", "world");
	// ft_printf("mine> |%s %% %s|\n", "hello", "world");
	// ft_putendl("");


	//    printf("\n====================\n\n");
	// ft_putendl("percentage");
	//    printf("real> |%%|\n");
	// ft_printf("mine> |%%|\n");
	// ft_putendl("");
	//    printf("real> |%10.5%|\n");
	// ft_printf("mine> |%10.5%|\n");


	//    printf("\n====================\n\n");
	// ft_putendl("regular string");
	//    printf("real> |%s, and good night|\n", "hello world");
	// ft_printf("mine> |%s, and good night|\n", "hello world");
	// ft_putendl("");


	//    printf("\n====================\n\n");
	// ft_putendl("null string");
	//    printf("real> |%s, and good night|\n", NULL);
	// ft_printf("mine> |%s, and good night|\n", NULL);
	// ft_putendl("");


	//    printf("\n====================\n\n");
	// ft_putendl("width positive");
	//    printf("real> |%15s, and good night|\n", "hello world");
	// ft_printf("mine> |%15s, and good night|\n", "hello world");
	// ft_putendl("");

	//    printf("real> |%15s, and good night|\n", NULL);
	// ft_printf("mine> |%15s, and good night|\n", NULL);
	// ft_putendl("");

	//    printf("real> |%1s, and good night|\n", "hello world");
	// ft_printf("mine> |%1s, and good night|\n", "hello world");
	// ft_putendl("");

	//    printf("real> |%1s, and good night|\n", NULL);
	// ft_printf("mine> |%1s, and good night|\n", NULL);
	// ft_putendl("");


	//    printf("\n====================\n\n"); // ? ok
	// ft_putendl("left-justified");
	//    printf("real> |%-15s, and good night|\n", "hello world");
	// ft_printf("mine> |%-15s, and good night|\n", "hello world");
	// ft_putendl("");

	//    printf("real> |%-15s, and good night|\n", NULL);
	// ft_printf("mine> |%-15s, and good night|\n", NULL);
	// ft_putendl("");

	//    printf("real> |%-1s, and good night|\n", "hello world");
	// ft_printf("mine> |%-1s, and good night|\n", "hello world");
	// ft_putendl("");

	//    printf("real> |%-1s, and good night|\n", NULL);
	// ft_printf("mine> |%-1s, and good night|\n", NULL);
	// ft_putendl("");

	// printf("\n====================\n\n");
	// printf("precision tests\n");
	//    printf("real> |%-.4s, and good night|\n", "hello world");
	// ft_printf("mine> |%-.4s, and good night|\n", "hello world");
	// ft_putendl(FG_YELLOW "---" TdX_NORMAL);
	// ft_putendl("");
	//    printf("real> |%.4s, and good night|\n", "hello world");
	// ft_printf("mine> |%.4s, and good night|\n", "hello world");
	// ft_putendl(FG_YELLOW "---" TX_NORMAL);
	// ft_putendl("");
	//    printf("real> |%-10.4s, and good night|\n", "hello world");
	// ft_printf("mine> |%-10.4s, and good night|\n", "hello world");
	// ft_putendl(FG_YELLOW "---" TX_NORMAL);
	// ft_putendl("");
	//    printf("real> |%10.4s, and good night|\n", "hello world");
	// ft_printf("mine> |%10.4s, and good night|\n", "hello world");
	// ft_putendl(FG_YELLOW "---" TX_NORMAL);
	// ft_putendl("");
	//    printf("real> |%10.s, and good night|\n", "hello world");
	// ft_printf("mine> |%10.s, and good night|\n", "hello world");
	// ft_putendl("");

	// printf("\n====================\n\n");
	// printf("no print\n");
	// a =    printf("real: '%.0d' '%.0i' '%.0o' '%.0u' '%.0x' '%.0X'\n", 0, 0, 0, 0, 0, 0);
	// b = ft_printf("mine: '%.0d' '%.0i' '%.0o' '%.0u' '%.0x' '%.0X'\n", 0, 0, 0, 0, 0, 0);
	// printf("%d == %d\n\n", a, b);
	// a =    printf("real: '%d' '%i' '%o' '%u' '%x' '%X'\n", 0, 0, 0, 0, 0, 0);
	// b = ft_printf("mine: '%d' '%i' '%o' '%u' '%x' '%X'\n", 0, 0, 0, 0, 0, 0);
	// printf("%d == %d\n\n", a, b);

	printf("\n====================\n\n");
	printf("alt forms\n");
	// For o conversion, it increases the precision to force the first digit of the result to be a zero (if the value and precision are both 0, a single 0 is printed).
	printf("o conversions (no flags)\n");
	printf("real: '%o' '%o' '%o' '%o'\n", 0, 9, 16, 34128);
 ft_printf("mine: '%o' '%o' '%o' '%o'\n", 0, 9, 16, 34128);
	printf("o conversions\n");
	printf("real: '%#o' '%#o' '%#o' '%#o'\n", 0, 9, 16, 34128);
 ft_printf("mine: '%#o' '%#o' '%#o' '%#o'\n", 0, 9, 16, 34128);
	printf("o conversions, 0 precision\n");
	printf("real zero: '%#.0o' '%#.0o' '%#.0o' '%#.0o'\n", 0, 9, 16, 34128);
 ft_printf("mine zero: '%#.0o' '%#.0o' '%#.0o' '%#.0o'\n", 0, 9, 16, 34128);
 printf("\n");

	printf("o conversions (no #)\n");
	printf("real: '%o' '%o' '%o' '%o'\n", 0, 9, 16, 34128);
 ft_printf("mine: '%o' '%o' '%o' '%o'\n", 0, 9, 16, 34128);
	printf("real zero: '%.0o' '%.0o' '%.0o' '%.0o'\n", 0, 9, 16, 34128);
 ft_printf("mine zero: '%.0o' '%.0o' '%.0o' '%.0o'\n", 0, 9, 16, 34128);
	printf("real: '%.5o' '%.5o' '%.5o' '%.5o'\n", 0, 9, 16, 34128);
 ft_printf("mine: '%.5o' '%.5o' '%.5o' '%.5o'\n", 0, 9, 16, 34128);
 printf("\n");

	// For x (or X) conversion, a nonzero result has 0x (or 0X) prefixed to it.
	printf("x conversions (no flags)\n");
	printf("real: '%x' '%x' '%x' '%x'\n", 0, 9, 16, 34128);
 ft_printf("mine: '%x' '%x' '%x' '%x'\n", 0, 9, 16, 34128);
	printf("x conversions\n");
	printf("real: '%#x' '%#x' '%#x' '%#x'\n", 0, 9, 16, 34128);
 ft_printf("mine: '%#x' '%#x' '%#x' '%#x'\n", 0, 9, 16, 34128);
	printf("x conversions, 0 precision\n");
	printf("real zero: '%#.0x' '%#.0x' '%#.0x' '%#.0x'\n", 0, 9, 16, 34128);
 ft_printf("mine zero: '%#.0x' '%#.0x' '%#.0x' '%#.0x'\n", 0, 9, 16, 34128);
	printf("x conversions, 1 precision\n");
	printf("real: '%#.5x' '%#.5x' '%#.5x' '%#.5x'\n", 0, 9, 16, 34128);
 ft_printf("mine: '%#.5x' '%#.5x' '%#.5x' '%#.5x'\n", 0, 9, 16, 34128);
 printf("\n");

	printf("x conversions (no #)\n");
	printf("real: '%x' '%x' '%x' '%x'\n", 0, 9, 16, 34128);
 ft_printf("mine: '%x' '%x' '%x' '%x'\n", 0, 9, 16, 34128);
	printf("real zero: '%.0x' '%.0x' '%.0x' '%.0x'\n", 0, 9, 16, 34128);
 ft_printf("mine zero: '%.0x' '%.0x' '%.0x' '%.0x'\n", 0, 9, 16, 34128);
	printf("real: '%.5x' '%.5x' '%.5x' '%.5x'\n", 0, 9, 16, 34128);
 ft_printf("mine: '%.5x' '%.5x' '%.5x' '%.5x'\n", 0, 9, 16, 34128);
 printf("\n");

	printf("d conversions (no flags)\n");
	printf("real: '%d' '%d' '%d' '%d'\n", 0, 9, 16, 34128);
 ft_printf("mine: '%d' '%d' '%d' '%d'\n", 0, 9, 16, 34128);
	printf("d conversions\n");
	printf("real: '%#d' '%#d' '%#d' '%#d'\n", 0, 9, 16, 34128);
 ft_printf("mine: '%#d' '%#d' '%#d' '%#d'\n", 0, 9, 16, 34128);
	printf("d conversions, 0 precision\n");
	printf("real: '%#.0d' '%#.0d' '%#.0d' '%#.0d'\n", 0, 9, 16, 34128);
 ft_printf("mine: '%#.0d' '%#.0d' '%#.0d' '%#.0d'\n", 0, 9, 16, 34128);
 printf("\n");

	printf("d conversions (no #)\n");
	printf("real: '%d' '%d' '%d' '%d'\n", 0, 9, 16, 34128);
 ft_printf("mine: '%d' '%d' '%d' '%d'\n", 0, 9, 16, 34128);
	printf("real zero: '%.0d' '%.0d' '%.0d' '%.0d'\n", 0, 9, 16, 34128);
 ft_printf("mine zero: '%.0d' '%.0d' '%.0d' '%.0d'\n", 0, 9, 16, 34128);
	printf("real: '%.5d' '%.5d' '%.5d' '%.5d'\n", 0, 9, 16, 34128);
 ft_printf("mine: '%.5d' '%.5d' '%.5d' '%.5d'\n", 0, 9, 16, 34128);
 printf("\n");

	// For a, A, e, E, f, F, g, and G conversions, the result of converting a floating-point number always contains a decimal-point wide character, even if no digits follow it.
	// (Normally, a decimal-point wide character appears in the result of these conversions only if a digit follows it.)
		printf("f conversions (no flags)\n");
	printf("real: '%f' '%f' '%f' '%f'\n", 0.0, 9.0, 16.0, 34128.0);
 ft_printf("mine: '%f' '%f' '%f' '%f'\n", 0.0, 9.0, 16.0, 34128.0);
	printf("f conversions\n");
	printf("real: '%#f' '%#f' '%#f' '%#f'\n", 0.0, 9.0, 16.0, 34128.0);
 ft_printf("mine: '%#f' '%#f' '%#f' '%#f'\n", 0.0, 9.0, 16.0, 34128.0);
	printf("f conversions, 0 precision\n");
	printf("real: '%#.0f' '%#.0f' '%#.0f' '%#.0f'\n", 0.0, 9.0, 16.0, 34128.0);
 ft_printf("mine: '%#.0f' '%#.0f' '%#.0f' '%#.0f'\n", 0.0, 9.0, 16.0, 34128.0);
 printf("\n");

	printf("f conversions (no #)\n");
	printf("real: '%f' '%f' '%f' '%f'\n", 0.0, 9.0, 16.0, 34128.0);
 ft_printf("mine: '%f' '%f' '%f' '%f'\n", 0.0, 9.0, 16.0, 34128.0);
	printf("real zero: '%.0f' '%.0f' '%.0f' '%.0f'\n", 0.0, 9.0, 16.0, 34128.0);
 ft_printf("mine zero: '%.0f' '%.0f' '%.0f' '%.0f'\n", 0.0, 9.0, 16.0, 34128.0);
	printf("real: '%.5f' '%.5f' '%.5f' '%.5f'\n", 0.0, 9.0, 16.0, 34128.0);
 ft_printf("mine: '%.5f' '%.5f' '%.5f' '%.5f'\n", 0.0, 9.0, 16.0, 34128.0);
 printf("\n");

	// todo:
	// For d, i, o, u, x, X, a, A, e, E, f, F, g, and G conversions, leading zeros (following any indication of sign or base)
	// are used to pad to the field width rather than performing space padding, except when converting an infinity or NaN.
	// If the 0 and - flags both appear, the 0 flag is ignored.
	// For d, i, o, u, x, and X conversions, if a precision is specified, the 0 flag is ignored.
	// For other conversions, the behavior is undefined.
	// printf("\n====================\n\n");
	//    printf("real: |%#10.5x|\n", 1);
	// ft_printf("mine: |%010.5d|\n", 1);
	//    printf("real: |%#10.5x|\n", 0);
	// ft_printf("mine: |%010.5d|\n", 0);
	// ft_putendl("");
	//    printf("real: |%#5.10x|\n", 1);
	// ft_printf("mine: |%05.10d|\n", 1);
	//    printf("real: |%#5.10x|\n", 0);
	// ft_printf("mine: |%05.10d|\n", 0);
	// ft_putendl("");
	//    printf("real: |%01.0d|\n", 1);
	// ft_printf("mine: |%01.0d|\n", 1);
	//    printf("real: |%01.0d|\n", 0);
	// ft_printf("mine: |%01.0d|\n", 0);
	// ft_putendl("");

	// printf("\n====================\n\n"); // ? ok
	//    printf("%.0u\n", 5592);
	// ft_printf("%.0u\n", 5592);
	// ft_putendl("");
	//    printf("%.1u\n", 5592);
	// ft_printf("%.1u\n", 5592);
	// ft_putendl("");
	//    printf("%.10u\n", 5592);
	// ft_printf("%.10u\n", 5592);
	// ft_putendl("");
}