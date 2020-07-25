#include "ft_printf.h"

int			output_double(long double arg, t_data *flag)
{
	printf("\n{output_double: '%lld', w%d p%d}\n", arg, flag->width, flag->precision);
}
