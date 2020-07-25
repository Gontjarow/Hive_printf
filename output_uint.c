#include "ft_printf.h"

int			output_uint(unsigned long long arg, t_data *flag)
{
	printf("\n{output_uint: '%llu', w%d p%d}\n", arg, flag->width, flag->precision);
}
