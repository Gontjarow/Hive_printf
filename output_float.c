#include "ft_printf.h"

void	output_double(long double arg, t_data *flag)
{
	printf("\n{output_double: '%Lf', w%d p%d}\n", arg, flag->width, flag->precision);
}
