#include "ft_printf.h"
#include <assert.h>

int			main(int argc, char **argv)
{
	(void)argc; (void)argv;
	int a, b;

	// printf("String format:\n");
	// printf("\nbasic: (no flags, empty string, null string)\n");
	// a =    printf("real: |%s|\n", "Hello world!");
	// b = ft_printf("mine: |%s|\n", "Hello world!");
	// assert(a == b);
	// a =    printf("real: |%s|\n", "");
	// b = ft_printf("mine: |%s|\n", "");
	// assert(a == b);
	// a =    printf("real: |%s|\n", NULL);
	// b = ft_printf("mine: |%s|\n", NULL);
	// assert(a == b);

	// printf("\nwidth (greater, smaller, equal, zero)\n");
	// a =    printf("real: |%20s|\n", "Hello world!");
	// b = ft_printf("mine: |%20s|\n", "Hello world!");
	// assert(a == b);
	// a =    printf("real: |%5s|\n", "Hello world!");
	// b = ft_printf("mine: |%5s|\n", "Hello world!");
	// assert(a == b);
	// a =    printf("real: |%12s|\n", "Hello world!");
	// b = ft_printf("mine: |%12s|\n", "Hello world!");
	// assert(a == b);
	// a =    printf("real: |%s|\n", "Hello world!");
	// b = ft_printf("mine: |%s|\n", "Hello world!");
	// assert(a == b);

	// printf("\nwidth (flags: -)\n");
	// a =    printf("real: |%-20s|\n", "Hello world!");
	// b = ft_printf("mine: |%-20s|\n", "Hello world!");
	// assert(a == b);
	// a =    printf("real: |%-5s|\n", "Hello world!");
	// b = ft_printf("mine: |%-5s|\n", "Hello world!");
	// assert(a == b);
	// a =    printf("real: |%-12s|\n", "Hello world!");
	// b = ft_printf("mine: |%-12s|\n", "Hello world!");
	// assert(a == b);
	// a =    printf("real: |%-s|\n", "Hello world!");
	// b = ft_printf("mine: |%-s|\n", "Hello world!");
	// assert(a == b);

	// printf("\nprecision (greater, smaller, equal, zero)\n");
	// a =    printf("real: |%.20s|\n", "Hello world!");
	// b = ft_printf("mine: |%.20s|\n", "Hello world!");
	// assert(a == b);
	// a =    printf("real: |%.5s|\n", "Hello world!");
	// b = ft_printf("mine: |%.5s|\n", "Hello world!");
	// assert(a == b);
	// a =    printf("real: |%.12s|\n", "Hello world!");
	// b = ft_printf("mine: |%.12s|\n", "Hello world!");
	// assert(a == b);
	// a =    printf("real: |%.0s|\n", "Hello world!");
	// b = ft_printf("mine: |%.0s|\n", "Hello world!");
	// assert(a == b);

	// printf("\nprecision (flags: -)\n");
	// a =    printf("real: |%-.20s|\n", "Hello world!");
	// b = ft_printf("mine: |%-.20s|\n", "Hello world!");
	// assert(a == b);
	// a =    printf("real: |%-.5s|\n", "Hello world!");
	// b = ft_printf("mine: |%-.5s|\n", "Hello world!");
	// assert(a == b);
	// a =    printf("real: |%-.12s|\n", "Hello world!");
	// b = ft_printf("mine: |%-.12s|\n", "Hello world!");
	// assert(a == b);
	// a =    printf("real: |%-.0s|\n", "Hello world!");
	// b = ft_printf("mine: |%-.0s|\n", "Hello world!");
	// assert(a == b);

	// printf("\nwidth & precision (greater, smaller, equal x2, zero)\n");
	// a =    printf("real: |%20.5s|\n", "Hello world!");
	// b = ft_printf("mine: |%20.5s|\n", "Hello world!");
	// assert(a == b);
	// a =    printf("real: |%5.20s|\n", "Hello world!");
	// b = ft_printf("mine: |%5.20s|\n", "Hello world!");
	// assert(a == b);
	// a =    printf("real: |%5.5s|\n", "Hello world!");
	// b = ft_printf("mine: |%5.5s|\n", "Hello world!");
	// assert(a == b);
	// a =    printf("real: |%15.15s|\n", "Hello world!");
	// b = ft_printf("mine: |%15.15s|\n", "Hello world!");
	// assert(a == b);
	// a =    printf("real: |%.0s|\n", "Hello world!");
	// b = ft_printf("mine: |%.0s|\n", "Hello world!");
	// assert(a == b);

	// printf("\n===========================\n");
	// printf("===========================  \n");
	// printf("===========================\n\n");

	// printf("Pointer format:\n");
	// printf("\nbasic: (no flags, null, address)\n");
	// a =    printf("real: |%p|\n", NULL);
	// b = ft_printf("mine: |%p|\n", NULL);
	// // printf("%d == %d\n", a, b); // note: Differs on Mac/Ubuntu
	// assert(a == b);
	// a =    printf("real: |%p|\n", &a);
	// b = ft_printf("mine: |%p|\n", &a);
	// assert(a == b);

	// printf("\nwidth (greater, smaller, equal)\n");
	// a =    printf("real: |%20p|\n", NULL);
	// b = ft_printf("mine: |%20p|\n", NULL);
	// assert(a == b);
	// a =    printf("real: |%20p|\n", &a);
	// b = ft_printf("mine: |%20p|\n", &a);
	// assert(a == b);
	// printf("\n");

	// a =    printf("real: |%2p|\n", NULL);
	// b = ft_printf("mine: |%2p|\n", NULL);
	// assert(a == b);
	// a =    printf("real: |%2p|\n", &a);
	// b = ft_printf("mine: |%2p|\n", &a);
	// assert(a == b);
	// printf("\n");

	// a =    printf("real: |%5p|\n", NULL);
	// b = ft_printf("mine: |%5p|\n", NULL);
	// assert(a == b);
	// a =    printf("real: |%14p|\n", &a);
	// b = ft_printf("mine: |%14p|\n", &a);
	// assert(a == b);

	// printf("\nwidth (flags: -)\n");
	// a =    printf("real: |%-20p|\n", NULL);
	// b = ft_printf("mine: |%-20p|\n", NULL);
	// assert(a == b);
	// a =    printf("real: |%-20p|\n", &a);
	// b = ft_printf("mine: |%-20p|\n", &a);
	// assert(a == b);
	// printf("\n");

	// a =    printf("real: |%-2p|\n", NULL);
	// b = ft_printf("mine: |%-2p|\n", NULL);
	// assert(a == b);
	// a =    printf("real: |%-2p|\n", &a);
	// b = ft_printf("mine: |%-2p|\n", &a);
	// assert(a == b);
	// printf("\n");

	// a =    printf("real: |%-5p|\n", NULL);
	// b = ft_printf("mine: |%-5p|\n", NULL);
	// assert(a == b);
	// a =    printf("real: |%-14p|\n", &a);
	// b = ft_printf("mine: |%-14p|\n", &a);
	// assert(a == b);

	// printf("\nShort pointer value\n");
	// a =    printf("real: |%p|\n", 57005);
	// b = ft_printf("mine: |%p|\n", 57005);
	// assert(a == b);
	// a =    printf("real: |%.3p|\n", 57005);
	// b = ft_printf("mine: |%.3p|\n", 57005);
	// assert(a == b);
	// a =    printf("real: |%.8p|\n", 57005);
	// b = ft_printf("mine: |%.8p|\n", 57005);
	// assert(a == b);
	// printf("\nShort pointer value (- flag)\n");
	// a =    printf("real: |%-p|\n", 57005);
	// b = ft_printf("mine: |%-p|\n", 57005);
	// assert(a == b);
	// a =    printf("real: |%-.3p|\n", 57005);
	// b = ft_printf("mine: |%-.3p|\n", 57005);
	// assert(a == b);
	// a =    printf("real: |%-.8p|\n", 57005);
	// b = ft_printf("mine: |%-.8p|\n", 57005);
	// assert(a == b);

	// printf("\n===========================\n");
	// printf("===========================  \n");
	// printf("===========================\n\n");

	// printf("Character format\n");
	// printf("\nbasic: (no flags)\n");
	// a =    printf("real: |%c|\n", '@');
	// b = ft_printf("mine: |%c|\n", '@');
	// assert(a == b);
	// printf("\n");

	// printf("\nwidth (greater, equal)\n");
	// a =    printf("real: |%5c|\n", '@');
	// b = ft_printf("mine: |%5c|\n", '@');
	// assert(a == b);
	// a =    printf("real: |%1c|\n", '@');
	// b = ft_printf("mine: |%1c|\n", '@');
	// assert(a == b);
	// printf("\n");

	// printf("\nwidth (flags: -)\n");
	// a =    printf("real: |%-5c|\n", '@');
	// b = ft_printf("mine: |%-5c|\n", '@');
	// assert(a == b);
	// a =    printf("real: |%-1c|\n", '@');
	// b = ft_printf("mine: |%-1c|\n", '@');
	// assert(a == b);
	// printf("\n");

	// printf("\n===========================\n");
	// printf("===========================  \n");
	// printf("===========================\n\n");

	// printf("Integer formats:\n");
	// printf("\ndefault: (no flags)\n");
	// printf("\n0:\n");
	// a =    printf("real: |%d|\n", 0);
	// b = ft_printf("mine: |%d|\n", 0);
	// assert(a == b);
	// a =    printf("real: |%5.0d|\n", 0);
	// b = ft_printf("mine: |%5.0d|\n", 0);
	// assert(a == b);

	// printf("\n-1:\n");
	// a =    printf("real: |%d|\n", -1);
	// b = ft_printf("mine: |%d|\n", -1);
	// assert(a == b);

	// printf("\nMAX_INT:\n");
	// a =    printf("real: |%d|\n", MAX_INT);
	// b = ft_printf("mine: |%d|\n", MAX_INT);
	// assert(a == b);

	// printf("\nMIN_INT:\n");
	// a =    printf("real: |%d|\n", MIN_INT);
	// b = ft_printf("mine: |%d|\n", MIN_INT);
	// assert(a == b);

	// printf("\nprecison == 0\n");
	// a =    printf("real: |%.0d|\n", 0);
	// b = ft_printf("mine: |%.0d|\n", 0);
	// assert(a == b);
	// a =    printf("real: |%.0d|\n", 1);
	// b = ft_printf("mine: |%.0d|\n", 1);
	// assert(a == b);
	// a =    printf("real: |%.0d|\n", -123);
	// b = ft_printf("mine: |%.0d|\n", -123);
	// assert(a == b);

	// printf("\nwidth: (greater)\n");
	// printf("\n0:\n");
	// a =    printf("real: |%15d|\n", 0);
	// b = ft_printf("mine: |%15d|\n", 0);
	// assert(a == b);

	// printf("\n-1:\n");
	// a =    printf("real: |%15d|\n", -1);
	// b = ft_printf("mine: |%15d|\n", -1);
	// assert(a == b);

	// printf("\nMAX_INT:\n");
	// a =    printf("real: |%15d|\n", MAX_INT);
	// b = ft_printf("mine: |%15d|\n", MAX_INT);
	// assert(a == b);

	// printf("\nMIN_INT:\n");
	// a =    printf("real: |%15d|\n", MIN_INT);
	// b = ft_printf("mine: |%15d|\n", MIN_INT);
	// assert(a == b);

	// printf("\nwidth: (1)\n");
	// printf("\n0:\n");
	// a =    printf("real: |%1d|\n", 0);
	// b = ft_printf("mine: |%1d|\n", 0);
	// assert(a == b);

	// printf("\n-1:\n");
	// a =    printf("real: |%1d|\n", -1);
	// b = ft_printf("mine: |%1d|\n", -1);
	// assert(a == b);

	// printf("\nMAX_INT:\n");
	// a =    printf("real: |%1d|\n", MAX_INT);
	// b = ft_printf("mine: |%1d|\n", MAX_INT);
	// assert(a == b);

	// printf("\nMIN_INT:\n");
	// a =    printf("real: |%1d|\n", MIN_INT);
	// b = ft_printf("mine: |%1d|\n", MIN_INT);
	// assert(a == b);

	// printf("\nwidth: (equal)\n");
	// printf("\n0:\n");
	// a =    printf("real: |%1d|\n", 0);
	// b = ft_printf("mine: |%1d|\n", 0);
	// assert(a == b);

	// printf("\n-1:\n");
	// a =    printf("real: |%2d|\n", -1);
	// b = ft_printf("mine: |%2d|\n", -1);
	// assert(a == b);

	// printf("\nMAX_INT:\n");
	// a =    printf("real: |%10d|\n", MAX_INT);
	// b = ft_printf("mine: |%10d|\n", MAX_INT);
	// assert(a == b);

	// printf("\nMIN_INT:\n");
	// a =    printf("real: |%11d|\n", MIN_INT);
	// b = ft_printf("mine: |%11d|\n", MIN_INT);
	// assert(a == b);
	// printf("\nwidth: (- flag, greater)\n");
	// printf("\n0:\n");
	// a =    printf("real: |%-15d|\n", 0);
	// b = ft_printf("mine: |%-15d|\n", 0);
	// assert(a == b);

	// printf("\n-1:\n");
	// a =    printf("real: |%-15d|\n", -1);
	// b = ft_printf("mine: |%-15d|\n", -1);
	// assert(a == b);

	// printf("\nMAX_INT:\n");
	// a =    printf("real: |%-15d|\n", MAX_INT);
	// b = ft_printf("mine: |%-15d|\n", MAX_INT);
	// assert(a == b);

	// printf("\nMIN_INT:\n");
	// a =    printf("real: |%-15d|\n", MIN_INT);
	// b = ft_printf("mine: |%-15d|\n", MIN_INT);
	// assert(a == b);

	// printf("\nwidth: (- flag, 1)\n");
	// printf("\n0:\n");
	// a =    printf("real: |%-1d|\n", 0);
	// b = ft_printf("mine: |%-1d|\n", 0);
	// assert(a == b);

	// printf("\n-1:\n");
	// a =    printf("real: |%-1d|\n", -1);
	// b = ft_printf("mine: |%-1d|\n", -1);
	// assert(a == b);

	// printf("\nMAX_INT:\n");
	// a =    printf("real: |%-1d|\n", MAX_INT);
	// b = ft_printf("mine: |%-1d|\n", MAX_INT);
	// assert(a == b);

	// printf("\nMIN_INT:\n");
	// a =    printf("real: |%-1d|\n", MIN_INT);
	// b = ft_printf("mine: |%-1d|\n", MIN_INT);
	// assert(a == b);

	// printf("\nwidth: (- flag, equal)\n");
	// printf("\n0:\n");
	// a =    printf("real: |%-1d|\n", 0);
	// b = ft_printf("mine: |%-1d|\n", 0);
	// assert(a == b);

	// printf("\n-1:\n");
	// a =    printf("real: |%-2d|\n", -1);
	// b = ft_printf("mine: |%-2d|\n", -1);
	// assert(a == b);

	// printf("\nMAX_INT:\n");
	// a =    printf("real: |%-10d|\n", MAX_INT);
	// b = ft_printf("mine: |%-10d|\n", MAX_INT);
	// assert(a == b);

	// printf("\nMIN_INT:\n");
	// a =    printf("real: |%-11d|\n", MIN_INT);
	// b = ft_printf("mine: |%-11d|\n", MIN_INT);
	// assert(a == b);

	// printf("\n+ flag\n");
	// printf("\npositive (greater width)\n");
	// a =    printf("real: |%+5d|\n", 123);
	// b = ft_printf("mine: |%+5d|\n", 123);
	// assert(a == b);

	// printf("\npositive (equal width)\n");
	// a =    printf("real: |%+3d|\n", 123);
	// b = ft_printf("mine: |%+3d|\n", 123);
	// assert(a == b);

	// printf("\npositive (no width)\n");
	// a =    printf("real: |%+d|\n", 123);
	// b = ft_printf("mine: |%+d|\n", 123);
	// assert(a == b);

	// printf("\nzero (no width)\n");
	// a =    printf("real: |%+d|\n", 0);
	// b = ft_printf("mine: |%+d|\n", 0);
	// assert(a == b);

	// printf("\nnegative (greater width)\n");
	// a =    printf("real: |%+5d|\n", -123);
	// b = ft_printf("mine: |%+5d|\n", -123);
	// assert(a == b);

	// printf("\nnegative (equal width)\n");
	// a =    printf("real: |%+3d|\n", -123);
	// b = ft_printf("mine: |%+3d|\n", -123);
	// assert(a == b);

	// printf("\nnegative (no width)\n");
	// a =    printf("real: |%+d|\n", -123);
	// b = ft_printf("mine: |%+d|\n", -123);
	// assert(a == b);

	// printf("\n+ flag (precision > width)\n");
	// a =    printf("real: |%+.15d|\n", MIN_INT); // |-000002147483648|
	// b = ft_printf("mine: |%+.15d|\n", MIN_INT);
	// assert(a == b);

	// printf("\n+ flag (precision < width)\n");
	// a =    printf("real: |%+20.15d|\n", MIN_INT); // |    -000002147483648|
	// b = ft_printf("mine: |%+20.15d|\n", MIN_INT);
	// assert(a == b);

	// printf("\n+ flag ((precision == width) < length)\n");
	// a =    printf("real: |%+5.5d|\n", MIN_INT); // |-2147483648|
	// b = ft_printf("mine: |%+5.5d|\n", MIN_INT);
	// assert(a == b);

	// printf("\n' ' flag, negative (precision > width)\n");
	// a =    printf("real: |% .15d|\n", MIN_INT);
	// b = ft_printf("mine: |% .15d|\n", MIN_INT);
	// assert(a == b);

	// printf("\n' ' flag, negative (precision < width)\n");
	// a =    printf("real: |% 20.15d|\n", MIN_INT);
	// b = ft_printf("mine: |% 20.15d|\n", MIN_INT);
	// assert(a == b);

	// printf("\n' ' flag, negative ((precision == width) < length)\n");
	// a =    printf("real: |% 5.5d|\n", MIN_INT);
	// b = ft_printf("mine: |% 5.5d|\n", MIN_INT);
	// assert(a == b);


	// printf("\n' ' flag, positive (precision > width)\n");
	// a =    printf("real: |% .15d|\n", 1);
	// b = ft_printf("mine: |% .15d|\n", 1);
	// assert(a == b);

	// printf("\n' ' flag, positive (precision < width)\n");
	// a =    printf("real: |% 20.15d|\n", 1);
	// b = ft_printf("mine: |% 20.15d|\n", 1);
	// assert(a == b);

	// printf("\n' ' flag, positive ((precision == width) > length)\n");
	// a =    printf("real: |% 5.5d|\n", 1);
	// b = ft_printf("mine: |% 5.5d|\n", 1);
	// assert(a == b);

	// printf("\n' ' flag, positive ((precision == width) < length)\n");
	// a =    printf("real: |% 2.2d|\n", 123);
	// b = ft_printf("mine: |% 2.2d|\n", 123);
	// assert(a == b);

	// printf("\n%% +5.5d\n");
	// a =    printf("real: |% +5.5d|\n", 1);
	// b = ft_printf("mine: |% +5.5d|\n", 1);
	// assert(a == b);

	// printf("\n%% +15.5d\n");
	// a =    printf("real: |% +15.5d|\n", 1);
	// b = ft_printf("mine: |% +15.5d|\n", 1);
	// assert(a == b);

	// printf("\n%% +5.15d\n");
	// a =    printf("real: |% +5.15d|\n", 1);
	// b = ft_printf("mine: |% +5.15d|\n", 1);
	// assert(a == b);

	// printf("\n0 flag, negative (width)\n");
	// a =    printf("real: |%010d|\n", -123);    // |-000000123|  // 10
	// b = ft_printf("mine: |%010d|\n", -123);
	// assert(a == b);

	// printf("\n0 flag, negative (precision > width)\n");
	// a =    printf("real: |%01.10d|\n", -123);  // |-0000000123| // 11
	// b = ft_printf("mine: |%01.10d|\n", -123);
	// assert(a == b);

	// printf("\n0 flag, negative ((precision == width) > length)\n");
	// a =    printf("real: |%010.10d|\n", -123); // |-0000000123| // 11
	// b = ft_printf("mine: |%010.10d|\n", -123);
	// assert(a == b);

	// printf("\n0 flag, negative ((precision == width) < length)\n");
	// a =    printf("real: |%02.2d|\n", -123); // |-0000000123| // 11
	// b = ft_printf("mine: |%02.2d|\n", -123);
	// assert(a == b);

	// printf("\n0 flag, negative (precision < width)\n");
	// a =    printf("real: |%010.5d|\n", -123);  // |    -00123|  // 10
	// b = ft_printf("mine: |%010.5d|\n", -123);
	// assert(a == b);

	// printf("\n===========================\n");

	// printf("\nInteger format (negative flag)\n");
	// printf("\n0:\n");
	// a =    printf("real: |%-d|\n", 0);
	// b = ft_printf("mine: |%-d|\n", 0);
	// assert(a == b);
	// a =    printf("real: |%-5.0d|\n", 0);
	// b = ft_printf("mine: |%-5.0d|\n", 0);
	// assert(a == b);

	// printf("\n-1:\n");
	// a =    printf("real: |%-d|\n", -1);
	// b = ft_printf("mine: |%-d|\n", -1);
	// assert(a == b);

	// printf("\nMAX_INT:\n");
	// a =    printf("real: |%-d|\n", MAX_INT);
	// b = ft_printf("mine: |%-d|\n", MAX_INT);
	// assert(a == b);

	// printf("\nMIN_INT:\n");
	// a =    printf("real: |%-d|\n", MIN_INT);
	// b = ft_printf("mine: |%-d|\n", MIN_INT);
	// assert(a == b);

	// printf("\nprecison == 0\n");
	// a =    printf("real: |%-.0d|\n", 0);
	// b = ft_printf("mine: |%-.0d|\n", 0);
	// assert(a == b);
	// a =    printf("real: |%-.0d|\n", 1);
	// b = ft_printf("mine: |%-.0d|\n", 1);
	// assert(a == b);
	// a =    printf("real: |%-.0d|\n", -123);
	// b = ft_printf("mine: |%-.0d|\n", -123);
	// assert(a == b);

	// printf("\nwidth: (greater)\n");
	// printf("\n0:\n");
	// a =    printf("real: |%-15d|\n", 0);
	// b = ft_printf("mine: |%-15d|\n", 0);
	// assert(a == b);

	// printf("\n-1:\n");
	// a =    printf("real: |%-15d|\n", -1);
	// b = ft_printf("mine: |%-15d|\n", -1);
	// assert(a == b);

	// printf("\nMAX_INT:\n");
	// a =    printf("real: |%-15d|\n", MAX_INT);
	// b = ft_printf("mine: |%-15d|\n", MAX_INT);
	// assert(a == b);

	// printf("\nMIN_INT:\n");
	// a =    printf("real: |%-15d|\n", MIN_INT);
	// b = ft_printf("mine: |%-15d|\n", MIN_INT);
	// assert(a == b);

	// printf("\nwidth: (1)\n");
	// printf("\n0:\n");
	// a =    printf("real: |%-1d|\n", 0);
	// b = ft_printf("mine: |%-1d|\n", 0);
	// assert(a == b);

	// printf("\n-1:\n");
	// a =    printf("real: |%-1d|\n", -1);
	// b = ft_printf("mine: |%-1d|\n", -1);
	// assert(a == b);

	// printf("\nMAX_INT:\n");
	// a =    printf("real: |%-1d|\n", MAX_INT);
	// b = ft_printf("mine: |%-1d|\n", MAX_INT);
	// assert(a == b);

	// printf("\nMIN_INT:\n");
	// a =    printf("real: |%-1d|\n", MIN_INT);
	// b = ft_printf("mine: |%-1d|\n", MIN_INT);
	// assert(a == b);

	// printf("\nwidth: (equal)\n");
	// printf("\n0:\n");
	// a =    printf("real: |%-1d|\n", 0);
	// b = ft_printf("mine: |%-1d|\n", 0);
	// assert(a == b);

	// printf("\n-1:\n");
	// a =    printf("real: |%-2d|\n", -1);
	// b = ft_printf("mine: |%-2d|\n", -1);
	// assert(a == b);

	// printf("\nMAX_INT:\n");
	// a =    printf("real: |%-10d|\n", MAX_INT);
	// b = ft_printf("mine: |%-10d|\n", MAX_INT);
	// assert(a == b);

	// printf("\nMIN_INT:\n");
	// a =    printf("real: |%-11d|\n", MIN_INT);
	// b = ft_printf("mine: |%-11d|\n", MIN_INT);
	// assert(a == b);

	// printf("\n+ flag\n");
	// printf("\npositive (greater width)\n");
	// a =    printf("real: |%-+5d|\n", 123);
	// b = ft_printf("mine: |%-+5d|\n", 123);
	// assert(a == b);

	// printf("\npositive (equal width)\n");
	// a =    printf("real: |%-+3d|\n", 123);
	// b = ft_printf("mine: |%-+3d|\n", 123);
	// assert(a == b);

	// printf("\npositive (no width)\n");
	// a =    printf("real: |%-+d|\n", 123);
	// b = ft_printf("mine: |%-+d|\n", 123);
	// assert(a == b);

	// printf("\nzero (no width)\n");
	// a =    printf("real: |%-+d|\n", 0);
	// b = ft_printf("mine: |%-+d|\n", 0);
	// assert(a == b);

	// printf("\nnegative (greater width)\n");
	// a =    printf("real: |%-+5d|\n", -123);
	// b = ft_printf("mine: |%-+5d|\n", -123);
	// assert(a == b);

	// printf("\nnegative (equal width)\n");
	// a =    printf("real: |%-+3d|\n", -123);
	// b = ft_printf("mine: |%-+3d|\n", -123);
	// assert(a == b);

	// printf("\nnegative (no width)\n");
	// a =    printf("real: |%-+d|\n", -123);
	// b = ft_printf("mine: |%-+d|\n", -123);
	// assert(a == b);

	// printf("\n+ flag (precision > width)\n");
	// a =    printf("real: |%-+.15d|\n", MIN_INT);
	// b = ft_printf("mine: |%-+.15d|\n", MIN_INT);
	// assert(a == b);

	// printf("\n+ flag (precision < width)\n");
	// a =    printf("real: |%-+20.15d|\n", MIN_INT);
	// b = ft_printf("mine: |%-+20.15d|\n", MIN_INT);
	// assert(a == b);

	// printf("\n+ flag ((precision == width) < length)\n");
	// a =    printf("real: |%-+5.5d|\n", MIN_INT);
	// b = ft_printf("mine: |%-+5.5d|\n", MIN_INT);
	// assert(a == b);

	// printf("\n' ' flag, negative (precision > width)\n");
	// a =    printf("real: |%- .15d|\n", MIN_INT);
	// b = ft_printf("mine: |%- .15d|\n", MIN_INT);
	// assert(a == b);

	// printf("\n' ' flag, negative (precision < width)\n");
	// a =    printf("real: |%- 20.15d|\n", MIN_INT);
	// b = ft_printf("mine: |%- 20.15d|\n", MIN_INT);
	// assert(a == b);

	// printf("\n' ' flag, negative ((precision == width) < length)\n");
	// a =    printf("real: |%- 5.5d|\n", MIN_INT);
	// b = ft_printf("mine: |%- 5.5d|\n", MIN_INT);
	// assert(a == b);

	// printf("\n' ' flag, positive (precision > width)\n");
	// a =    printf("real: |%- .15d|\n", 1);
	// b = ft_printf("mine: |%- .15d|\n", 1);
	// assert(a == b);

	// printf("\n' ' flag, positive (precision < width)\n");
	// a =    printf("real: |%- 20.15d|\n", 1);
	// b = ft_printf("mine: |%- 20.15d|\n", 1);
	// assert(a == b);

	// printf("\n' ' flag, positive ((precision == width) > length)\n");
	// a =    printf("real: |%- 5.5d|\n", 1);
	// b = ft_printf("mine: |%- 5.5d|\n", 1);
	// assert(a == b);

	// printf("\n' ' flag, positive ((precision == width) < length)\n");
	// a =    printf("real: |%- 2.2d|\n", 123);
	// b = ft_printf("mine: |%- 2.2d|\n", 123);
	// assert(a == b);

	// printf("\n%% +5.5d\n");
	// a =    printf("real: |%- +5.5d|\n", 1);
	// b = ft_printf("mine: |%- +5.5d|\n", 1);
	// assert(a == b);

	// printf("\n%% +15.5d\n");
	// a =    printf("real: |%- +15.5d|\n", 1);
	// b = ft_printf("mine: |%- +15.5d|\n", 1);
	// assert(a == b);

	// printf("\n%% +5.15d\n");
	// a =    printf("real: |%- +5.15d|\n", 1);
	// b = ft_printf("mine: |%- +5.15d|\n", 1);
	// assert(a == b);

	// printf("\n-0 flag, negative (width)\n");
	// a =    printf("real: |%-010d|\n", -123);
	// b = ft_printf("mine: |%-010d|\n", -123);
	// assert(a == b);

	// printf("\n-0 flag, negative (precision > width)\n");
	// a =    printf("real: |%-01.10d|\n", -123);
	// b = ft_printf("mine: |%-01.10d|\n", -123);
	// assert(a == b);

	// printf("\n-0 flag, negative ((precision == width) > length)\n");
	// a =    printf("real: |%-010.10d|\n", -123);
	// b = ft_printf("mine: |%-010.10d|\n", -123);
	// assert(a == b);

	// printf("\n-0 flag, negative ((precision == width) < length)\n");
	// a =    printf("real: |%-02.2d|\n", -123);
	// b = ft_printf("mine: |%-02.2d|\n", -123);
	// assert(a == b);

	// printf("\n-0 flag, negative (precision < width)\n");
	// a =    printf("real: |%-010.5d|\n", -123);
	// b = ft_printf("mine: |%-010.5d|\n", -123);
	// assert(a == b);

	// printf("\n===========================\n");
	// printf("===========================  \n");
	// printf("===========================\n\n");

	// printf("Hexadecimal format\n");
	// printf("\ndefault: (no flags)\n");
	// printf("\n0:\n");
	// a =    printf("real: |%x|\n", 0);
	// b = ft_printf("mine: |%x|\n", 0);
	// assert(a == b);
	// a =    printf("real: |%5.0x|\n", 0);
	// b = ft_printf("mine: |%5.0x|\n", 0);
	// assert(a == b);

	// printf("\n-1:\n");
	// a =    printf("real: |%x|\n", -1);
	// b = ft_printf("mine: |%x|\n", -1);
	// assert(a == b);

	// printf("\nMAX_INT:\n");
	// a =    printf("real: |%x|\n", MAX_INT);
	// b = ft_printf("mine: |%x|\n", MAX_INT);
	// assert(a == b);

	// printf("\nMIN_INT:\n");
	// a =    printf("real: |%x|\n", MIN_INT);
	// b = ft_printf("mine: |%x|\n", MIN_INT);
	// assert(a == b);

	// printf("\nprecison == 0\n");
	// a =    printf("real: |%.0x|\n", 0);
	// b = ft_printf("mine: |%.0x|\n", 0);
	// assert(a == b);
	// a =    printf("real: |%.0x|\n", 1);
	// b = ft_printf("mine: |%.0x|\n", 1);
	// assert(a == b);
	// a =    printf("real: |%.0x|\n", -123);
	// b = ft_printf("mine: |%.0x|\n", -123);
	// assert(a == b);

	// printf("\nwidth: (greater)\n");
	// printf("\n0:\n");
	// a =    printf("real: |%15x|\n", 0);
	// b = ft_printf("mine: |%15x|\n", 0);
	// assert(a == b);

	// printf("\n-1:\n");
	// a =    printf("real: |%15x|\n", -1);
	// b = ft_printf("mine: |%15x|\n", -1);
	// assert(a == b);

	// printf("\nMAX_INT:\n");
	// a =    printf("real: |%15x|\n", MAX_INT);
	// b = ft_printf("mine: |%15x|\n", MAX_INT);
	// assert(a == b);

	// printf("\nMIN_INT:\n");
	// a =    printf("real: |%15x|\n", MIN_INT);
	// b = ft_printf("mine: |%15x|\n", MIN_INT);
	// assert(a == b);

	// printf("\nwidth: (1)\n");
	// printf("\n0:\n");
	// a =    printf("real: |%1x|\n", 0);
	// b = ft_printf("mine: |%1x|\n", 0);
	// assert(a == b);

	// printf("\n-1:\n");
	// a =    printf("real: |%1x|\n", -1);
	// b = ft_printf("mine: |%1x|\n", -1);
	// assert(a == b);

	// printf("\nMAX_INT:\n");
	// a =    printf("real: |%1x|\n", MAX_INT);
	// b = ft_printf("mine: |%1x|\n", MAX_INT);
	// assert(a == b);

	// printf("\nMIN_INT:\n");
	// a =    printf("real: |%1x|\n", MIN_INT);
	// b = ft_printf("mine: |%1x|\n", MIN_INT);
	// assert(a == b);

	// printf("\nwidth: (equal)\n");
	// printf("\n0:\n");
	// a =    printf("real: |%1x|\n", 0);
	// b = ft_printf("mine: |%1x|\n", 0);
	// assert(a == b);

	// printf("\n-1:\n");
	// a =    printf("real: |%2x|\n", -1);
	// b = ft_printf("mine: |%2x|\n", -1);
	// assert(a == b);

	// printf("\nMAX_INT:\n");
	// a =    printf("real: |%10x|\n", MAX_INT);
	// b = ft_printf("mine: |%10x|\n", MAX_INT);
	// assert(a == b);

	// printf("\nMIN_INT:\n");
	// a =    printf("real: |%11x|\n", MIN_INT);
	// b = ft_printf("mine: |%11x|\n", MIN_INT);
	// assert(a == b);

	// printf("\n0 flag, negative (width)\n");
	// a =    printf("real: |%010x|\n", -123);
	// b = ft_printf("mine: |%010x|\n", -123);
	// assert(a == b);

	// printf("\n0 flag, negative (precision > width)\n");
	// a =    printf("real: |%01.10x|\n", -123);
	// b = ft_printf("mine: |%01.10x|\n", -123);
	// assert(a == b);

	// printf("\n0 flag, negative ((precision == width) > length)\n");
	// a =    printf("real: |%010.10x|\n", -123);
	// b = ft_printf("mine: |%010.10x|\n", -123);
	// assert(a == b);

	// printf("\n0 flag, negative ((precision == width) < length)\n");
	// a =    printf("real: |%02.2x|\n", -123);
	// b = ft_printf("mine: |%02.2x|\n", -123);
	// assert(a == b);

	// printf("\n0 flag, negative (precision < width)\n");
	// a =    printf("real: |%010.5x|\n", -123);
	// b = ft_printf("mine: |%010.5x|\n", -123);
	// assert(a == b);

	// printf("\n===========================\n");

	// printf("\n0:\n");
	// a =    printf("real: |%-X|\n", 0);
	// b = ft_printf("mine: |%-X|\n", 0);
	// assert(a == b);
	// a =    printf("real: |%-5.0X|\n", 0);
	// b = ft_printf("mine: |%-5.0X|\n", 0);
	// assert(a == b);

	// printf("\n-1:\n");
	// a =    printf("real: |%-X|\n", -1);
	// b = ft_printf("mine: |%-X|\n", -1);
	// assert(a == b);

	// printf("\nMAX_INT:\n");
	// a =    printf("real: |%-X|\n", MAX_INT);
	// b = ft_printf("mine: |%-X|\n", MAX_INT);
	// assert(a == b);

	// printf("\nMIN_INT:\n");
	// a =    printf("real: |%-X|\n", MIN_INT);
	// b = ft_printf("mine: |%-X|\n", MIN_INT);
	// assert(a == b);

	// printf("\nprecison == 0\n");
	// a =    printf("real: |%-.0X|\n", 0);
	// b = ft_printf("mine: |%-.0X|\n", 0);
	// assert(a == b);
	// a =    printf("real: |%-.0X|\n", 1);
	// b = ft_printf("mine: |%-.0X|\n", 1);
	// assert(a == b);
	// a =    printf("real: |%-.0X|\n", -123);
	// b = ft_printf("mine: |%-.0X|\n", -123);
	// assert(a == b);

	// printf("\nwidth: (greater)\n");
	// printf("\n0:\n");
	// a =    printf("real: |%-15X|\n", 0);
	// b = ft_printf("mine: |%-15X|\n", 0);
	// assert(a == b);

	// printf("\n-1:\n");
	// a =    printf("real: |%-15X|\n", -1);
	// b = ft_printf("mine: |%-15X|\n", -1);
	// assert(a == b);

	// printf("\nMAX_INT:\n");
	// a =    printf("real: |%-15X|\n", MAX_INT);
	// b = ft_printf("mine: |%-15X|\n", MAX_INT);
	// assert(a == b);

	// printf("\nMIN_INT:\n");
	// a =    printf("real: |%-15X|\n", MIN_INT);
	// b = ft_printf("mine: |%-15X|\n", MIN_INT);
	// assert(a == b);

	// printf("\nwidth: (1)\n");
	// printf("\n0:\n");
	// a =    printf("real: |%-1X|\n", 0);
	// b = ft_printf("mine: |%-1X|\n", 0);
	// assert(a == b);

	// printf("\n-1:\n");
	// a =    printf("real: |%-1X|\n", -1);
	// b = ft_printf("mine: |%-1X|\n", -1);
	// assert(a == b);

	// printf("\nMAX_INT:\n");
	// a =    printf("real: |%-1X|\n", MAX_INT);
	// b = ft_printf("mine: |%-1X|\n", MAX_INT);
	// assert(a == b);

	// printf("\nMIN_INT:\n");
	// a =    printf("real: |%-1X|\n", MIN_INT);
	// b = ft_printf("mine: |%-1X|\n", MIN_INT);
	// assert(a == b);

	// printf("\nwidth: (equal)\n");
	// printf("\n0:\n");
	// a =    printf("real: |%-1X|\n", 0);
	// b = ft_printf("mine: |%-1X|\n", 0);
	// assert(a == b);

	// printf("\n-1:\n");
	// a =    printf("real: |%-2X|\n", -1);
	// b = ft_printf("mine: |%-2X|\n", -1);
	// assert(a == b);

	// printf("\nMAX_INT:\n");
	// a =    printf("real: |%-10X|\n", MAX_INT);
	// b = ft_printf("mine: |%-10X|\n", MAX_INT);
	// assert(a == b);

	// printf("\nMIN_INT:\n");
	// a =    printf("real: |%-11X|\n", MIN_INT);
	// b = ft_printf("mine: |%-11X|\n", MIN_INT);
	// assert(a == b);

	// printf("\n+ flag\n");
	// printf("\npositive (greater width)\n");
	// a =    printf("real: |%-+5X|\n", 123);
	// b = ft_printf("mine: |%-+5X|\n", 123);
	// assert(a == b);

	// printf("\npositive (equal width)\n");
	// a =    printf("real: |%-+3X|\n", 123);
	// b = ft_printf("mine: |%-+3X|\n", 123);
	// assert(a == b);

	// printf("\npositive (no width)\n");
	// a =    printf("real: |%-+X|\n", 123);
	// b = ft_printf("mine: |%-+X|\n", 123);
	// assert(a == b);

	// printf("\nzero (no width)\n");
	// a =    printf("real: |%-+X|\n", 0);
	// b = ft_printf("mine: |%-+X|\n", 0);
	// assert(a == b);

	// printf("\nnegative (greater width)\n");
	// a =    printf("real: |%-+5X|\n", -123);
	// b = ft_printf("mine: |%-+5X|\n", -123);
	// assert(a == b);

	// printf("\nnegative (equal width)\n");
	// a =    printf("real: |%-+3X|\n", -123);
	// b = ft_printf("mine: |%-+3X|\n", -123);
	// assert(a == b);

	// printf("\nnegative (no width)\n");
	// a =    printf("real: |%-+X|\n", -123);
	// b = ft_printf("mine: |%-+X|\n", -123);
	// assert(a == b);

	// printf("\n+ flag (precision > width)\n");
	// a =    printf("real: |%-+.15X|\n", MIN_INT);
	// b = ft_printf("mine: |%-+.15X|\n", MIN_INT);
	// assert(a == b);

	// printf("\n+ flag (precision < width)\n");
	// a =    printf("real: |%-+20.15X|\n", MIN_INT);
	// b = ft_printf("mine: |%-+20.15X|\n", MIN_INT);
	// assert(a == b);

	// printf("\n+ flag ((precision == width) < length)\n");
	// a =    printf("real: |%-+5.5X|\n", MIN_INT);
	// b = ft_printf("mine: |%-+5.5X|\n", MIN_INT);
	// assert(a == b);

	// printf("\n' ' flag, negative (precision > width)\n");
	// a =    printf("real: |%- .15X|\n", MIN_INT);
	// b = ft_printf("mine: |%- .15X|\n", MIN_INT);
	// assert(a == b);

	// printf("\n' ' flag, negative (precision < width)\n");
	// a =    printf("real: |%- 20.15X|\n", MIN_INT);
	// b = ft_printf("mine: |%- 20.15X|\n", MIN_INT);
	// assert(a == b);

	// printf("\n' ' flag, negative ((precision == width) < length)\n");
	// a =    printf("real: |%- 5.5X|\n", MIN_INT);
	// b = ft_printf("mine: |%- 5.5X|\n", MIN_INT);
	// assert(a == b);

	// printf("\n' ' flag, positive (precision > width)\n");
	// a =    printf("real: |%- .15X|\n", 1);
	// b = ft_printf("mine: |%- .15X|\n", 1);
	// assert(a == b);

	// printf("\n' ' flag, positive (precision < width)\n");
	// a =    printf("real: |%- 20.15X|\n", 1);
	// b = ft_printf("mine: |%- 20.15X|\n", 1);
	// assert(a == b);

	// printf("\n' ' flag, positive ((precision == width) > length)\n");
	// a =    printf("real: |%- 5.5X|\n", 1);
	// b = ft_printf("mine: |%- 5.5X|\n", 1);
	// assert(a == b);

	// printf("\n' ' flag, positive ((precision == width) < length)\n");
	// a =    printf("real: |%- 2.2X|\n", 123);
	// b = ft_printf("mine: |%- 2.2X|\n", 123);
	// assert(a == b);

	// printf("\n%% +5.5d\n");
	// a =    printf("real: |%- +5.5X|\n", 1);
	// b = ft_printf("mine: |%- +5.5X|\n", 1);
	// assert(a == b);

	// printf("\n%% +15.5d\n");
	// a =    printf("real: |%- +15.5X|\n", 1);
	// b = ft_printf("mine: |%- +15.5X|\n", 1);
	// assert(a == b);

	// printf("\n%% +5.15d\n");
	// a =    printf("real: |%- +5.15X|\n", 1);
	// b = ft_printf("mine: |%- +5.15X|\n", 1);
	// assert(a == b);

	// printf("\n-0 flag, negative (width)\n");
	// a =    printf("real: |%-010X|\n", -123);
	// b = ft_printf("mine: |%-010X|\n", -123);
	// assert(a == b);

	// printf("\n-0 flag, negative (precision > width)\n");
	// a =    printf("real: |%-01.10X|\n", -123);
	// b = ft_printf("mine: |%-01.10X|\n", -123);
	// assert(a == b);

	// printf("\n-0 flag, negative ((precision == width) > length)\n");
	// a =    printf("real: |%-010.10X|\n", -123);
	// b = ft_printf("mine: |%-010.10X|\n", -123);
	// assert(a == b);

	// printf("\n-0 flag, negative ((precision == width) < length)\n");
	// a =    printf("real: |%-02.2X|\n", -123);
	// b = ft_printf("mine: |%-02.2X|\n", -123);
	// assert(a == b);

	// printf("\n-0 flag, negative (precision < width)\n");
	// a =    printf("real: |%-010.5X|\n", -123);
	// b = ft_printf("mine: |%-010.5X|\n", -123);
	// assert(a == b);

	// printf("\n===========================\n");

	// printf("\n# flag\n");
	// a =    printf("real: |%#x|\n", 1);
	// b = ft_printf("mine: |%#x|\n", 1);
	// assert(a == b);

	// a =    printf("real: |%#x|\n", 57005);
	// b = ft_printf("mine: |%#x|\n", 57005);
	// assert(a == b);

	// a =    printf("real: |%#x|\n", 0);
	// b = ft_printf("mine: |%#x|\n", 0);
	// assert(a == b);


	// printf("\n0# flag\n");
	// a =    printf("real: |%0#x|\n", 1);
	// b = ft_printf("mine: |%0#x|\n", 1);
	// assert(a == b);

	// a =    printf("real: |%0#x|\n", 57005);
	// b = ft_printf("mine: |%0#x|\n", 57005);
	// assert(a == b);

	// a =    printf("real: |%0#x|\n", 0);
	// b = ft_printf("mine: |%0#x|\n", 0);
	// assert(a == b);


	// printf("\n#10 flag\n");
	// a =    printf("real: |%#10x|\n", 1);
	// b = ft_printf("mine: |%#10x|\n", 1);
	// assert(a == b);

	// a =    printf("real: |%#10x|\n", 57005);
	// b = ft_printf("mine: |%#10x|\n", 57005);
	// assert(a == b);

	// a =    printf("real: |%#10x|\n", 0);
	// b = ft_printf("mine: |%#10x|\n", 0);
	// assert(a == b);


	// printf("\n0#10 flag\n");
	// a =    printf("real: |%0#10x|\n", 1);
	// b = ft_printf("mine: |%0#10x|\n", 1);
	// assert(a == b);

	// a =    printf("real: |%0#10x|\n", 57005);
	// b = ft_printf("mine: |%0#10x|\n", 57005);
	// assert(a == b);

	// a =    printf("real: |%0#10x|\n", 0);
	// b = ft_printf("mine: |%0#10x|\n", 0);
	// assert(a == b);


	// printf("\n#.10 flag\n");
	// a =    printf("real: |%#.10x|\n", 1);
	// b = ft_printf("mine: |%#.10x|\n", 1);
	// assert(a == b);

	// a =    printf("real: |%#.10x|\n", 57005);
	// b = ft_printf("mine: |%#.10x|\n", 57005);
	// assert(a == b);

	// a =    printf("real: |%#.10x|\n", 0);
	// b = ft_printf("mine: |%#.10x|\n", 0);
	// assert(a == b);


	// printf("\n0#.10 flag\n");
	// a =    printf("real: |%0#.10x|\n", 1);
	// b = ft_printf("mine: |%0#.10x|\n", 1);
	// assert(a == b);

	// a =    printf("real: |%0#.10x|\n", 57005);
	// b = ft_printf("mine: |%0#.10x|\n", 57005);
	// assert(a == b);

	// a =    printf("real: |%0#.10x|\n", 0);
	// b = ft_printf("mine: |%0#.10x|\n", 0);
	// assert(a == b);


	// printf("\n#3.3 flag\n");
	// a =    printf("real: |%#3.3x|\n", 1);
	// b = ft_printf("mine: |%#3.3x|\n", 1);
	// assert(a == b);

	// a =    printf("real: |%#3.3x|\n", 57005);
	// b = ft_printf("mine: |%#3.3x|\n", 57005);
	// assert(a == b);

	// a =    printf("real: |%#3.3x|\n", 0);
	// b = ft_printf("mine: |%#3.3x|\n", 0);
	// assert(a == b);


	// printf("\n0#3.3 flag\n");
	// a =    printf("real: |%0#3.3x|\n", 1);
	// b = ft_printf("mine: |%0#3.3x|\n", 1);
	// assert(a == b);

	// a =    printf("real: |%0#3.3x|\n", 57005);
	// b = ft_printf("mine: |%0#3.3x|\n", 57005);
	// assert(a == b);

	// a =    printf("real: |%0#3.3x|\n", 0);
	// b = ft_printf("mine: |%0#3.3x|\n", 0);
	// assert(a == b);

	// printf("\n===========================\n");

	// printf("\n-# flag\n");
	// a =    printf("real: |%-#x|\n", 1);
	// b = ft_printf("mine: |%-#x|\n", 1);
	// assert(a == b);

	// a =    printf("real: |%-#x|\n", 57005);
	// b = ft_printf("mine: |%-#x|\n", 57005);
	// assert(a == b);

	// a =    printf("real: |%-#x|\n", 0);
	// b = ft_printf("mine: |%-#x|\n", 0);
	// assert(a == b);


	// printf("\n-0# flag\n");
	// a =    printf("real: |%-0#x|\n", 1);
	// b = ft_printf("mine: |%-0#x|\n", 1);
	// assert(a == b);

	// a =    printf("real: |%-0#x|\n", 57005);
	// b = ft_printf("mine: |%-0#x|\n", 57005);
	// assert(a == b);

	// a =    printf("real: |%-0#x|\n", 0);
	// b = ft_printf("mine: |%-0#x|\n", 0);
	// assert(a == b);


	// printf("\n-#10 flag\n");
	// a =    printf("real: |%-#10x|\n", 1);
	// b = ft_printf("mine: |%-#10x|\n", 1);
	// // assert(a == b);

	// a =    printf("real: |%-#10x|\n", 57005);
	// b = ft_printf("mine: |%-#10x|\n", 57005);
	// // assert(a == b);

	// a =    printf("real: |%-#10x|\n", 0);
	// b = ft_printf("mine: |%-#10x|\n", 0);
	// assert(a == b);


	// printf("\n-0#10 flag\n");
	// a =    printf("real: |%-0#10x|\n", 1);
	// b = ft_printf("mine: |%-0#10x|\n", 1);
	// assert(a == b);

	// a =    printf("real: |%-0#10x|\n", 57005);
	// b = ft_printf("mine: |%-0#10x|\n", 57005);
	// assert(a == b);

	// a =    printf("real: |%-0#10x|\n", 0);
	// b = ft_printf("mine: |%-0#10x|\n", 0);
	// assert(a == b);


	// printf("\n-#.10 flag\n");
	// a =    printf("real: |%-#.10x|\n", 1);
	// b = ft_printf("mine: |%-#.10x|\n", 1);
	// assert(a == b);

	// a =    printf("real: |%-#.10x|\n", 57005);
	// b = ft_printf("mine: |%-#.10x|\n", 57005);
	// assert(a == b);

	// a =    printf("real: |%-#.10x|\n", 0);
	// b = ft_printf("mine: |%-#.10x|\n", 0);
	// assert(a == b);


	// printf("\n-0#.10 flag\n");
	// a =    printf("real: |%-0#.10x|\n", 1);
	// b = ft_printf("mine: |%-0#.10x|\n", 1);
	// assert(a == b);

	// a =    printf("real: |%-0#.10x|\n", 57005);
	// b = ft_printf("mine: |%-0#.10x|\n", 57005);
	// assert(a == b);

	// a =    printf("real: |%-0#.10x|\n", 0);
	// b = ft_printf("mine: |%-0#.10x|\n", 0);
	// assert(a == b);


	// printf("\n-#3.3 flag\n");
	// a =    printf("real: |%-#3.3x|\n", 1);
	// b = ft_printf("mine: |%-#3.3x|\n", 1);
	// assert(a == b);

	// a =    printf("real: |%-#3.3x|\n", 57005);
	// b = ft_printf("mine: |%-#3.3x|\n", 57005);
	// assert(a == b);

	// a =    printf("real: |%-#3.3x|\n", 0);
	// b = ft_printf("mine: |%-#3.3x|\n", 0);
	// assert(a == b);


	// printf("\n-0#3.3 flag\n");
	// a =    printf("real: |%-0#3.3x|\n", 1);
	// b = ft_printf("mine: |%-0#3.3x|\n", 1);
	// assert(a == b);

	// a =    printf("real: |%-0#3.3x|\n", 57005);
	// b = ft_printf("mine: |%-0#3.3x|\n", 57005);
	// assert(a == b);

	// a =    printf("real: |%-0#3.3x|\n", 0);
	// b = ft_printf("mine: |%-0#3.3x|\n", 0);
	// assert(a == b);

	// printf("\n===========================\n");
	// printf("===========================  \n");
	// printf("===========================\n\n");

	// printf("Octal format\n");
	// printf("\ndefault: (no flags)\n");
	// printf("\n0:\n");
	// a =    printf("real: |%o|\n", 0);
	// b = ft_printf("mine: |%o|\n", 0);
	// assert(a == b);
	// a =    printf("real: |%5.0o|\n", 0);
	// b = ft_printf("mine: |%5.0o|\n", 0);
	// assert(a == b);

	// printf("\n-1:\n");
	// a =    printf("real: |%o|\n", -1);
	// b = ft_printf("mine: |%o|\n", -1);
	// assert(a == b);

	// printf("\nMAX_INT:\n");
	// a =    printf("real: |%o|\n", MAX_INT);
	// b = ft_printf("mine: |%o|\n", MAX_INT);
	// assert(a == b);

	// printf("\nMIN_INT:\n");
	// a =    printf("real: |%o|\n", MIN_INT);
	// b = ft_printf("mine: |%o|\n", MIN_INT);
	// assert(a == b);

	// printf("\nprecison == 0\n");
	// a =    printf("real: |%.0o|\n", 0);
	// b = ft_printf("mine: |%.0o|\n", 0);
	// assert(a == b);
	// a =    printf("real: |%.0o|\n", 1);
	// b = ft_printf("mine: |%.0o|\n", 1);
	// assert(a == b);
	// a =    printf("real: |%.0o|\n", -123);
	// b = ft_printf("mine: |%.0o|\n", -123);
	// assert(a == b);

	// printf("\nwidth: (greater)\n");
	// printf("\n0:\n");
	// a =    printf("real: |%15o|\n", 0);
	// b = ft_printf("mine: |%15o|\n", 0);
	// assert(a == b);

	// printf("\n-1:\n");
	// a =    printf("real: |%15o|\n", -1);
	// b = ft_printf("mine: |%15o|\n", -1);
	// assert(a == b);

	// printf("\nMAX_INT:\n");
	// a =    printf("real: |%15o|\n", MAX_INT);
	// b = ft_printf("mine: |%15o|\n", MAX_INT);
	// assert(a == b);

	// printf("\nMIN_INT:\n");
	// a =    printf("real: |%15o|\n", MIN_INT);
	// b = ft_printf("mine: |%15o|\n", MIN_INT);
	// assert(a == b);

	// printf("\nwidth: (1)\n");
	// printf("\n0:\n");
	// a =    printf("real: |%1o|\n", 0);
	// b = ft_printf("mine: |%1o|\n", 0);
	// assert(a == b);

	// printf("\n-1:\n");
	// a =    printf("real: |%1o|\n", -1);
	// b = ft_printf("mine: |%1o|\n", -1);
	// assert(a == b);

	// printf("\nMAX_INT:\n");
	// a =    printf("real: |%1o|\n", MAX_INT);
	// b = ft_printf("mine: |%1o|\n", MAX_INT);
	// assert(a == b);

	// printf("\nMIN_INT:\n");
	// a =    printf("real: |%1o|\n", MIN_INT);
	// b = ft_printf("mine: |%1o|\n", MIN_INT);
	// assert(a == b);

	// printf("\nwidth: (equal)\n");
	// printf("\n0:\n");
	// a =    printf("real: |%1o|\n", 0);
	// b = ft_printf("mine: |%1o|\n", 0);
	// assert(a == b);

	// printf("\n-1:\n");
	// a =    printf("real: |%2o|\n", -1);
	// b = ft_printf("mine: |%2o|\n", -1);
	// assert(a == b);

	// printf("\nMAX_INT:\n");
	// a =    printf("real: |%10o|\n", MAX_INT);
	// b = ft_printf("mine: |%10o|\n", MAX_INT);
	// assert(a == b);

	// printf("\nMIN_INT:\n");
	// a =    printf("real: |%11o|\n", MIN_INT);
	// b = ft_printf("mine: |%11o|\n", MIN_INT);
	// assert(a == b);

	// printf("\n0 flag, negative (width)\n");
	// a =    printf("real: |%010o|\n", -123);
	// b = ft_printf("mine: |%010o|\n", -123);
	// assert(a == b);

	// printf("\n0 flag, negative (precision > width)\n");
	// a =    printf("real: |%01.10o|\n", -123);
	// b = ft_printf("mine: |%01.10o|\n", -123);
	// assert(a == b);

	// printf("\n0 flag, negative ((precision == width) > length)\n");
	// a =    printf("real: |%010.10o|\n", -123);
	// b = ft_printf("mine: |%010.10o|\n", -123);
	// assert(a == b);

	// printf("\n0 flag, negative ((precision == width) < length)\n");
	// a =    printf("real: |%02.2o|\n", -123);
	// b = ft_printf("mine: |%02.2o|\n", -123);
	// assert(a == b);

	// printf("\n0 flag, negative (precision < width)\n");
	// a =    printf("real: |%010.5o|\n", -123);
	// b = ft_printf("mine: |%010.5o|\n", -123);
	// assert(a == b);

	// printf("\n===========================\n");

	// printf("\n0:\n");
	// a =    printf("real: |%-o|\n", 0);
	// b = ft_printf("mine: |%-o|\n", 0);
	// assert(a == b);
	// a =    printf("real: |%-5.0o|\n", 0);
	// b = ft_printf("mine: |%-5.0o|\n", 0);
	// assert(a == b);

	// printf("\n-1:\n");
	// a =    printf("real: |%-o|\n", -1);
	// b = ft_printf("mine: |%-o|\n", -1);
	// assert(a == b);

	// printf("\nMAX_INT:\n");
	// a =    printf("real: |%-o|\n", MAX_INT);
	// b = ft_printf("mine: |%-o|\n", MAX_INT);
	// assert(a == b);

	// printf("\nMIN_INT:\n");
	// a =    printf("real: |%-o|\n", MIN_INT);
	// b = ft_printf("mine: |%-o|\n", MIN_INT);
	// assert(a == b);

	// printf("\nprecison == 0\n");
	// a =    printf("real: |%-.0o|\n", 0);
	// b = ft_printf("mine: |%-.0o|\n", 0);
	// assert(a == b);
	// a =    printf("real: |%-.0o|\n", 1);
	// b = ft_printf("mine: |%-.0o|\n", 1);
	// assert(a == b);
	// a =    printf("real: |%-.0o|\n", -123);
	// b = ft_printf("mine: |%-.0o|\n", -123);
	// assert(a == b);

	// printf("\nwidth: (greater)\n");
	// printf("\n0:\n");
	// a =    printf("real: |%-15o|\n", 0);
	// b = ft_printf("mine: |%-15o|\n", 0);
	// assert(a == b);

	// printf("\n-1:\n");
	// a =    printf("real: |%-15o|\n", -1);
	// b = ft_printf("mine: |%-15o|\n", -1);
	// assert(a == b);

	// printf("\nMAX_INT:\n");
	// a =    printf("real: |%-15o|\n", MAX_INT);
	// b = ft_printf("mine: |%-15o|\n", MAX_INT);
	// assert(a == b);

	// printf("\nMIN_INT:\n");
	// a =    printf("real: |%-15o|\n", MIN_INT);
	// b = ft_printf("mine: |%-15o|\n", MIN_INT);
	// assert(a == b);

	// printf("\nwidth: (1)\n");
	// printf("\n0:\n");
	// a =    printf("real: |%-1o|\n", 0);
	// b = ft_printf("mine: |%-1o|\n", 0);
	// assert(a == b);

	// printf("\n-1:\n");
	// a =    printf("real: |%-1o|\n", -1);
	// b = ft_printf("mine: |%-1o|\n", -1);
	// assert(a == b);

	// printf("\nMAX_INT:\n");
	// a =    printf("real: |%-1o|\n", MAX_INT);
	// b = ft_printf("mine: |%-1o|\n", MAX_INT);
	// assert(a == b);

	// printf("\nMIN_INT:\n");
	// a =    printf("real: |%-1o|\n", MIN_INT);
	// b = ft_printf("mine: |%-1o|\n", MIN_INT);
	// assert(a == b);

	// printf("\nwidth: (equal)\n");
	// printf("\n0:\n");
	// a =    printf("real: |%-1o|\n", 0);
	// b = ft_printf("mine: |%-1o|\n", 0);
	// assert(a == b);

	// printf("\n-1:\n");
	// a =    printf("real: |%-2o|\n", -1);
	// b = ft_printf("mine: |%-2o|\n", -1);
	// assert(a == b);

	// printf("\nMAX_INT:\n");
	// a =    printf("real: |%-10o|\n", MAX_INT);
	// b = ft_printf("mine: |%-10o|\n", MAX_INT);
	// assert(a == b);

	// printf("\nMIN_INT:\n");
	// a =    printf("real: |%-11o|\n", MIN_INT);
	// b = ft_printf("mine: |%-11o|\n", MIN_INT);
	// assert(a == b);

	// printf("\n+ flag\n");
	// printf("\npositive (greater width)\n");
	// a =    printf("real: |%-+5o|\n", 123);
	// b = ft_printf("mine: |%-+5o|\n", 123);
	// assert(a == b);

	// printf("\npositive (equal width)\n");
	// a =    printf("real: |%-+3o|\n", 123);
	// b = ft_printf("mine: |%-+3o|\n", 123);
	// assert(a == b);

	// printf("\npositive (no width)\n");
	// a =    printf("real: |%-+o|\n", 123);
	// b = ft_printf("mine: |%-+o|\n", 123);
	// assert(a == b);

	// printf("\nzero (no width)\n");
	// a =    printf("real: |%-+o|\n", 0);
	// b = ft_printf("mine: |%-+o|\n", 0);
	// assert(a == b);

	// printf("\nnegative (greater width)\n");
	// a =    printf("real: |%-+5o|\n", -123);
	// b = ft_printf("mine: |%-+5o|\n", -123);
	// assert(a == b);

	// printf("\nnegative (equal width)\n");
	// a =    printf("real: |%-+3o|\n", -123);
	// b = ft_printf("mine: |%-+3o|\n", -123);
	// assert(a == b);

	// printf("\nnegative (no width)\n");
	// a =    printf("real: |%-+o|\n", -123);
	// b = ft_printf("mine: |%-+o|\n", -123);
	// assert(a == b);

	// printf("\n+ flag (precision > width)\n");
	// a =    printf("real: |%-+.15o|\n", MIN_INT);
	// b = ft_printf("mine: |%-+.15o|\n", MIN_INT);
	// assert(a == b);

	// printf("\n+ flag (precision < width)\n");
	// a =    printf("real: |%-+20.15o|\n", MIN_INT);
	// b = ft_printf("mine: |%-+20.15o|\n", MIN_INT);
	// assert(a == b);

	// printf("\n+ flag ((precision == width) < length)\n");
	// a =    printf("real: |%-+5.5o|\n", MIN_INT);
	// b = ft_printf("mine: |%-+5.5o|\n", MIN_INT);
	// assert(a == b);

	// printf("\n' ' flag, negative (precision > width)\n");
	// a =    printf("real: |%- .15o|\n", MIN_INT);
	// b = ft_printf("mine: |%- .15o|\n", MIN_INT);
	// assert(a == b);

	// printf("\n' ' flag, negative (precision < width)\n");
	// a =    printf("real: |%- 20.15o|\n", MIN_INT);
	// b = ft_printf("mine: |%- 20.15o|\n", MIN_INT);
	// assert(a == b);

	// printf("\n' ' flag, negative ((precision == width) < length)\n");
	// a =    printf("real: |%- 5.5o|\n", MIN_INT);
	// b = ft_printf("mine: |%- 5.5o|\n", MIN_INT);
	// assert(a == b);

	// printf("\n' ' flag, positive (precision > width)\n");
	// a =    printf("real: |%- .15o|\n", 1);
	// b = ft_printf("mine: |%- .15o|\n", 1);
	// assert(a == b);

	// printf("\n' ' flag, positive (precision < width)\n");
	// a =    printf("real: |%- 20.15o|\n", 1);
	// b = ft_printf("mine: |%- 20.15o|\n", 1);
	// assert(a == b);

	// printf("\n' ' flag, positive ((precision == width) > length)\n");
	// a =    printf("real: |%- 5.5o|\n", 1);
	// b = ft_printf("mine: |%- 5.5o|\n", 1);
	// assert(a == b);

	// printf("\n' ' flag, positive ((precision == width) < length)\n");
	// a =    printf("real: |%- 2.2o|\n", 123);
	// b = ft_printf("mine: |%- 2.2o|\n", 123);
	// assert(a == b);

	// printf("\n%% +5.5d\n");
	// a =    printf("real: |%- +5.5o|\n", 1);
	// b = ft_printf("mine: |%- +5.5o|\n", 1);
	// assert(a == b);

	// printf("\n%% +15.5d\n");
	// a =    printf("real: |%- +15.5o|\n", 1);
	// b = ft_printf("mine: |%- +15.5o|\n", 1);
	// assert(a == b);

	// printf("\n%% +5.15d\n");
	// a =    printf("real: |%- +5.15o|\n", 1);
	// b = ft_printf("mine: |%- +5.15o|\n", 1);
	// assert(a == b);

	// printf("\n-0 flag, negative (width)\n");
	// a =    printf("real: |%-010o|\n", -123);
	// b = ft_printf("mine: |%-010o|\n", -123);
	// assert(a == b);

	// printf("\n-0 flag, negative (precision > width)\n");
	// a =    printf("real: |%-01.10o|\n", -123);
	// b = ft_printf("mine: |%-01.10o|\n", -123);
	// assert(a == b);

	// printf("\n-0 flag, negative ((precision == width) > length)\n");
	// a =    printf("real: |%-010.10o|\n", -123);
	// b = ft_printf("mine: |%-010.10o|\n", -123);
	// assert(a == b);

	// printf("\n-0 flag, negative ((precision == width) < length)\n");
	// a =    printf("real: |%-02.2o|\n", -123);
	// b = ft_printf("mine: |%-02.2o|\n", -123);
	// assert(a == b);

	// printf("\n-0 flag, negative (precision < width)\n");
	// a =    printf("real: |%-010.5o|\n", -123);
	// b = ft_printf("mine: |%-010.5o|\n", -123);
	// assert(a == b);

	// printf("\n===========================\n");

	// printf("\n# flag\n");
	// a =    printf("real: |%#o|\n", 1);
	// b = ft_printf("mine: |%#o|\n", 1);
	// assert(a == b);

	// a =    printf("real: |%#o|\n", 57005);
	// b = ft_printf("mine: |%#o|\n", 57005);
	// assert(a == b);

	// a =    printf("real: |%#o|\n", 0);
	// b = ft_printf("mine: |%#o|\n", 0);
	// assert(a == b);


	// printf("\n0# flag\n");
	// a =    printf("real: |%0#o|\n", 1);
	// b = ft_printf("mine: |%0#o|\n", 1);
	// assert(a == b);

	// a =    printf("real: |%0#o|\n", 57005);
	// b = ft_printf("mine: |%0#o|\n", 57005);
	// assert(a == b);

	// a =    printf("real: |%0#o|\n", 0);
	// b = ft_printf("mine: |%0#o|\n", 0);
	// assert(a == b);


	// printf("\n#10 flag\n");
	// a =    printf("real: |%#10o|\n", 1);
	// b = ft_printf("mine: |%#10o|\n", 1);
	// // assert(a == b);

	// a =    printf("real: |%#10o|\n", 57005);
	// b = ft_printf("mine: |%#10o|\n", 57005);
	// // assert(a == b);

	// a =    printf("real: |%#10o|\n", 0);
	// b = ft_printf("mine: |%#10o|\n", 0);
	// assert(a == b);


	// printf("\n0#10 flag\n");
	// a =    printf("real: |%0#10o|\n", 1);
	// b = ft_printf("mine: |%0#10o|\n", 1);
	// assert(a == b);

	// a =    printf("real: |%0#10o|\n", 57005);
	// b = ft_printf("mine: |%0#10o|\n", 57005);
	// assert(a == b);

	// a =    printf("real: |%0#10o|\n", 0);
	// b = ft_printf("mine: |%0#10o|\n", 0);
	// assert(a == b);


	// printf("\n#.10 flag\n");
	// a =    printf("real: |%#.10o|\n", 1);
	// b = ft_printf("mine: |%#.10o|\n", 1);
	// assert(a == b);

	// a =    printf("real: |%#.10o|\n", 57005);
	// b = ft_printf("mine: |%#.10o|\n", 57005);
	// assert(a == b);

	// a =    printf("real: |%#.10o|\n", 0);
	// b = ft_printf("mine: |%#.10o|\n", 0);
	// assert(a == b);


	// printf("\n0#.10 flag\n");
	// a =    printf("real: |%0#.10o|\n", 1);
	// b = ft_printf("mine: |%0#.10o|\n", 1);
	// assert(a == b);

	// a =    printf("real: |%0#.10o|\n", 57005);
	// b = ft_printf("mine: |%0#.10o|\n", 57005);
	// assert(a == b);

	// a =    printf("real: |%0#.10o|\n", 0);
	// b = ft_printf("mine: |%0#.10o|\n", 0);
	// assert(a == b);


	// printf("\n#3.3 flag\n");
	// a =    printf("real: |%#3.3o|\n", 1);
	// b = ft_printf("mine: |%#3.3o|\n", 1);
	// assert(a == b);

	// a =    printf("real: |%#3.3o|\n", 57005);
	// b = ft_printf("mine: |%#3.3o|\n", 57005);
	// assert(a == b);

	// a =    printf("real: |%#3.3o|\n", 0);
	// b = ft_printf("mine: |%#3.3o|\n", 0);
	// assert(a == b);


	// printf("\n0#3.3 flag\n");
	// a =    printf("real: |%0#3.3o|\n", 1);
	// b = ft_printf("mine: |%0#3.3o|\n", 1);
	// assert(a == b);

	// a =    printf("real: |%0#3.3o|\n", 57005);
	// b = ft_printf("mine: |%0#3.3o|\n", 57005);
	// assert(a == b);

	// a =    printf("real: |%0#3.3o|\n", 0);
	// b = ft_printf("mine: |%0#3.3o|\n", 0);
	// assert(a == b);

	// printf("\n===========================\n");

	// printf("\n-# flag\n");
	// a =    printf("real: |%-#o|\n", 1);
	// b = ft_printf("mine: |%-#o|\n", 1);
	// assert(a == b);

	// a =    printf("real: |%-#o|\n", 57005);
	// b = ft_printf("mine: |%-#o|\n", 57005);
	// assert(a == b);

	// a =    printf("real: |%-#o|\n", 0);
	// b = ft_printf("mine: |%-#o|\n", 0);
	// assert(a == b);


	// printf("\n-0# flag\n");
	// a =    printf("real: |%-0#o|\n", 1);
	// b = ft_printf("mine: |%-0#o|\n", 1);
	// assert(a == b);

	// a =    printf("real: |%-0#o|\n", 57005);
	// b = ft_printf("mine: |%-0#o|\n", 57005);
	// assert(a == b);

	// a =    printf("real: |%-0#o|\n", 0);
	// b = ft_printf("mine: |%-0#o|\n", 0);
	// assert(a == b);


	// printf("\n-#10 flag\n");
	// a =    printf("real: |%-#10o|\n", 1);
	// b = ft_printf("mine: |%-#10o|\n", 1);
	// // assert(a == b);

	// a =    printf("real: |%-#10o|\n", 57005);
	// b = ft_printf("mine: |%-#10o|\n", 57005);
	// // assert(a == b);

	// a =    printf("real: |%-#10o|\n", 0);
	// b = ft_printf("mine: |%-#10o|\n", 0);
	// assert(a == b);


	// printf("\n-0#10 flag\n");
	// a =    printf("real: |%-0#10o|\n", 1);
	// b = ft_printf("mine: |%-0#10o|\n", 1);
	// assert(a == b);

	// a =    printf("real: |%-0#10o|\n", 57005);
	// b = ft_printf("mine: |%-0#10o|\n", 57005);
	// assert(a == b);

	// a =    printf("real: |%-0#10o|\n", 0);
	// b = ft_printf("mine: |%-0#10o|\n", 0);
	// assert(a == b);


	// printf("\n-#.10 flag\n");
	// a =    printf("real: |%-#.10o|\n", 1);
	// b = ft_printf("mine: |%-#.10o|\n", 1);
	// assert(a == b);

	// a =    printf("real: |%-#.10o|\n", 57005);
	// b = ft_printf("mine: |%-#.10o|\n", 57005);
	// assert(a == b);

	// a =    printf("real: |%-#.10o|\n", 0);
	// b = ft_printf("mine: |%-#.10o|\n", 0);
	// assert(a == b);


	// printf("\n-0#.10 flag\n");
	// a =    printf("real: |%-0#.10o|\n", 1);
	// b = ft_printf("mine: |%-0#.10o|\n", 1);
	// assert(a == b);

	// a =    printf("real: |%-0#.10o|\n", 57005);
	// b = ft_printf("mine: |%-0#.10o|\n", 57005);
	// assert(a == b);

	// a =    printf("real: |%-0#.10o|\n", 0);
	// b = ft_printf("mine: |%-0#.10o|\n", 0);
	// assert(a == b);


	// printf("\n-#3.3 flag\n");
	// a =    printf("real: |%-#3.3o|\n", 1);
	// b = ft_printf("mine: |%-#3.3o|\n", 1);
	// assert(a == b);

	// a =    printf("real: |%-#3.3o|\n", 57005);
	// b = ft_printf("mine: |%-#3.3o|\n", 57005);
	// assert(a == b);

	// a =    printf("real: |%-#3.3o|\n", 0);
	// b = ft_printf("mine: |%-#3.3o|\n", 0);
	// assert(a == b);


	// printf("\n-0#3.3 flag\n");
	// a =    printf("real: |%-0#3.3o|\n", 1);
	// b = ft_printf("mine: |%-0#3.3o|\n", 1);
	// assert(a == b);

	// a =    printf("real: |%-0#3.3o|\n", 57005);
	// b = ft_printf("mine: |%-0#3.3o|\n", 57005);
	// assert(a == b);

	// a =    printf("real: |%-0#3.3o|\n", 0);
	// b = ft_printf("mine: |%-0#3.3o|\n", 0);
	// assert(a == b);

	// printf("\n===========================\n");
	// printf("===========================  \n");
	// printf("===========================\n\n");

	// printf("Unsigned format\n");
	// printf("\ndefault: (no flags)\n");
	// printf("\n0:\n");
	// a =    printf("real: |%u|\n", 0);
	// b = ft_printf("mine: |%u|\n", 0);
	// assert(a == b);
	// a =    printf("real: |%5.0u|\n", 0);
	// b = ft_printf("mine: |%5.0u|\n", 0);
	// assert(a == b);

	// printf("\n-1:\n");
	// a =    printf("real: |%u|\n", -1);
	// b = ft_printf("mine: |%u|\n", -1);
	// assert(a == b);

	// printf("\nMAX_INT:\n");
	// a =    printf("real: |%u|\n", MAX_INT);
	// b = ft_printf("mine: |%u|\n", MAX_INT);
	// assert(a == b);

	// printf("\nMIN_INT:\n");
	// a =    printf("real: |%u|\n", MIN_INT);
	// b = ft_printf("mine: |%u|\n", MIN_INT);
	// assert(a == b);

	// printf("\nprecison == 0\n");
	// a =    printf("real: |%.0u|\n", 0);
	// b = ft_printf("mine: |%.0u|\n", 0);
	// assert(a == b);
	// a =    printf("real: |%.0u|\n", 1);
	// b = ft_printf("mine: |%.0u|\n", 1);
	// assert(a == b);
	// a =    printf("real: |%.0u|\n", -123);
	// b = ft_printf("mine: |%.0u|\n", -123);
	// assert(a == b);

	// printf("\nwidth: (greater)\n");
	// printf("\n0:\n");
	// a =    printf("real: |%15u|\n", 0);
	// b = ft_printf("mine: |%15u|\n", 0);
	// assert(a == b);

	// printf("\n-1:\n");
	// a =    printf("real: |%15u|\n", -1);
	// b = ft_printf("mine: |%15u|\n", -1);
	// assert(a == b);

	// printf("\nMAX_INT:\n");
	// a =    printf("real: |%15u|\n", MAX_INT);
	// b = ft_printf("mine: |%15u|\n", MAX_INT);
	// assert(a == b);

	// printf("\nMIN_INT:\n");
	// a =    printf("real: |%15u|\n", MIN_INT);
	// b = ft_printf("mine: |%15u|\n", MIN_INT);
	// assert(a == b);

	// printf("\nwidth: (1)\n");
	// printf("\n0:\n");
	// a =    printf("real: |%1u|\n", 0);
	// b = ft_printf("mine: |%1u|\n", 0);
	// assert(a == b);

	// printf("\n-1:\n");
	// a =    printf("real: |%1u|\n", -1);
	// b = ft_printf("mine: |%1u|\n", -1);
	// assert(a == b);

	// printf("\nMAX_INT:\n");
	// a =    printf("real: |%1u|\n", MAX_INT);
	// b = ft_printf("mine: |%1u|\n", MAX_INT);
	// assert(a == b);

	// printf("\nMIN_INT:\n");
	// a =    printf("real: |%1u|\n", MIN_INT);
	// b = ft_printf("mine: |%1u|\n", MIN_INT);
	// assert(a == b);

	// printf("\nwidth: (equal)\n");
	// printf("\n0:\n");
	// a =    printf("real: |%1u|\n", 0);
	// b = ft_printf("mine: |%1u|\n", 0);
	// assert(a == b);

	// printf("\n-1:\n");
	// a =    printf("real: |%2u|\n", -1);
	// b = ft_printf("mine: |%2u|\n", -1);
	// assert(a == b);

	// printf("\nMAX_INT:\n");
	// a =    printf("real: |%10u|\n", MAX_INT);
	// b = ft_printf("mine: |%10u|\n", MAX_INT);
	// assert(a == b);

	// printf("\nMIN_INT:\n");
	// a =    printf("real: |%11u|\n", MIN_INT);
	// b = ft_printf("mine: |%11u|\n", MIN_INT);
	// assert(a == b);

	// printf("\n0 flag, negative (width)\n");
	// a =    printf("real: |%010u|\n", -123);
	// b = ft_printf("mine: |%010u|\n", -123);
	// assert(a == b);

	// printf("\n0 flag, negative (precision > width)\n");
	// a =    printf("real: |%01.10u|\n", -123);
	// b = ft_printf("mine: |%01.10u|\n", -123);
	// assert(a == b);

	// printf("\n0 flag, negative ((precision == width) > length)\n");
	// a =    printf("real: |%010.10u|\n", -123);
	// b = ft_printf("mine: |%010.10u|\n", -123);
	// assert(a == b);

	// printf("\n0 flag, negative ((precision == width) < length)\n");
	// a =    printf("real: |%02.2u|\n", -123);
	// b = ft_printf("mine: |%02.2u|\n", -123);
	// assert(a == b);

	// printf("\n0 flag, negative (precision < width)\n");
	// a =    printf("real: |%010.5u|\n", -123);
	// b = ft_printf("mine: |%010.5u|\n", -123);
	// assert(a == b);

	// printf("\n===========================\n");

	// printf("\n0:\n");
	// a =    printf("real: |%-u|\n", 0);
	// b = ft_printf("mine: |%-u|\n", 0);
	// assert(a == b);
	// a =    printf("real: |%-5.0u|\n", 0);
	// b = ft_printf("mine: |%-5.0u|\n", 0);
	// assert(a == b);

	// printf("\n-1:\n");
	// a =    printf("real: |%-u|\n", -1);
	// b = ft_printf("mine: |%-u|\n", -1);
	// assert(a == b);

	// printf("\nMAX_INT:\n");
	// a =    printf("real: |%-u|\n", MAX_INT);
	// b = ft_printf("mine: |%-u|\n", MAX_INT);
	// assert(a == b);

	// printf("\nMIN_INT:\n");
	// a =    printf("real: |%-u|\n", MIN_INT);
	// b = ft_printf("mine: |%-u|\n", MIN_INT);
	// assert(a == b);

	// printf("\nprecison == 0\n");
	// a =    printf("real: |%-.0u|\n", 0);
	// b = ft_printf("mine: |%-.0u|\n", 0);
	// assert(a == b);
	// a =    printf("real: |%-.0u|\n", 1);
	// b = ft_printf("mine: |%-.0u|\n", 1);
	// assert(a == b);
	// a =    printf("real: |%-.0u|\n", -123);
	// b = ft_printf("mine: |%-.0u|\n", -123);
	// assert(a == b);

	// printf("\nwidth: (greater)\n");
	// printf("\n0:\n");
	// a =    printf("real: |%-15u|\n", 0);
	// b = ft_printf("mine: |%-15u|\n", 0);
	// assert(a == b);

	// printf("\n-1:\n");
	// a =    printf("real: |%-15u|\n", -1);
	// b = ft_printf("mine: |%-15u|\n", -1);
	// assert(a == b);

	// printf("\nMAX_INT:\n");
	// a =    printf("real: |%-15u|\n", MAX_INT);
	// b = ft_printf("mine: |%-15u|\n", MAX_INT);
	// assert(a == b);

	// printf("\nMIN_INT:\n");
	// a =    printf("real: |%-15u|\n", MIN_INT);
	// b = ft_printf("mine: |%-15u|\n", MIN_INT);
	// assert(a == b);

	// printf("\nwidth: (1)\n");
	// printf("\n0:\n");
	// a =    printf("real: |%-1u|\n", 0);
	// b = ft_printf("mine: |%-1u|\n", 0);
	// assert(a == b);

	// printf("\n-1:\n");
	// a =    printf("real: |%-1u|\n", -1);
	// b = ft_printf("mine: |%-1u|\n", -1);
	// assert(a == b);

	// printf("\nMAX_INT:\n");
	// a =    printf("real: |%-1u|\n", MAX_INT);
	// b = ft_printf("mine: |%-1u|\n", MAX_INT);
	// assert(a == b);

	// printf("\nMIN_INT:\n");
	// a =    printf("real: |%-1u|\n", MIN_INT);
	// b = ft_printf("mine: |%-1u|\n", MIN_INT);
	// assert(a == b);

	// printf("\nwidth: (equal)\n");
	// printf("\n0:\n");
	// a =    printf("real: |%-1u|\n", 0);
	// b = ft_printf("mine: |%-1u|\n", 0);
	// assert(a == b);

	// printf("\n-1:\n");
	// a =    printf("real: |%-2u|\n", -1);
	// b = ft_printf("mine: |%-2u|\n", -1);
	// assert(a == b);

	// printf("\nMAX_INT:\n");
	// a =    printf("real: |%-10u|\n", MAX_INT);
	// b = ft_printf("mine: |%-10u|\n", MAX_INT);
	// assert(a == b);

	// printf("\nMIN_INT:\n");
	// a =    printf("real: |%-11u|\n", MIN_INT);
	// b = ft_printf("mine: |%-11u|\n", MIN_INT);
	// assert(a == b);

	// printf("\n-0 flag, negative (width)\n");
	// a =    printf("real: |%-010u|\n", -123);
	// b = ft_printf("mine: |%-010u|\n", -123);
	// assert(a == b);

	// printf("\n-0 flag, negative (precision > width)\n");
	// a =    printf("real: |%-01.10u|\n", -123);
	// b = ft_printf("mine: |%-01.10u|\n", -123);
	// assert(a == b);

	// printf("\n-0 flag, negative ((precision == width) > length)\n");
	// a =    printf("real: |%-010.10u|\n", -123);
	// b = ft_printf("mine: |%-010.10u|\n", -123);
	// assert(a == b);

	// printf("\n-0 flag, negative ((precision == width) < length)\n");
	// a =    printf("real: |%-02.2u|\n", -123);
	// b = ft_printf("mine: |%-02.2u|\n", -123);
	// assert(a == b);

	// printf("\n-0 flag, negative (precision < width)\n");
	// a =    printf("real: |%-010.5u|\n", -123);
	// b = ft_printf("mine: |%-010.5u|\n", -123);
	// assert(a == b);

	printf("\n===========================\n");
	printf("===========================  \n");
	printf("===========================\n\n");

	printf("\nFloating-point format\n");
	printf("\nBasic (no flags)\n");
	// b = ft_printf("debug: |%f|\n", 12345679020032.0);

	a =    printf("real: |%f|\n", 0.0);
	b = ft_printf("mine: |%f|\n", 0.0);
	assert(a == b);
	a =    printf("real: |%f|\n", 0.1);
	b = ft_printf("mine: |%f|\n", 0.1);
	assert(a == b);
	a =    printf("real: |%f|\n", -123.456);
	b = ft_printf("mine: |%f|\n", -123.456);
	assert(a == b);

	printf("\nWidth > length\n");
	a =    printf("real: |%15f|\n", 0.0);
	b = ft_printf("mine: |%15f|\n", 0.0);
	assert(a == b);
	a =    printf("real: |%15f|\n", 0.1);
	b = ft_printf("mine: |%15f|\n", 0.1);
	assert(a == b);
	a =    printf("real: |%15f|\n", -123.456);
	b = ft_printf("mine: |%15f|\n", -123.456);
	assert(a == b);

	printf("\nWidth == length\n");
	a =    printf("real: |%8f|\n", 0.0);
	b = ft_printf("mine: |%8f|\n", 0.0);
	assert(a == b);
	a =    printf("real: |%8f|\n", 0.1);
	b = ft_printf("mine: |%8f|\n", 0.1);
	assert(a == b);
	a =    printf("real: |%11f|\n", -123.456);
	b = ft_printf("mine: |%11f|\n", -123.456);
	assert(a == b);

	printf("\nWidth < length\n");
	a =    printf("real: |%1f|\n", 0.0);
	b = ft_printf("mine: |%1f|\n", 0.0);
	assert(a == b);
	a =    printf("real: |%1f|\n", 0.1);
	b = ft_printf("mine: |%1f|\n", 0.1);
	assert(a == b);
	a =    printf("real: |%1f|\n", -123.456);
	b = ft_printf("mine: |%1f|\n", -123.456);
	assert(a == b);

	printf("\nPrecision == 6\n");
	a =    printf("real: |%.6f|\n", 0.0);
	b = ft_printf("mine: |%.6f|\n", 0.0);
	assert(a == b);
	a =    printf("real: |%.6f|\n", 0.1);
	b = ft_printf("mine: |%.6f|\n", 0.1);
	assert(a == b);
	a =    printf("real: |%.6f|\n", -123.456);
	b = ft_printf("mine: |%.6f|\n", -123.456);
	assert(a == b);

	printf("\nPrecision == 16\n");
	a =    printf("real: |%.16f|\n", 0.0);
	b = ft_printf("mine: |%.16f|\n", 0.0);
	assert(a == b);
	a =    printf("real: |%.16f|\n", 0.1);
	b = ft_printf("mine: |%.16f|\n", 0.1);
	assert(a == b);
	a =    printf("real: |%.16f|\n", -123.456);
	b = ft_printf("mine: |%.16f|\n", -123.456);
	assert(a == b);

	printf("\nPrecision == 1\n");
	a =    printf("real: |%.1f|\n", 0.0);
	b = ft_printf("mine: |%.1f|\n", 0.0);
	assert(a == b);
	a =    printf("real: |%.1f|\n", 0.1);
	b = ft_printf("mine: |%.1f|\n", 0.1);
	assert(a == b);
	a =    printf("real: |%.1f|\n", -123.456);
	b = ft_printf("mine: |%.1f|\n", -123.456);
	assert(a == b);

	printf("\nPrecision == 0\n");
	a =    printf("real: |%.0f|\n", 0.0);
	b = ft_printf("mine: |%.0f|\n", 0.0);
	assert(a == b);
	a =    printf("real: |%.0f|\n", 0.1);
	b = ft_printf("mine: |%.0f|\n", 0.1);
	assert(a == b);
	a =    printf("real: |%.0f|\n", -123.456);
	b = ft_printf("mine: |%.0f|\n", -123.456);
	assert(a == b);
}
