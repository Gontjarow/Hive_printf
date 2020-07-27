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

	printf("\n===========================\n");
	printf("===========================  \n");
	printf("===========================\n\n");

	printf("Integer formats:\n");
	printf("default: (no flags)\n");
	printf("0:\n");
	a =    printf("real d: |%d|\n", 0);
	b = ft_printf("mine d: |%d|\n", 0);
	assert(a == b);

	a =    printf("real i: |%d|\n", 0);
	b = ft_printf("mine i: |%d|\n", 0);
	assert(a == b);
	printf("\n");

	printf("-1:\n");
	a =    printf("real d: |%d|\n", -1);
	b = ft_printf("mine d: |%d|\n", -1);
	assert(a == b);

	a =    printf("real i: |%d|\n", -1);
	b = ft_printf("mine i: |%d|\n", -1);
	assert(a == b);
	printf("\n");

	printf("MAX_INT:\n");
	a =    printf("real d: |%d|\n", MAX_INT);
	b = ft_printf("mine d: |%d|\n", MAX_INT);
	assert(a == b);

	a =    printf("real i: |%d|\n", MAX_INT);
	b = ft_printf("mine i: |%d|\n", MAX_INT);
	assert(a == b);
	printf("\n");

	printf("MIN_INT:\n");
	a =    printf("real d: |%d|\n", MIN_INT);
	b = ft_printf("mine d: |%d|\n", MIN_INT);
	assert(a == b);

	a =    printf("real i: |%d|\n", MIN_INT);
	b = ft_printf("mine i: |%d|\n", MIN_INT);
	assert(a == b);
	printf("\n");

	printf("width: (greater)\n");
	printf("0:\n");
	a =    printf("real d: |%15d|\n", 0);
	b = ft_printf("mine d: |%15d|\n", 0);
	assert(a == b);

	printf("-1:\n");
	a =    printf("real d: |%15d|\n", -1);
	b = ft_printf("mine d: |%15d|\n", -1);
	assert(a == b);

	printf("MAX_INT:\n");
	a =    printf("real d: |%15d|\n", MAX_INT);
	b = ft_printf("mine d: |%15d|\n", MAX_INT);
	assert(a == b);

	printf("MIN_INT:\n");
	a =    printf("real d: |%15d|\n", MIN_INT);
	b = ft_printf("mine d: |%15d|\n", MIN_INT);
	assert(a == b);

	printf("width: (1)\n");
	printf("0:\n");
	a =    printf("real d: |%1d|\n", 0);
	b = ft_printf("mine d: |%1d|\n", 0);
	assert(a == b);

	printf("-1:\n");
	a =    printf("real d: |%1d|\n", -1);
	b = ft_printf("mine d: |%1d|\n", -1);
	assert(a == b);

	printf("MAX_INT:\n");
	a =    printf("real d: |%1d|\n", MAX_INT);
	b = ft_printf("mine d: |%1d|\n", MAX_INT);
	assert(a == b);

	printf("MIN_INT:\n");
	a =    printf("real d: |%1d|\n", MIN_INT);
	b = ft_printf("mine d: |%1d|\n", MIN_INT);
	assert(a == b);

	printf("width: (equal)\n");
	printf("0:\n");
	a =    printf("real d: |%1d|\n", 0);
	b = ft_printf("mine d: |%1d|\n", 0);
	assert(a == b);

	printf("-1:\n");
	a =    printf("real d: |%2d|\n", -1);
	b = ft_printf("mine d: |%2d|\n", -1);
	assert(a == b);

	printf("MAX_INT:\n");
	a =    printf("real d: |%10d|\n", MAX_INT);
	b = ft_printf("mine d: |%10d|\n", MAX_INT);
	assert(a == b);

	printf("MIN_INT:\n");
	a =    printf("real d: |%11d|\n", MIN_INT);
	b = ft_printf("mine d: |%11d|\n", MIN_INT);
	assert(a == b);
	printf("width: (- flag, greater)\n");
	printf("0:\n");
	a =    printf("real d: |%-15d|\n", 0);
	b = ft_printf("mine d: |%-15d|\n", 0);
	assert(a == b);

	printf("-1:\n");
	a =    printf("real d: |%-15d|\n", -1);
	b = ft_printf("mine d: |%-15d|\n", -1);
	assert(a == b);

	printf("MAX_INT:\n");
	a =    printf("real d: |%-15d|\n", MAX_INT);
	b = ft_printf("mine d: |%-15d|\n", MAX_INT);
	assert(a == b);

	printf("MIN_INT:\n");
	a =    printf("real d: |%-15d|\n", MIN_INT);
	b = ft_printf("mine d: |%-15d|\n", MIN_INT);
	assert(a == b);

	printf("width: (- flag, 1)\n");
	printf("0:\n");
	a =    printf("real d: |%-1d|\n", 0);
	b = ft_printf("mine d: |%-1d|\n", 0);
	assert(a == b);

	printf("-1:\n");
	a =    printf("real d: |%-1d|\n", -1);
	b = ft_printf("mine d: |%-1d|\n", -1);
	assert(a == b);

	printf("MAX_INT:\n");
	a =    printf("real d: |%-1d|\n", MAX_INT);
	b = ft_printf("mine d: |%-1d|\n", MAX_INT);
	assert(a == b);

	printf("MIN_INT:\n");
	a =    printf("real d: |%-1d|\n", MIN_INT);
	b = ft_printf("mine d: |%-1d|\n", MIN_INT);
	assert(a == b);

	printf("width: (- flag, equal)\n");
	printf("0:\n");
	a =    printf("real d: |%-1d|\n", 0);
	b = ft_printf("mine d: |%-1d|\n", 0);
	assert(a == b);

	printf("-1:\n");
	a =    printf("real d: |%-2d|\n", -1);
	b = ft_printf("mine d: |%-2d|\n", -1);
	assert(a == b);

	printf("MAX_INT:\n");
	a =    printf("real d: |%-10d|\n", MAX_INT);
	b = ft_printf("mine d: |%-10d|\n", MAX_INT);
	assert(a == b);

	printf("MIN_INT:\n");
	a =    printf("real d: |%-11d|\n", MIN_INT);
	b = ft_printf("mine d: |%-11d|\n", MIN_INT);
	assert(a == b);

	printf("+ flag\n");
	printf("positive (greater width)\n");
	a =    printf("real d: |%+5d|\n", 123);
	b = ft_printf("mine d: |%+5d|\n", 123);
	assert(a == b);
	printf("\n");

	printf("positive (equal width)\n");
	a =    printf("real d: |%+3d|\n", 123);
	b = ft_printf("mine d: |%+3d|\n", 123);
	assert(a == b);
	printf("\n");

	printf("positive (no width)\n");
	a =    printf("real d: |%+d|\n", 123);
	b = ft_printf("mine d: |%+d|\n", 123);
	assert(a == b);
	printf("\n");

	printf("zero (no width)\n");
	a =    printf("real d: |%+d|\n", 0);
	b = ft_printf("mine d: |%+d|\n", 0);
	assert(a == b);
	printf("\n");

	printf("negative (greater width)\n");
	a =    printf("real d: |%+5d|\n", -123);
	b = ft_printf("mine d: |%+5d|\n", -123);
	assert(a == b);
	printf("\n");

	printf("negative (equal width)\n");
	a =    printf("real d: |%+3d|\n", -123);
	b = ft_printf("mine d: |%+3d|\n", -123);
	assert(a == b);
	printf("\n");

	printf("negative (no width)\n");
	a =    printf("real d: |%+d|\n", -123);
	b = ft_printf("mine d: |%+d|\n", -123);
	assert(a == b);
	printf("\n");

	printf("+ flag (precision > width)\n");
	a =    printf("real d: |%+.15d|\n", MIN_INT); // |-000002147483648|
	b = ft_printf("mine d: |%+.15d|\n", MIN_INT);
	assert(a == b);
	printf("\n");

	printf("+ flag (precision < width)\n");
	a =    printf("real d: |%+20.15d|\n", MIN_INT); // |    -000002147483648|
	b = ft_printf("mine d: |%+20.15d|\n", MIN_INT);
	assert(a == b);
	printf("\n");

	printf("+ flag ((precision == width) < length)\n");
	a =    printf("real d: |%+5.5d|\n", MIN_INT); // |-2147483648|
	b = ft_printf("mine d: |%+5.5d|\n", MIN_INT);
	assert(a == b);
	printf("\n");

	printf("' ' flag, negative (precision > width)\n");
	a =    printf("real d: |% .15d|\n", MIN_INT);
	b = ft_printf("mine d: |% .15d|\n", MIN_INT);
	assert(a == b);
	printf("\n");

	printf("' ' flag, negative (precision < width)\n");
	a =    printf("real d: |% 20.15d|\n", MIN_INT);
	b = ft_printf("mine d: |% 20.15d|\n", MIN_INT);
	assert(a == b);
	printf("\n");

	printf("' ' flag, negative ((precision == width) < length)\n");
	a =    printf("real d: |% 5.5d|\n", MIN_INT);
	b = ft_printf("mine d: |% 5.5d|\n", MIN_INT);
	assert(a == b);
	printf("\n");


	printf("' ' flag, positive (precision > width)\n");
	a =    printf("real d: |% .15d|\n", 1);
	b = ft_printf("mine d: |% .15d|\n", 1);
	assert(a == b);
	printf("\n");

	printf("' ' flag, positive (precision < width)\n");
	a =    printf("real d: |% 20.15d|\n", 1);
	b = ft_printf("mine d: |% 20.15d|\n", 1);
	assert(a == b);
	printf("\n");

	printf("' ' flag, positive ((precision == width) < length)\n");
	a =    printf("real d: |% 5.5d|\n", 1);
	b = ft_printf("mine d: |% 5.5d|\n", 1);
	assert(a == b);
	printf("\n");

	printf("%% +5.5d\n");
	a =    printf("real d: |% +5.5d|\n", 1);
	b = ft_printf("mine d: |% +5.5d|\n", 1);
	assert(a == b);
	printf("\n");
}