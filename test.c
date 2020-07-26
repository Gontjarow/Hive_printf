#include "ft_printf.h"
#include <assert.h>

int			main(int argc, char **argv)
{
	(void)argc; (void)argv;
	int a, b;

	printf("String format:\n");
	printf("\nbasic: (no flags, empty string, null string)\n");
	a =    printf("real: |%s|\n", "Hello world!");
	b = ft_printf("mine: |%s|\n", "Hello world!");
	assert(a == b);
	a =    printf("real: |%s|\n", "");
	b = ft_printf("mine: |%s|\n", "");
	assert(a == b);
	a =    printf("real: |%s|\n", NULL);
	b = ft_printf("mine: |%s|\n", NULL);
	assert(a == b);

	printf("\nwidth (greater, smaller, equal, zero)\n");
	a =    printf("real: |%20s|\n", "Hello world!");
	b = ft_printf("mine: |%20s|\n", "Hello world!");
	assert(a == b);
	a =    printf("real: |%5s|\n", "Hello world!");
	b = ft_printf("mine: |%5s|\n", "Hello world!");
	assert(a == b);
	a =    printf("real: |%12s|\n", "Hello world!");
	b = ft_printf("mine: |%12s|\n", "Hello world!");
	assert(a == b);
	a =    printf("real: |%s|\n", "Hello world!");
	b = ft_printf("mine: |%s|\n", "Hello world!");
	assert(a == b);

	printf("\nwidth (flags: -)\n");
	a =    printf("real: |%-20s|\n", "Hello world!");
	b = ft_printf("mine: |%-20s|\n", "Hello world!");
	assert(a == b);
	a =    printf("real: |%-5s|\n", "Hello world!");
	b = ft_printf("mine: |%-5s|\n", "Hello world!");
	assert(a == b);
	a =    printf("real: |%-12s|\n", "Hello world!");
	b = ft_printf("mine: |%-12s|\n", "Hello world!");
	assert(a == b);
	a =    printf("real: |%-s|\n", "Hello world!");
	b = ft_printf("mine: |%-s|\n", "Hello world!");
	assert(a == b);

	printf("\nprecision (greater, smaller, equal, zero)\n");
	a =    printf("real: |%.20s|\n", "Hello world!");
	b = ft_printf("mine: |%.20s|\n", "Hello world!");
	assert(a == b);
	a =    printf("real: |%.5s|\n", "Hello world!");
	b = ft_printf("mine: |%.5s|\n", "Hello world!");
	assert(a == b);
	a =    printf("real: |%.12s|\n", "Hello world!");
	b = ft_printf("mine: |%.12s|\n", "Hello world!");
	assert(a == b);
	a =    printf("real: |%.0s|\n", "Hello world!");
	b = ft_printf("mine: |%.0s|\n", "Hello world!");
	assert(a == b);

	printf("\nprecision (flags: -)\n");
	a =    printf("real: |%-.20s|\n", "Hello world!");
	b = ft_printf("mine: |%-.20s|\n", "Hello world!");
	assert(a == b);
	a =    printf("real: |%-.5s|\n", "Hello world!");
	b = ft_printf("mine: |%-.5s|\n", "Hello world!");
	assert(a == b);
	a =    printf("real: |%-.12s|\n", "Hello world!");
	b = ft_printf("mine: |%-.12s|\n", "Hello world!");
	assert(a == b);
	a =    printf("real: |%-.0s|\n", "Hello world!");
	b = ft_printf("mine: |%-.0s|\n", "Hello world!");
	assert(a == b);

	printf("\nwidth & precision (greater, smaller, equal x2, zero)\n");
	a =    printf("real: |%20.5s|\n", "Hello world!");
	b = ft_printf("mine: |%20.5s|\n", "Hello world!");
	assert(a == b);
	a =    printf("real: |%5.20s|\n", "Hello world!");
	b = ft_printf("mine: |%5.20s|\n", "Hello world!");
	assert(a == b);
	a =    printf("real: |%5.5s|\n", "Hello world!");
	b = ft_printf("mine: |%5.5s|\n", "Hello world!");
	assert(a == b);
	a =    printf("real: |%15.15s|\n", "Hello world!");
	b = ft_printf("mine: |%15.15s|\n", "Hello world!");
	assert(a == b);
	a =    printf("real: |%.0s|\n", "Hello world!");
	b = ft_printf("mine: |%.0s|\n", "Hello world!");
	assert(a == b);
}