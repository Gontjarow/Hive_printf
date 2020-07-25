#include "ft_printf.h"

int			main(int argc, char **argv)
{
	(void)argc; (void)argv;
	int a, b;

	a =    printf("real: |%s|\n", "Hello world!");
	b = ft_printf("mine: |%s|\n", "Hello world!");
	printf("%d == %d\n", a, b);
}