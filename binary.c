#include "ft_printf.h"

void		print_bits(size_t size, void *ptr)
{
	unsigned char	*data;
	unsigned char	bit;
	int				byte;
	int				shift;

	data = (unsigned char *)ptr;
	for (byte = size - 1; byte >= 0; byte--)
	{
		for (shift = 7; shift >= 0; shift--)
		{
			bit = (data[byte] >> shift) & 1;
			printf("%u", bit);
		}
	}
	printf("\n");
}

int			double_to_binary(double d)
{
	t_double	test;
	int			bit;

	test.d = d;
	ft_putendl("===v");
	for (bit = 63; bit >= 0; --bit)
	{
		write(1, (test.ul >> bit) & 1 ? "1" : "0", 1);
		if (bit == 63 || bit == 52)
			write(1, " ", 1);
	}
	ft_putendl(" (binary)");
	output_double(test.d, NULL);
	ft_putendl(" (double)");
	ft_putendl("===^");
	return 0;
}

int			float_to_binary(float f)
{
	unsigned char n[4]; ft_memcpy(n, &f, 4);

	t_float	test;
	int		bit;

	ft_putendl("---v");
	test.f = f;
	for (bit = 31; bit >= 0; --bit)
	{
		write(1, (test.u >> bit) & 0b1 ? "1" : "0", 1);
		if (bit == 31 || bit == 23)
			write(1, " ", 1);
	}
	ft_putendl(" (binary)");
	output_double(test.f, NULL);
	ft_putendl(" (float)");
	ft_putendl("---^");
	return 0;
}
